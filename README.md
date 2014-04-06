eecs560_lab9
============

Lab 9: MinMaxHeap

To run the test, use "make test".  To change the number of values put into
the heap, use "make test N=<number of values>" (e.g. "make test N=100" to
put 100 values into the heap).  The heap does not grow automatically, so
if using the no argument constructor, inserting more than 500 elements will
cause the MinMaxHeap to stop inserting (it won't crash, but it also won't
insert the new values).  The output of my program is then taken and compared
against the output of a perl script that has the correct values.  The 
MinMaxHeap built using the perl script builds slightly differently than 
mine (it uses a less efficient algorithm for finding the minimum/maximum
child/grandchild), but when you compare the minimum and maximum values
extracted from the heap they are always the same (the build construction
is only different is there are duplicate input values).


