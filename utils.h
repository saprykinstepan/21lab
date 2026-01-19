#ifndef UTILS_H
#define UTILS_H

#include "database.h"

// Расчет стажа работы
int calculate_experience(Employee emp);

// Очистка буфера ввода
void clear_buffer();

// Показать сотрудников со стажем > 10 лет
void show_experienced(Employee* arr, int size);

#endif
