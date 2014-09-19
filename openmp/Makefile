  #the compiler: gcc for C program, define as g++ for C++
  CC = gcc

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall -fopenmp 

  practice1: practice1.c
	$(CC) -o practice1.o practice1.c $(CFLAGS)
  practice2: practice2.c
	$(CC) -o practice2.o practice2.c $(CFLAGS)
  practice3: practice3.c
	$(CC) -o practice3.o practice3.c $(CFLAGS)
  practice4: practice3.c
	$(CC) -o practice4.o practice4.c $(CFLAGS)

