#Do not edit the contents of this file.
# the compiler: gcc for C program, define as g++ for C++
 CC = gcc

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
 CFLAGS  = -Werror -Wall -g -std=gnu99
 LDFLAGS = -lrt -lpthread

  # the build target executable:
 TARGET = allocation
 OBJFILE = allocation.o

 all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o allocation allocation.c $(LDFLAGS)

run: allocation
	./allocation
clean:
	rm -f $(OBJFILES) $(TARGET) *~
