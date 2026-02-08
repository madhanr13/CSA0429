#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rem[n], wt[n], tat[n];
    int completed = 0, time = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);

        rem[i] = bt[i];
        wt[i] = tat[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    // Round Robin simulation loop
    while (completed < n) {
        int anyExecuted = 0;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rem[i] > 0) {
                anyExecuted = 1;

                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    rem[i] = 0;
                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];
                    completed++;
                }
            }
        }

        // If no process has arrived yet
        if (!anyExecuted)
            time++;
    }

    // Output
    float avg_wt = 0, avg_tat = 0;
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);

    return 0;
}
