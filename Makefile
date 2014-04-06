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

.PHONY: test
test: $(EXEC) Driver.pl generate_test_file
	./generate_test_file $(N)
	./$(EXEC) > my.out
	perl Driver.pl > perl.out
	diff my.out perl.out
.PHONY: clean
clean:
	rm -rf $(OBJS) $(EXEC) *.out test_data.txt
