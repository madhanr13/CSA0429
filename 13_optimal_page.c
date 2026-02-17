#include <stdio.h>

int main() {
    int n, f, i, j, k, faults = 0, hit;

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

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        hit = 0;

        // Check hit
        for(j = 0; j < f; j++)
            if(frame[j] == pages[i]) {
                hit = 1;
                break;
            }

        if(!hit) {
            int pos = -1, farthest = i + 1;

            for(j = 0; j < f; j++) {
                int found = 0;

                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        found = 1;
                        break;
                    }
                }

                if(!found) { // not used again
                    pos = j;
                    break;
                }
            }

            if(pos == -1) pos = 0;

            frame[pos] = pages[i];
            faults++;
        }

        printf("%d\t", pages[i]);
        for(j = 0; j < f; j++)
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
