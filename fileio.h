#ifndef FILEIO_H
#define FILEIO_H

#include "database.h"

// Загрузка с созданием тестовых данных
int load_from_file(Employee* arr, int* size, char* filename);

// Сохранение всего массива
int save_to_file(Employee* arr, int size, char* filename);

// Простое чтение файла
int input_file(char* filename, Employee* arr);

// Простая запись в файл
int output_file(char* filename, Employee* arr, int n);

#endif
