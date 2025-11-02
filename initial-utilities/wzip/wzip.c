#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wzip: file1 [file2 ...]\n");
    return 1;
  }
  int count = 0;
  char last = '\0';
  for (int i = 1; i < argc; i++) {

    FILE *file_ptr = fopen(argv[i], "r");
    if (file_ptr == NULL) {
      printf("wzip: cannot open file\n");
      return 1;
    }

    char buffer[256];
    while (fgets(buffer, 256, file_ptr) != NULL) {

      for (int j = 0; buffer[j] != '\0'; j++) {
        char cur = buffer[j];
        if (count == 0) {
          count++;
          last = buffer[j];
        } else {
          if (cur == last) {
            count++;
          } else {
            int *c = &count;
            char *b = &last;
            fwrite(c, sizeof(int), 1, stdout);
            fwrite(b, sizeof(char), 1, stdout);
            last = cur;
            count = 1;
          }
        }
      }
    }
    fclose(file_ptr);
  }
  if (count > 0) {
    int *c = &count;
    char *b = &last;
    fwrite(c, sizeof(int), 1, stdout);
    fwrite(b, sizeof(char), 1, stdout);
  }
}