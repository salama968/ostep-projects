#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    exit(0);
  }
  for (int i = 1; i < argc; i++) {

    const char *file = argv[i];

    FILE *file_ptr = fopen(file, "r");

    if (file_ptr == NULL) {
      printf("wcat: cannot open file\n");
      return 1;
    }
    char buffer[256];
    while (fgets(buffer, 256, file_ptr) != NULL) {
      printf("%s", buffer);
    }

    if (fclose(file_ptr) == EOF) {
      perror("Error closing the file");
      return 1;
    }
  }
  return 0;
}