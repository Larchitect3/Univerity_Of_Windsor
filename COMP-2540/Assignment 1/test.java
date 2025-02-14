public static Entry<String, integer> count LINKED LIST BAD( String [ ] tokens ) 
{
    LinkedList<Entry<String, integer>> l i s t = new LinkedList<Entry<String, integer >>() ;
    for ( int j = 0 ; j < tokens.length; j++) 
    {
        String word = tokens[j] ;
        boolean found = false ;
        for ( int i = 0 ; i < list.size(); i++) {
        Entry<String, Integer> e = list.get (i) ;
        if (word . equals ( e.getKey ( ) ) ) 
        {
            e.setValue (e.getValue ( ) + 1) ;
            list.set (i,e ) ;
            found = true ;
            break;
        }
        }
        if(!found )
        list.add (new AbstractMap.SimpleEntry<String , integer >(word , 1) ) ;
    }
}