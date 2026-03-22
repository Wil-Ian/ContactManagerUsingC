# Compiler and Flags
CC = gcc
CFLAGS = -Iinclude -Wall

# Folders and Files
SRC = src/main.c src/contacts.c src/ui.c
TARGET = ContactManager.exe

# Rule to compile everything
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Rule to clean up the folder
clean:
	del $(TARGET)