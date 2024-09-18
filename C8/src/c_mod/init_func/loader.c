#include "../loader.h"

/**
 * @brief Главная функция загрузки данных из файла
 * @param data Указатель на структуру данных
 * @param file_name Имя файла для загрузки данных
 * @return Код ошибки: 0 - успех, 1 - ошибка
 */
int loader(data_t* data, const char* file_name) {
  int error_code = 0;
  if (!file_name || !data) return 1;

  FILE* f = fopen(file_name, "r");
  if (f == NULL) {
    error_code = 1;
  } else {
    calc_count(f, data);
    error_code = handle_data(f, data);
    fclose(f);
  }
  if (error_code != 0) free_memory_data(data);
  return error_code;
}