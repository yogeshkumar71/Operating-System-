#include<stdio.h>
int main(){
printf("USN:1BF24CS337\n");
printf("DuplicateElement\n");
int i,j,n,item;
int a[10];
int pos=-1,poss=-1;
printf("Enter the lenght of elements: ");
scanf("%d",&n);
for(i=0;i<n;i++){
    printf("\nEnter the elements: ");
    scanf("%d",&a[i]);
}
for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
            if(a[i]==a[j]){
                pos=1;
            }
    }
}
if(pos==-1)
    printf("No Duplicates");
else
    printf("\nElement has duplicate");
return 0;
}
