//2. Write a program to convert an infix mathematical expression to postfix and evaluate it.
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

//Push and Pop functions for stack operations
void push(char p)
{
    stack[++top] = p;
}

char pop()
{
    return stack[top--];
}

//Checks for operator precedence
int precedence(char p){
    if(p == '+' || p == '-') 
    return 1;
    if(p == '*' || p == '/') 
    return 2;

    return 0;
}

//Converts infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]){
    int i, j = 0;
    char ch;

    while((ch = infix[i++]) != '\0')
    {
        //If the character is an operand, add it to output
        if(ch >= '0' && ch <= '9')
        {
            postfix[j++] = ch;
        }
        //If the character is '(', push it to stack
        else if(ch == '(')
        {
            push(ch);
        }
        //If the character is ')', pop and output from the stack
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        //If an operator is encountered
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }
    //Pop all the operators from the stack
    while(top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

//Evaluates the postfix expression
int evaluatePostfix(char postfix[]){
    int valueStack[MAX];
    int valueTop = -1;
    int i = 0;
    char ch;

    while((ch = postfix[i++]) != '\0')
    {
        //If the character is an operand, push it to value stack
        if(ch >= '0' && ch <= '9')
        {
            valueStack[++valueTop] = ch - '0';
        }
        else
        {
            int val2 = valueStack[valueTop--];
            int val1 = valueStack[valueTop--];

            switch(ch)
            {
                case '+':
                    valueStack[++valueTop] = val1 + val2;
                    break;
                case '-':
                    valueStack[++valueTop] = val1 - val2;
                    break;
                case '*':
                    valueStack[++valueTop] = val1 * val2;
                    break;
                case '/':
                    valueStack[++valueTop] = val1 / val2;
                    break;
            }
        }
    }

    return valueStack[valueTop];
}

//Main function
int main(){
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);

    return 0;
}