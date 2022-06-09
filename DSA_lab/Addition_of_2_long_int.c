#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node 
	{ int data; struct node *addr;};
typedef struct node *NODE;
NODE insertbegin(NODE head,int item)
	{NODE temp;
	 temp=(NODE)malloc(sizeof(struct node));
	 temp->data=item;
	 if (head->addr==head)
		{ head->addr=temp;
		  temp->addr=head;
		  return head;
		}
	 temp->addr=head->addr;
	 head->addr=temp;
	 return head;
	}
NODE insertend(NODE head,int item)
	{NODE temp,cur;
	 temp=(NODE)malloc(sizeof(struct node));
	 temp->data=item;
	 temp->addr=head;
	 if (head->addr==NULL)
		{head->addr=temp;
		 return head;
		}
	 cur=head->addr;
	 while(cur->addr!=head)
	 	cur=cur->addr;
	 cur->addr=temp;
	 return head;
	}
void display(NODE head)
	{NODE temp;
	 if(head->addr==head)
	 	printf("\nNumber not entered\n");
	 else
		{temp=head->addr;
		 while(temp!=head)
			{printf("%d",temp->data);
			 temp=temp->addr;
			}
		}
	printf("\n");
	}
void addzero(NODE head1,NODE head2)
	{int count1=1,count2=1,i;
	 NODE t1,t2;
	 t1=head1->addr;
	 t2=head2->addr;
	 while(t1!=head1)
		{count1+=1;
	 	 t1=t1->addr;
		}
	 while(t2!=head2)
		{count2+=1;
		 t2=t2->addr;
		}
	 if(count1>count2)
		{for(i=1;i<=count1-count2;i++)
			head2=insertbegin(head2,0);
		}
	 else
		{for(i=1;i<=count2-count1;i++)
			head1=insertbegin(head1,0);
		}
	}
NODE reverse(NODE head)
	{NODE cur,prev,next;
	 cur=head->addr;
	 prev=head;
	 while(cur!=head)
		{next=cur->addr;
		 cur->addr=prev;
		 prev=cur;
	 	 cur=next;
		}
	 head->addr=prev;
	 return head;
	}
void add(NODE head1,NODE head2)
	{NODE addhead,t1,t2;
	 int x,sum=0,carry=0;
	 addhead=(NODE)malloc(sizeof(struct node));
	 addhead->addr=addhead;
	 head1=reverse(head1);
	 head2=reverse(head2);
	 t1=head1->addr;
	 t2=head2->addr;
	 while(t1!=head1)
		{x=t1->data+t2->data+carry;
		 sum=x%10;
		 carry=x/10;
		 addhead=insertbegin(addhead,sum);
		 t1=t1->addr;
		 t2=t2->addr;
		}
	 if(carry>0)
		addhead=insertbegin(addhead,carry);
	 printf("\nThe final result is\n");
	 display(addhead);
	}
int main()
	{NODE head1,head2;
	 char first[20],second[20];
	 int i;
	 head1=(NODE)malloc(sizeof(struct node));
	 head2=(NODE)malloc(sizeof(struct node));
	 head1->addr=head1;
	 head2->addr=head2;
	 printf("\nEnter the first number\n");
	 scanf("%s",first);
	 for(i=0;first[i]!='\0';i++)
		head1=insertend(head1,first[i]-'0');
	 printf("\nThe first number is\n");
	 display(head1);
	 printf("\nEnter the second number\n");
	 scanf("%s",second);
	 for(i=0;second[i]!='\0';i++)
		head2=insertend(head2,second[i]-'0');
	 printf("\nThe second number is\n");
	 display(head2);
	 addzero(head1,head2);
	 printf("\nThe updated first number is\n");
	 display(head1);
	 printf("\nThe updated second number is\n");
	 display(head2);
	 add(head1,head2);
	 return 0;
	}
