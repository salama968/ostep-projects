#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wunzip: file1 [file2 ...]\n");
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    FILE *file_ptr = fopen(argv[i], "r");
    if (file_ptr == NULL) {
      printf("wunzip: cannot open file\n");
      return 1;
    }
    while (1) {
      int count;
      size_t read_count = fread(&count, sizeof(int), 1, file_ptr);
      if (read_count != 1) {
        break;
      }
      char ch;
      size_t read_char = fread(&ch, sizeof(char), 1, file_ptr);
      if (read_char != 1) {
        break;
      }

      for (int j = 0; j < count; j++) {
        printf("%c", ch);
      }
    }

    fclose(file_ptr);
  }
}