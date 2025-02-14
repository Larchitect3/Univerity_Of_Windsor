// Winter 2025
//------------
//(mkdir "filename.ext") : makes a new folder/directory
//(cd "filename.ext") : change directory
//  (echo "message" > "filename.txt" ): writes the message to the file and saves it in the current folder. However, if you rewrite a new message, it erases the previous one.
// A program is an executable file that resides on a disk
// A process is an executing program usually with a limited life time. A process is made from a process.
// A process ID (PID) is a unique nonnegative
// getpid() system call gets you the PID of the process.
// getuid() gets you the user ID of the process.
// ctrl+D closes the shell terminal.
// >: output redirect
// <: Input redirect
// rm: delete
// rm *ps: delete any character ending ps
// rm *.? :delete delete files with one character after "."
// ls ??: list files with 2 characters
// wc: word count
// #: means a comment except for the first line of code, the first line will tell you if you are using bash or csh. i.e: #!/bin/bash
// A shell script is a text file containing shell commands. It has to define, read and write shell variable. control structures  such as loop and if statement
// ls -l "filename" : shows you the long information of the filename such as the permissions you allowed to do on the file (read, write, execute)
// chmod : change mode(the permissions)
// more "filename" : allows you to read the file content
// grep NAME: will search a specific pattern
// echo $USER : will show you the current user
// 'any_text': single quotations mean the text is supposed to be considered as non-other than characters.
// #!/bin/bash : means the script is for bash
// -n :tells the compiler not to go on the next. example: echo -n hello
// -ne :stands for not equal
//^G Get Help  ^O WriteOut  ^R Read File ^Y Prev Pg   ^K Cut Text  ^C Cur Pos
//^X Exit ^ J Justify ^ W Where is ^ V Next Pg ^ U UnCut Text ^ T To Spell
//
//
// Assignment one

// To achieve the same result without using any specific functions like stat(), you can use a simpler approach based purely on if statements and the properties of struct dirent. However, without using stat() or other system calls to explicitly check whether an entry is a directory, the only thing you can rely on is the file type returned by d_type in the struct dirent.

// The d_type field in struct dirent tells you the type of the entry. It can be one of the following:

// DT_UNKNOWN - Type is unknown (not always reliable).
// DT_REG - Regular file.
// DT_DIR - Directory.
// DT_LNK - Symbolic link, etc.
// To modify your program to append a / for directories based on d_type, here's a simple solution:

// #include <stdlib.h>
// #include <sys/types.h>
// #include <dirent.h>
// #include <stdio.h>
// int main(int argc, char *argv[])
// {
//     DIR *dp;
//     struct dirent *dirp;

//     // Open the directory based on the argument
//     if (argc == 1)
//         dp = opendir("./");
//     else
//         dp = opendir(argv[1]);

//     if (dp == NULL)
//     {
//         perror("opendir");
//         exit(1);
//     }

//     // Read through the directory entries
//     while ((dirp = readdir(dp)) != NULL)
//     {
//         // Print the name of the file/directory
//         printf("%s", dirp->d_name);

//         // Check if the entry is a directory (using d_type)
//         if (dirp->d_type == DT_DIR)
//         {
//             printf("/"); // It's a directory, so add "/"
//         }

//         printf("\n");
//     }

//     closedir(dp);
//     exit(0);
// }
//
//

// Assignment 2

// write a bash script to organise some files in a given directory according to their extendsions

// Synopsis:

//  organize [-t target-directory] [-d destination-directory] <extension-list>

// REMEMBER!! [] is used for optional parameters while <> is used for non optional parameters.

// 
//
//
//
//
//
