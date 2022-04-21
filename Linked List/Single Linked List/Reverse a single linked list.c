C coad:
struct node{
  int data;
  struct node *addr;
};
typedef struct node *NODE;
NODE start;

NODE reverse(NODE start)
{
  NODE temp, prev, cur;
  if(start==NULL){
    printf("List is Empty\n");
    return NULL;
  }
  temp = NULL;
  prev = NULL;
  cur = start;
  while(cur!=NULL){
    temp = prev;
    prev = cur;
    cur = cur->addr;
    prev->addr = temp;
  }
  return prev;
}
