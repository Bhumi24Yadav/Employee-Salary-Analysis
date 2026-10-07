Employee Salary Analysis and Ranking System
A robust, menu-driven command-line application designed to manage, analyze, and rank employee records while evaluating the performance of elementary sorting algorithms (Selection Sort and Insertion Sort) under various input conditions.

Features & Menu Options
1. Add Employee Records: Input employee details including Employee ID, Name, Department, and Salary.

2. Display Employee List: View all currently stored records in a clean, tabular format.

3. Salary-Wise Sorting & Comparison: Sort records by salary using both Selection Sort and Insertion Sort on identical data copies, tracking total comparisons and movements.

4. Search Employee: Retrieve a specific employee record instantly using their Employee ID.

5. HR Analytics & Reports: View highest/lowest salary details and department-wise employee distributions.

6. Performance Summary: Compare algorithm efficiency across best, average, and worst-case input scenarios with varying record sizes.

Methodology & Implementation Steps
Data Structure: Employee records are encapsulated in structs/objects and managed using dynamic arrays.

Sorting Analysis: Implements both Selection Sort and Insertion Sort to highlight how initial data order (sorted, reverse-sorted, random) impacts algorithmic efficiency.

Operation Counting: Explicitly tracks and logs key metrics such as comparison counts and data movements/swaps.

Modular Menu System: Continuously prompts the user for selections until an exit command is given.

Expected Inputs
Employee ID: Unique numeric or alphanumeric identifier.

Name: Full name of the employee.

Department: Functional unit (e.g., HR, Engineering, Sales).

Salary: Floating-point or integer monetary value.

Control Parameters: Number of records to generate/input, target search ID, and desired sort order (Ascending/Descending).

Expected Outputs
Sorted employee lists by salary.

Extremum reports (highest and lowest paid employee details).

Department-wise employee breakdowns.

Detailed search results for queried Employee IDs.

Comparative performance metrics (comparisons and movements) between Selection and Insertion sorts.
