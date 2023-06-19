# Alexander Badura
# Write a shell script ...
# $0 is the call of this script itself e.g. ./finder.sh

# -z for empty string
# path + file
if [ -z "$1" ]; then 
   echo "Argument \$1 is empty."
   exit 1
fi

# -z for empty string
# string to store in file
if [ -z "$2" ]; then 
   echo "Argument \$2 is empty."
   exit 1
fi

# Attention no space here
writefile="$1"
writestr="$2"

# Create the file now
directory=$(dirname "$1")
mkdir -p "$directory"
echo "$2" > "$1"

# Error Handling
if [ ! $? -eq 0 ]; then
   echo "File could not be created"
   exit 1
fi

exit 0

