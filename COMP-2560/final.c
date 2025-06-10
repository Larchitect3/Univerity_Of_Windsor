#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include <sys/wait.h>  // for wait()
#include<stdlib.h>


// Question 2.1

// int main(int argc, char *argv[])
// {
//     int fd;
//     char buffer1[10] = "One ";
//     char buffer2[10] = "Two ";
//     fd = open("file.txt", O_WRONLY|O_CREAT|O_TRUNC);
//     write(fd, buffer1, strlen(buffer1));
//     write(STDOUT_FILENO, buffer2, strlen(buffer2));
//     // STDOUT_FILENO is the screen file descriptor
//     dup2(fd, STDOUT_FILENO);
//     write(fd, buffer1, strlen(buffer1));
//     write(STDOUT_FILENO, buffer2, strlen(buffer2));
//     close(fd);
// }

// The Answer: The word "Two" will appear on the screen


// Question 2.2

// int main(int argc, char *argv[])
// {
//     fork();
//     printf("Hello\n");
//     fork();
//     printf("Hello\n");
//     return 0;
// }
//    Answer:  The word hello will appear 6 times


// Question 2.3

// int main(int argc, char *argv[])
// {
//     int i;
//     for(i=1; i<=3; i++){
//     fork();
//     printf("Hello\n");
//     }
//     printf("Hello\n");
// }

// Answer : Hello will appear 22 times

// Question 2.4
// int main(int argc, char *argv[])
// {
//     printf("A ");
//     fork();
//     printf("B\n");
//     fork();
//     pause();
//     printf("Bye\n");
// }

// Question 2.5

// void action()
// {
//     fprintf(stderr, " Thursday ");
//     exit(1);
//     }
//     int main(){
//     pid_t pid, st;
//     if(!(pid=fork()))
//     {
//         signal(SIGALRM, action);
//         alarm(1);
//         while(1)
//         sleep(1);
//         fprintf(stderr, "exam ");
//     }
//     else{
//         fprintf(stderr, "Final");
//         wait(&st);
//         fprintf(stderr, "%d\n", WEXITSTATUS(st));
//     }
// }
// Hint: WEXITSTATUS(st) extracts exit status from st

// Question 2.6

int main(int argc, char *argv[])
{
    int fd;
    char name1[15] = "Bonjour\n";
    char name2[15] = "Bonsoir\n";
    fd = open("file.txt", O_WRONLY|O_CREAT|O_TRUNC);
    write(fd, name1, 8);
    close(fd);
    fd = open("file.txt", O_RDONLY);
    dup2(fd, 0);
    read(0, name2, 8);
    write(1, name2, 8);
    exit(0);
}