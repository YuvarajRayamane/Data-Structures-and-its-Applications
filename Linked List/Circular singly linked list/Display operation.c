
NODE display(NODE last)
{
  NODE temp;
  if(last = NULL){
    printf("List is Empty\n");
    return NULL;
  }
  else{
    printf("List contents are\n");
    temp = last->addr;
    while(temp!=last){
      printf("%d\t",temp->data);
      temp = temp->addr;
    }
    printf("%d",temp->data);
  }
}
