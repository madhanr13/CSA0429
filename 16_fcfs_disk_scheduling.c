#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total = 0;
    int current = head;

    printf("\nHead Movements:\n");

    for (int i = 0; i < n; i++) {
        int movement = abs(req[i] - current);
        total += movement;

        printf("Move from %d to %d -> %d\n",
               current, req[i], movement);

        current = req[i];
    }

    printf("\nTotal Head Movement = %d\n", total);

    return 0;
}
