#include <stdio.h>

int main()
{
    int n, tq;
    printf("USN:1BF24CS337\n");


    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];
    int remaining[n], first[n];

    printf("Enter arrival times:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter burst times:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        remaining[i]=bt[i];
        first[i] = -1;
    }

    int time = 0, completed = 0;

    while(completed < n)
    {
        int executed = 0;

        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && remaining[i] > 0)
            {
                executed = 1;

                if(first[i] == -1)
                    first[i] = time;

                if(remaining[i] > tq)
                {
                    time += tq;
                    remaining[i] -= tq;
                }
                else
                {
                    time += remaining[i];

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    rt[i] = first[i] - at[i];

                    remaining[i] = 0;
                    completed++;
                }
            }
        }

        if(executed == 0)
            time++;
    }

    printf("\nRRS scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    float avgTAT=0, avgWT=0;

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);

        avgTAT += tat[i];
        avgWT += wt[i];
    }

    avgTAT/=n;
    avgWT/=n;

    printf("\nAverage turnaround time: %fms\n",avgTAT);
    printf("\nAverage waiting time: %fms\n",avgWT);

    return 0;
}
