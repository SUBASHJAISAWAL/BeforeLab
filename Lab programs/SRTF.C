#include <stdio.h>
#include <limits.h>

int main() {

    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt_bt[n];
    int ct[n], tat[n], wt[n], rt[n];
    int completed = 0, current_time = 0;
    float total_tat = 0, total_wt = 0, total_rt = 0;

    for(i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        rt_bt[i] = bt[i];  // remaining burst time
        rt[i] = -1;        // response time initially unset
    }

    printf("\nGantt Chart:\n|");

    while(completed != n) {

        int min_index = -1;
        int min_remaining = INT_MAX;

        // Find process with smallest remaining time
        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && rt_bt[i] > 0) {
                if(rt_bt[i] < min_remaining) {
                    min_remaining = rt_bt[i];
                    min_index = i;
                }
            }
        }

        if(min_index == -1) {
            current_time++;
        }
        else {
            // First time execution → calculate Response Time
            if(rt[min_index] == -1)
                rt[min_index] = current_time - at[min_index];

            printf(" P%d |", pid[min_index]);

            rt_bt[min_index]--;
            current_time++;

            // If process finished
            if(rt_bt[min_index] == 0) {
                completed++;
                ct[min_index] = current_time;

                tat[min_index] = ct[min_index] - at[min_index];
                wt[min_index] = tat[min_index] - bt[min_index];

                total_tat += tat[min_index];
                total_wt += wt[min_index];
                total_rt += rt[min_index];
            }
        }
    }

    // Print Results
    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i],
               ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Response Time = %.2f\n", total_rt/n);

    return 0;
}