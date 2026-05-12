# NexGen-Skills-Hub-Cpp-Internship-task2

# Student Marks Management System

A console-based C++ application built as part of the **NexGen Skills Hub Internship Program**  Week 2 Task.  
The system demonstrates **modular programming** using functions and arrays to manage student academic records.

---

##  Project Overview

This program allows users to add student records, display them in a formatted table, search by name and identify the top performing student all through a clean, menu-driven interface.

Every input is fully validated the program will never crash on bad input such as letters in a number field, special characters or numbers entered as a student name.

---

##  Features

| Feature | Description |
|---|---|
| ➕ Add Student | Enter student name and marks for 3 subjects |
| 📋 Display All Records | View all students in a formatted table with averages |
| 🔍 Search Student | Find any student record by name |
| 🏆 Find Top Student | Automatically identify the student with the highest average |
| 🛡️ Input Validation | Rejects letters/symbols in number fields, numbers in name fields |
| ✅ C++98 Compatible | Works on older compilers like Dev-C++ without any errors |

---

##  Project Structure

```
student-marks-system/
│
├── student_marks_system.cpp    # Main source file (all code)
└── README.md                   # Project documentation
```

---

##  How It Works

### Data Storage
The program uses three **parallel global arrays** to store records:

```cpp
string studentNames[50];       // Stores student names
int    studentMarks[50][3];    // 2D array: 50 students × 3 subjects
int    studentCount = 0;       // Tracks number of active records
```

> Index `i` in `studentNames` always corresponds to index `i` in `studentMarks` — they represent the same student.

---

### Functions

| Function | Purpose |
|---|---|
| `main()` | Runs the menu loop — entry point of the program |
| `showMenu()` | Displays the navigation menu |
| `getValidInt()` | Crash-safe integer reader — rejects all non-numeric input |
| `isValidName()` | Validates names — allows letters and spaces only |
| `stringToInt()` | C++98-safe replacement for `stoi()` using `istringstream` |
| `addStudent()` | Collects and stores a new student record |
| `displayAll()` | Prints all records in an aligned table |
| `searchStudent()` | Performs linear search by student name |
| `calculateAverage()` | Reusable helper — returns the mean of 3 subject marks |
| `findTopStudent()` | Scans all averages and reports the highest |

---

##  Sample Output

```
+======================================+
|   Student Marks Management System   |
+======================================+
|  1. Add Student                      |
|  2. Display All Records              |
|  3. Search Student                   |
|  4. Find Top Student                 |
|  5. Exit                             |
+======================================+
  Enter choice (1-5): 1

-- Add Student --
Enter student name (letters only): Ali Khan
  Enter marks for Math (0-100): 85
  Enter marks for Physics (0-100): 90
  Enter marks for CS (0-100): 78
[OK] Student added successfully.
```

```
No.  Name                Math      Physics   CS        Average
-------------------------------------------------------
1    Ali Khan            85        90        78        84.3
2    Sara Ahmed          92        88        95        91.7
```

---

##  Input Validation Examples

```
Enter choice (1-5): abc
  [!] Invalid input "abc". Only numeric digits are allowed here.

Enter student name (letters only): Ali123
  [!] Invalid name "Ali123".
      Name must contain letters and spaces only.
      Numbers and special characters are not allowed.

Enter marks for Math (0-100): @#$
  [!] Invalid input "@#$". Only numeric digits are allowed here.

Enter marks for Math (0-100): 150
  [!] Out of range. Enter a value between 0 and 100.
```

---

##  How to Compile & Run

### Using Dev-C++ (Windows)
1. Open Dev-C++
2. Go to **File → Open** and select `student_marks_system.cpp`
3. Press **F11** to Compile & Run

### Using Terminal / Command Line
```bash
# Compile
g++ student_marks_system.cpp -o marks

# Run
./marks          # Linux / macOS
marks.exe        # Windows
```

### Compile in strict C++98 mode (to verify compatibility)
```bash
g++ -std=c++98 student_marks_system.cpp -o marks
```

---

##  Requirements

- Any C++ compiler (GCC, MSVC, Clang)
- Compatible with **C++98 and above** — no C++11 features used
- No external libraries required — uses only standard headers:
  - `<iostream>` — input/output
  - `<iomanip>` — table formatting (`setw`)
  - `<string>` — string handling
  - `<cctype>` — character checks (`isalpha`, `isdigit`)
  - `<sstream>` — string-to-int conversion

---

##  Concepts Demonstrated

- ✅ Modular programming with reusable functions
- ✅ Single and multi-dimensional arrays
- ✅ Input validation without crashes
- ✅ Linear search algorithm
- ✅ Parallel array data structure
- ✅ C++98 backward compatibility

---

##  Author

**[Syeda Minahil Zahra]**  
C++ Development Track — Week 2  
NexGen Skills Hub Internship Program

---

##  License

This project is submitted as part of an internship task.  
Feel free to reference or learn from the code.
