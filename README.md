# arch1-binarySearchTreeDemo

This directory contains:
* code that implements a binary tree of strings 
* a demo program that uses it

The demo program reads lines from stdin.
Employee 1 and Employee 2 is inserted to the binary tree in an organized manner.
After the employees are inserted the tree is printed in alphabetical order.

This demo contains the following files:
 btree.h: header file of llist structure & "public" interface functions
 btree.c: implementation of a binary tree with corresponding functions to manipulate
 main.c: a demonstration program that uses the binary tree
 

To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ make demo
~~~

To delete binaries:
~~~
$ make clean
~~~

# Using the interface #

1. When executing the program will welcome the user and give them the option to:
  - Print the contents of the binary tree
  - Enter a new employee
  - Delete employees
  - Read from a given file and store into the tree
  - Write to a given file
  - Exit the interface

2. To select an option enter the corresponding number
  - 0 to exit. After selecting user will be asked they want to save.
  - 1 to print tree content alphabetically
  - 2 add new employee
  - 3 remove existing employee
  - 4 read from file. After selecting user will be asked for file name
  - 5 write to file. After selecting user will be asked for file name