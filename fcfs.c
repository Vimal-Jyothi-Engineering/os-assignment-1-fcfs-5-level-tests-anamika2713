#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int pid[n], at[n], bt[n], wt[n], tat[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
    }

    // Sort by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int current_time = 0;
    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {

        if (current_time < at[i])
            current_time = at[i];

        wt[i] = current_time - at[i];
        current_time += bt[i];
        tat[i] = wt[i] + bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    // EXACT FORMAT (NO EXTRA SPACES OR LINES)

    printf("Waiting Time: ");
    for (int i = 0; i < n; i++) {
        printf("P%d %d", pid[i], wt[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n");

    printf("Turnaround Time: ");
    for (int i = 0; i < n; i++) {
        printf("P%d %d", pid[i], tat[i]);
        if (i != n - 1) printf(" ");
    }
    printf("\n");

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f", total_tat / n);

    return 0;
}
