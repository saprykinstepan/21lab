#ifndef FILEIO_H
#define FILEIO_H

#include "database.h"

// Загрузка с тестовыми данными
int load_from_file(Employee* arr, int* size, char* filename);

// Сохранение всего массива
int save_to_file(Employee* arr, int size, char* filename);

// Чтение файла без тестовых данных
int input_file(char* filename, Employee* arr);

// Запись в файл
int output_file(char* filename, Employee* arr, int n);

#endif
