//NOT DONE!!!

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // DIR *dp;
    // struct dirent *dirp;

    // if (argc == 1)
    //     dp = opendir("./");
    // else
    //     dp = opendir(argv[1]);

    // while ((dirp = readdir(dp)) != NULL)
    // {
    //     printf("%s", dirp->d_name);
    //     if (dirp->d_type == DT_DIR) //
    //         printf("/");
    //     printf("\n");
    // }
    // closedir(dp);

    #!/ bin / bash

    #Function to display usage instructions
        usage(){
            echo "Usage: $0 [-t target-directory] [-d destination-directory] <extension-list>" exit 1}

    #Default values : use the current directory
        TARGET_DIR = "$(pwd)" DEST_DIR = ""

    #Parse command - line options
            while getopts "t:d:" opt;
        do
        case "$opt" in
            t) TARGET_DIR="$OPTARG" ;;
            d) DEST_DIR="$OPTARG" ;;
            *) usage ;;
        esac
    done
    shift $((OPTIND - 1))

    #Ensure at least one extension is provided
    if [ $# -lt 1 ]; then
        echo "Error: You must provide at least one file extension."
        usage
    fi

    #Validate that the target directory exists
    if [ ! -d "$TARGET_DIR" ]; then
        echo "Error: Target directory '$TARGET_DIR' does not exist or is not a directory."
        exit 1
    fi

    #If no destination directory is specified, use the target directory
    if [ -z "$DEST_DIR" ]; then
        DEST_DIR="$TARGET_DIR"
    fi

    #Validate that the destination directory exists
    if [ ! -d "$DEST_DIR" ]; then
        echo "Error: Destination directory '$DEST_DIR' does not exist or is not a directory."
        exit 1
    fi

    #Organize files based on their extensions
    for ext in "$@"; do
    #Create a directory inside the destination directory for the extension
        EXT_DIR="$DEST_DIR/$ext"
        mkdir -p "$EXT_DIR"

    #Move matching files from the target directory to the destination subdirectory
        mv "$TARGET_DIR"/*."$ext" "$EXT_DIR" 2>/dev/null
    done

    echo "Files organized successfully."

    exit(0);
}