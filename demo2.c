#include<stdio.h>
int main(){
int i,n,item;
int low=0,high,mid;
int a[10];
int pos=-1;
printf("Enter the lenght of elements: ");
scanf("%d",&n);
high=n-1;
for(i=0;i<n;i++){
    printf("\nEnter the elements: ");
    scanf("%d",&a[i]);
}
printf("\nEnter the element to be searched: ");
scanf("%d",&item);
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
    printf("\nElement found at %d",pos+1);
else
    printf("\nElement not found");
return 0;
}
