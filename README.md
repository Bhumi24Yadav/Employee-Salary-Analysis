# Employee Salary Analysis and Ranking System

A menu-driven program for managing employee records, sorting employees based on salary, searching for employee details, and comparing the performance of **Selection Sort** and **Insertion Sort**.

The project demonstrates how elementary sorting algorithms behave with different input sizes and different initial arrangements of data, while working with real-world employee records.

## 📌 Problem Statement

Create a menu-driven application that maintains employee details, arranges employees salary-wise, and retrieves a required employee record.

The system generates simple HR-style reports without using a database and focuses on understanding the performance of elementary sorting algorithms.

## 🎯 Objectives

* Store and manage employee records using an array of structures/objects.
* Sort employee records according to salary.
* Implement **Selection Sort** and **Insertion Sort**.
* Compare the performance of both sorting algorithms.
* Search for an employee using their Employee ID.
* Generate salary-wise and department-wise reports.
* Identify employees with the highest and lowest salaries.
* Count comparisons and data movements during sorting.
* Observe the effect of input size and initial data order on sorting performance.

## ✨ Features

### Employee Management

* Add employee records
* Display all employee records
* Store:

  * Employee ID
  * Employee Name
  * Department
  * Salary

### Salary Ranking

* Sort employees by salary in:

  * Ascending order
  * Descending order
* Supports both Selection Sort and Insertion Sort.

### Employee Search

* Search for an employee using their Employee ID.
* Display the complete employee record when found.

### HR Reports

* Display the highest-paid employee.
* Display the lowest-paid employee.
* Display employees department-wise.
* Display the complete salary-wise ranking.

### Algorithm Comparison

The program compares Selection Sort and Insertion Sort using:

* Number of comparisons
* Number of data movements
* Different numbers of employee records
* Different initial arrangements of employee data

## 🛠️ Technologies Used

* **Programming Language:** C / C++ *(choose the one used in your implementation)*
* **Data Structure:** Array of Structures / Objects
* **Sorting Algorithms:**

  * Selection Sort
  * Insertion Sort
* **Searching:** Linear Search
* **Storage:** In-memory data only
* **Database:** Not used

## 🧩 Employee Record Structure

Each employee record contains:

| Field       | Description                       |
| ----------- | --------------------------------- |
| Employee ID | Unique identifier of the employee |
| Name        | Employee's name                   |
| Department  | Employee's department             |
| Salary      | Employee's salary                 |

Example:

```text
Employee ID : 101
Name        : Rahul Sharma
Department  : IT
Salary      : 65000
```

## 🔄 Program Workflow

```text
Start
  │
  ▼
Enter Number of Employees
  │
  ▼
Enter Employee Details
  │
  ▼
Display Menu
  │
  ├── Add Employee
  │
  ├── Display Employees
  │
  ├── Sort by Salary
  │      ├── Selection Sort
  │      └── Insertion Sort
  │
  ├── Search Employee by ID
  │
  ├── Highest Salary
  │
  ├── Lowest Salary
  │
  ├── Department-wise Display
  │
  ├── Compare Sorting Operations
  │
  └── Exit
  │
  ▼
End
```

## 📊 Sorting Algorithms

### 1. Selection Sort

Selection Sort repeatedly finds the smallest or largest element from the unsorted portion of the array and places it in its correct position.

**Time Complexity:**

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(n²)      |
| Average | O(n²)      |
| Worst   | O(n²)      |

Selection Sort performs a relatively small number of data movements because elements are swapped only when required.

### 2. Insertion Sort

Insertion Sort builds the sorted portion of the array one element at a time by inserting each employee into its appropriate position according to salary.

**Time Complexity:**

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(n)       |
| Average | O(n²)      |
| Worst   | O(n²)      |

Insertion Sort performs particularly well when employee records are already sorted or nearly sorted.

## 🔍 Searching

The program uses **Linear Search** to find an employee using their Employee ID.

For each record, the Employee ID is compared with the required search ID until a match is found or all records have been checked.

**Time Complexity:**

* Best Case: O(1)
* Average Case: O(n)
* Worst Case: O(n)

## 📈 Performance Analysis

To study the behaviour of the sorting algorithms, the program can be tested with increasing numbers of employee records.

Example:

```text
Number of Records
        ↓
     10
        ↓
     50
        ↓
    100
        ↓
    500
        ↓
   1000
```

The algorithms can also be tested using different initial arrangements:

### Best Case

Data is already arranged in the order required by the sorting algorithm.

### Average Case

Employee salaries are arranged randomly.

### Worst Case

Data is arranged in the reverse of the required order.

The number of **comparisons** and **data movements** is recorded for each experiment.

## 📋 Sample Comparison

| Input Size | Algorithm      | Case    | Comparisons | Movements |
| ---------: | -------------- | ------- | ----------: | --------: |
|         10 | Selection Sort | Best    |           — |         — |
|         10 | Insertion Sort | Best    |           — |         — |
|         50 | Selection Sort | Average |           — |         — |
|         50 | Insertion Sort | Average |           — |         — |
|        100 | Selection Sort | Worst   |           — |         — |
|        100 | Insertion Sort | Worst   |           — |         — |

> The actual values should be filled using the counts produced by the program.


## 📚 Concepts Demonstrated

This project provides practical implementation of:

* Structures / Classes
* Arrays
* Functions
* Menu-driven programming
* Sorting algorithms
* Searching algorithms
* Time complexity
* Best, average, and worst cases
* Comparisons and data movements
* Basic data analysis
* Performance comparison of algorithms






This project is intended primarily for educational and academic purposes.
