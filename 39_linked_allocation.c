#include <stdio.h>

int main() {
    int total_blocks, required_blocks;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &total_blocks);

    int disk[total_blocks];
    int next[total_blocks];

    for (int i = 0; i < total_blocks; i++) {
        disk[i] = 0;     // 0 means free
        next[i] = -1;    // no next pointer
    }

    char filename[20];
    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter number of blocks required: ");
    scanf("%d", &required_blocks);

    int blocks[required_blocks];
    int count = 0;

    // Allocate blocks
    for (int i = 0; i < total_blocks && count < required_blocks; i++) {
        if (disk[i] == 0) {
            disk[i] = 1;
            blocks[count++] = i;
        }
    }

    if (count < required_blocks) {
        printf("Not enough free blocks available.\n");
        return 0;
    }

    // Link blocks
    for (int i = 0; i < required_blocks - 1; i++) {
        next[blocks[i]] = blocks[i + 1];
    }

    int start = blocks[0];
    int end = blocks[required_blocks - 1];

    // Display result
    printf("\nFile Name: %s\n", filename);
    printf("Start Block: %d\n", start);
    printf("End Block: %d\n", end);

    printf("Linked Blocks:\n");
    int current = start;
    while (current != -1) {
        printf("%d -> ", current);
        current = next[current];
    }
    printf("NULL\n");

    return 0;
}
