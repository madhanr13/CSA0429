#include <stdio.h>
#include <string.h>

struct directory {
    char dname[20];
    char fname[20][20];
    int fcount;
} dir[10];

int main() {
    int n, choice;
    char uname[20], fname[20];

    printf("Enter number of users: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter user directory name: ");
        scanf("%s", dir[i].dname);
        dir[i].fcount = 0;
    }

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
        case 1:  // Create file
            printf("Enter user name: ");
            scanf("%s", uname);
            printf("Enter file name: ");
            scanf("%s", fname);

            for (int i = 0; i < n; i++) {
                if (strcmp(dir[i].dname, uname) == 0) {
                    strcpy(dir[i].fname[dir[i].fcount], fname);
                    dir[i].fcount++;
                    printf("File created.\n");
                    break;
                }
            }
            break;

        case 2:  // Delete file
            printf("Enter user name: ");
            scanf("%s", uname);
            printf("Enter file name to delete: ");
            scanf("%s", fname);

            for (int i = 0; i < n; i++) {
                if (strcmp(dir[i].dname, uname) == 0) {
                    int found = 0;
                    for (int j = 0; j < dir[i].fcount; j++) {
                        if (strcmp(dir[i].fname[j], fname) == 0) {
                            found = 1;
                            for (int k = j; k < dir[i].fcount - 1; k++)
                                strcpy(dir[i].fname[k], dir[i].fname[k + 1]);
                            dir[i].fcount--;
                            printf("File deleted.\n");
                            break;
                        }
                    }
                    if (!found) printf("File not found.\n");
                }
            }
            break;

        case 3:  // Search file
            printf("Enter user name: ");
            scanf("%s", uname);
            printf("Enter file name to search: ");
            scanf("%s", fname);

            for (int i = 0; i < n; i++) {
                if (strcmp(dir[i].dname, uname) == 0) {
                    int found = 0;
                    for (int j = 0; j < dir[i].fcount; j++) {
                        if (strcmp(dir[i].fname[j], fname) == 0) {
                            found = 1;
                            printf("File found.\n");
                            break;
                        }
                    }
                    if (!found) printf("File not found.\n");
                }
            }
            break;

        case 4:  // Display files under a user
            printf("Enter user name: ");
            scanf("%s", uname);

            for (int i = 0; i < n; i++) {
                if (strcmp(dir[i].dname, uname) == 0) {
                    printf("Files under %s:\n", uname);
                    for (int j = 0; j < dir[i].fcount; j++)
                        printf("%s\n", dir[i].fname[j]);
                }
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice.\n");
        }
    }
}
