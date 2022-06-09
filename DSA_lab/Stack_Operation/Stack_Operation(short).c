#include <stdio.h>
# define MAX 8
typedef struct STACK{
    int item[MAX];
    int top;
}stack;

void create(stack *s)
{
    s->top = -1;
}

void push(stack *s, int ele)
{
    if(s->top == MAX-1){
        printf("\n Stack is overflow");
    }
    else{
        ++(s->top);
        s->item[s->top]= ele;
    }
}

int pop(stack *s)
{
    if(s->top == -1)
    printf("\n Stack is underflow");
    return (s->item[s->top--]);
}

void display(stack *s){
    if(s->top == -1)
    printf("\n Stack is Empty");
    printf("\n Stack content are :");
    for(int i=s->top; i>=0; i--)
    printf("\n %d",s->item[i]);
}

int main()
{
    stack s, temp;
    int y1,y2,n,ele,i;
    create(&s);
    printf("\n Enter %d element to be pushed into the stack\n",MAX);
    for(i=0;i<MAX;i++){
        scanf("%d",&ele);
        push(&s,ele);
    }
    display(&s);
    create(&temp);
    i=2;
    while(i>0){
        push(&temp,pop(&s));
        i--;
    }
    y1 = pop(&s);
    push(&s,y1);
    i=2;
    while(i>0){
        push(&s, pop(&temp));
        i--;
    }
    printf("\n Third element from top the stack is %d\n",y1);
    printf("\n Enter no. of elements to be poped: ");
    scanf("%d",&n);
    while(n>=(s.top)+1){
        printf("\n Enter valid no. element");
        scanf("%d",&n);
    }
    for(i=0;i<n;i++){
        push(&temp,pop(&s));
    }
    printf("\n After poping %d element:",n);
    display(&s);
    for(i=0;i<n;i++)
    push(&s,pop(&temp));
    for(i=MAX-3;i>0;i--)
    push(&temp,pop(&s));
    y2=pop(&s);
    printf("\n Third element from bottom of the stack is %d",y2);
    for(i=MAX-3;i>0;i--)
    push(&s,pop(&temp));
}
