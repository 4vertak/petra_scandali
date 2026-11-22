#include <limits.h>

#include "s21_string.h"

char *s21_strerror(int errnum) {
#if defined(__APPLE__)
  static const char *const messages[] = {MACOS_ERRORS};
  const char *unknown = "Unknown error: %d";
#elif defined(__linux__)
  static const char *const messages[] = {LINUX_ERRORS};
  const char *unknown = "Unknown error %d";
#else
  const char *unknown = "Unknown error %d";
#endif
#if defined(__APPLE__) || defined(__linux__)
  if (errnum >= 0 && (size_t)errnum < sizeof(messages) / sizeof(*messages))
    return (char *)messages[errnum];
#endif
  static _Thread_local char
      buffer[sizeof("Unknown error: -") + sizeof(int) * CHAR_BIT];
  s21_sprintf(buffer, unknown, errnum);
  return buffer;
}
