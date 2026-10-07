. Algorithm
Start the program.
Create a queue named printerQueue to store print jobs.
Display the Printer Queue menu.
Ask the user to enter a choice.
If the choice is 1, accept a job name and add it to the queue using push().
If the choice is 2, check whether the queue is empty.
If the queue is not empty, display the first job using front() and remove it using pop().
If the choice is 3, copy the queue into a temporary queue and display all pending jobs.
If the choice is 4, exit the program.
For any other choice, display an invalid-choice message.
Repeat the menu until the user selects 4.
Stop the program.
2. Input (IP)

The program accepts:

Menu choice from the user.
Print job name from the user.
Print job names can be:
Assignment
Project
Report
Document

Example Input:

Enter your choice: 1
Enter print job name: Assignment

Enter your choice: 1
Enter print job name: Project

Enter your choice: 3
3. Output (OP)

The program produces:

Confirmation when a print job is added.
The name of the job currently being printed.
List of pending print jobs.
Message when the queue is empty.
Invalid choice message.
Exit message.

Example Output:

Print job added successfully.

Jobs in Printer Queue:
- Assignment
- Project
4. Data Structure Used

Queue

The program uses the FIFO (First In, First Out) principle.

First Job → Second Job → Third Job
    ↓
Printed First

For example, if jobs are added in this order:

Assignment → Project → Report

They will be printed in the same order:

Assignment → Project → Report
5. C++ Functions Used
Function	Purpose
push()	Adds a new print job
front()	Accesses the first print job
pop()	Removes the completed print job
empty()	Checks whether the queue is empty
queue<string>	Creates a queue for storing job names
6. Advantages
Simple and easy to understand.
Demonstrates the Queue data structure.
Follows FIFO order.
Prevents printing jobs out of sequence.
Useful for understanding real-world queue applications.
7. Real-World Application

This project represents how printer systems manage multiple print requests. When several users send documents to a printer, their jobs can be stored in a queue and processed one by one in the order they were received.
