#include <stdio.h>
#include <stdbool.h>

int main() {

    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n];
    int st[n], ct[n], tat[n], wt[n], rt[n];
    bool completed[n];

    float total_tat = 0, total_wt = 0, total_rt = 0;

    for(i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        completed[i] = false;   // initially no process is completed
    }

    int current_time = 0, completed_count = 0;

    while(completed_count < n) {

        int min_bt = 9999;
        int index = -1;

        // Find shortest job among arrived processes
        for(i = 0; i < n; i++) {
            if(at[i] <= current_time && completed[i] == false) {
                if(bt[i] < min_bt) {
                    min_bt = bt[i];
                    index = i;
                }
            }
        }

        if(index != -1) {
            // Start time
            st[index] = current_time;

            // Completion time
            ct[index] = st[index] + bt[index];

            // Move time forward
            current_time = ct[index];

            // Calculations
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            rt[index] = st[index] - at[index];

            total_tat += tat[index];
            total_wt += wt[index];
            total_rt += rt[index];

            completed[index] = true;
            completed_count++;
        }
        else {
            // If no process has arrived yet
            current_time++;
        }
    }

    // Output Table
    printf("\nPID\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i],
               st[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Response Time = %.2f\n", total_rt/n);
    
    return 0;
}