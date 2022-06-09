#include<stdio.h>
#define N 5
void insert(int arr[],int ele);
void delete(int arr[],int ele);
int search(int arr[],int ele);
void display(int arr[]);
int main()
{
int arr[N];
for(int i=0;i<N;i++)arr[i]=-1;
int ch=0,ele,co;
while(ch!=5){
printf("What would you like to do\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Quit\n");
scanf("%d",&ch);
switch(ch){
case 1:
printf("How many elements do you want to insert\n");
scanf("%d",&co);
for(int i=0;i<co;i++){
printf("Which element do you want to insert\n");
scanf("%d",&ele);
insert(arr,ele);
}
break;
case 2:
printf("How many elements do you want to delete\n");
scanf("%d",&co);
for(int i=0;i<co;i++){
printf("Which element do you want to delete\n");
scanf("%d",&ele);
delete(arr,ele);
printf("The elements are \n");
display(arr);
printf("\n");
}
break;
case 3:
printf("Which element do you want to search\n");
scanf("%d",&ele);
co=search(arr,ele);
if(co!=-1)printf("Element found at position %d\n",co);
else printf("Element not found\n");
break;
case 4:
printf("The elements are \n");
display(arr);
printf("\n");
break;
case 5:
break;
default:
printf("Invalid input TRY Again!!!");
}
}
}
void insert(int arr[],int ele){
int pos=(ele)%N;
int cou=0,flag=0;
while(cou!=N){
if(arr[pos]==-1||arr[pos]==-2){
arr[pos]=ele;
break;
}
else pos=(pos+1)%N;
cou++;
}
if(cou==N)printf("Hash is filled!!Insertion Failed.\n");
else printf("Insertion Successful\n");
}
int search(int arr[],int ele){
int pos=(ele)%N;
int cou=0;
while(cou!=N){
if(arr[pos]==ele) return pos;
else if(arr[pos]==-1) break;
else{ cou++;
pos=(pos+1)%N;
}
}
return -1;
}
void delete(int arr[],int ele){
int pos=0,flag=0;
while(pos!=-1){
pos=search(arr,ele);
if(pos!=-1){
arr[pos]=-2;
flag=1;
}
}
if(flag)printf("Deletion Successful!!\n");
else 
printf("Element not found\n");
}
void display(int arr[]){
for(int i=0;i<N;i++)
if(arr[i]!=-1&&arr[i]!=-2)printf(" %d ",arr[i]);
}
