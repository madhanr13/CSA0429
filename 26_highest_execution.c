#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], wt[n], tat[n], completed[n];
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority (smaller = higher): ");
        scanf("%d", &pr[i]);
        completed[i] = 0;
    }

    int time = 0, count = 0;

    while (count < n) {
        int highest = 9999;
        int index = -1;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && pr[i] < highest) {
                highest = pr[i];
                index = i;
            }
        }

        if (index == -1) {
            time++;
        } else {
            time += bt[index];
            tat[index] = time - at[index];
            wt[index] = tat[index] - bt[index];

            total_wt += wt[index];
            total_tat += tat[index];

            completed[index] = 1;
            count++;
        }
    }

    printf("\nProcess\tAT\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f",
           (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n",
           (float)total_tat / n);

    return 0;
}
