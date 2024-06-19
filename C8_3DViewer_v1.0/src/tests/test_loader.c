#include "./test.h"

START_TEST(test_loader_01) {
  char file_name[] = "./test_object.obj";
  data_t data = {0};
  double test_e[] = {0, 6, 6, 4, 4, 0, 0, 2, 2, 6, 6, 0, 0, 3, 3,
                     2, 2, 0, 0, 1, 1, 3, 3, 0, 2, 7, 7, 6, 6, 2,
                     2, 3, 3, 7, 7, 2, 4, 6, 6, 7, 7, 4, 4, 7, 7,
                     5, 5, 4, 0, 4, 4, 5, 5, 0, 0, 5, 5, 1, 1, 0};
  double test_v[] = {-0.5, -0.5, -0.5, -0.5, -0.5, 0.5,  -0.5, 0.5,
                     -0.5, -0.5, 0.5,  0.5,  0.5,  -0.5, -0.5, 0.5,
                     -0.5, 0.5,  0.5,  0.5,  -0.5, 0.5,  0.5,  0.5};

  int res = loader(&data, file_name);
  ck_assert_int_eq(data.count_vertex, 8);
  ck_assert_int_eq(data.count_edges, 30);

  for (int i = 0; i < data.count_edges * 2; i++) {
    printf("%f == %d\n", test_e[i], data.edges_points[i]);
    ck_assert_int_eq(test_e[i], data.edges_points[i]);
  }
  printf("\n");
  for (int i = 0; i < data.count_vertex * 3; i++) {
    int test_res = test_v[i] - data.vertex[i];
    printf("%f == %f\n", test_v[i], data.vertex[i]);
    ck_assert_int_eq(test_res, 0);
  }
  free(data.vertex);
  free(data.edges_points);
}
END_TEST

Suite *test_loader(void) {
  Suite *s = suite_create("\n\033[37;1m==========| LOADER |=========\033[0m");
  TCase *tc = tcase_create("tc_loader");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_loader_01);
  return s;
}