C coad:
struct node{
  int data;
  struct node *addr;
};
typedef struct node *NODE;
NODE last;

//Deletion at the begining
NODE deletbegin(NODE last)
{
  NODE temp;
  if(last==NULL){
    printf("List is Empty\n");
    return NULL;
  }
  if(last->addr=last){
    printf("Node deleted is %d\n",last->data);
    free(last);
    return NULL;
  }
  temp = last->addr;
  last->addr = temp->addr;
  printf("Node deleted is %d\n",temp->data);
  free(temp);
  return last;
}


//Deletion at end
NODE deletend(NODE last)
{
  NODE temp;
  if(last==NULL){
    printf("List is Empty\n");
    return NULL;
  }
  if(last->addr=last){
    printf("Node deleted is %d\n",last->data);
    free(last);
    return NULL;
  }
  temp = last;
  while(temp->addr!=last){
    temp = temp->addr;
  }
  temp->addr = last->addr;
  printf("Node deleted is %d\n",last->data);
  free(last);
  return temp;
}

    
