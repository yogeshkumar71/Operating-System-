#include<stdio.h>
int main(){
int i,n,a[10],min;
printf("Enter the lenght of elements: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("\nEnter the elements: ");
    scanf("%d",&a[i]);
}
for(i=0;i<n;i++){
    if(a[i]<min)
        min=a[i];
}
printf("Smallest element:%d",min);
return 0;
}
