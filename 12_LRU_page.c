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

    int frame[f], time[f], counter = 0;

    for(i = 0; i < f; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        hit = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                hit = 1;
                break;
            }
        }

        if(!hit) {
            int lru = 0;
            for(j = 1; j < f; j++)
                if(time[j] < time[lru])
                    lru = j;

            frame[lru] = pages[i];
            counter++;
            time[lru] = counter;
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
