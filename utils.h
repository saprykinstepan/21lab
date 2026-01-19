#ifndef UTILS_H
#define UTILS_H

#include "database.h"

// Расчет стажа
int calculate_experience(Employee emp);

// Очистка буфера
void clear_buffer();

// Показать стаж > 10 лет
void show_experienced(Employee* arr, int size);

#endif
