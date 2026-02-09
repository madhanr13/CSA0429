#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, direction, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

    // Sort request queue
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (req[i] > req[j]) {
                int t = req[i]; req[i] = req[j]; req[j] = t;
            }

    int total = 0;
    int current = head;

    printf("\nHead Movements:\n");

    // SCAN Movement

    if (direction == 1) { // Moving right
        // Move right requests
        for (int i = 0; i < n; i++) {
            if (req[i] >= head) {
                printf("Move %d -> %d : %d\n", current, req[i], abs(req[i] - current));
                total += abs(req[i] - current);
                current = req[i];
            }
        }

        // Move to end
        printf("Move %d -> %d : %d\n", current, disk_size - 1, abs((disk_size - 1) - current));
        total += abs((disk_size - 1) - current);
        current = disk_size - 1;

        // Move left requests
        for (int i = n - 1; i >= 0; i--) {
            if (req[i] < head) {
                printf("Move %d -> %d : %d\n", current, req[i], abs(req[i] - current));
                total += abs(req[i] - current);
                current = req[i];
            }
        }

    } else { // Moving left
        // Move left requests
        for (int i = n - 1; i >= 0; i--) {
            if (req[i] <= head) {
                printf("Move %d -> %d : %d\n", current, req[i], abs(req[i] - current));
                total += abs(req[i] - current);
                current = req[i];
            }
        }

        // Move to start
        printf("Move %d -> 0 : %d\n", current, current);
        total += current;
        current = 0;

        // Move right requests
        for (int i = 0; i < n; i++) {
            if (req[i] > head) {
                printf("Move %d -> %d : %d\n", current, req[i], abs(req[i] - current));
                total += abs(req[i] - current);
                current = req[i];
            }
        }
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
