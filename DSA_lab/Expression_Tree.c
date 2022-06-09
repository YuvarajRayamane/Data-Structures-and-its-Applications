#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CAPACITY 512

typedef struct node {
    char data;
    struct node *left_node, *right_node;
} node;

typedef struct stack {
    node *items[CAPACITY];
    int top;
} stack;

int precedence(char);
node *create_node(char);
stack *create_stack();
void preorder_traversal(node *);
void postorder_traversal(node *);
void push(stack *, node *);
node *pop(stack *);
bool is_empty(stack *);
bool is_full(stack *);
bool check_space(char);
node *create_expression_tree(char *);

int main() {
    node *root = NULL;
    char infix[CAPACITY];

    printf("Enter an infix expression: ");
    scanf("%[^\n]s", infix);

    root = create_expression_tree(infix);

    printf("Prefix expression: ");
    preorder_traversal(root);
    printf("\nPostfix expression: ");
    postorder_traversal(root);
    printf("\n");
    return 0;
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

node *create_node(char symbol) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = symbol;
    new_node->right_node = NULL;
    new_node->left_node = NULL;

    return new_node;
}

stack *create_stack() {
    stack *st = (stack *) malloc(sizeof(stack));
    st->top = -1;

    return st;
}

void preorder_traversal(node *root) {
    if (root) {
        printf("%c ", root->data);
        preorder_traversal(root->left_node);
        preorder_traversal(root->right_node);
    }
}


void postorder_traversal(node *root) {
    if (root) {
        postorder_traversal(root->left_node);
        postorder_traversal(root->right_node);
        printf("%c ", root->data);
    }
}

void push(stack *st, node *temp) {
    if (is_full(st))
        printf("error:stack overflow\n");
    else
        st->items[++st->top] = temp;
}

node *pop(stack *st) {
    if (is_empty(st)) {
        printf("error:stack underflow\n");
        return NULL;
    }
    return st->items[st->top--];
}

bool is_empty(stack *st) {
    return st->top == -1;
}

bool is_full(stack *st) {
    return st->top == CAPACITY - 1;
}

node *create_expression_tree(char *expression) {
    stack *tree_st = create_stack();
    stack *operator_st = create_stack();
    char symbol;
    node *new_node = NULL, *temp = NULL;
    for (int i = 0; expression[i] != '\0'; i++) {
        symbol = expression[i];
        if (check_space(symbol))
            continue;
        new_node = create_node(symbol);
        if (isalnum(symbol))
            push(tree_st, new_node);
        else {
            if (is_empty(operator_st))
                push(operator_st, new_node);
            else {
                while (!is_empty(operator_st) &&
                       precedence(operator_st->items[operator_st->top]->data) >= precedence(symbol)) {
                    temp = pop(operator_st);
                    temp->right_node = pop(tree_st);
                    temp->left_node = pop(tree_st);
                    push(tree_st, temp);
                }
                push(operator_st, new_node);
            }
        }
    }

    while (!is_empty(operator_st)) {
        temp = pop(operator_st);
        temp->right_node = pop(tree_st);
        temp->left_node = pop(tree_st);
        push(tree_st, temp);
    }
    return pop(tree_st);
}

bool check_space(char symbol) {
    return symbol == ' ';
}
