#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 *  * create_buffer - Allocates memory for a buffer.
 *   * @filename: The name of the file to be copied.
 *    *
 *     * Return: A pointer to the allocated buffer.
 *      */
char *create_buffer(const char *filename) {
	    int fd;
	        char *buffer;
		    ssize_t n;

		        fd = open(filename, O_RDONLY);
			    if (fd == -1) {
				            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
					            exit(98);
						        }

			        /* Get the size of the file */
			        off_t file_size = lseek(fd, 0, SEEK_END);
				    lseek(fd, 0, SEEK_SET);

				        /* Allocate memory for the buffer */
				        buffer = malloc(file_size);
					    if (buffer == NULL) {
						            dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
							            exit(98);
								        }

					        /* Read the file into the buffer */
					        n = read(fd, buffer, file_size);
						    if (n == -1) {
							            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
								            free(buffer); // Don't forget to free allocated memory
									            exit(98);
										        }

						        close(fd);
							    return (buffer);
}

/**
 *  * close_file - Closes a file descriptor.
 *   * @fd: The file descriptor to close.
 *    */
void close_file(int fd) {
	    close(fd);
}

int main(int argc, char *argv[]) {
	    int from, to;
	        ssize_t r, w;
		    char *buffer;

		        if (argc != 3) {
				        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
					        exit(97);
						    }

			    buffer = create_buffer(argv[1]);
			        from = open(argv[1], O_RDONLY);
				    if (from == -1) {
					            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
						            free(buffer);
							            exit(98);
								        }

				        to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
					    if (to == -1) {
						            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
							            free(buffer);
								            close_file(from);
									            exit(99);
										        }

					        do {
							        r = read(from, buffer, 1024);
								        if (r == -1) {
										            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
											                free(buffer);
													            close_file(from);
														                close_file(to);
																            exit(98);
																	            }

									        w = write(to, buffer, r);
										        if (w == -1) {
												            dprintf(STDERR_FILENO, "Error: Can't write

