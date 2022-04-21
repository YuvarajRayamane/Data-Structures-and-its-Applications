C coad:
struct node{
  int data;
  struct node *addr;
};
typedef struct node *NODE;
NODE start;

//Insertion at the begining
NODE insertbegin(NODE start,int item)
{
  NODE temp;
  temp = (NODE)malloc(sizeof(struct node));
  temp->data = item;
  temp->addr = NULL;
  if(start==NULL){
    return temp;
  }
  temp->addr=start;
  return temp;
}

//Insertion at the end
NODE insertend(NODE start,int item)
{
  NODE temp,cur;
  temp = (NODE)malloc(sizeof(struct node));
  temp->data = item;
  temp->addr = NULL;
  if(start==NULL)
    return temp;
  cur = start;
  while(cur->addr!=NULL){
    cur=cur->addr;
  }
  cur_>addr = temp;
  return start;
}
  
