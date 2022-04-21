C coad:
struct node{
  int data;
  struct node *addr;
};
typedef struct node *NODE;
NODE last;

//Insertion at begining
NODE insertbegin(NODE last, int item)
{
  NODE temp;
  temp = (NODE)malloc(sizeof(struct node));
  temp->data = item;
  if(last==NULL){
    temp->addr = temp;
    return temp;
  }
  temp->addr=last->addr;
  last->addr=temp;
  return last;
}

//Insertion at end
NODE insertend(NODE last,int item)
{
 NODE temp;
  temp = (NODE)malloc(sizeof(struct node));
  temp->data = item;
  if(last==NULL){
    temp->addr = temp;
    return temp;
  }
  temp->addr=last->addr;
  last->addr=temp;
  return temp;
}

