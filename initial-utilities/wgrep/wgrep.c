#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc < 2) {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }
  if (argc == 3) {
    const char *file_name = argv[2];
    FILE *file_ptr = fopen(file_name, "r");

    if (file_ptr == NULL) {
      printf("wgrep: cannot open file\n");
      return 1;
    }
    const char *pattern = argv[1];

    char buffer[256];
    while (fgets(buffer, 256, file_ptr) != NULL) {
      if (strstr(buffer, pattern) != NULL) {
        printf("%s", buffer);
      }
    }
    if (fclose(file_ptr) == EOF) {
      perror("Error closing file");
      return 1;
    }
  } else {
    char buffer[256];
    const char *pattern = argv[1];
    while (fgets(buffer, 256, stdin) != NULL) {
      if (strstr(buffer, pattern) != NULL) {
        printf("%s", buffer);
      }
    }
  }
  return 0;
}