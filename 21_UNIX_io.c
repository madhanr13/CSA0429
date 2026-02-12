#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd;
    char buffer[100];

    // ----------- open() and fcntl() -----------
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    printf("File opened successfully.\n");

    // Get file flags
    int flags = fcntl(fd, F_GETFL);
    printf("Old Flags = %d\n", flags);

    // Set non-blocking mode (example)
    fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    // ----------- write() and lseek() -----------
    write(fd, "Operating Systems", 17);
    lseek(fd, 0, SEEK_SET);
    int n = read(fd, buffer, sizeof(buffer));
    buffer[n] = '\0';

    printf("File Content: %s\n", buffer);

    // ----------- stat() -----------
    struct stat info;
    stat("sample.txt", &info);

    printf("\nFile Information (stat):\n");
    printf("Size: %ld bytes\n", info.st_size);
    printf("Inode: %ld\n", info.st_ino);
    printf("Links: %ld\n", info.st_nlink);

    // ----------- opendir() and readdir() -----------
    DIR *d = opendir(".");
    struct dirent *de;

    if (d == NULL) {
        perror("opendir");
        return 1;
    }

    printf("\nDirectory Contents:\n");
    while ((de = readdir(d)) != NULL) {
        printf("%s\n", de->d_name);
    }

    closedir(d);
    close(fd);

    return 0;
}
