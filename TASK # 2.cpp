#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>   
#include <sstream>   
using namespace std;

const int MAX_STUDENTS = 50;
const int SUBJECTS     = 3;
const string SUBJECT_NAMES[SUBJECTS] = {"Math", "Physics", "CS"};

string studentNames[MAX_STUDENTS];
int    studentMarks[MAX_STUDENTS][SUBJECTS];
int    studentCount = 0;

void   addStudent();
void   displayAll();
void   searchStudent();
double calculateAverage(int index);
void   findTopStudent();
void   showMenu();
int    getValidInt(const string& prompt, int minVal, int maxVal);
bool   isValidName(const string& name);
int    stringToInt(const string& s);

int stringToInt(const string& s) {
    int value = 0;
    istringstream ss(s);
    ss >> value;
    return value;
}
int getValidInt(const string& prompt, int minVal, int maxVal) {
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);

        if (line.empty()) {
            cout << "  [!] Input cannot be empty. Please enter a number.\n";
            continue;
        }

        bool allDigits = true;
        for (int i = 0; i < (int)line.size(); i++) {
            if (!isdigit((unsigned char)line[i])) {
                allDigits = false;
                break;
            }
        }

        if (!allDigits) {
            cout << "  [!] Invalid input \"" << line
                 << "\". Only numeric digits are allowed here.\n";
            continue;
        }

        int value = stringToInt(line);

        if (value < minVal || value > maxVal) {
            cout << "  [!] Out of range. Enter a value between "
                 << minVal << " and " << maxVal << ".\n";
            continue;
        }

        return value;
    }
}

bool isValidName(const string& name) {
    if (name.empty()) return false;

    bool hasLetter = false;
    for (int i = 0; i < (int)name.size(); i++) {
        char c = name[i];
        if (!isalpha((unsigned char)c) && !isspace((unsigned char)c)) {
            return false;
        }
        if (isalpha((unsigned char)c)) hasLetter = true;
    }
    return hasLetter;
}

void showMenu() {
    cout << "\n+======================================+\n";
    cout <<   "|   Student Marks Management System   |\n";
    cout <<   "+======================================+\n";
    cout <<   "|  1. Add Student                      |\n";
    cout <<   "|  2. Display All Records              |\n";
    cout <<   "|  3. Search Student                   |\n";
    cout <<   "|  4. Find Top Student                 |\n";
    cout <<   "|  5. Exit                             |\n";
    cout <<   "+======================================+\n";
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "[!] Storage full. Cannot add more students.\n";
        return;
    }

    cout << "\n-- Add Student --\n";

    string name;
    while (true) {
        cout << "Enter student name (letters only): ";
        getline(cin, name);

        if (!isValidName(name)) {
            cout << "  [!] Invalid name \"" << name
                 << "\".\n      Name must contain letters and spaces only.\n"
                 << "      Numbers and special characters are not allowed.\n";
        } else {
            break;
        }
    }
    studentNames[studentCount] = name;

    for (int i = 0; i < SUBJECTS; i++) {
        string prompt = "  Enter marks for " + SUBJECT_NAMES[i] + " (0-100): ";
        studentMarks[studentCount][i] = getValidInt(prompt, 0, 100);
    }

    studentCount++;
    cout << "[OK] Student added successfully.\n";
}

double calculateAverage(int index) {
    int sum = 0;
    for (int i = 0; i < SUBJECTS; i++)
        sum += studentMarks[index][i];
    return static_cast<double>(sum) / SUBJECTS;
}

void displayAll() {
    if (studentCount == 0) {
        cout << "\n[!] No records found.\n";
        return;
    }

    cout << "\n" << left
         << setw(5)  << "No."
         << setw(20) << "Name";
    for (int i = 0; i < SUBJECTS; i++)
        cout << setw(10) << SUBJECT_NAMES[i];
    cout << setw(10) << "Average" << "\n";
    cout << string(55, '-') << "\n";

    for (int i = 0; i < studentCount; i++) {
        cout << left
             << setw(5)  << (i + 1)
             << setw(20) << studentNames[i];
        for (int j = 0; j < SUBJECTS; j++)
            cout << setw(10) << studentMarks[i][j];
        cout << fixed << setprecision(1)
             << setw(10) << calculateAverage(i) << "\n";
    }
}

void searchStudent() {
    if (studentCount == 0) {
        cout << "\n[!] No records to search.\n";
        return;
    }

    cout << "\nEnter student name to search: ";
    string query;
    getline(cin, query);

    bool found = false;
    for (int i = 0; i < studentCount; i++) {
        if (studentNames[i] == query) {
            found = true;
            cout << "\n[OK] Record found:\n";
            cout << "  Name    : " << studentNames[i] << "\n";
            for (int j = 0; j < SUBJECTS; j++)
                cout << "  " << SUBJECT_NAMES[j] << "     : "
                     << studentMarks[i][j] << "\n";
            cout << fixed << setprecision(1)
                 << "  Average : " << calculateAverage(i) << "\n";
            break;
        }
    }

    if (!found)
        cout << "[!] Student \"" << query << "\" not found.\n";
}

void findTopStudent() {
    if (studentCount == 0) {
        cout << "\n[!] No records available.\n";
        return;
    }

    int    topIndex = 0;
    double topAvg   = calculateAverage(0);

    for (int i = 1; i < studentCount; i++) {
        double avg = calculateAverage(i);
        if (avg > topAvg) {
            topAvg   = avg;
            topIndex = i;
        }
    }

    cout << "\n[*] Top Student:\n";
    cout << "  Name    : " << studentNames[topIndex] << "\n";
    cout << fixed << setprecision(1)
         << "  Average : " << topAvg << "\n";
}

int main() {
    int choice;

    do {
        showMenu();
        choice = getValidInt("  Enter choice (1-5): ", 1, 5);

        switch (choice) {
            case 1: addStudent();     break;
            case 2: displayAll();     break;
            case 3: searchStudent();  break;
            case 4: findTopStudent(); break;
            case 5: cout << "\nGoodbye!\n"; break;
        }

    } while (choice != 5);

    return 0;
}
