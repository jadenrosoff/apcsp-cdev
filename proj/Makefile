TARGET = studentproj
CC = gcc
CFLAGS = -g -Wall -O3

.PHONY: clean all default

default: $(TARGET)
all: default

HEADERS = encrypt/encrypt.h
OBJECTS = studentmain.o student.o

$(TARGET): studentmain.o student.o encrypt.o
	$(CC) -o $(TARGET) studentmain.o student.o encrypt.o

studentmain.o: studentmain.c
	$(CC) $(CFLAGS) -c studentmain.c

student.o: student.c
	$(CC) $(CFLAGS) -c student.c

encrypt.o: encrypt/encrypt.c
	$(CC) $(CFLAGS) -c encrypt/encrypt.c

clean:
	-rm -f *.o a.out
	-rm -f $(TARGET)
