#include<stdio.h>
#include<string.h>

#define MAX 100

int balanced(char exp[]) 
{
    char stack[MAX];
    int top = -1;
    int i;

   for(i=0; exp[i] != '\0'; i++) {
       if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') 
       {
           stack[++top] = exp[i];
       } 
       else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') 
       {
           if(top == -1) 
           {
            return 0; // If stack is empty then its not balanced
           }

           char ch = stack[top--];

           if((exp[i] == ')' && ch != '(') ||(exp[i] == '}' && ch != '{') ||(exp[i] == ']' && ch != '[')) 
           {
            return 0; // Mismatched brackets
           }
       }
   }
   if(top == -1) 
   {
       return 1; // Balanced
   }
   else
   {
       return 0; // Not Balanced
    }
}
//The main function to test the balanced function
int main() {
    char exp1[]="a + (b - c) * (d";
    char exp2[]="m + [a - b * (c + d *{m)]";
    char exp3[]="a + (b - c)";

    //For expression 1
    if(balanced(exp1)) 
    {
        printf("Expression 1 is Balanced\n");
    } 
    else 
    {
        printf("Expression 1 is Not Balanced\n");
    }

    //For expression 2
    if(balanced(exp2)) {
        printf("Expression 2 is Balanced\n");
    } 
    else 
    {
        printf("Expression 2 is Not Balanced\n");
    }

    //For expression 3
    if(balanced(exp3)) 
    {
        printf("Expression 3 is Balanced\n");
    } 
    else 
    {
        printf("Expression 3 is Not Balanced\n");
    }

    return 0;
}