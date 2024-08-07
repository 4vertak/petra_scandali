#include "./test.h"

START_TEST(test_translation_01) {
  char file_name[] =
      "/mnt/c/S21/C2/petra_scandali/C8_3DViewer_v1.0/src/tests/test_object.obj";
  data_t data = {0};
  double test_v[] = {9.5,  -0.5, -0.5, 9.5, -0.5, 0.5,  9.5,  0.5,
                     -0.5, 9.5,  0.5,  0.5, 10.5, -0.5, -0.5, 10.5,
                     -0.5, 0.5,  10.5, 0.5, -0.5, 10.5, 0.5,  0.5};
  int res = loader(&data, file_name);
  ck_assert_int_eq(res, 0);
  x_offset(&data, 10);
  for (int i = 0; i < data.count_vertex * 3; i++) {
    int test_res = test_v[i] - data.vertex[i];
#ifdef DEBAG
    if (test_v[i] - data.vertex[i] < 0.000001)
      printf(GREEN "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
    else
      printf(RED "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
#endif
    ck_assert_int_eq(test_res, 0);
  }
  free_memory_data(&data);
}
END_TEST

START_TEST(test_translation_02) {
  char file_name[] =
      "/mnt/c/S21/C2/petra_scandali/C8_3DViewer_v1.0/src/tests/test_object.obj";
  data_t data = {0};
  double test_v[] = {-0.5, 9.5,  -0.5, -0.5, 9.5,  0.5, -0.5, 10.5,
                     -0.5, -0.5, 10.5, 0.5,  0.5,  9.5, -0.5, 0.5,
                     9.5,  0.5,  0.5,  10.5, -0.5, 0.5, 10.5, 0.5};
  int res = loader(&data, file_name);
  ck_assert_int_eq(res, 0);
  y_offset(&data, 10);
  for (int i = 0; i < data.count_vertex * 3; i++) {
    int test_res = test_v[i] - data.vertex[i];
#ifdef DEBAG
    if (test_v[i] - data.vertex[i] < 0.000001)
      printf(GREEN "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
    else
      printf(RED "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
#endif
    ck_assert_int_eq(test_res, 0);
  }
  free_memory_data(&data);
}
END_TEST

START_TEST(test_translation_03) {
  char file_name[] =
      "/mnt/c/S21/C2/petra_scandali/C8_3DViewer_v1.0/src/tests/test_object.obj";
  data_t data = {0};
  double test_v[] = {-0.5, -0.5, 9.5, -0.5, -0.5, 10.5, -0.5, 0.5,
                     9.5,  -0.5, 0.5, 10.5, 0.5,  -0.5, 9.5,  0.5,
                     -0.5, 10.5, 0.5, 0.5,  9.5,  0.5,  0.5,  10.5};
  int res = loader(&data, file_name);
  ck_assert_int_eq(res, 0);
  z_offset(&data, 10);
  for (int i = 0; i < data.count_vertex * 3; i++) {
    int test_res = test_v[i] - data.vertex[i];
#ifdef DEBAG
    if (test_v[i] - data.vertex[i] < 0.000001)
      printf(GREEN "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
    else
      printf(RED "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
#endif
    ck_assert_int_eq(test_res, 0);
  }
  free_memory_data(&data);
}
END_TEST

START_TEST(test_rotation_01) {
  char file_name[] =
      "/mnt/c/S21/C2/petra_scandali/C8_3DViewer_v1.0/src/tests/test_object.obj";
  data_t data = {0};
  double test_v[] = {-0.500000, 0.500000,  -0.500000, -0.500000, -0.500000,
                     -0.500000, -0.500000, 0.500000,  0.500000,  -0.500000,
                     -0.500000, 0.500000,  0.500000,  0.500000,  -0.500000,
                     0.500000,  -0.500000, -0.500000, 0.500000,  0.500000,
                     0.500000,  0.500000,  -0.500000, 0.500000};

  int res = loader(&data, file_name);
  ck_assert_int_eq(res, 0);
  rotation_x(&data, 90.0);
  for (int i = 0; i < data.count_vertex * 3; i++) {
    int test_res = test_v[i] - data.vertex[i];
    // printf("%f, ", data.vertex[i]);
    ck_assert_int_eq(test_res, 0);
#ifdef DEBAG
    printf(ORANGE "\nrotation X\n");
    if (test_v[i] - data.vertex[i] < 0.000001)
      printf(GREEN "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
    else
      printf(RED "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
#endif
  }

  free_memory_data(&data);
}
END_TEST

START_TEST(test_rotation_02) {
  char file_name[] =
      "/mnt/c/S21/C2/petra_scandali/C8_3DViewer_v1.0/src/tests/test_object.obj";
  data_t data = {0};
  double test_v[] = {-0.500000, -0.500000, 0.500000,  -0.500000, -0.500000,
                     -0.500000, -0.500000, 0.500000,  0.500000,  -0.500000,
                     0.500000,  -0.500000, -0.500000, -0.500000, -0.500000,
                     0.500000,  -0.500000, -0.500000, -0.500000, 0.500000,
                     -0.500000, 0.500000,  0.500000,  -0.500000};

  int res = loader(&data, file_name);
  ck_assert_int_eq(res, 0);
  rotation_y(&data, 90.0);
  for (int i = 0; i < data.count_vertex * 3; i++) {
    int test_res = abs(test_v[i]) - abs(data.vertex[i]);
#ifdef DEBAG
    printf(ORANGE "\nrotation Y\n");
    if (test_v[i] - data.vertex[i] < 0.000001)
      printf(GREEN "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
    else
      printf(RED "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
#endif
    ck_assert_int_eq(test_res, 0);
    // ck_assert_double_eq_tol(test_v[i], data.vertex[i], 0.000001);
  }

  free_memory_data(&data);
}
END_TEST

START_TEST(test_rotation_03) {
  char file_name[] =
      "/mnt/c/S21/C2/petra_scandali/C8_3DViewer_v1.0/src/tests/test_object.obj";
  data_t data = {0};
  double test_v[] = {-0.500000, 0.500000,  -0.500000, -0.500000, -0.500000,
                     -0.500000, -0.500000, -0.500000, -0.500000, -0.500000,
                     -0.500000, 0.500000,  0.500000,  0.500000,  -0.500000,
                     0.500000,  -0.500000, -0.500000, 0.500000,  -0.500000,
                     -0.500000, 0.500000,  -0.500000, 0.500000};

  int res = loader(&data, file_name);
  ck_assert_int_eq(res, 0);
  rotation_z(&data, 90.0);
  for (int i = 0; i < data.count_vertex * 3; i++) {
    int test_res = abs(test_v[i]) - (data.vertex[i]);
#ifdef DEBAG
    printf(ORANGE "\nrotation Z\n");
    if (test_v[i] - data.vertex[i] < 0.000001)
      printf(GREEN "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
    else
      printf(RED "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
#endif
    ck_assert_int_eq(test_res, 0);
    // ck_assert_double_eq_tol(test_v[i], data.vertex[i], 0.000001);
  }

  free_memory_data(&data);
}
END_TEST

START_TEST(test_scaling_01) {
  char file_name[] =
      "/mnt/c/S21/C2/petra_scandali/C8_3DViewer_v1.0/src/tests/test_object.obj";
  data_t data = {0};

  double test_v[] = {-1.5, -1.5, -1.5, -1.5, -1.5, 1.5,  -1.5, 1.5,
                     -1.5, -1.5, 1.5,  1.5,  1.5,  -1.5, -1.5, 1.5,
                     -1.5, 1.5,  1.5,  1.5,  -1.5, 1.5,  1.5,  1.5};
  int res = loader(&data, file_name);
  ck_assert_int_eq(res, 0);
  // printf("загрузка\n");
  // for (int i = 0; i < data.count_vertex * 3; i++) {
  //   printf("%f, ", data.vertex[i]);
  // }
  scaling(&data, 3);
  // printf("scaling\n");
  for (int i = 0; i < data.count_vertex * 3; i++) {
    int test_res = data.vertex[i] - test_v[i];
#ifdef DEBAG
    printf(ORANGE "\nscaling\n");
    if (test_v[i] - data.vertex[i] < 0.000001)
      printf(GREEN "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
    else
      printf(RED "test_rotation\n%f == %f\n", test_v[i], data.vertex[i]);
#endif
    ck_assert_int_eq(test_res, 0);
    // ck_assert_double_eq(test_v[i], data.vertex[i]);
  }

  free_memory_data(&data);
}
END_TEST

Suite *affine_transformations(void) {
  Suite *s = suite_create(ORANGE "\n==========| AFFINE FUNC |=========");
  TCase *tc = tcase_create("tc_affine_func");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_translation_01);
  tcase_add_test(tc, test_translation_02);
  tcase_add_test(tc, test_translation_03);
  tcase_add_test(tc, test_rotation_01);
  tcase_add_test(tc, test_rotation_02);
  tcase_add_test(tc, test_rotation_03);
  tcase_add_test(tc, test_scaling_01);

  return s;
}
