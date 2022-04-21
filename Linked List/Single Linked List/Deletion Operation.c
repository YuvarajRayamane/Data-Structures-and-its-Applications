C coad:
struct node{
  int data;
  struct node *addr;
};
typedef struct node *NODE;
NODE start;


//To delete a node at the begining of the list
NODE deletbegin(NODE start)
{
  NODE temp = start;
  if(start==NULL){
    printf("List is Empty\n");
    return NULL;
  }
  start = start->addr;
  printf("\n Node deleted is %d",temp->data);
  free(temp);
  return start;
}

//To delete node at end of the list
NODE deletend(NODE start)
{
  NODE cur, prev;
  if(start==NULL){
    printf("\n List is Empty\n");
    return NULL;
  }
  prev=NULL;
  cur = start;
  while(cur->addr!=NULL){
    prev=cur;
    cur=cur->addr;
  }
  prev->addr=NULL;
  printf("Node deleted is %d",cur->data);
  free(cur);
  return start;
}
