STUDENT_ID = 2204896
CC = g++
DEBUG = -g
CFLAGS = -Wall -Werror -std=c++11 $(DEBUG)
EXEC = $(STUDENT_ID)_lab9
OBJS = main.o MinMaxHeap.o 
N = 200

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
MinMaxHeap.o: MinMaxHeap.cpp MinMaxHeap.hpp
	$(CC) $(CFLAGS) -c MinMaxHeap.cpp 
generate_test_file: generate_test_file.cpp
	$(CC) $(CFLAGS) -o generate_test_file generate_test_file.cpp
pretty_print.o: pretty_print.cpp
	$(CC) $(CFLAGS) -c pretty_print.cpp
pretty_print: pretty_print.o MinMaxHeap.o MyHeapUtils.hpp
	$(CC) $(CFLAGS) -o pretty_print pretty_print.o MinMaxHeap.o
.PHONY: test
test: $(EXEC) Driver.pl generate_test_file pretty_print
	./generate_test_file $(N)
	./pretty_print
	./$(EXEC) > my.out
	perl Driver.pl > perl.out
	diff my.out perl.out
.PHONY: clean
clean:
	rm -rf $(OBJS) $(EXEC) *.out test_data.txt pretty_print
