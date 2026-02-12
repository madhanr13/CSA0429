#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];

    // Creating and writing to file
    fd = open("demo.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        printf("Error creating file\n");
        return 1;
    }

    write(fd, "Hello OS World!", 16);
    close(fd);

    // Reading file
    fd = open("demo.txt", O_RDONLY);
    if (fd < 0) {
        printf("Error opening file\n");
        return 1;
    }

    int n = read(fd, buffer, sizeof(buffer));
    buffer[n] = '\0';
    printf("File content: %s\n", buffer);
    close(fd);

    // Using lseek
    fd = open("demo.txt", O_RDWR);
    lseek(fd, 6, SEEK_SET); // Move to position
    write(fd, "UNIX ", 5);
    close(fd);

    printf("File modified successfully using lseek.\n");

    return 0;
}
