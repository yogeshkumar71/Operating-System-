#include<stdio.h>
int main(){
printf("1BF24CS337\n");
printf("Binary Search\n");
int i,n,item;
int low=0,high,mid;
int a[10];
int pos=-1;
printf("Enter the length of elements: ");
scanf("%d",&n);
printf("Enter %d elements in ascending order:\n",n);
for(i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("Enter the element to be searched: ");
scanf("%d",&item);
high=n-1;
while(low<=high){
    mid=(low+high)/2;
    if(a[mid]==item){
        pos=mid;
        break;
    }
    else if(a[mid]<item){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}
if(pos!=-1)
    printf("Element found at position %d",pos+1);
else
    printf("Element not found");
return 0;
}
