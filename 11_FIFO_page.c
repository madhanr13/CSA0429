#include <stdio.h>

int main() {
    int n, f, i, j, k = 0, faults = 0, hit;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    int frame[f];
    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < f; j++)
            if(frame[j] == pages[i]) {
                hit = 1;
                break;
            }

        if(!hit) {
            frame[k] = pages[i];
            k = (k + 1) % f;   // FIFO rotation
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
