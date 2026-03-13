#include <stdio.h>

int main()
{
    printf("USN:1BF24CS337\n");
    int n;
    int at[10], bt[10], rt[10];
    int ct[10], tat[10], wt[10];
    int finished[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time and Burst Time\n");
    for(int i=0;i<n;i++)
    {
        printf("\nProcess %d\n",i+1);
        printf("AT: ");
        scanf("%d",&at[i]);
        printf("BT: ");
        scanf("%d",&bt[i]);

        rt[i] = bt[i];   // remaining time
    }

    int current_time = 0;
    int completed = 0;

    while(completed < n)
    {
        int idx = -1;
        int min_rt = 9999;

        // find process with smallest remaining time
        for(int i=0;i<n;i++)
        {
            if(at[i] <= current_time && finished[i]==0)
            {
                if(rt[i] < min_rt && rt[i] > 0)
                {
                    min_rt = rt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1)
        {
            current_time++;
        }
        else
        {
            rt[idx]--;        // execute for 1 unit
            current_time++;

            if(rt[idx] == 0)
            {
                ct[idx] = current_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];

                finished[idx] = 1;
                completed++;
            }
        }
    }

    float total_tat = 0, total_wt = 0;

    printf("\nProcess AT BT CT TAT WT\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d      %d  %d  %d  %d  %d\n",
               i+1,at[i],bt[i],ct[i],tat[i],wt[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f", total_tat/n);
    printf("\nAverage WT = %.2f\n", total_wt/n);

    return 0;
}

