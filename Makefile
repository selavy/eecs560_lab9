STUDENT_ID = 2204896
CC = g++
DEBUG = -g
CFLAGS = -Wall -Werror -std=c++11 $(DEBUG)
EXEC = $(STUDENT_ID)_lab9
OBJS = main.o MinMaxHeap.o 

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
MinMaxHeap.o: MinMaxHeap.cpp MinMaxHeap.hpp
	$(CC) $(CFLAGS) -c MinMaxHeap.cpp 
generate_test_file: generate_test_file.cpp
	$(CC) $(CFLAGS) -o generate_test_file generate_test_file.cpp
.PHONY: clean
clean:
	rm -rf $(OBJS) $(EXEC)
