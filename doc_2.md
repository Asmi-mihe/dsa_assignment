# Documentation for Program 2: Conversion of Infix Expression to Postfix and Evaluation
The program converts an infix expression to postfix and evaluates it using a 'stack'. A stack to store operators during conversion based on precedence rules. For evaluation, the stack is used to store operands, perform operations, and push results back. The stack operations are managed using a top variable with a fixed maximum size.

## (a) Explanation of how the data structures are defined
In this program, the stack data structure is used for two purposes:
1. Converting the infix expression to postfix.
2. Evaluating the postfix expression.

1) Opeartor Stack
char stack[MAX];
int top = -1;
Here, 
stack[MAX]=A character array used to store operator and parentheses.
top=An integer variable that keeps track of the top position of the stack.

2) Value Stack(for evaluation)
int valueStack[MAX];
int valueTop = -1;
Here, 
valueStack=Stores integer operands during postfix evaluation
valueTop=Keeps track of the top of the value stack.

## (b) Description of the Function Implemented and its purpose

1) push(char p)
Function: 
    void push(char x)
    {
        stack[top++] = x;
    }
Purpose: 
    Pushes an element onto the operator stack.
Working:
It scans an element at the top of the stack and increases/increments the 'top'

2) pop()
Function:
    char pop()
    {
        return stack[top--];
    }
Purpose: 
    Removes and returns the top element of the operator stack.
Working: 
    It scans the element, removes it and returns the top element of the operator stack.

3) precedence(char p)
Function: 
    int precedence(char p){....}
Purpose: 
    Determines the precedence of operators
    >> '+' and '-' = precedence 1
    >> '*' and '/' = precedence 2
Working:
    This helps to decide which operator should bt popped first during conversion.

4) infixToPostfix(char infix[], char postfix[])
Function:
    void infixToPostfix(char infix[], char postfix[]){...}
Purpose:
    Converts an infix expression into a postfix expression.
Working:
    1. First it scans the infix expression character by character.
    2. If it finds operand, then add directly to postfix.
    3. If '(' is found then push to stack.
    4. If ')' is found then pop from stack until '(' is found.
    5. If operator then
    >>Operators are popped from stack having higher or equal precedence.
    >>Then push the current operator.
    6. After scanning the complete expression, pop the remaining operators.
    7. Added null character at the end of postfix string.

5) evaluatePostfix(char postfix[])
Function:
    int evaluatePostfix(char postfix[]){...}
Purpose:
    Evaluates the postfix expression and returns the final result.
Working:
    1. First it scans the postfix expression from left to right.
    2. If operand then Push onto value stack.
    3. If operator then pop two values, perform operation, and push result back to stack.
    4. The final value remaining in stack is the result.

## (c) Overview of the main() Function
In the main funnction: 
1. It declares two character arrays: 
    char infix[MAX], postfix[MAX];
2. It takes input from the user
    printf("Enter an infix expression: ");
    scanf("%s", infix);
3. It then calls infixToPostfix(infix, postfix) to convert the expression.
4. It prints the postfix expression.
5. Following that, it calls evaluatePostfix(postfix) to compute the result.
6. Finally, it prints the evaluated result.
Thus, the main() function controls the overall flow.

## (d) Sample Output of Complete Run
1. Input: 
    2+3*4
Output: 
    Postfix Expression: 234*+
    Evaluated Result: 14
2. Input: 
    (1+2)*(3+4)
Output: 
    Postfix Expression: 12+34+*
    Evaluated Result: 21

## (e) Conclusion
This program demonstrates how a stack can be used to convert infix expressions to postfix form and evaluate them efficiently. It correctly handles operator precedence and parentheses, producing accurate postfix expressions and evaluated results for a variety of mathematical expressions.