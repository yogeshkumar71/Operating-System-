#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n];
    for(int i=0;i<n;i++){
        printf("\nEnter the arrival time of process %d: ",i+1);
        scanf("%d",&at[i]);
        printf("\nEnter the burst time of process %d: ",i+1);
        scanf("%d",&bt[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
               int temp=at[i];
               at[i]=at[j];
               at[j]=temp;
            }
        }
    }
    int current_time=0;
    for(int i=0;i<n;i++){
        if(at[i]>current_time)
            current_time=at[i];
        ct[i]=current_time+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        current_time=ct[i];
    }
    printf("\nProcess AT BT CT TAT WT");
    for(int i=0;i<n;i++){
        printf("\n        %d  %d  %d  %d",i+1,ct[i],tat[i],wt[i]);
    }
    float avgtat=0;
    float avgwt=0;
    for(int i=0;i<n;i++){
        avgtat=avgtat+tat[i];
        avgwt=avgwt+wt[i];
    }
    float AVGTAT=avgtat/n;
    float AVGWT=avgwt/n;
    printf("\nAvgerage TurnaroundTime:%.2f",AVGTAT);
    printf("\nAvgerage WaitingTime:%.2f",AVGWT);
    return 0;
}
