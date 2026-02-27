#include<stdio.h>
int main(){
int i,n,item;
int a[10];
int pos=-1;
printf("Enter the lenght of elements: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("\nEnter the elements: ");
    scanf("%d",&a[i]);
}
printf("\nEnter the element to be searched: ");
scanf("%d",&item);
for (i=0;i<n;i++){
    if(item==a[i])
        pos=i;
}
if(pos!=-1)
    printf("\nElement found at %d",pos);
else
    printf("\nElement not found");
return 0;
}
