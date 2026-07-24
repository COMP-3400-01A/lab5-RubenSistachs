#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    // Declare the buffer to use. Do NOT change!
    enum { BUFSIZE = 8 };
    char buffer[BUFSIZE];
    // TODO: Complete and document
   
    ssize_t bytes_read;
    bytes_read = read(STDIN_FILENO, buffer, BUFSIZE);
    // Process the read data
    if (bytes_read > 0) {
        for (ssize_t i = 0; i < bytes_read; i++) {
            buffer[i] = toupper((unsigned char)buffer[i]);
        }
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    return 0;
}
