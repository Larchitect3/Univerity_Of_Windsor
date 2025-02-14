//Question provided

// #include <stdlib.h>
// #include <sys/types.h>
// #include <dirent.h>
// #include <stdio.h>
// int main(int argc, char *argv[])
// {
//     DIR *dp;
//     struct dirent *dirp;
//     if (argc == 1)
//         dp = opendir("./");
//     else
//         dp = opendir(argv[1]);
//     while ((dirp = readdir(dp)) != NULL)
//         printf("%s\n", dirp->d_name);
//     closedir(dp);
//     exit(0);
// }
//-----------------------------------------------------------------------------------------------------------

// First Answer where I include the stat function
// To modify your program so that it adds a trailing slash (/) to directory names when printed, you can use the stat() function to check if the entry is a directory or a regular file. If it's a directory, append the slash to the printed name.
// Here is the modified code for my first answer


// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <dirent.h>
// #include <stdio.h>
// #include <string.h>

// int main(int argc, char *argv[])
// {
//     DIR *dp;
//     struct dirent *dirp;
//     struct stat statbuf;

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
//         // Construct the full path of the entry
//         char path[1024];
//         snprintf(path, sizeof(path), "%s/%s", argv[1] ? argv[1] : ".", dirp->d_name);

//         // Get the status of the entry
//         if (stat(path, &statbuf) == -1)
//         {
//             perror("stat");
//             continue;
//         }

//         // Print the name and append "/" if it's a directory
//         printf("%s", dirp->d_name);
//         if (S_ISDIR(statbuf.st_mode))
//         {
//             printf("/"); // It's a directory, so add "/"
//         }
//         printf("\n");
//     }

//     closedir(dp);
//     exit(0);
// }

//-----------------------------------------------------------------------------------------------------------

//Second Answer without the stat function




#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    // Open the directory based on the argument
    if (argc == 1)
        dp = opendir("./");
    else
        dp = opendir(argv[1]);

    if (dp == NULL)
    {
        perror("opendir");
        exit(1);
    }

    // Read through the directory entries
    while ((dirp = readdir(dp)) != NULL)
    {
        // Print the name of the file/directory
        printf("%s", dirp->d_name);

        // Check if the entry is a directory (using d_type)
        if (dirp->d_type == DT_DIR)
        {
            printf("/"); // It's a directory, so add "/"
        }

        printf("\n");
    }

    closedir(dp);
    exit(0);
}
