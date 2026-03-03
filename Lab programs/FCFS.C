#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n];
    int st[n], ct[n], tat[n], wt[n], rt[n];

    float total_wt = 0, total_tat = 0, total_rt = 0;

    // Input
    for(i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Sort by Arrival Time (FCFS)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(at[i] > at[j]) {
                int temp;

                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // First process
    st[0] = at[0];
    ct[0] = st[0] + bt[0];

    // Remaining processes
    for(i = 1; i < n; i++) {

        if(ct[i-1] < at[i])
            st[i] = at[i];
        else
            st[i] = ct[i-1];

        ct[i] = st[i] + bt[i];
    }

    // Calculate TAT, WT, RT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = st[i] - at[i];

        total_tat += tat[i];
        total_wt += wt[i];
        total_rt += rt[i];
    }

    // Table Output
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], st[i],
               ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Response Time = %.2f\n", total_rt/n);

    // Gantt Chart
    printf("\nGantt Chart:\n");

    printf(" ");

    for(i = 0; i < n; i++)
        printf("-------");

    printf("\n|");

    for(i = 0; i < n; i++)
        printf("  P%d  |", pid[i]);

    printf("\n ");

    for(i = 0; i < n; i++)
        printf("-------");

    printf("\n");

    printf("%d", st[0]);

    for(i = 0; i < n; i++)
        printf("      %d", ct[i]);

    printf("\n");

    return 0;
}