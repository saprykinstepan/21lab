#ifndef FILEIO_H
#define FILEIO_H

#include "database.h"

// Функции работы с файлами
int load_employees(Employee* arr, int* size, const char* filename);
int save_employees(Employee* arr, int size, const char* filename);
int input_file(const char* filename, Employee* arr);
int output_file(const char* filename, Employee* arr, int n);

#endif // FILEIO_H
