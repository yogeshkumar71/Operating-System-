#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], finished[n];
    int current_time = 0, completed = 0;
    float avg_tat = 0, avg_wt = 0;

    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
        finished[i] = 0;
    }

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    while(completed < n) {
        int idx = -1;
        int min_bt = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && finished[i] == 0) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            current_time++;
        }
        else {
            ct[idx] = current_time + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            avg_tat += tat[idx];
            avg_wt += wt[idx];

            current_time = ct[idx];
            finished[idx] = 1;
            completed++;
        }
    }

    printf("\nSJF scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    avg_tat /= n;
    avg_wt /= n;

    printf("\nAverage turnaround time: %fms\n", avg_tat);
    printf("Average waiting time: %fms\n", avg_wt);

    return 0;
}
