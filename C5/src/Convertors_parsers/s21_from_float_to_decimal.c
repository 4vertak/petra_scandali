#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_convertors_error_code error_code = S21_CONVERTORS_OK;
  if (!dst) {
    error_code = S21_CONVERTORS_ERROR;
  } else if (src == 0.0) {
    error_code = S21_CONVERTORS_OK;
    *dst = init_decimal_null();
    if (signbit(src) != 0) {
      set_sign(dst, 1);
    }
  } else if (isinf(src) || isnan(src)) {
    error_code = S21_CONVERTORS_ERROR;
    if (signbit(src) != 0) {
      set_sign(dst, 1);
    }
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    error_code = S21_CONVERTORS_ERROR;
    if (signbit(src) != 0) {
      set_sign(dst, 1);
    }
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    error_code = S21_CONVERTORS_ERROR;
    *dst = init_decimal_null();
  } else {
    *dst = init_decimal_null();
    s21_decimal result;
    char flt[64];
    sprintf(flt, "%.6E", fabsf(src));
    int exp = 0;
    char *ptr = flt;
    while (*ptr) {
      if (*ptr == 'E') {
        ++ptr;
        exp = strtol(ptr, NULL, 10);
        break;
      }
      ++ptr;
    }
    if (exp <= -23) {
      int float_precision = exp + 28;
      sprintf(flt, "%.*E", float_precision, fabsf(src));
    }
    result = s21_float_string_to_decimal(flt);
    if (signbit(src) != 0) {
      set_sign(&result, 1);
    }
    *dst = result;
  }
  return error_code;
}

s21_decimal s21_float_string_to_decimal(char *str) {
  int digits_counter = 6;
  s21_decimal result = init_decimal_null();
  char *ptr = str;
  int exp = 0;
  char *ptr_s = str;
  while (*ptr_s) {
    if (*ptr_s == 'E') {
      ++ptr_s;
      exp = strtol(ptr_s, NULL, 10);
      break;
    }
    ++ptr_s;
  }
  while (*ptr) {
    if (*ptr == '.') {
      ++ptr;
      continue;
    } else if (*ptr >= '0' && *ptr <= '9') {
      s21_decimal tmp = init_decimal_null();
      s21_mul(decimal_get_char(*ptr), all_ten_pows[digits_counter], &tmp);
      s21_add(result, tmp, &result);
      --digits_counter;
      ++ptr;
    } else {
      break;
    }
  }
  exp = exp - 6;
  if (exp > 0) {
    s21_mul(result, all_ten_pows[exp], &result);
  } else if (exp < 0) {
    if (exp < -28) {
      s21_div(result, all_ten_pows[28], &result);
      exp += 28;
    }
    s21_div(result, all_ten_pows[-exp], &result);
  }
  return result;
}