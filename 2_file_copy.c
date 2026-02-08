#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Open source file (read-only)
    src_fd = open("source.txt", O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return 1;
    }

    // Open destination file (write-only, create if not exists, truncate if exists)
    dest_fd = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening destination file");
        close(src_fd);
        return 1;
    }

    // Read–Write Loop
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, bytes_read) != bytes_read) {
            perror("Write error");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytes_read < 0) {
        perror("Read error");
    }

    // Close both files
    close(src_fd);
    close(dest_fd);

    return 0;
}
