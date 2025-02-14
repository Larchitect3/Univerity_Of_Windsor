
    # #!/ bin / bash

    # #Function to display usage instructions
    #     usage(){
    #         echo "Usage: $0 [-t target-directory] [-d destination-directory] <extension-list>" exit 1}

    # #Default values : use the current directory
    #     TARGET_DIR = "$(pwd)" DEST_DIR = ""

    # #Parse command - line options
    #         while getopts "t:d:" opt;
    #     do
    #     case "$opt" in
    #         t) TARGET_DIR="$OPTARG" ;;
    #         d) DEST_DIR="$OPTARG" ;;
    #         *) usage ;;
    #     esac
    # done
    # shift $((OPTIND - 1))

    # #Ensure at least one extension is provided
    # if [ $# -lt 1 ]; then
    #     echo "Error: You must provide at least one file extension."
    #     usage
    # fi

    # #Validate that the target directory exists
    # if [ ! -d "$TARGET_DIR" ]; then
    #     echo "Error: Target directory '$TARGET_DIR' does not exist or is not a directory."
    #     exit 1
    # fi

    # #If no destination directory is specified, use the target directory
    # if [ -z "$DEST_DIR" ]; then
    #     DEST_DIR="$TARGET_DIR"
    # fi

    # #Validate that the destination directory exists
    # if [ ! -d "$DEST_DIR" ]; then
    #     echo "Error: Destination directory '$DEST_DIR' does not exist or is not a directory."
    #     exit 1
    # fi

    # #Organize files based on their extensions
    # for ext in "$@"; do
    # #Create a directory inside the destination directory for the extension
    #     EXT_DIR="$DEST_DIR/$ext"
    #     mkdir -p "$EXT_DIR"

    # #Move matching files from the target directory to the destination subdirectory
    #     mv "$TARGET_DIR"/*."$ext" "$EXT_DIR" 2>/dev/null
    # done

    # echo "Files organized successfully."





    #!/bin/bash

# Default values
target_dir="$(pwd)"
dest_dir="$target_dir"

# Options we have are the following
while [[ "$1" =~ ^- ]]; do
    case "$1" in
        (-t)
            shift
            if [[ -d "$1" ]]; then
                target_dir="$1"
            else
                echo "Error: Target directory '$1' does not exist."
                exit 1
            fi
            ;;
        (-d)
            shift
            if [[ -d "$1" ]]; then
                dest_dir="$1"
            else
                echo "Error: Destination directory '$1' does not exist."
                exit 1
            fi
            ;;
        (*)
            echo "Usage: organize [-t target-directory] [-d destination-directory] <extension-list>"
            exit 1
            ;;
    esac #acts like fi.. for if statements or done for loops
    shift
done

# Check if at least one extension is provided
if [[ $# -eq 0 ]]; then
    echo "Error: No file extensions provided."
    echo "Usage: organize [-t target-directory] [-d destination-directory] <extension-list>"
    exit 1
fi

# Organize files based on extensions
for ext in "$@"; do
    subdir="$dest_dir/$ext"
    mkdir -p "$subdir"
    mv "$target_dir"/*."$ext" "$subdir" 2>/dev/null
done

echo "Files have been organized successfully."
