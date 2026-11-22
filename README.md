# Grade Management (C)

A command-line program in C that manages exam grades using the German grading scale (1.0 = best, 5.0 = fail). It loads grades from a file or manual input and calculates statistics.

## Features
- Load grades from a text file (`examgrades1.txt`)
- Enter grades manually, with input validation (1.0 to 5.0)
- Statistics: average, best grade, worst grade, number of fails (grade > 4.0)
- Dynamic memory management with `realloc` and `free`

## Tech Used
- C (standard library only: `stdio.h`, `stdlib.h`)
- Dynamic arrays, file I/O, pointers

## How to Run
```bash
git clone https://github.com/YOUR-USERNAME/grade-management-c.git
cd grade-management-c
gcc main.c -o grade-manager
./grade-manager
```
On Windows: `gcc main.c -o grade-manager.exe` then `grade-manager.exe`

## Input File Format
One grade per line:
```
1.7
2.3
5.0
3.0
```

## Example
```
HELLO TO THE GRADE MANAGEMENT
1. Load a file
2. Enter Grade
3. View Statistics
4. Quit
3
The average of the grades is 3.00
The best grade is 1.70
The worst grade is 5.00
The number of failures is 1
```

## What I Learned
- Managing memory manually with `realloc` and `free`
- Reading files line by line with `fgets`
- Validating user input
- Structuring a program into separate functions

## Future Improvements
- Handle invalid (non-numeric) input safely
- Save grades back to a file
- Split the code into multiple files (`grades.c`, `grades.h`)
- Add median and grade distribution
