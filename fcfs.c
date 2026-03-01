#include <stdio.h>

int main() {
    int n;

    // Read number of processes
    scanf("%d", &n);

    int pid[n];
    int at[n], bt[n];
    int wt[n], tat[n];
    int ct[n];   // Completion time

    // Read PID, Arrival Time and Burst Time
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    // Sort processes by Arrival Time (Simple Bubble Sort)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(at[j] > at[j + 1]) {
                // Swap arrival time
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap pid
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    int current_time = 0;
    float total_wt = 0, total_tat = 0;

    // Calculate WT, TAT and Completion Time
    for(int i = 0; i < n; i++) {

        if(current_time < at[i]) {
            current_time = at[i];
        }

        wt[i] = current_time - at[i];

        ct[i] = current_time + bt[i];

        tat[i] = ct[i] - at[i];

        current_time = ct[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Print Waiting Time
    printf("Waiting Time:");
    for(int i = 0; i < n; i++) {
        printf(" P%d %d", pid[i], wt[i]);
    }

    printf("\n");

    // Print Turnaround Time
    printf("Turnaround Time:");
    for(int i = 0; i < n; i++) {
        printf(" P%d %d", pid[i], tat[i]);
    }

    printf("\n");

    // Print Averages (2 decimal places)
    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}