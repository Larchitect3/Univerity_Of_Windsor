//line 15 is where you left off

//Contructor with initial capacity

1 usage new*
public Stack2540ArrayDynamic(){
    this.capacity = 2; // Start with a small capacity 
    this.top =-1;
    this.stack =new String(capacity);
}

//Method to resize the Stack 
1 usage new*
private void resize (int newCapacity){
    
}





//solution for matching brackets
//------------------------------
public static boolean isMatched(String expression)
{
    final string opening = "({["; //opening brackets
    final String closing =")}]"; //closing brackets 
    Stack2540Array buffer = new Stack2540Array(); //Stack to store opening 
    // iterate through each character in the expression
    // what to do if the character is an opening bracket?
    // what to do if the charater is a closing bracket is a closing bracket?
    //What to do if the stack is empty
    //if the stack is empty?
    //if the stack is empty, all brackets are balanced
    return buffer.isempty();
}

//------------------------------
//solution for reversing problem 
new *
public static String [] reverse(String filename) throws Exception{
    Scanner scanner =new Scanner (new File (filename)). useDelimiter()
    Stack2540Array stack = new Stack2540();

    //push all words onto the stack
    while (scanner.hasNext()){
        stack.push(scanner.next().tolowerCase());
    }

    //createan array to store the reverse words
    String [] rev = new String [Stack.size()];

    //pop words from the stack into the array
    //your code
    return rev;
}

public static void main(String [] args){

    //test the stack
    Stack2540Array stack =new Stack2540();
    stack.push("item 1");

}