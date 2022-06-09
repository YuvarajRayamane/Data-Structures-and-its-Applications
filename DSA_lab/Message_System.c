#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Size 5
struct queue{
    int f,r;
    char data[Size][20];
};
typedef struct queue QUEUE;

void sender (QUEUE *q,char item[20])
{
    if(q->f==(q->r+1)%Size)
    printf("queue is full\n");
    else
      {
        q->r=(q->r+1)%Size;
        strcpy(q->data[q->r],item);
      }
    if(q->f==-1) 
       q->f=0;
}

char* receiver (QUEUE *q)
{
    char *d;
    if(q->f==-1) 
      {
        printf("empty queue\n");
        return NULL;
      }
    else
    {
      d=q->data[q->f];
        if(q->f==q->r)
           {
            q->f=-1;
            q->r=-1;
           }
        else
           {
            q->f=(q->f+1)%Size;
           }
        return d;
    }
}

void display(QUEUE q)
{
    int i;
    if(q.f==-1)
       printf("queue is empty\n");
    else
       {
        printf("queue elements are\n");
        for(i=q.f; i!=q.r; i=(i+1)%Size)   
           {
            printf("%s\t",q.data[i]);
           }
        printf("%s\t",q.data[i]);
       }
}

int main(){
    QUEUE q;
    q.f=-1;
    q.r=-1;
    int ch;
    char item[20],*m;
    for(;;)
    {
        printf("\n 1.insert \n 2.Delete \n 3.dispaly \n4.exit\n");
        printf("read choice\n");
        scanf("%d",&ch);
        getchar();
        switch(ch)
         {
            case 1:printf("\nRead message\n");
                   scanf("%[^\n]s",item); //gets(item);
                   sender(&q,item);
                   break;
            case 2:m=receiver(&q);
                   if(m!=NULL) 
                      printf("\n message received is %s\n",m);
                   break;
            case 3: display(q);
                   break;
            default: exit(0);
           }
    }return 0;
}
