# Documentation for Program 1: Balanced Parentheses
The program documentation describes its functioning through its balanced parentheses system which uses a stack data structure. The program uses a character array to create its stack which has a maximum capacity of stack size.

## (a) Explanation of how the data structures are defined
In this program, a 'stack' data structure is used to check whether the parentheses in the given mathematical expression are balanced or not.

The stack is implemented using:
    char stack[MAX];
    int top = -1;
Here, 
stack[MAX]= A character array used to store the opening bracket/parentheses
top= An integer value that keeps track of the top element of the stack

The stack follows the LIFO(Last In First Out) principle:
>>Opening brackets are pushed into the stack.
>>When a closing bracket is found, the last inserted opening bracket is popped and checked.

If at the end the stack is empty i.e. top==-1, the expression is balanced.

## (b) Description of the Function Implemented and its purpose
Function: 
    int balanced(char exp[]) 

Purpose: 
    To check whether a given expression has balanced parentheses or not.

Working:
1. The function scans the expression character by character.
2. If it finds, '(, {, or [', it pushes them into the stack.
    If it finds, '), }, or ]', it checks whether the stack is empty.
    If its not then, it pops the top element and checks if it matches
3. After the whole expression is scanned, if the top==-1 i.e. brackets are matched then it returns 1(Balanced). 
If return=0 i.e. Not Balanced.

Return Values: 
1= Balanced Expression
0= Not Balanced Expression

## (c) Overview of the main() Function
In the main function:
1. It declares the three given expressions: 
    char exp1[]="a + (b - c) * (d";
    char exp2[]="m + [a - b * (c + d *{m)]";
    char exp3[]="a + (b - c)";
2. It calls the function 'balanced()' to evaluate each expression.
3. It uses the if-else statements to print whether each expression is Balanced or Not balanced.

The main function is basically used for testing the balanced() function with different inputs.

## (d) Sample Output of Complete Run

PS C:\Users\Acer\OneDrive\Documents\dsa_assignment> cd "c:\Users\Acer\OneDrive\Documents\dsa_assignment\" ; if ($?) { gcc prog_1.c -o prog_1 } ; if ($?) { .\prog_1 }
Expression 1 is Not Balanced
Expression 2 is Not Balanced
Expression 3 is Balanced

Explanation of Output:
exp1[]="a + (b - c) * (d"; Missing closing bracket i.e. Not balanced
exp2[]="m + [a - b * (c + d *{m)]"; Incorrect bracket matching i.e. Not balanced
exp3[]="a + (b - c)"; All brackets properly matched i.e. Balanced

## (e) Conclusion
This program demonstrates how a stack can be used to validate balanced parentheses in mathematical expressions. It correctly identifies mismatched or missing brackets in the given expression.