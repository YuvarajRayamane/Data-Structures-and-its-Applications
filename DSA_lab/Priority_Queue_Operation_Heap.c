#include <stdio.h>
#include <stdlib.h>
void heapify(int a[10],int n)
{
    int i,k,j,v,flag;
    for(i=n/2;i>=1;i--){
        k=i;
        v=a[k];
        flag=0;
        while(!flag && 2*k<=n){
            j=2*k;
            if(j<n){
                if(a[j]<a[j+1])
                j=j+1;
            }
            if(v>=a[j])
            flag=1;
            else{
                a[k]=a[j];
                k=j;
            }
        }
        a[k]=v;
    }
}

int main()
{
    int i,n,ch,a[10];
    for(;;){
        printf("\n1. Create heap\n 2. Delete\n 3. Exit\n Enter your choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\n Read no. of element:");
            scanf("%d",&n);
            printf("\n Read elements\n");
            for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
            heapify(a,n);
            printf("\n Elements after heapify\n");
            for(i=1;i<=n;i++)
            printf("%d\t",a[i]);
            break;
            
            case 2:if(n>=1){
                printf("\n Element deleted is %d",a[1]);
                a[1]=a[n];
                n=n-1;
                heapify(a,n);
                printf("\n Elements after deletion\n");
                for(i=1;i<=n;i++)
                printf("%d\t",a[i]);
            }
            else
            printf("\n No element for deletion!!!");
            break;
            
            default :exit(0);
        }
    }
    return 0;
}
