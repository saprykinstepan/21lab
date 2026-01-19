#include <stdio.h>
#include "database.h"

int calculate_experience(Employee emp) {
    // Фиксированная текущая дата
    int current_year = 2025;
    int current_month = 12;
    int current_day = 15;
    
    int years = current_year - emp.hire_date.year;
    
    // Корректировка если день приема еще не наступил в этом году
    if (current_month < emp.hire_date.month ||
        (current_month == emp.hire_date.month && 
         current_day < emp.hire_date.day)) {
        years--;
    }
    
    return years;
}

void clear_buffer() {
    while (getchar() != '\n');
}

void show_experienced(Employee* arr, int size) {
    int count = 0;
    printf("\nСотрудники со стажем > 10 лет:\n");
    
    for (int i = 0; i < size; i++) {
        int exp = calculate_experience(arr[i]);
        if (exp > 10) {
            printf("%d. ", i+1);
            print_employee(arr[i]);
            printf("  Стаж: %d лет\n", exp);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Не найдено\n");
    }
}
