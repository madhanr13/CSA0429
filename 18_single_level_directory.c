#include <stdio.h>
#include <string.h>

struct directory {
    char dname[20];
    char fname[20][20];
    int fcount;
} dir;

int main() {
    int choice;
    char name[20];
    
    printf("Enter directory name: ");
    scanf("%s", dir.dname);
    dir.fcount = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create File\n");
        printf("2. Delete File\n");
        printf("3. Search File\n");
        printf("4. Display Files\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", name);
                strcpy(dir.fname[dir.fcount], name);
                dir.fcount++;
                printf("File created.\n");
                break;

            case 2: {
                printf("Enter file name to delete: ");
                scanf("%s", name);
                int found = 0;

                for (int i = 0; i < dir.fcount; i++) {
                    if (strcmp(dir.fname[i], name) == 0) {
                        found = 1;
                        for (int j = i; j < dir.fcount - 1; j++)
                            strcpy(dir.fname[j], dir.fname[j + 1]);
                        dir.fcount--;
                        printf("File deleted.\n");
                        break;
                    }
                }

                if (!found)
                    printf("File not found.\n");
                break;
            }

            case 3: {
                printf("Enter file name to search: ");
                scanf("%s", name);
                int found = 0;

                for (int i = 0; i < dir.fcount; i++) {
                    if (strcmp(dir.fname[i], name) == 0) {
                        found = 1;
                        printf("File found.\n");
                        break;
                    }
                }

                if (!found)
                    printf("File not found.\n");
                break;
            }

            case 4:
                printf("Directory: %s\n", dir.dname);
                printf("Files:\n");
                for (int i = 0; i < dir.fcount; i++)
                    printf("%s\n", dir.fname[i]);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
