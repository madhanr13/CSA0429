#include <stdio.h>

int main() {
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb], used[nb];
    printf("Enter block sizes:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &block[i]);
        used[i] = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np], allocation[np];
    printf("Enter process sizes:\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for (int i = 0; i < np; i++) {
        int min = 9999, index = -1;

        for (int j = 0; j < nb; j++) {
            if (!used[j] && block[j] >= process[i]) {
                if (block[j] - process[i] < min) {
                    min = block[j] - process[i];
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
            printf("P%d\t%d\tB%d\n", i + 1, process[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, process[i]);
    }

    return 0;
}
