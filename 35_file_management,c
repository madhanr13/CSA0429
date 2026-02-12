#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    char filename[50], data[200];
    FILE *fp;

    while (1) {
        printf("\nFile Management Menu\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read File\n");
        printf("4. Append to File\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("File creation failed.\n");
            } else {
                printf("File created successfully.\n");
                fclose(fp);
            }
            break;

        case 2:
            printf("Enter filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("Cannot open file.\n");
            } else {
                printf("Enter data to write: ");
                getchar(); // clear buffer
                fgets(data, sizeof(data), stdin);
                fputs(data, fp);
                fclose(fp);
                printf("Data written successfully.\n");
            }
            break;

        case 3:
            printf("Enter filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("Cannot open file.\n");
            } else {
                printf("\nFile Content:\n");
                while (fgets(data, sizeof(data), fp) != NULL)
                    printf("%s", data);
                fclose(fp);
            }
            break;

        case 4:
            printf("Enter filename: ");
            scanf("%s", filename);

            fp = fopen(filename, "a");
            if (fp == NULL) {
                printf("Cannot open file.\n");
            } else {
                printf("Enter data to append: ");
                getchar();
                fgets(data, sizeof(data), stdin);
                fputs(data, fp);
                fclose(fp);
                printf("Data appended successfully.\n");
            }
            break;

        case 5:
            printf("Enter filename: ");
            scanf("%s", filename);

            if (remove(filename) == 0)
                printf("File deleted successfully.\n");
            else
                printf("File deletion failed.\n");
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
