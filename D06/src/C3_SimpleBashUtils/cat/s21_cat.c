#include "../cat/s21_cat.h"

int main(int argc, char** argv) {
  Flags flags = {0};
  init_flags(argc, argv, &flags);
  file_processing(argc - optind, argv + optind, &flags);
  return 0;
}
void flags_parser(char flag, Flags* flags) {
  switch (flag) {
    case 'A':
      flags->v = 1;
      flags->e = 1;
      flags->t = 1;
      break;
    case 'b':
      flags->b = 1;
      break;
    case 'e':
      flags->v = 1;
      flags->e = 1;
      break;
    case 'E':
      flags->e = 1;
      break;
    case 'n':
      flags->n = 1;
      break;
    case 's':
      flags->s = 1;
      break;
    case 't':
      flags->v = 1;
      flags->t = 1;
      break;
    case 'T':
      flags->t = 1;
      break;
    case 'v':
      flags->v = 1;
      break;
    case 0:
      fprintf(stderr,
              "Usage: cat [OPTION]... [FILE]...\n"
              "Concatenate FILE(s) to standard output.\n");
      exit(1);
      break;
    case '?':
    default:
      fprintf(stderr, "Try 'cat --help' for more information.\n");
      exit(1);
  }
}

void init_flags(int argc, char** argv, Flags* flags) {
  struct option LONG_FLAGS[] = {{"show-all", 0, NULL, 'A'},
                                {"number-nonblank", 0, NULL, 'b'},
                                {"show-ends", 0, NULL, 'E'},
                                {"number", 0, NULL, 'n'},
                                {"squeeze-blank", 0, NULL, 's'},
                                {"show-tabs", 0, NULL, 'T'},
                                {"show-nonprinting", 0, NULL, 'v'},
                                {"help", 0, NULL, 0},
                                {NULL, 0, NULL, 0}};
  int long_flag_index = 0;
  char curr_flag =
      getopt_long(argc, argv, "AbevEnstT", LONG_FLAGS, &long_flag_index);
  while (curr_flag != -1) {
    flags_parser(curr_flag, flags);
    curr_flag =
        getopt_long(argc, argv, "AbevEnstT", LONG_FLAGS, &long_flag_index);
  }
  if (flags->b) {
    flags->n = 0;
  }
}

void file_processing(int argc, char** argv, Flags* flags) {
  FILE* file = NULL;
  for (file = NULL; argc--; ++argv) {
    file = fopen(*argv, "r");
    if (file == NULL) fprintf(stderr, "%s: No such file or directory\n", *argv);
    static char previous_char = '\n';
    static size_t lfd_count = 1;
    char current_char = fgetc(file);
    while (!feof(file)) {
      if (flags->s) {
        if (current_char == '\n')
          lfd_count += 1;
        else
          lfd_count = 0;
      }
      if (current_char != '\n' || lfd_count <= 2) {
        static size_t line_count = 0;
        if (flags->b && previous_char == '\n' && current_char != '\n') {
          fprintf(stdout, "%6zu\t", ++line_count);
        } else if (flags->n && previous_char == '\n') {
          fprintf(stdout, "%6zu\t", ++line_count);
        }
        if (flags->e && current_char == '\n') fputc('$', stdout);
        if (isprint(current_char)) {
          fputc(current_char, stdout);
        } else if (current_char == '\t') {
          if (flags->t) {
            fputc('^', stdout);
            fputc('\t' + 64, stdout);
          } else {
            fputc('\t', stdout);
          }
        } else if (current_char == '\n') {
          fputc('\n', stdout);
        } else if (iscntrl(current_char)) {
          if (flags->v) {
            fputc('^', stdout);
            if (current_char == 127) {
              fputc(current_char - 64, stdout);
            } else {
              fputc(current_char + 64, stdout);
            }
          } else
            fputc(current_char, stdout);
        } else {
          if (flags->v) {
            char meta_symbol = (signed char)current_char + 127 + 1;
            fputc('M', stdout);
            fputc('-', stdout);
            if (isprint(meta_symbol)) {
              fputc(meta_symbol, stdout);
            } else {
              fputc('^', stdout);
              if (meta_symbol == 127) {
                fputc(meta_symbol - 64, stdout);
              } else {
                fputc(meta_symbol + 64, stdout);
              }
            }
          } else
            fputc(current_char, stdout);
        }
      }
      previous_char = current_char;
      current_char = fgetc(file);
    }
    fflush(stdout);
    fclose(file);
  }
}