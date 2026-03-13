#include <stdio.h>

int main()
{
    printf("USN:1BF24CS337\n");
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int Process_ID[n], Arrival_Time[n], Burst_Time[n], Priority[n];
    int Remaining_Time[n], Completion_Time[n];
    int Turnaround_Time[n], Waiting_Time[n];

    int Current_Time = 0;
    int Completed = 0;

    float avgWT = 0, avgTAT = 0;

    printf("\nEnter Arrival Time, Burst Time and Priority for\n");

    for(int i = 0; i < n; i++)
    {
        Process_ID[i] = i + 1;
        printf("%d : ", i+1);
        scanf("%d %d %d", &Arrival_Time[i], &Burst_Time[i], &Priority[i]);
        Remaining_Time[i] = Burst_Time[i];
    }

    while(Completed < n)
    {
        int Highest_Priority = 9999;
        int Selected_Process = -1;

        for(int i = 0; i < n; i++)
        {
            if(Arrival_Time[i] <= Current_Time && Remaining_Time[i] > 0)
            {
                if(Priority[i] < Highest_Priority)
                {
                    Highest_Priority = Priority[i];
                    Selected_Process = i;
                }
            }
        }

        if(Selected_Process == -1)
        {
            Current_Time++;
        }
        else
        {
            Remaining_Time[Selected_Process]--;
            Current_Time++;

            if(Remaining_Time[Selected_Process] == 0)
            {
                Completion_Time[Selected_Process] = Current_Time;

                Turnaround_Time[Selected_Process] =
                Completion_Time[Selected_Process] -
                Arrival_Time[Selected_Process];

                Waiting_Time[Selected_Process] =
                Turnaround_Time[Selected_Process] -
                Burst_Time[Selected_Process];

                Completed++;
            }
        }
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n");

    for(int i = 0; i < n; i++)
    {
        avgWT += Waiting_Time[i];
        avgTAT += Turnaround_Time[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        Process_ID[i],
        Arrival_Time[i],
        Burst_Time[i],
        Priority[i],
        Completion_Time[i],
        Waiting_Time[i],
        Turnaround_Time[i]);
    }

    avgWT = avgWT / n;
    avgTAT = avgTAT / n;

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}

