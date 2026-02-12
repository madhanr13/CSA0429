#include <stdio.h>

void allocate(int block[], int nb, int process[], int np, int choice) {
    int allocation[np];
    int used[nb];

    for (int i = 0; i < nb; i++)
        used[i] = 0;

    for (int i = 0; i < np; i++)
        allocation[i] = -1;

    for (int i = 0; i < np; i++) {
        int index = -1;

        if (choice == 1) { // First Fit
            for (int j = 0; j < nb; j++) {
                if (!used[j] && block[j] >= process[i]) {
                    index = j;
                    break;
                }
            }
        }
        else if (choice == 2) { // Best Fit
            int min = 9999;
            for (int j = 0; j < nb; j++) {
                if (!used[j] && block[j] >= process[i] &&
                    (block[j] - process[i]) < min) {
                    min = block[j] - process[i];
                    index = j;
                }
            }
        }
        else if (choice == 3) { // Worst Fit
            int max = -1;
            for (int j = 0; j < nb; j++) {
                if (!used[j] && block[j] >= process[i] &&
                    (block[j] - process[i]) > max) {
                    max = block[j] - process[i];
                    index = j;
                }
            }
        }

        if (index != -1) {
            allocation[i] = index;
            used[index] = 1;
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (int i = 0; i < np; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\tB%d\n",
                   i + 1, process[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n",
                   i + 1, process[i]);
    }
}

int main() {
    int nb, np, choice;

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    int block[nb];
    printf("Enter block sizes:\n");
    for (int i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np];
    printf("Enter process sizes:\n");
    for (int i = 0; i < np; i++)
        scanf("%d", &process[i]);

    printf("\nChoose Allocation Strategy:\n");
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    allocate(block, nb, process, np, choice);

    return 0;
}
