# Alexander Badura
# Write a shell script ...
# $0 is the call of this script itself e.g. ./finder.sh

# -z for empty string
if [ -z "$1" ]; then 
   echo "Argument \$1 is empty."
   exit 1
fi

# -z for empty string
if [ -z "$2" ]; then 
   echo "Argument \$2 is empty."
   exit 1
fi

# -d FILE exists and is a directory
# e.g. /home/alex4cable/Documents/coursera/assignment-1-alex4cable/finder-app
# Attention space here
if [ ! -d "$1" ]; then 
   echo "Argument \$1 is not a directory."
   exit 1
fi

# Attention no space here
filesdir="$1"
searchstr="$2"

# how many files
nbFiles=$(ls -r "$filesdir" | wc -l)
nbHits=$(grep -r "$searchstr" "$filesdir" | wc -l)

# result
echo "The number of files are $nbFiles and the number of matching lines are $nbHits"
#     The number of files are ${NUMFILES} and the number of matching lines are ${NUMFILES}
