#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
 typedef struct
{
int item[SIZE];
int top;
}stack;


void create(stack*s)
{
  s->top=-1;
  return;
}

void push(stack*s,char elem)
{
  if(s->top==SIZE-1){
    printf("\n over flow");
    return;
    }
    ++(s->top);
    s->item[s->top]=elem;
}

int pop(stack*s)
{
  if(s->top==-1){
    printf("\n underflow");
    return -1;
    }
  else{
      return s->item[(s->top)--];
      }
}

int peek(stack*s)
{
  return (s->item[s->top]);
}

void display(stack*s)
{
  int i;
  if(s->top==-1)
    printf("\n Stack is empty");
  else{
    printf("\n Stack content are:\n");
    for(i=s->top;i>=0;i--)
      printf("%d\n",s->item[i]);
      }
}

int get_top_third_elem(stack *s) {
    if (s->top < 2)
        return -2;

    stack temp;
    create(&temp);
    int top_3rd_ele;

    for (int i = 0; i < 2; i++)
        push(&temp, pop(s));
    top_3rd_ele = peek(s);

    for (int i = 0; i < 2; i++)
        push(s, pop(&temp));

    return top_3rd_ele;
}


void pop_top_n_elem(stack*s,int n)
{
  for(int i=0;i<n;i++){
      pop(s);
  }
  printf("After popping %d elements\n", n);
}

int get_bottom_third_elem(stack*s)
{
    if(s->top<2)
    return -2;
    int bottom_3rd_elem;
    stack temp;
    create(&temp);
    for(int i=s->top;i>2;i--)
    push(&temp,pop(s));
    bottom_3rd_elem=peek(s);
    
    for(int i=temp.top;i>=0;i--)
    push(s,pop(&temp));
    return bottom_3rd_elem;
}


int main()
{
  int i,ch,elem,n,num,numElem,t;
  int j=2;
  int y;
  stack s,temp;
  create(&s);
  create(&temp);
  for(;;){
     printf("\n 1. PUSH");
     printf("\n 2. POP");
     printf("\n 3. PEEK");
     printf("\n 4. DISPLAY");
     printf("\n 5. Get the 3rd element from top of the stac");
     printf("\n 6. Pop out top n elements from the stack");
     printf("\n 7. Get 3rd element from bottem of the stack");
     printf("\n 0. Exit");
     printf("\n Enter choice \n");
     scanf("%d",&ch);
     switch(ch){
     case 1: {
              printf("\n Enter number of elements:\n");
              scanf("%d",&n);
              printf("\n Enter elements:\n");
              for(i=0;i<n;i++){
                scanf("%d",&elem);
                push(&s,elem);
                }
                break;
                }
                
     case 2: if(s.top==-1){
               printf("\n Empty stack");
               }
               elem=pop(&s);
               printf("\n Popped top element is %d \n",elem);
               break;
               
     case 3: printf("Top element of stack is %d \n",peek(&s));
             break;
               
     case 4: display(&s);
             break;
             
     case 5:t = get_top_third_elem(&s);
                if (t == -2)
                    printf("The top third element does not exist\n");
                else
                    printf("The third element from top of the stack is: %d\n", t);
                break;
                
     case 6:printf("\n Enter number of elements to be popped from the stack:\n"); 
            scanf("%d",&num);
            while(num>s.top+1){
                printf("\n The number of elements in stack is %d ,try again:",s.top+1);
                scanf("%d",&num);
            }
            pop_top_n_elem(&s,num);
            display(&s);
            break;
            
     case 7:t=get_bottom_third_elem(&s);
            if(t==-2)
            printf("\n The bottom 3rd element does not exist");
            else
            printf("\n The 3rd element from bottom of tht stack is %d\n",t);
            break;
            
     default : exit(0);
     }
     }
     return 0;
}
