// Problem 10142 Australian Voting
// @author Ziad Kobti 

import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

interface GLOBAL
{
	boolean DEBUG=false;		// set to true to enable debugging
}

// must call the class Main
public class Main implements GLOBAL
{
	public static void main(String args[]) throws Exception
	{
		// Read input program loop

		int t;	// number of test cases

		Scanner sc = new Scanner(new FileInputStream(args[0]));
		t = Integer.parseInt(sc.nextLine().trim());
						
		if (DEBUG) System.err.println("Number of test cases = " + t);
		
		while (t > 0)
		{
			// Read a single Test Case
			// Process a single Test Case
			if (DEBUG) System.err.println("ReadProcessTestCase("+t+")"); 			
			ReadProcessTestCase(sc);
			System.out.print("\n"); // need a new line between cases
			t--;
		}

	}
	
	// main logic here
	public static void ReadProcessTestCase(Scanner sc)
	{
		int n;	// use to store the number of candidates
		String names[] = new String[21]; // use to store names 1 to 20
		int votes[][] = new int[1000][20]; // store the votes up to 1000
		int sum[] = new int[21]; // store the vote counts for the 20 candidates
		int i,v, voters; // counter
		String line;
		
		// advance over blank lines if any
		line = sc.nextLine().trim(); // read the blank line!
		if (line.isEmpty())
		{
			n = Integer.parseInt(sc.nextLine().trim());		// read n
		}
		else
		{
			n = Integer.parseInt(line);
		}

		if (DEBUG) System.err.println("n = " + n);
		
		for (i=1;i<=n; i++)		// read names
		{
			names[i] = sc.nextLine();
			if (DEBUG) System.err.println("Reading names into index " + i + ": " + names[i]);
		}
		
		boolean done = false;
		// read the votes
		voters = 0;
		while(!done) // test this for multiple cases
		{
			line = sc.nextLine().trim(); // trim spaces in the line
			if (DEBUG) System.err.println("Read voter line: " + line);
			if (!line.isEmpty())
			{
				// tokenize the line into its numbers
				if (DEBUG) System.out.println("Tokenizing line: " + line);
			     StringTokenizer st = new StringTokenizer(line);
			     i=0;
			     while (st.hasMoreTokens()) {
					votes[voters][i++] = Integer.valueOf(st.nextToken());
			     }
			     voters++;
			     
			}
			else
			{
				done = true;
			}
		}

		// DONE READING - NOW START PROCESSING 
		if (DEBUG) System.err.println("Read " + voters + " voters");

		do
		{

			//Reset Sum array to 0
			for (i=1; i <= n; i++) sum[i]=0;
		
			//count the votes in col 0 for each candidate
			for (v=0; v<voters; v++)
			{
				sum[votes[v][0]]++;
			}

			if (DEBUG)
			{
				System.err.print("Sum Array: ");
				for (i=1; i <= n; i++)
				{
					System.err.print(" " + sum[i]);
				}
				System.err.print("\n");
			}

			//check for a majority winner 
			if (DEBUG) System.err.println("checking majority winner...");
			for (i=1; i <= n; i++)
			{
				if (sum[i] > (Math.floor(voters/2)))
				{
					if (DEBUG) System.err.println("found majority at " + i+ "="+sum[i]);
					System.out.println(names[i]);			
					return;				
				}
			}

			if (DEBUG) System.err.println("checking all tie...");
			// Check if all tie
			// find min > 0
			// find max
			int min=999, min_index=0;
			int max=sum[1];
			for (i=1; i <= n; i++)
			{
				if (sum[i] > 0 && sum[i] > max)
				{
					max = sum[i];
				}
				if (sum[i] > 0 && sum[i] < min)
				{
					min = sum[i];
					min_index = i;
				}
			}
			if (DEBUG) System.err.println("min="+min+"; max="+max+" ;min_index="+min_index);

			if (min == max) // case detected!
			{
				// print all non 0 names
				for (int j=1; j<= n; j++)					
				{
					if (sum[j] > 0) System.out.println(names[j]);
				}					
				return;				
			}
			

		// if still here, then 
		// drop all mins to 0 from the votes array			
		// left shift the votes array to eliminate gaps with 0 entry
		// repeat the loop back to do.
		
		for (i=0; i < voters; i++)
		{
			for (int j=0; j< n; j++)
			{
				if (votes[i][j] == min_index)
				{
					// shift the rest of the array
					// from j to n-1
					for (int k=j; k < n-1; k++)
					  votes[i][k] = votes[i][k+1];
				}
			}
			if (DEBUG)
			{
				for (int j=0; j<n;j++)
				{
					System.err.print(" " + votes[i][j]);
				}	
				System.err.print("\n");
			}		
		}
			

		} while(true);

	}

}



