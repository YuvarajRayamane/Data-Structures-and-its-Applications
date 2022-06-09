#include <stdio.h>
#include <stdlib.h>
struct node
{
 int row,col,data;
 struct node * next;
 struct node * prev;
};
typedef struct node * NODE;

NODE insertend(NODE head, int row, int col, int elem)
{
 NODE temp,cur;
 temp=(NODE)malloc(sizeof(struct node));
 temp->data = elem;
 temp->col = col;
 temp->row = row;
 temp->prev = NULL;
 temp->next = NULL;
 if(head == NULL)
  return temp;
 cur = head;
 while(cur->next != NULL)
  cur = cur->next;
 cur->next = temp;
 temp->prev = cur;
 return head;
}

void display(NODE head)
{
 NODE temp;
 if(head == NULL)
   printf("\n List is empty");
 else
 {
  printf("\n Row\t Col\t Data\n");
  temp = head;
  while(temp != NULL){
    printf("%d\t %d\t %d\n",temp->row,temp->col,temp->data);
    temp=temp->next;
  }}
}

void displaymatrix(NODE head, int m, int n)
{
 int i,j;
 NODE temp;
 temp = head;
 for(i=1; i<=m; i++){
    for(j=1; j<=n; j++){
       if(temp != NULL  && i == temp->row && j == temp->col){
         printf("%d\t",temp->data);
         temp = temp->next;
         }
       else
         printf("0\t");
    }
   printf("\n");
 }
}

int main()
{
 NODE head = NULL;
 int m,n,j,i,item;
 printf("\n Read order of matrix\n");
 scanf("%d %d",&m,&n);
 printf("\n Read matrix\n");
 for(i=1; i <= m; i++){
    for(j = 1; j <= n; j++){
       scanf("%d",&item);
       if(item != 0)
          head = insertend(head, i, j, item);
      }
  }
 display(head);
 printf("\n The sparse matrix is\n");
 displaymatrix(head, m, n);
 return 0;
} 
 
