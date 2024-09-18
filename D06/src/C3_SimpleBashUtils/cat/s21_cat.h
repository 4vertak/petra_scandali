#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#define _GNU_SOURCE

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Flags {
  int b, e, v, n, s, t;
} Flags;

void flags_parser(char flag, Flags* flags);
void init_flags(int argc, char** argv, Flags* flags);
void file_processing(int argc, char** argv, Flags* flags);

#endif  // SRC_GREP_S21_GREP_H_
