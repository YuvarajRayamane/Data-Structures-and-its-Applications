C coad:
struct node{
  int data;
  struct node *addr;
};
typedef struct node *NODE;
NODE start;

void display(NODE start)
{
  NODE temp;
  if(start==NULL){
    printf("List is Empty\n");
  }
  else{
    printf(" List content are\n");
    temp = start;
    while(temp!=NULL){
      printf("%d\t",temp->data);
      temp = temp->addr;
    }
  }
}
