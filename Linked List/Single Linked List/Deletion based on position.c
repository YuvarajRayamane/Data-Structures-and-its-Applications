C coad:
struct node{
  int data;
  struct node *addr;
};
typedef struct node *NODE;
NODE start;

//pos = position
NODE deletpos(NODE start, int pos)
{
  NODE temp, cur, prev;
  int count=1;
  if(pos==1){
    temp = start;
    start = start->addr;
    printf("Node deleted is %d",temp->data);
    free(temp);
    return start;
  }
  prev = NULL;
  cur = start;
  while(cur!=NULL && pos!=count){
    prev = cur;
    cur = cur->addr;
    count = count+1;
  }
  if(pos!=count){
    printf("Node not found\n");
    return start;
  }
  prev->addr = cur->addr;
  printf("Node deleted is %d",cur->data);
  free(cur);
  return start;
}
