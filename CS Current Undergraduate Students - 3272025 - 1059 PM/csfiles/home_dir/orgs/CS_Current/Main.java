/**
@author Dr. Ziad Kobti
@copyright 2016
problem UVA10300
*/

import java.util.*;

interface constants
{
	boolean DEBUG = false;  // use true/false to enable/disable debugging
}

public class Main implements constants
{
	public static void main(String[] args) 
	{	
		int n_case=0;
		Scanner sc = new Scanner(System.in);

		n_case = Integer.parseInt(sc.next()); // could just use: sc.nextInt() 

		while (n_case > 0)
		{
			if (DEBUG) System.err.printf("ncase="+n_case);
			if (DEBUG) System.err.printf("calling ProcessCase...");

			ProcessCase(sc);
			if (DEBUG) System.err.printf("ProcessCase returned");
			n_case--;
		}
		sc.close();
	}

	public static void ProcessCase(Scanner sc)
	{
		
		int n_farmers=0;
		int farm_size=0;
		int n_animals=0;
		int eco=0;
		int i;

		int premium=0;
		
		if (DEBUG) System.err.println("reading n_farmers...");
		n_farmers = Integer.parseInt(sc.next());

		// read case of size n_farmers
		for (i=0; i < n_farmers; i++)
		{
			if (DEBUG) System.err.println("reading farm_size...");
			farm_size = Integer.parseInt(sc.next());
			if (DEBUG) System.err.println("reading n_animals...");
			n_animals = Integer.parseInt(sc.next());
			if (DEBUG) System.err.println("reading eco...");
			eco = Integer.parseInt(sc.next());
			
			premium += farm_size * eco; 
		}
		System.out.println(premium);
	}
}


