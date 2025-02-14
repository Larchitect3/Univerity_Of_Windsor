static void reverse ( String [] a) 
{
    Stack < String > stack = new Stack < String >();
    for (int i =0; i < a. length ; i ++)
        stack . push (a[i]);
    for (int i =0; i < a. length ; i ++)
        a[i] = stack . pop ();
}
