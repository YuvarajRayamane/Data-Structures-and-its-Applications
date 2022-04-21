C coad:
struct node{
  int data;
  struct node *addr;
};
typedef struct node *NODE;
NODE start;

NODE deletkey(NODE start, int key)
{
  NODE prev, cur, temp;
  if(key == start->data){
    temp = start;
    start = start->addr;
    printf("Node deleted is %d",temp->data);
    free(temp);
    return start;
  }
  cur = start;
  prev = NULL;
  while(cur!=NULL && key!=cur->data){
    prev = cur;
    cur = cur->addr;
  }
  if(cur == NULL){
    printf("Key not found!!\n");
    return start;
  }
  prev->addr = cur->addr;
  printf("Node deleted is %d ",cur->data);
  free(cur);
  return start;
}

