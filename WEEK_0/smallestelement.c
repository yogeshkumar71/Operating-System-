#include<stdio.h>
int main(){
printf("1BF24CS337\n");
printf("SmallestElement\n");
printf("USN:1BF24CS337\n");
int i,n,a[10];
printf("Enter the lenght of elements: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("\nEnter the elements: ");
    scanf("%d",&a[i]);
}
int min=a[0];
for(i=0;i<n;i++){
    if(a[i]<min)
        min=a[i];
}
printf("Smallest element:%d",min);
return 0;
}
