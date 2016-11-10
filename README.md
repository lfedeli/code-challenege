# code-challenege
code challenge for insight data

In the source folder there are two files, project.cpp, that contains the main
routine, and QUEUE.cpp, that implements a queue.
After the launch of the program you will be asked how many transactions you want to test.
In order to meet the features of the challenge, I implemented a GRAPH class
that contains a modified version of the classical breadth first search algorithm.
The performance is about 700 transactions verified per minute.

To compile you have to use the flag -std=c++11 because of some standard
functions used in the program.

In the folder "possible-improvement/" there is a preliminar version of the code
that, along with the adjacency list of the graph, implements a vector that store
a binary search tree for each node processed. The basic idea is to run a breadth first search
only once per user, to store the information gained in a binary search tree (or whatever data structure
that can implement the function "search" quickly), and run a search on the tree whenever
we have to process a user already met. The problem is that for about 80000 users I need an amount
of memory not available in a home machine.
