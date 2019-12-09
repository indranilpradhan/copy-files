# copy-files

Write a program to copy files and measure the performance(time taken) to copy files in
all the cases mentioned below.
1. Inside same partitions but different level(i.e. Hierarchy of folder structure) of
folders.
2. Inside the same physical disk but different partitions.
3. From HDD to a USB drive or vice-versa.
4. Feature to split large files ( > 4GB ) and also to merge them when needed as an
option.
You can only use Read and Write system calls for performing copy operation.
Test Cases for performance check
1. 1000 1KB files and 1 GB file to see the difference between copying multiple small
files and a single large file.
2. A multimedia file.
Instructions :-
1. Find out the command to copy a file in Linux environment and understand its
working.
2. Learn about system calls and how they work.
3. The input might be a very large text file or video file(5GB).Your code should be
able to handle such large files.
Input :-
1. Calling format for the program :: ./myprog [src] [dest], names are excluding
square brackets.
2. Detect split and merge requirements as per your logic.
