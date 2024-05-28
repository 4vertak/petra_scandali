#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  if (!valid_decimal(value_1) || !valid_decimal(value_2)) {
    error_code = S21_ARITHMETIC_ERROR;
  } else if (result) {
    *result = init_decimal_null();
    s21_decimal res = init_decimal_null();
    int sign1 = get_sign(value_1);
    int sign2 = get_sign(value_2);
    if (sign1 == 0 && sign2 == 0) {
      error_code = handle_add(value_1, value_2, &res);
    } else if (sign1 == 0 && sign2 == 1) {
      error_code = s21_sub(value_1, s21_abs(value_2), &res);
    } else if (sign1 == 1 && sign2 == 0) {
      error_code = s21_sub(s21_abs(value_1), value_2, &res);
      s21_negate(res, &res);
    } else if (sign1 == 1 && sign2 == 1) {
      error_code = handle_add(s21_abs(value_1), s21_abs(value_2), &res);

      s21_negate(res, &res);
    }
    if (get_sign(res) == 1 &&
        error_code == S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF) {
      error_code = S21_ARITHMETIC_IS_TOO_SMALL_OR_EQUAL_NEG_INF;
    }
    *result = res;

  } else {
    error_code = S21_ARITHMETIC_ERROR;
  }
  return error_code;
}

int handle_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  s21_decimal decimal_num_ten = init_decimal_null();
  decimal_num_ten.bits[0] = 10;
  int exp_value_1 = get_exp(value_1);
  int exp_value_2 = get_exp(value_2);
  int max_exp_value = (exp_value_1 > exp_value_2) ? exp_value_1 : exp_value_2;

  normalized_decimal(value_1, value_2, &big_value_1, &big_value_2);
  s21_big_decimal res = big_decimal_add(big_value_1, big_value_2);
  int count_shift = 0;
  if (!(check_zero(res.decimals[0]) && check_zero(res.decimals[1]))) {
    s21_decimal decimal_max_value = MAX_DEC;
    s21_big_decimal max = set_big_decimal(decimal_max_value);
    s21_big_decimal koef = big_decimal_bin_div(res, max, NULL);
    while (1) {
      int compare =
          decimal_compare(koef.decimals[0], all_ten_pows[count_shift]);
      if (compare == -1 || compare == 0) {
        break;
      }
      ++count_shift;
    }
    s21_big_decimal tmp = big_decimal_bin_div(
        res, set_big_decimal(all_ten_pows[count_shift]), NULL);
    if (!check_zero(tmp.decimals[1]) || tmp.decimals[0].bits[3] != 0) {
      ++count_shift;
    }
  }

  int res_power = max_exp_value - count_shift;

  if (res_power < 0) {
    error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
  } else {
    while (count_shift > 28) {
      res = big_decimal_bin_div(res, set_big_decimal(decimal_num_ten), NULL);
      --count_shift;
    }
    s21_big_decimal remainder = set_big_decimal(init_decimal_null());

    s21_big_decimal powerten = set_big_decimal(all_ten_pows[count_shift]);
    res = big_decimal_bin_div(res, powerten, &remainder);
    set_exp(&remainder.decimals[0], count_shift);
    s21_decimal decimal_float_0_5 = {{0x5, 0x0, 0x0, 0x10000}};
    s21_decimal decimal_digit_one = init_decimal_null();
    decimal_digit_one.bits[0] = 1;
    if (s21_is_equal(remainder.decimals[0], decimal_float_0_5)) {
      if (((res.decimals[0].bits[0] & 1) != 1)) {
        res.decimals[0] = res.decimals[0];
      } else {
        res.decimals[0] = decimal_bin_add(res.decimals[0], decimal_digit_one);
      }
    } else if (s21_is_greater(remainder.decimals[0], decimal_float_0_5)) {
      res.decimals[0] = decimal_bin_add(res.decimals[0], decimal_digit_one);
    } else {
      res.decimals[0] = res.decimals[0];
    }

    set_exp(&res.decimals[0], res_power);
    if (!check_zero(res.decimals[1]) || !valid_decimal(res.decimals[0])) {
      error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
    } else {
      *result = res.decimals[0];
    }
  }

  return error_code;
}
