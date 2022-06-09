#include<stdio.h>
#include<stdlib.h>
struct node
{ int c,p;
  struct node *addr;
};
typedef struct node *NODE;
NODE insertend(NODE start,int c,int p)
{ NODE temp, cur;
  temp=(NODE)malloc(sizeof(struct node));
  temp->c=c;
  temp->p=p;
  temp->addr=NULL;
  if(start==NULL)
  	return temp;
  cur=start;
  while(cur->addr!=NULL)
  	cur=cur->addr;
  cur->addr=temp;
  return start;
}
void display(NODE start)
{ NODE temp;
  if (start==NULL)
  	printf("\nThe list is empty\n");
  else
  {	temp=start;
	while(temp->addr!=NULL)
  	{	printf("%d*x^%d+",temp->c,temp->p);
		temp=temp->addr;
	}
  	printf("%d*x^%d",temp->c,temp->p);
  }
}
NODE addterm(NODE res,int c,int p)
{ NODE temp,cur;
  int flag=0;
  temp=(NODE)malloc(sizeof(struct node));
  temp->c=c;
  temp->p=p;
  temp->addr=NULL;
  if (res==NULL)
	return temp;
  cur=res;
  while(cur!=NULL)
  {	if (cur->p==p)
	{	cur->c=cur->c+c;
		flag=1;
	}
	cur=cur->addr;
  }
  if (flag==0)
  {	cur=res;
	while(cur!=NULL)
		cur=cur->addr;
	cur->addr=temp;
  }
  return res;
}
NODE multiply(NODE poly1,NODE poly2)
{ NODE first, second,res=NULL;
  for (first=poly1; first!=NULL; first=first->addr)
  	for(second=poly2; second!=NULL; second=second->addr)
		res=addterm(res,first->c*second->c,first->p+second->p);
  return res;
}
int main()
{ NODE poly1=NULL,poly2=NULL,res;
  int i,n,c,p;
  printf("\nRead number of terms of first polynomial\n");
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {	printf("\nEnter the coeff and power of term %d\n",i);
	scanf("%d%d",&c,&p);
	poly1=insertend(poly1,c,p);
  }
  printf("\nThe first polynomial is : ");
  display(poly1);
  printf("\nRead number of terms of second polynomial\n");
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {	printf("\nEnter the coeff and power of term %d\n",i);
	scanf("%d%d",&c,&p);
	poly2=insertend(poly2,c,p);
  }
  printf("\nThe second polynomial is : ");
  display(poly2);
  res=multiply(poly1,poly2);
  printf("\nThe resultant polynomial is : ");
  display(res);
  printf("\n");
  return 0;
}
