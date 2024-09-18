#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define _GNU_SOURCE

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_MEMSIZE 16
#define SHORT_FLAGS "e:ivclnhsof:"

typedef struct Flags {
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
  char **files;
  int count_files;
  char **patterns;
  int count_patts;
  int empty_patts;
  int regexp_cflags;

} Flags;

typedef struct Samples {
  char *data;
  char *file_name;
  unsigned long num_line;
} Samples;

Flags init_flags(int argc, char *argv[]);
void processing_file(Flags flags);
void parse_flagF(Flags *flags, char *filename);
int search_matches(char *filename, Flags flags);
int regmatch_func(Samples line, Flags flags);
void add_string_patterns(char ***patterns, char *opt_arg, int *count_patterns);

#endif  // SRC_GREP_S21_GREP_H_
