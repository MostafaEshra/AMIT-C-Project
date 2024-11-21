# Student Database Management System (SDB)

This project is a Student Database Management System implemented in C, using a doubly linked list to store and manage student records. It allows users to add, view, list, check, and delete student entries. The system provides a simple console-based interface and several features for handling student data entries. It is part of the Embedded C course in the AMIT Embedded Systems Diploma.

---

## Table of Contents
1. [Overview](#overview)
2. [Project Structure](#project-structure)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Example Run](#example-run)
6. [File Descriptions](#file-descriptions)
7. [Functions](#functions)
8. [Makefile](#makefile)
9. [Notes](#notes)

---

## Overview
The Student Database Management System (SDB) allows users to:
- Add new student records.
- Delete existing student records.
- Read and display details of a student by ID.
- List all student IDs.
- Check if a specific student ID exists in the database.
- Check if the database is full (max 10 students).
- Get the count of current entries.

The project consists of three `.c` files (`SDB.c`, `SDBAPP.c`, `main.c`) and three `.h` files (`SDB.h`, `SDBAPP.h`, `STD.h`).

---

## Project Structure
```.
├── SDB.c       # Core functions for managing the student database
├── SDBAPP.c    # Application interface for user interaction
├── main.c      # Main entry point of the program
├── SDB.h       # Header file for SDB.c
├── SDBAPP.h    # Header file for SDBAPP.c
├── STD.h       # Common definitions and data types
├── Makefile    # Build configuration for compiling and running the project
└── README.md   # Project documentation
```
## Installation
1. Clone or download this repository.
2. Compile the code using GCC or any other C compiler and then run using the make all command in the makefile:
   ```
   make all
   ```

## Usage
After running the program, a menu will appear with options to perform various database operations. Follow the on-screen instructions to navigate through the options.

## Example Run
```
To add entry, enter 1
To get used size in database, enter 2
To read student data, enter 3
To get the list of all student IDs, enter 4
To check if an ID exists, enter 5
To delete student data, enter 6
To check if database is full, enter 7
To exit, enter 0

Enter Your Choice: 
```


## File Descriptions

- `SDB.c`: Core functions for managing the student database.
- `SDBAPP.c`: Application interface for user interaction with the database.
- `main.c`: Main entry point of the program, where the execution starts.
- `SDB.h`: Header file that defines the structures and functions for `SDB.c`.
- `SDBAPP.h`: Header file that defines the structures and functions for `SDBAPP.c`.
- `STD.h`: Common definitions and data types used across the project.
- `Makefile`: Build configuration file that automates the process of compiling and linking the project. It includes rules for compiling the source files and running the application.

## Functions

### Core Functions in SDB.c

- **`bool SDB_IsFull()`**  
  Checks if the database has reached its maximum capacity (10 students).

- **`uint8 SDB_GetUsedSize()`**  
  Returns the current number of student records in the database.

- **`bool SDB_AddEntry()`**  
  Adds a new student entry to the list. Prompts the user to enter student details.

- **`void SDB_DeleteEntry(uint32 id)`**  
  Deletes a student entry by the specified ID. Assumes a minimum of three students in the list.

- **`bool SDB_ReadEntry(uint32 id)`**  
  Reads and displays details of a student with the specified ID.

- **`void SDB_Getlist(uint8* count, uint32* list)`**  
  Retrieves a list of all student IDs in the database.

- **`bool SDB_IsIdExist(uint32 id)`**  
  Checks if a student ID exists in the list.

### User Interface Functions in SDBAPP.c

- **`void SDB_APP()`**  
  Provides a console-based menu and prompts the user to select actions.

- **`void SDB_action(uint8 choice)`**  
  Executes an action based on the user's menu choice, calling the appropriate functions from SDB.c.


## Makefile

The `Makefile` is used to compile and link the project files into an executable. It contains the following rules:

```makefile
out: main.o SDBAPP.o SDB.o
	gcc -o out main.o SDBAPP.o SDB.o

main.o: main.c SDB.h SDBAPP.h STD.h
	gcc -c main.c

SDBAPP.o: SDBAPP.c SDBAPP.h STD.h
	gcc -c SDBAPP.c

SDB.o: SDB.c SDB.h STD.h
	gcc -c SDB.c

run:
	./out.exe

all:
	gcc -c SDB.c
	gcc -c SDBAPP.c
	gcc -c main.c
	gcc -o out main.o SDBAPP.o SDB.o
	./out.exe

push:
	git add .
	git commit -m "$(msg)"
	git push -u origin main

OBJS = main.o SDBAPP.o SDB.o
Target = out

clean:
	rm $(OBJS) $(Target)
```

### Explanation of Makefile Rules:

- **out**: Compiles `main.o`, `SDBAPP.o`, and `SDB.o` into the executable `out`.
- **main.o**, **SDBAPP.o**, **SDB.o**: These rules compile each corresponding source file into object files (`.o`).
- **run**: Runs the executable `out.exe`.
- **all**: A convenience rule that compiles all source files, links them, and runs the program.
- **push**: Git commands to add, commit, and push changes to the repository with a parameter msg to be added to the commit.
- **clean**: Removes object files and the final executable to clean up the project directory.

## Notes

- The list can hold a maximum of 10 student entries.
- The program enforces a minimum of three entries for list operations.
- Input validation is provided for ID uniqueness and list capacity.

