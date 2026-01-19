#ifndef FILEIO_H
#define FILEIO_H

#include "database.h"

// Загрузка из файла в массив
int load_employees(Employee* arr, int* size, const char* filename);

// Сохранение массива в файл
int save_employees(Employee* arr, int size, const char* filename);

// Чтение из файла (задание 3)
int input_file(const char* filename, Employee* arr);

// Запись в файл (задание 3)
int output_file(const char* filename, Employee* arr, int n);

#endif // FILEIO_H
