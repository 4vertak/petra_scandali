#include "../s21_decimal.h"

int valid_decimal(s21_decimal value) {
  int error_code = 1;
  decimal_bit_3 bits_3;
  bits_3.part_decimal = value.bits[3];
  if (bits_3.parts.empty_bits_24_30 != 0 || bits_3.parts.empty_bits_0_15 != 0) {
    error_code = 0;
  } else {
    int exp = get_exp(value);
    if (exp < 0 || exp > 28) {
      error_code = 0;
    }
  }
  return error_code;
}

int get_sign(s21_decimal value) {
  decimal_bit_3 bits_3;
  bits_3.part_decimal = value.bits[3];
  return bits_3.parts.sign;
}

int get_exp(s21_decimal value) {
  decimal_bit_3 bits_3;
  bits_3.part_decimal = value.bits[3];
  return bits_3.parts.power;
}

void set_sign(s21_decimal *value, int sign) {
  decimal_bit_3 bits_3;
  bits_3.part_decimal = value->bits[3];
  if (sign == 0) {
    bits_3.parts.sign = 0;
  } else {
    bits_3.parts.sign = 1;
  }
  value->bits[3] = bits_3.part_decimal;
}

void set_exp(s21_decimal *value, int exp) {
  decimal_bit_3 bits_3;
  bits_3.part_decimal = value->bits[3];
  bits_3.parts.power = exp;
  value->bits[3] = bits_3.part_decimal;
}

void normalized_decimal(s21_decimal value_1, s21_decimal value_2,
                        s21_big_decimal *big_value_1,
                        s21_big_decimal *big_value_2) {
  int exp_value_1 = get_exp(value_1);
  int exp_value_2 = get_exp(value_2);
  s21_decimal tmp1 = value_1;
  s21_decimal tmp2 = value_2;

  tmp1.bits[3] = 0;
  tmp2.bits[3] = 0;

  if (exp_value_1 > exp_value_2) {
    *big_value_1 = set_big_decimal(tmp1);
    *big_value_2 =
        decimal_bin_mul(tmp2, all_ten_pows[exp_value_1 - exp_value_2]);
  } else if (exp_value_1 < exp_value_2) {
    *big_value_1 =
        decimal_bin_mul(tmp1, all_ten_pows[exp_value_2 - exp_value_1]);
    *big_value_2 = set_big_decimal(tmp2);
  } else {
    *big_value_1 = set_big_decimal(tmp1);
    *big_value_2 = set_big_decimal(tmp2);
  }
}

s21_decimal s21_abs(s21_decimal value_1) {
  s21_decimal result = value_1;
  set_sign(&result, 0);
  return result;
}

int handle_div(s21_big_decimal big_value_2, s21_big_decimal res,
               s21_big_decimal remainder, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  int exp_value_1 = div_exp(&res, big_value_2, &remainder);
  s21_big_decimal tmp_res = set_big_decimal(init_decimal_null());
  int exp_value_2 = div_exp(&tmp_res, big_value_2, &remainder);
  set_exp(&tmp_res.decimals[0], exp_value_2);
  s21_decimal decimal_float_0_5 = {{0x5, 0x0, 0x0, 0x10000}};
  if (s21_is_equal(tmp_res.decimals[0], decimal_float_0_5)) {
    if (!check_zero(remainder.decimals[0]) ||
        !check_zero(remainder.decimals[1])) {
      s21_decimal min_decimal = {{0x1, 0x0, 0x0, 0x1C0000}};
      s21_add(tmp_res.decimals[0], min_decimal, &tmp_res.decimals[0]);
    }
  }
  s21_decimal decimal_digit_one = init_decimal_null();
  decimal_digit_one.bits[0] = 1;

  if (s21_is_equal(tmp_res.decimals[0], decimal_float_0_5)) {
    if (((res.decimals[0].bits[0] & 1) != 1)) {
      res.decimals[0] = res.decimals[0];
    } else {
      res.decimals[0] = decimal_bin_add(res.decimals[0], decimal_digit_one);
    }
  } else if (s21_is_greater(tmp_res.decimals[0], decimal_float_0_5)) {
    res.decimals[0] = decimal_bin_add(res.decimals[0], decimal_digit_one);
  } else {
    res.decimals[0] = res.decimals[0];
  }

  set_exp(&res.decimals[0], exp_value_1);
  if (!check_zero(res.decimals[1]) || !valid_decimal(res.decimals[0])) {
    error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
  } else {
    *result = res.decimals[0];
  }

  return error_code;
}

int div_exp(s21_big_decimal *res, s21_big_decimal big_value_2,
            s21_big_decimal *remainder) {
  int exp = 0;
  s21_big_decimal number = *res;
  s21_big_decimal tmp;
  s21_big_decimal tmp_remainder = *remainder;
  while ((!check_zero((*remainder).decimals[0]) ||
          !check_zero((*remainder).decimals[1])) &&
         exp < 28) {
    s21_big_decimal number_stored = number;
    s21_big_decimal remainder_stored = tmp_remainder;
    s21_decimal decimal_num_ten = init_decimal_null();
    decimal_num_ten.bits[0] = 10;
    number = big_decimal_bin_mul(number, decimal_num_ten);
    tmp_remainder = big_decimal_bin_mul(tmp_remainder, decimal_num_ten);
    tmp = big_decimal_bin_div(tmp_remainder, big_value_2, &tmp_remainder);
    number = big_decimal_add(number, tmp);
    if (!valid_decimal(number.decimals[0])) {
      number = number_stored;
      tmp_remainder = remainder_stored;
      break;
    }
    ++exp;
  }
  *res = number;
  *remainder = tmp_remainder;
  return exp;
}

int handle_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  int exp_value_1 = get_exp(value_1);
  int exp_value_2 = get_exp(value_2);
  value_1.bits[3] = 0;
  value_2.bits[3] = 0;
  s21_big_decimal res = decimal_bin_mul(value_1, value_2);
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

  int res_exp = exp_value_1 + exp_value_2 - count_shift;
  if (res_exp < 0) {
    error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
  } else {
    s21_decimal decimal_num_ten = init_decimal_null();
    decimal_num_ten.bits[0] = 10;
    while (count_shift > 28) {
      res = big_decimal_bin_div(res, set_big_decimal(decimal_num_ten), NULL);
      --count_shift;
    }
    if (res_exp > 28) {
      s21_big_decimal tmp = res;
      int tmp_exp = res_exp;
      while (tmp_exp > 28) {
        tmp = big_decimal_bin_div(tmp, set_big_decimal(decimal_num_ten), NULL);
        --tmp_exp;
      }
      count_shift = res_exp - tmp_exp + count_shift;
      res_exp = tmp_exp;
    }
    s21_big_decimal remainder = set_big_decimal(init_decimal_null());
    s21_big_decimal expten = set_big_decimal(all_ten_pows[count_shift]);
    res = big_decimal_bin_div(res, expten, &remainder);
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

    set_exp(&res.decimals[0], res_exp);
    if (!check_zero(res.decimals[1]) || !valid_decimal(res.decimals[0])) {
      error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
    } else {
      *result = res.decimals[0];
    }
  }
  return error_code;
}

int handle_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_arithmetic_error_code error_code = S21_ARITHMETIC_OK;
  s21_big_decimal big_value_1;
  s21_big_decimal big_value_2;
  int exp_value_1 = get_exp(value_1);
  int exp_value_2 = get_exp(value_2);
  int max_exp = (exp_value_1 > exp_value_2) ? exp_value_1 : exp_value_2;
  normalized_decimal(value_1, value_2, &big_value_1, &big_value_2);
  s21_big_decimal res = big_decimal_bin_sub(big_value_1, big_value_2);
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
  int res_exp = max_exp - count_shift;
  if (res_exp < 0) {
    error_code = S21_ARITHMETIC_IS_TOO_LARGE_OR_EQUAL_INF;
  } else {
    s21_big_decimal remainder = set_big_decimal(init_decimal_null());
    s21_big_decimal expten = set_big_decimal(all_ten_pows[count_shift]);
    res = big_decimal_bin_div(res, expten, &remainder);
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

    set_exp(&res.decimals[0], res_exp);
    *result = res.decimals[0];
  }
  return error_code;
}

int handle_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_comparison_return_value error_code = S21_COMPARISON_FALSE;
  s21_decimal tmp1 = value_1;
  s21_decimal tmp2 = value_2;
  s21_big_decimal tmp1l;
  s21_big_decimal tmp2l;
  normalized_decimal(tmp1, tmp2, &tmp1l, &tmp2l);
  int compare = decimal_compare(tmp1l.decimals[1], tmp2l.decimals[1]);
  if (compare == 0) {
    compare = decimal_compare(tmp1l.decimals[0], tmp2l.decimals[0]);
  }

  error_code = (compare == -1) ? S21_COMPARISON_TRUE : S21_COMPARISON_FALSE;

  return error_code;
}

s21_decimal decimal_get_char(char c) {
  s21_decimal result;
  s21_decimal decimal_digit_one = init_decimal_null();
  decimal_digit_one.bits[0] = 1;
  switch (c) {
    case '0':
      result = init_decimal_null();
      break;
    case '1':
      result = decimal_digit_one;
      break;
    case '2':
      s21_from_int_to_decimal(2, &result);
      break;
    case '3':
      s21_from_int_to_decimal(3, &result);
      break;
    case '4':
      s21_from_int_to_decimal(4, &result);
      break;
    case '5':
      s21_from_int_to_decimal(5, &result);
      break;
    case '6':
      s21_from_int_to_decimal(6, &result);
      break;
    case '7':
      s21_from_int_to_decimal(7, &result);
      break;
    case '8':
      s21_from_int_to_decimal(8, &result);
      break;
    case '9':
      s21_from_int_to_decimal(9, &result);
      break;
  }
  return result;
}

int get_bit(s21_decimal decimal, int index) {
  return !!(decimal.bits[index / MAX_BLOCK_BITS] &
            (1U << index % MAX_BLOCK_BITS));
}

s21_decimal set_bit(s21_decimal decimal, int index) {
  decimal.bits[index / MAX_BLOCK_BITS] =
      decimal.bits[index / MAX_BLOCK_BITS] | (1U << (index % MAX_BLOCK_BITS));

  return decimal;
}

int decimal_get_bit(s21_decimal decimal) {
  int result = -1;
  for (int i = MAX_BITS - 1; i >= 0; i--) {
    if (get_bit(decimal, i)) {
      result = i;
      break;
    }
  }
  return result;
}

s21_decimal decimal_bin_add(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal result = value_1;
  s21_decimal tmp = value_2;

  while (!check_zero(tmp)) {
    s21_decimal overflow_bits = init_decimal_null();
    for (int j = 0; j < 4; j++)
      overflow_bits.bits[j] = result.bits[j] & tmp.bits[j];
    overflow_bits = decimal_shift_left(overflow_bits, 1);
    s21_decimal temp_result = init_decimal_null();
    for (int i = 0; i < 4; i++)
      temp_result.bits[i] = result.bits[i] ^ tmp.bits[i];
    result = temp_result;
    tmp = overflow_bits;
  }

  return result;
}

s21_big_decimal big_decimal_add(s21_big_decimal value_1,
                                s21_big_decimal value_2) {
  s21_big_decimal result = value_1;
  s21_big_decimal tmp = value_2;

  while (!check_zero(tmp.decimals[0]) || !check_zero(tmp.decimals[1])) {
    s21_big_decimal overflow_bits;
    for (int i = 0; i < 2; i++) {
      overflow_bits.decimals[i] = init_decimal_null();
      for (int j = 0; j < 4; j++)
        overflow_bits.decimals[i].bits[j] =
            result.decimals[i].bits[j] & tmp.decimals[i].bits[j];
    }
    overflow_bits = big_decimal_shift_left(overflow_bits, 1);

    s21_decimal temp_result = init_decimal_null();
    for (int i = 0; i < 4; i++)
      temp_result.bits[i] =
          result.decimals[0].bits[i] ^ tmp.decimals[0].bits[i];
    result.decimals[0] = temp_result;
    temp_result = init_decimal_null();
    for (int i = 0; i < 4; i++)
      temp_result.bits[i] =
          result.decimals[1].bits[i] ^ tmp.decimals[1].bits[i];
    result.decimals[1] = temp_result;
    tmp = overflow_bits;
  }
  return result;
}

int check_zero(s21_decimal decimal) {
  int error_error_code = (decimal.bits[0] == 0 && decimal.bits[1] == 0 &&
                          decimal.bits[2] == 0 && decimal.bits[3] == 0)
                             ? 1
                             : 0;

  return error_error_code;
}

int decimal_compare(s21_decimal d1, s21_decimal d2) {
  int result = 0;
  for (int i = MAX_BITS - 1; i >= 0; i--) {
    int b1 = get_bit(d1, i);
    int b2 = get_bit(d2, i);
    if (b1 == 0 && b2 != 0) {
      result = -1;
    }
    if (b1 != 0 && b2 == 0) {
      result = 1;
    }
    if (result != 0) {
      break;
    }
  }
  return result;
}

s21_decimal decimal_bin_div(s21_decimal value_1, s21_decimal value_2,
                            s21_decimal *remainder) {
  s21_decimal result;
  s21_decimal partial_remainder = init_decimal_null();
  s21_decimal koef = init_decimal_null();

  if (check_zero(value_1)) {
    koef = init_decimal_null();
    partial_remainder = init_decimal_null();
  } else if (decimal_compare(value_1, value_2) == -1) {
    koef = init_decimal_null();
    partial_remainder = value_1;
  } else {
    int left1 = decimal_get_bit(value_1);
    int left2 = decimal_get_bit(value_2);
    int count_shift = left1 - left2;
    s21_decimal shifted_divisor = decimal_shift_left(value_2, count_shift);
    s21_decimal dividend = value_1;
    int need_subtraction = 1;
    while (count_shift >= 0) {
      if (need_subtraction == 1) {
        partial_remainder = decimal_bin_sub(dividend, shifted_divisor);
      } else {
        partial_remainder = decimal_bin_add(dividend, shifted_divisor);
      }
      koef = decimal_shift_left(koef, 1);
      if (get_bit(partial_remainder, MAX_BITS - 1) == 0) {
        koef = set_bit(koef, 0);
      }
      dividend = decimal_shift_left(partial_remainder, 1);
      if (get_bit(partial_remainder, MAX_BITS - 1) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --count_shift;
    }
    if (get_bit(partial_remainder, MAX_BITS - 1)) {
      partial_remainder = decimal_bin_add(partial_remainder, shifted_divisor);
    }
    partial_remainder = decimal_shift_right(partial_remainder, left1 - left2);
  }

  result = koef;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }

  return result;
}

s21_big_decimal big_decimal_bin_div(s21_big_decimal value_1,
                                    s21_big_decimal value_2,
                                    s21_big_decimal *remainder) {
  s21_big_decimal result;
  s21_big_decimal partial_remainder = set_big_decimal(init_decimal_null());
  s21_big_decimal koef = set_big_decimal(init_decimal_null());
  int compare = decimal_compare(value_1.decimals[1], value_2.decimals[1]);
  if (compare == 0) {
    compare = decimal_compare(value_1.decimals[0], value_2.decimals[0]);
  }
  if (check_zero(value_1.decimals[0]) && check_zero(value_1.decimals[1])) {
    koef = set_big_decimal(init_decimal_null());
    partial_remainder = set_big_decimal(init_decimal_null());
  } else if (compare == -1) {
    koef = set_big_decimal(init_decimal_null());
    partial_remainder = value_1;
  } else {
    int left1 = decimal_get_bit(value_1.decimals[1]);
    if (left1 == -1) {
      left1 = decimal_get_bit(value_1.decimals[0]);
    } else {
      left1 = MAX_BITS + left1;
    }
    int left2 = decimal_get_bit(value_2.decimals[1]);
    if (left2 == -1) {
      left2 = decimal_get_bit(value_2.decimals[0]);
    } else {
      left2 = MAX_BITS + left2;
    }
    int count_shift = left1 - left2;
    s21_big_decimal shifted_divisor =
        big_decimal_shift_left(value_2, count_shift);
    s21_big_decimal dividend = value_1;
    int need_subtraction = 1;
    while (count_shift >= 0) {
      if (need_subtraction == 1) {
        partial_remainder = big_decimal_bin_sub(dividend, shifted_divisor);
      } else {
        partial_remainder = big_decimal_add(dividend, shifted_divisor);
      }
      koef = big_decimal_shift_left(koef, 1);
      if (get_bit(partial_remainder.decimals[1], MAX_BITS - 1) == 0) {
        koef.decimals[0] = set_bit(koef.decimals[0], 0);
      }
      dividend = big_decimal_shift_left(partial_remainder, 1);
      if (get_bit(partial_remainder.decimals[1], MAX_BITS - 1) == 0) {
        need_subtraction = 1;
      } else {
        need_subtraction = 0;
      }
      --count_shift;
    }
    if (get_bit(partial_remainder.decimals[1], MAX_BITS - 1)) {
      partial_remainder = big_decimal_add(partial_remainder, shifted_divisor);
    }
    partial_remainder =
        big_decimal_shift_right(partial_remainder, left1 - left2);
  }
  result = koef;
  if (remainder != NULL) {
    *remainder = partial_remainder;
  }
  return result;
}

s21_big_decimal decimal_bin_mul(s21_decimal value_1, s21_decimal value_2) {
  s21_big_decimal big_decimal_result = set_big_decimal(init_decimal_null());
  s21_big_decimal big_decimal_tmp1 = set_big_decimal(value_1);
  int max_bit = decimal_get_bit(value_2);
  for (int i = 0; i <= max_bit; i++) {
    if (get_bit(value_2, i) != 0) {
      big_decimal_result =
          big_decimal_add(big_decimal_result, big_decimal_tmp1);
    }
    big_decimal_tmp1 = big_decimal_shift_left(big_decimal_tmp1, 1);
  }
  return big_decimal_result;
}

s21_big_decimal big_decimal_bin_mul(s21_big_decimal value_1,
                                    s21_decimal value_2) {
  s21_big_decimal big_decimal_result = set_big_decimal(init_decimal_null());
  s21_big_decimal big_decimal_tmp1 = value_1;

  int max_bit = decimal_get_bit(value_2);

  for (int i = 0; i <= max_bit; i++) {
    if (get_bit(value_2, i) != 0) {
      big_decimal_result =
          big_decimal_add(big_decimal_result, big_decimal_tmp1);
    }

    big_decimal_tmp1 = big_decimal_shift_left(big_decimal_tmp1, 1);
  }

  return big_decimal_result;
}

s21_decimal decimal_shift_left(s21_decimal decimal, int count_shift) {
  s21_decimal result = decimal;
  while (count_shift > 0) {
    result = decimal_shift_left_one(result);
    --count_shift;
  }
  return result;
}

s21_decimal decimal_shift_right(s21_decimal decimal, int count_shift) {
  s21_decimal result = decimal;
  while (count_shift > 0) {
    result = decimal_shift_right_one(result);
    --count_shift;
  }
  return result;
}

s21_big_decimal big_decimal_shift_left(s21_big_decimal decimal,
                                       int count_shift) {
  s21_big_decimal result = decimal;
  while (count_shift > 0) {
    int b0 = get_bit(result.decimals[0], MAX_BITS - 1);
    result.decimals[0] = decimal_shift_left_one(result.decimals[0]);
    result.decimals[1] = decimal_shift_left_one(result.decimals[1]);
    if (b0) {
      result.decimals[1] = set_bit(result.decimals[1], 0);
    }
    --count_shift;
  }
  return result;
}

s21_big_decimal big_decimal_shift_right(s21_big_decimal decimal,
                                        int count_shift) {
  s21_big_decimal result = decimal;
  while (count_shift > 0) {
    int b1 = get_bit(result.decimals[1], 0);
    result.decimals[0] = decimal_shift_right_one(result.decimals[0]);
    result.decimals[1] = decimal_shift_right_one(result.decimals[1]);
    if (b1) {
      result.decimals[0] = set_bit(result.decimals[0], MAX_BITS - 1);
    }
    --count_shift;
  }
  return result;
}

s21_decimal decimal_shift_left_one(s21_decimal decimal) {
  s21_decimal result = init_decimal_null();
  int bits_0 = 0;
  int bits_1 = 0;
  int bits_2 = 0;

  for (int i = 0; i < 4; i++) {
    int temp_bits = !!(decimal.bits[i] & (1U << (MAX_BLOCK_BITS - 1)));
    if (i == 0)
      bits_0 = temp_bits;
    else if (i == 1)
      bits_1 = temp_bits;
    else if (i == 2)
      bits_2 = temp_bits;
    unsigned int temp_result = decimal.bits[i];
    temp_result = temp_result << 1;
    result.bits[i] = temp_result;
  }

  if (bits_0) result.bits[1] = result.bits[1] | (1U << 0);
  if (bits_1) result.bits[2] = result.bits[2] | (1U << 0);
  if (bits_2) result.bits[3] = result.bits[3] | (1U << 0);

  return result;
}

s21_decimal decimal_shift_right_one(s21_decimal decimal) {
  s21_decimal result = init_decimal_null();

  int b3 = !!(decimal.bits[3] & (1U << 0));
  unsigned int result3 = decimal.bits[3];
  result3 = result3 >> 1;
  result.bits[3] = result3;

  int b2 = !!(decimal.bits[2] & (1U << 0));
  unsigned int result2 = decimal.bits[2];
  result2 = result2 >> 1;
  result.bits[2] = result2;

  int b1 = !!(decimal.bits[1] & (1U << 0));
  unsigned int result1 = decimal.bits[1];
  result1 = result1 >> 1;
  result.bits[1] = result1;

  unsigned int result0 = decimal.bits[0];
  result0 = result0 >> 1;
  result.bits[0] = result0;
  if (b3) {
    result.bits[2] =
        result.bits[2] | (1U << ((MAX_BLOCK_BITS - 1) % MAX_BLOCK_BITS));
  }
  if (b2) {
    result.bits[1] =
        result.bits[1] | (1U << ((MAX_BLOCK_BITS - 1) % MAX_BLOCK_BITS));
  }
  if (b1) {
    result.bits[0] =
        result.bits[0] | (1U << ((MAX_BLOCK_BITS - 1) % MAX_BLOCK_BITS));
  }
  return result;
}

s21_decimal decimal_bin_sub(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal result;
  s21_decimal decimal_digit_one = init_decimal_null();
  decimal_digit_one.bits[0] = 1;
  s21_decimal temp = init_decimal_null();
  for (int i = 0; i < 4; i++) temp.bits[i] = ~value_2.bits[i];
  value_2 = temp;
  value_2 = decimal_bin_add(value_2, decimal_digit_one);
  result = decimal_bin_add(value_1, value_2);

  return result;
}

s21_big_decimal big_decimal_bin_sub(s21_big_decimal value_1,
                                    s21_big_decimal value_2) {
  s21_big_decimal result;
  s21_decimal temp = init_decimal_null();
  for (int i = 0; i < 4; i++) temp.bits[i] = ~value_2.decimals[0].bits[i];
  value_2.decimals[0] = temp;

  temp = init_decimal_null();
  for (int i = 0; i < 4; i++) temp.bits[i] = ~value_2.decimals[1].bits[i];
  value_2.decimals[1] = temp;

  s21_decimal decimal_digit_one = init_decimal_null();
  decimal_digit_one.bits[0] = 1;
  s21_big_decimal one = set_big_decimal(decimal_digit_one);

  value_2 = big_decimal_add(value_2, one);
  result = big_decimal_add(value_1, value_2);

  return result;
}

s21_decimal init_decimal_null(void) {
  s21_decimal result;
  for (int i = 0; i < 4; i++) {
    result.bits[i] = 0;
  }
  return result;
}

s21_big_decimal set_big_decimal(s21_decimal value_1) {
  s21_big_decimal result;
  result.decimals[0] = value_1;
  result.decimals[1] = init_decimal_null();
  return result;
}
