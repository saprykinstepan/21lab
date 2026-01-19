#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

int add_employee(Employee* arr, int* size) {
    if (*size >= MAX) return 0;
    
    printf("Фамилия: ");
    scanf("%49s", arr[*size].surname);
    printf("Имя: ");
    scanf("%49s", arr[*size].name);
    printf("Отчество: ");
    scanf("%49s", arr[*size].otchestvo);
    printf("Должность: ");
    scanf("%49s", arr[*size].position);
    printf("Пол: ");
    scanf("%9s", arr[*size].gender);
    printf("Дата приема: ");
    scanf("%d %d %d", &arr[*size].hire_date.day, 
                      &arr[*size].hire_date.month, 
                      &arr[*size].hire_date.year);
    
    (*size)++;
    return 1;
}

void print_employee(Employee emp) {
    printf("%s %s %s, %s, %s, %02d.%02d.%d\n",
           emp.surname, emp.name, emp.otchestvo,
           emp.position, emp.gender,
           emp.hire_date.day, emp.hire_date.month, emp.hire_date.year);
}

int print_all(Employee* arr, int size) {
    if (size == 0) {
        printf("Нет данных\n");
        return 0;
    }
    
    for (int i = 0; i < size; i++) {
        printf("%d. ", i+1);
        print_employee(arr[i]);
    }
    return size;
}

int edit_employee(Employee* arr, int size) {
    int index;
    printf("Номер записи (1-%d): ", size);
    scanf("%d", &index);
    
    if (index < 1 || index > size) return 0;
    
    index--;
    printf("Новая фамилия: ");
    scanf("%49s", arr[index].surname);
    printf("Новое имя: ");
    scanf("%49s", arr[index].name);
    printf("Новое отчество: ");
    scanf("%49s", arr[index].otchestvo);
    printf("Новая должность: ");
    scanf("%49s", arr[index].position);
    printf("Новый пол: ");
    scanf("%9s", arr[index].gender);
    printf("Новая дата: ");
    scanf("%d %d %d", &arr[index].hire_date.day,
                      &arr[index].hire_date.month,
                      &arr[index].hire_date.year);
    return 1;
}

int search_employee(Employee* arr, int size) {
    char search[50];
    int found = 0;
    
    printf("Фамилия для поиска: ");
    scanf("%49s", search);
    
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].surname, search) == 0) {
            printf("%d. ", i+1);
            print_employee(arr[i]);
            found++;
        }
    }
    return found;
}

int compare_surname(const void* a, const void* b) {
    Employee* emp1 = (Employee*)a;
    Employee* emp2 = (Employee*)b;
    return strcmp(emp1->surname, emp2->surname);
}

int compare_position(const void* a, const void* b) {
    Employee* emp1 = (Employee*)a;
    Employee* emp2 = (Employee*)b;
    return strcmp(emp1->position, emp2->position);
}

int compare_date(const void* a, const void* b) {
    Employee* emp1 = (Employee*)a;
    Employee* emp2 = (Employee*)b;
    
    if (emp1->hire_date.year != emp2->hire_date.year)
        return emp1->hire_date.year - emp2->hire_date.year;
    if (emp1->hire_date.month != emp2->hire_date.month)
        return emp1->hire_date.month - emp2->hire_date.month;
    return emp1->hire_date.day - emp2->hire_date.day;
}

int sort_array(Employee* arr, int size) {
    int choice;
    printf("1. По фамилии\n2. По должности\n3. По дате\nВыбор: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: qsort(arr, size, sizeof(Employee), compare_surname); break;
        case 2: qsort(arr, size, sizeof(Employee), compare_position); break;
        case 3: qsort(arr, size, sizeof(Employee), compare_date); break;
        default: return 0;
    }
    return 1;
}
