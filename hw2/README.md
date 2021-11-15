# Grow Array algorithm (with capacity)

Read the following input from standard input and output
Use the compaction algorithm to efficiently remove all the values (Do not remove a position and shift to the left, too expensive!)

case 1:
1 20 5

2 3 5 7 11

 

case 2:

5 1000000 20

2 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39

The first two numbers (1, 20) are the range to add to the list.  In this case, the list consists of 1 to 20.

The third number (5) is the number of numbers to follow. Read in those and remove all numbers which are multiples of these from the list.

The output should be the number of elements remaining, the sum of all the numbers remaining, and the time (in milliseconds) that it took your algorithm to complete.

For the first case, output should be:

the number of values remaining in the list.  In this case, the numbers start with

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

but then 2, 4, 6, 8, 10, 12, 14, 16 18, 20 are removed because they are multiples of 2

3, 9, 15 are then removed because they are multiples of 3

5 is removed because it is a multiple of 5.

7 is removed because it is a multiple of 7

and last, 11 is removed.

This leaves: 1 13 17 19

The output should be the number of numbers remaining, the sum of all the numbers, followed by the time (in milliseconds) that the algorithm took (not including printing!)

For example, in this case, the answer might be:

4      50      22

The inputs can be quite large.  We might assign n=106. or 107.  There might be 20 or 40 or even 100 numbers to remove.  Your program will have to run in less than 30 seconds. Suffice it to say, your algorithm had better not be O(n^2).  Try it with:

Cases: 1

1 10000000 30

2 3 5 7 11 13 17 19 23 29 31 37 41 43 53 59 67 71 73 79 83 87 91 97
