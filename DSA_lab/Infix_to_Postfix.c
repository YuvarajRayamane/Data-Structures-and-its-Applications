#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100

int top;
char infix_string[MAX_LEN],postfix_string[MAX_LEN],stack[MAX_LEN];
char pop();
void push(char);
int precedence(char);
void infix_to_postfix();
bool is_empty();

int main()
{
    top=-1;
    printf("\t\tInfix to postfix\n");
    printf("Input the infix expression:");
    scanf("%s",infix_string);
    
    infix_to_postfix();
    printf("Equivalent postfix expression: %s\n",postfix_string);
    return 0;
}

void infix_to_postfix()
{
    int i,temp=0;
    char next,symbol;
    for(i=0;i<strlen(infix_string);i++){
        symbol = infix_string[i];
        switch(symbol){
            case '(': push(symbol);
                     break;
            case ')':while((next=pop())!='(')
                           postfix_string[temp++]=next;
                           break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while(!is_empty()&&precedence(stack[top])>=precedence(symbol))
                    postfix_string[temp++]=pop();
                push(symbol);
                break;
            default:postfix_string[temp++]=symbol;
        }
    }
    while(!is_empty())
        postfix_string[temp++]=pop();
        
       postfix_string[temp] = '\0';
}

int precedence(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void push(char symbol) {
    if (top >= MAX_LEN) {
        printf("error: stack is full\n");
        exit(1);
    }
    stack[++top] = symbol;
}

bool is_empty() {
    if (top == -1)
        return true;
    return false;
}

char pop() {
    if (is_empty()) {
        printf("error: stack is empty\n");
        exit(1);
    }
    return (stack[top--]);
}
    
