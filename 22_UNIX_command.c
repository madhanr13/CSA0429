#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *d;
    struct dirent *de;

    d = opendir(".");
    if (d == NULL) {
        printf("Unable to open directory.\n");
        return 1;
    }

    printf("Files in current directory:\n");

    while ((de = readdir(d)) != NULL) {
        printf("%s\n", de->d_name);
    }

    closedir(d);
    return 0;
}
