# Contact Book Management System in C++

A console-based Contact Book Management System developed in C++ as a Data Structures and Algorithms (DSA) project. The application uses a custom **Singly Linked List** to manage contacts and maintain them in alphabetical order.

## Features

- **Add Contacts:** Store a contact's name, phone number, and email address.
- **Alphabetical Sorting:** Automatically insert contacts in alphabetical order by name.
- **Search Contacts:** Find a contact by name using case-insensitive comparison.
- **Edit Contacts:** Update an existing contact's details.
- **Delete Contacts:** Remove a contact from the list.
- **Save Contacts:** Store contact information in `contacts.txt`.
- **Load Contacts:** Load previously saved contacts when the application starts or when requested.
- **CSV Export:** Export contacts to `contacts.csv` for spreadsheet applications.
- **Input Validation:** Prevent empty names and duplicate names when adding contacts.
- **Dynamic Memory Management:** Allocate and release linked-list nodes using `new` and `delete`.

## Data Structure

### Singly Linked List

The project implements a custom singly linked list without using arrays or built-in linked-list containers.

Each node contains:
- `name` — Contact's name
- `phone` — Contact's phone number
- `email` — Contact's email address
- `next` — Pointer to the next contact

The list maintains contacts in alphabetical order using a custom case-insensitive string comparison function.

## Technologies Used

- C++
- Data Structures and Algorithms (DSA)
- Singly Linked List
- Pointers and Dynamic Memory Allocation
- Object-Oriented Programming
- File Handling (`ifstream` and `ofstream`)
- CSV Export

## Application Menu

1. Add Contact
2. Display Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Save Contacts
7. Load Contacts
8. Export CSV
0. Exit

## Getting Started

### Prerequisites

- A C++ compiler, such as GCC or MinGW
- A C++ IDE or code editor, such as Visual Studio Code

### Installation and Execution

1. Clone or download this repository.
2. Open the C++ source file in your preferred IDE.
3. Compile the program using a C++ compiler.

Example using GCC:

```bash
g++ ContactBook.cpp -o ContactBook
```

Run on Windows:

```bash
ContactBook.exe
```

**Note:** Replace `ContactBook.cpp` with the actual filename of the source file if it is different.

## File Storage

- `contacts.txt` stores contact information for saving and loading.
- `contacts.csv` stores exported contact data in CSV format.

These files are created in the program's working directory when the corresponding operations are performed.

## Learning Objectives

This project demonstrates the practical use of linked lists, pointer manipulation, dynamic memory management, searching, sorted insertion, deletion, and file handling in C++.

## Author

**MUHAMMAD HASEEB ARIF**

**Project:** Contact Book Management System  
**Language:** C++  
**Category:** University DSA Project
**Institute:** University of Mianwali
