#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

// Расчет стажа работы
int calculate_experience(Employee emp, Date current_date) {
    int years = current_date.year - emp.hire_date.year;
    
    // Корректировка, если текущая дата раньше даты приема в этом году
    if (current_date.month < emp.hire_date.month ||
        (current_date.month == emp.hire_date.month && 
         current_date.day < emp.hire_date.day)) {
        years--;
    }
    
    return years;
}

// Очистка буфера ввода
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Получение целого числа с проверкой диапазона
int get_integer_input(const char* prompt, int min, int max) {
    int value;
    int valid_input = 0;
    
    while (!valid_input) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            if (value >= min && value <= max) {
                valid_input = 1;
            } else {
                printf("Ошибка: значение должно быть от %d до %d\n", min, max);
            }
        } else {
            printf("Ошибка: введите целое число\n");
            clear_input_buffer();
        }
    }
    
    clear_input_buffer();
    return value;
}

// Печать разделительной линии
void print_separator() {
    printf("================================================\n");
}
