#include <stdio.h>

int main() {
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb], block_used[nb];
    printf("Enter size of each block:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
        block_used[i] = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np], allocation[np];
    printf("Enter size of each process:\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    // First Fit Algorithm
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (!block_used[j] && block[j] >= process[i]) {
                allocation[i] = j;
                block_used[j] = 1;
                break;
            }
        }
    }

    // Output result
    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n", i + 1, process[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
    }

    return 0;
}
