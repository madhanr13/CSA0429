#include <stdio.h>
#include <string.h>

int main() {
    char filename[50], pattern[50], line[200];
    FILE *fp;

    printf("Enter filename: ");
    scanf("%s", filename);

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    printf("\nMatching lines:\n");

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, pattern) != NULL) {
            printf("%s", line);
        }
    }

    fclose(fp);
    return 0;
}
