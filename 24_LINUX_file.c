#include <stdio.h>
#include <sys/stat.h>

void print_permissions(mode_t mode) {
    printf((S_ISDIR(mode)) ? "d" : "-");

    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");

    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");

    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

int main() {
    char filename[50];
    struct stat info;

    printf("Enter filename: ");
    scanf("%s", filename);

    if (stat(filename, &info) != 0) {
        printf("Error: Cannot read file info.\n");
        return 1;
    }

    printf("\nFile Permissions: ");
    print_permissions(info.st_mode);

    printf("\nOwner User ID : %d", info.st_uid);
    printf("\nGroup ID      : %d\n", info.st_gid);

    return 0;
}
