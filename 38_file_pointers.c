#include <stdio.h>

int main() {
    int total_blocks, required_blocks;
    
    printf("Enter total number of disk blocks: ");
    scanf("%d", &total_blocks);

    int disk[total_blocks];
    for (int i = 0; i < total_blocks; i++)
        disk[i] = 0;  // 0 means free

    char filename[20];
    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter number of blocks required: ");
    scanf("%d", &required_blocks);

    int index_block = -1;

    // Allocate index block
    for (int i = 0; i < total_blocks; i++) {
        if (disk[i] == 0) {
            index_block = i;
            disk[i] = 1;
            break;
        }
    }

    if (index_block == -1) {
        printf("No free block available for index block.\n");
        return 0;
    }

    int data_blocks[required_blocks];
    int count = 0;

    // Allocate data blocks
    for (int i = 0; i < total_blocks && count < required_blocks; i++) {
        if (disk[i] == 0) {
            data_blocks[count] = i;
            disk[i] = 1;
            count++;
        }
    }

    if (count < required_blocks) {
        printf("Not enough free blocks available.\n");
        return 0;
    }

    // Display allocation
    printf("\nFile Name: %s\n", filename);
    printf("Index Block: %d\n", index_block);
    printf("Data Blocks Allocated:\n");

    for (int i = 0; i < required_blocks; i++)
        printf("Block %d -> %d\n", i, data_blocks[i]);

    return 0;
}
