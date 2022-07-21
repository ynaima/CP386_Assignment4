#Do not edit the contents of this file.
CC = gcc
CFLAGS = -Werror -Wall -g -std=gnu99
LDFLAGS = -lrt -lpthread
TARGET = allocation
OBJFILE = allocation.o
all: $(TARGET)
allocation: allocation.c
	$(CC) $(CFLAGS) -o allocation allocation.c $(LDFLAGS)

runq2: allocation
	./allocation
clean:
	rm -f $(OBJFILES) $(TARGET) *~ 
