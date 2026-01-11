#ifndef UTILS_H
#define UTILS_H

#include "database.h"

// Вспомогательные функции
int calculate_experience(Employee emp, Date current_date);
void clear_input_buffer();
int get_integer_input(const char* prompt, int min, int max);
void print_separator();

#endif // UTILS_H
