#include "../grep/s21_grep.h"

int main(int argc, char *argv[]) {
  Flags flags = init_flags(argc, argv);
  processing_file(flags);

  for (int i = 0; i < flags.count_files; i++) {
    free(flags.files[i]);
  }
  if (flags.count_files > 0) {
    free(flags.files);
    flags.count_files = 0;
  }
  for (int i = 0; i < flags.count_patts; i++) {
    free(flags.patterns[i]);
  }
  if (flags.count_patts > 0) {
    free(flags.patterns);
    flags.count_patts = 0;
  }
  return 0;
}

void processing_file(Flags flags) {
  for (int i = 0; i < flags.count_files; i++) {
    int count_matches = search_matches(flags.files[i], flags);
    if (count_matches >= 0) {
      if (flags.c == 1 || flags.l == 1) {
        if (count_matches > 0 || flags.c == 1) {
          if ((flags.count_files > 1 || flags.l == 1) &&
              (flags.h == 0 || (flags.h == 1 && flags.l == 1)) &&
              !(count_matches == 0 && flags.count_files == 1 && flags.c == 1 &&
                flags.l == 1)) {
            if (flags.c == 1 && !(flags.l == 1 && count_matches > 0)) {
              printf("%s:", flags.files[i]);
            } else {
              printf("%s", flags.files[i]);
            }
          }
          if (flags.c == 1 && !(flags.l == 1 && count_matches > 0)) {
            printf("%d", count_matches);
          }
          putchar('\n');
        }
      }
    } else if (count_matches == -2) {
      break;
    }
  }
}

void add_string_patterns(char ***patterns, char *opt_arg, int *count_patterns) {
  int count_n = *count_patterns;
  if (count_n == 0) {
    *patterns = (char **)malloc(sizeof(char *));
    //   if (patterns == NULL) {
    //     fprintf(stderr, "%zu: Memory allocate error.\n", size);
    //     exit(EXIT_SUCCESS);
  } else {
    *patterns = (char **)realloc(*patterns,
                                 (unsigned long)(count_n + 1) * sizeof(char *));
  }
  (*patterns)[count_n] = (char *)malloc(sizeof(char) * (strlen(opt_arg) + 1));
  strcpy((*patterns)[count_n], opt_arg);
  count_n++;
  *count_patterns = count_n;
}

Flags init_flags(int argc, char *argv[]) {
  Flags flags = {0};

  struct option LONG_FLAGS[] = {
      {"regexp", required_argument, NULL, 'e'},  // Шаблон
      {"ignore-case", no_argument, NULL, 'i'},  // Игнорирует различия регистра.
      {"invert-match", no_argument, NULL,
       'v'},  // Инвертирует смысл поиска соответствий.
      {"count", no_argument, NULL,
       'c'},  // Выводит только количество совпадающих строк.
      {"files-with-matches", no_argument, NULL,
       'l'},  // Выводит только совпадающие файлы.
      {"line-number", no_argument, NULL,
       'n'},  // Предваряет каждую строку вывода номером строки из файла ввода.
      // Бонусная часть
      {"no-filename", no_argument, NULL,
       'h'},  // Выводит совпадающие строки, не предваряя их именами файлов.
      {"no-messages", no_argument, NULL,
       's'},  // Подавляет сообщения об ошибках о несуществующих или нечитаемых
              // файлах.
      {"file", required_argument, NULL,
       'f'},  // Получает регулярные выражения из файла.
      {"only-matching", no_argument, NULL,
       'o'},  // Печатает только совпадающие (непустые) части совпавшей строки.
      {"help", no_argument, NULL, 0},
      {NULL, 0, NULL, 0}};
  int res;
  flags.regexp_cflags |= REG_NEWLINE;
  while ((res = getopt_long(argc, argv, SHORT_FLAGS, LONG_FLAGS, NULL)) != -1) {
    switch (res) {
      case 'e':
        add_string_patterns(&flags.patterns, optarg, &flags.count_patts);
        break;
      case 'i':
        flags.i = 1;
        break;
      case 'v':
        flags.v = 1;
        break;
      case 'c':
        flags.c = 1;
        break;
      case 'l':
        flags.l = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 'h':
        flags.h = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 'f':
        flags.f = 1;
        parse_flagF(&flags, optarg);
        break;
      case 'o':
        flags.o = 1;
        break;
      case 0:
        fprintf(stdout,
                "Usage: grep [OPTION]... PATTERNS [FILE]...\n"
                "Search for PATTERNS in each FILE.\n");
        exit(EXIT_SUCCESS);
      case '?':
      default:
        fprintf(stderr,
                "Usage: grep [OPTION]... PATTERNS [FILE]...\n"
                "Try 'grep --help' for more information.\n");
        exit(EXIT_SUCCESS);
    }
  }
  if (optind < argc) {
    while (optind < argc) {
      int count_n = flags.count_files;
      if (count_n == 0) {
        flags.files = (char **)malloc(sizeof(char *));
      } else {
        flags.files = (char **)realloc(
            flags.files, (unsigned long)(count_n + 1) * sizeof(char *));
      }
      (flags.files)[count_n] =
          (char *)malloc(sizeof(char) * (strlen(argv[optind]) + 1));
      strcpy((flags.files)[count_n], argv[optind]);
      count_n++;
      flags.count_files = count_n;
      optind++;
    }
  } else {
    fprintf(stderr,
            "Usage: grep [OPTION]... PATTERNS [FILE]...\n"
            "Try 'grep --help' for more information.\n");
    exit(EXIT_SUCCESS);
  }
  if (flags.count_patts == 0 && flags.f == 0) {
    char *pull_str = NULL;
    if (flags.count_files > 0) {
      pull_str = malloc(sizeof(char *) * (strlen((flags.files)[0]) + 1));
      strcpy(pull_str, (flags.files)[0]);  // +1 байт для '\0'
      for (int i = 0; i < flags.count_files - 1; i++) {
        (flags.files)[i] =
            realloc((flags.files)[i],
                    sizeof(char *) * (strlen((flags.files)[i + 1]) + 1));
        strcpy((flags.files)[i], (flags.files)[i + 1]);
      }
      free((flags.files)[flags.count_files - 1]);
      (flags.count_files)--;
    }
    if (pull_str != NULL) {
      add_string_patterns(&flags.patterns, pull_str, &flags.count_patts);
    }
    free(pull_str);
  }
  if (flags.i == 1) {
    flags.regexp_cflags |= REG_ICASE;
  }
  for (int i = 0; i < flags.count_patts; i++) {
    if (strlen(flags.patterns[i]) == 0) {
      flags.empty_patts = 1;
      break;
    }
  }
  return flags;
}

void parse_flagF(Flags *flags, char *filename) {
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "grep: %s: No such file or directory\n", filename);
    exit(EXIT_SUCCESS);
  } else {
    char *line = NULL;
    size_t len = 0;
    while ((getline(&line, &len, fp)) != -1) {
      size_t line_len = strlen(line);
      if (line[line_len - 1] == '\n') {
        line[line_len - 1] = '\0';
      }
      add_string_patterns(&flags->patterns, line, &flags->count_patts);
    }
    free(line);
    fclose(fp);
  }
}

int search_matches(char *filename, Flags flags) {
  int count_matches = -1;
  FILE *fp = fopen(filename, "r");
  if (!fp) {
    if (flags.s == 0) {
      fprintf(stderr, "grep: %s: No such file or directory\n", filename);
    }
  } else {
    char *line = NULL;
    size_t len = 0;
    unsigned long string_num = 0;
    count_matches = 0;
    while ((getline(&line, &len, fp)) != -1) {
      Samples str;
      if (strlen(line) > 0) {
        if (line[strlen(line) - 1] == '\n') {
          line[strlen(line) - 1] = '\0';
        }
      }
      string_num++;
      str.data = line;
      str.file_name = filename;
      str.num_line = string_num;
      int res = regmatch_func(str, flags);
      if (res > 0) {
        count_matches++;
        if (flags.l == 1) {
          break;
        }
      }
    }
    free(line);
    fclose(fp);
  }
  return count_matches;
}

int regmatch_func(Samples line, Flags flags) {
  int force_quit = 0;
  int count_matches = 0;
  int memory_num = MIN_MEMSIZE;
  regmatch_t *matches;
  regoff_t shift = 0;
  regmatch_t pm;
  int result = 0;
  char *ptr = line.data;
  matches = malloc(sizeof(regmatch_t) * (size_t)(memory_num));
  pm.rm_so = 0;
  pm.rm_eo = (regoff_t)strlen(line.data);
  for (int i = flags.count_patts - 1; i >= 0; i--) {
    if (flags.empty_patts == 1 && flags.o == 0) {
      count_matches++;
      matches[count_matches - 1] = pm;
    } else {
      if (strlen(flags.patterns[i]) == 0) {
        force_quit = 1;
      } else {
        regex_t preg;
        int err;
        err = regcomp(&preg, flags.patterns[i], flags.regexp_cflags);
        if (err != 0) {
          char buff[512];
          regerror(err, &preg, buff, sizeof(buff));
          fprintf(stderr, "s21_grep: %s\n", buff);
        } else {
          int regerr;
          regerr = regexec(&preg, ptr, 1, &pm, 0);
          if (regerr == 0) {
            while (regerr == 0) {
              count_matches++;
              if (count_matches >= memory_num) {
                memory_num += MIN_MEMSIZE;
                matches =
                    realloc(matches, sizeof(regmatch_t) * (size_t)(memory_num));
              }
              pm.rm_so += shift;
              pm.rm_eo += shift;
              matches[count_matches - 1] = pm;
              shift = pm.rm_eo;
              ptr = line.data + shift;
              if (strlen(line.data) == 0) {
                break;
              }
              regerr = regexec(&preg, ptr, 1, &pm, 0);
            }
            force_quit = 1;
          }
        }
        regfree(&preg);
      }
    }
    if (force_quit == 1) {
      break;
    }
  }
  result = (count_matches > 0 && flags.v == 0) ||
           (count_matches == 0 && flags.v == 1);
  if (flags.c == 0 && flags.l == 0) {
    if (result == 1 && !(flags.o == 1 && flags.v == 1)) {
      if (flags.o == 1 && flags.v == 0) {
        for (int i = 0; i < count_matches; i++) {
          if (flags.count_files > 1 && flags.h == 0) {
            printf("%s:", line.file_name);
          }

          if (flags.n == 1) {
            printf("%lu:", line.num_line);
          }
          char *str = line.data + matches[i].rm_so;
          int n = matches[i].rm_eo - matches[i].rm_so;
          for (long long int i = 0; i < n; i++) {
            putchar(str[i]);
          }
          if (!(flags.o == 1 && (matches[i].rm_eo - matches[i].rm_so) == 0)) {
            putchar('\n');
          }
        }
      } else {
        if (flags.count_files > 1 && flags.h == 0) {
          printf("%s:", line.file_name);
        }
        if (flags.n == 1) {
          printf("%lu:", line.num_line);
        }
        printf("%s\n", line.data);
      }
    }
  }
  free(matches);
  return result;
}
