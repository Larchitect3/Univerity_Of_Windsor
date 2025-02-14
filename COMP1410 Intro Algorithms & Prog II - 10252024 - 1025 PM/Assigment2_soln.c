#include<stdio.h>
#include<string.h>

#define N 100
#define M 21

//Simply returns 1 if the char is a-z or A-Z, 0 otherwise
int is_alpha(char c){
   if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
      return 1;
   return 0;
}

//Swaps two strings using a copy approach
//There are other ways of swapping strings
void swap(char *s1, char *s2) {
     //Step 1: TEMP = S1
     strcpy(temp, s1);

     //Step 2: S1 = S2
     strcpy(s1, s2);

     //Step 3: S2 = TEMP
     strcpy(s2, temp);
}

//Insert a word into the list and maintain sorted order
void insert_into_list(char list[N][M], char word[M], int num_words) {
   int k = 0;
   for(; k < num_words; k++)
      if(strcmp(word, list[k]) <= 0)
          swap(word, list[k]);
   strcpy(list[k], word); //place last word
}

//Read words from a list
int read_list(char list[N][M], int max_len) {
    printf("Please enter your list:\n");
    int k = 0;
    int j = 0;
    char c = '\0';
    scanf("%c", &c);
    char word[M];
    while(1) {
       if( is_alpha(c) ) { //Reading word chars
          word[j++] = c;
          scanf("%c", &c);
       } else if(c == '\n' || k == max_len) { //Done reading
          word[j] = '\0';
          insert_into_list(list, word, k++);
          break;
       } else {               // Reading delimiters
          word[j] = '\0';
          insert_into_list(list, word, k++);
          j = 0;
          do{
            scanf("%c", &c);
          }while(!is_alpha(c) && c != '\n');
       }
    }

    while(c != '\n')  //Clear the remaining list if we ran out of words (>100 words)
      scanf("%c", &c);

    return k;
}

//Print the list given the number of words in it
void print_list(char list[N][M], int num_words) {
    printf("\nWord list:\n");
    for(int k = 0; k < num_words; k++)
       printf("\t%s\n", list[k]);
    printf("\n");
}

//Prints longest and shorted words
//"Larger" in terms of number of chars
void print_longest(char list[N][M], int num_words) {
    int max_pos, min_pos;
    int max_len = 0, min_len = M;
    for(int k = 0; k < num_words; k++){
        int len = strlen(list[k]);
        if(len > max_len) {
           max_pos = k;
           max_len = len;
        }
        if(len < min_len) {
           min_pos = k;
           min_len = len;
        }
    }

    printf("Word length:\n");
    printf("\tLongest:  %s, %d\n", list[max_pos], max_len);
    printf("\tShortest: %s, %d\n", list[min_pos], min_len);
    printf("\n");
    return;
}


//Lexicographically larger
//Assumes list is not sorted
void print_largest_unsorted(char list[N][M], int num_words) {
    int max_pos, min_pos;
    int max_size = 0, min_size = M;
    for(int k = 0; k < num_words; k++){
        int size = strcmp(list[k], list[max_pos]);
        if(size > max_size) {
           max_pos = k;
           max_size = size;
        }
        size = strcmp(list[k], list[min_pos]);
        if(size < min_size) {
           min_pos = k;
           min_size = size;
        }
    }

    printf("Lexicographically:\n");
    printf("\tLargest:  %s\n", list[max_pos]);
    printf("\tSmallest: %s\n", list[min_pos]);
    printf("\n");
    return;
}

//Lexicographically larger
//Assume list is sorted
void print_largest_sorted(char list[N][M], int num_words) {
    printf("Lexicographically:\n");
    printf("\tLargest:  %s\n", list[num_words-1]);
    printf("\tSmallest: %s\n", list[0]);
    printf("\n");
    return;
}


//Reads a word and deletes everything after the first white space encountered
void read_word(char *str, int max_len){
    //Read word 1 char at a time
    int k = 0;
    for(; k < max_len-1; k++) {
      scanf("%c", &str[k]);
      if(str[k] == '\n' || str[k] == ' ')
         break;
    }
    str[k] = '\0';
    return;
}

/*
   This is a modified version of strcmp which just accounts for a partial match.
   Returns 1 (True) on partial match and 0 (False) otherwise.
*/
int strcmp_partial(const char s1[], const char s2[]) {
    int i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
      i++;
    if(s1[i] == '\0')
       return 1;
    return 0;
}

//Search the list for a partial match to a given word
void search_list(char list[N][M], int num_words) {
    printf("Please enter a word:\n");
    char find[M];
    read_word(find, M);

    printf("\nMatched word list:\n");
    for(int k = 0; k < num_words; k++)
       if(strcmp_partial(find, list[k]))
          printf("\t%s\n", list[k]);
    printf("\n");
} 

//Search the list and replace it
//We allow a partial match-replace
//If you don't want this, you can use strcmp == 0 directly
void list_replace(char list[N][M], int num_words, char find[M], char replace[M]) {
   for(int k = 0; k < num_words; k++)
      if(strcmp_partial(find, list[k])) //Use strcmp == 0 for an exact match
         strcpy(list[k], replace);
}

int main() {
   char list[N][M] = {}; //100 words of 20 chars each + \0
   int num_words = 0;

   num_words = read_list(list, N);

   print_list(list, num_words);

   print_longest(list, num_words);
   print_largest_sorted(list, num_words);

   //This should have been in the task list for the assignent
   search_list(list, num_words);

   printf("We can now search and replace words. [Press enter to escape].\n");
   while(1) {
     printf("Please enter a word to find:\n");
     char find[M];
     read_word(find, M);
     if(strlen(find) == 0)
        break;

     printf("Please enter a word to replace:\n");
     char replace[M];
     read_word(replace, M);
     if(strlen(replace) == 0)
        break;

     list_replace(list, num_words, find, replace);
     print_list(list, num_words);
   }

   print_list(list, num_words);
   print_longest(list, num_words);
   print_largest_unsorted(list, num_words);

   return 0;
}
