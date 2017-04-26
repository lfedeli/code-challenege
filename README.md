# DESCRIPTION

This program simulates a "digital wallet" that implements features to prevent fraudulent payment requests from untrusted users. 

### Feature 1

When anyone makes a payment to another user, they'll be notified if they've never made a transaction with that user before.

### Feature 2

With this feature  transactions between users that share a past transaction with a common user are considered legal; in particular they are 2nd degree friends 

example: A------C-------B => A and B can pay each other because in the past had a transaction with C

Feature 3

The idea explained in the previous point is extended till 4th order friends

example: A---B---C---D---E---F => A and E can send money, but not A and F 

### IMPLEMENTATION

In the "/src" folder there are two files, project.cpp, that contains the main routine, and QUEUE.cpp, that implements a queue.
After the launch of the program you will be asked how many transactions you want to test.
In order to meet the features of the challenge, I implemented a GRAPH class that contains a modified version of the classical breadth first search algorithm.
The performance is about 700 transactions verified per minute.

Input files can be found in "/paymo_input", while the output are written in "/paymo_output"

In the "/possible-improvement/" folder there is a preliminar version of the code that, along with the adjacency list of the graph, implements a vector that store a binary search tree for each node processed. The basic idea is to run a breadth first search
only once per user, to store the information gained in a binary search tree (or whatever data structure that can implement the function "search" quickly), and run a search on the tree whenever we have to process a user already met. 

###USAGE

Just type "./run.sh" and enjoy it!
