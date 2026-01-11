#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "database.h"
#include "utils.h"

// Добавление нового сотрудника
int add_employee(Employee* arr, int* size) {
    if (*size >= MAX_EMPLOYEES) {
        return 0;
    }

    printf("\n=== ДОБАВЛЕНИЕ НОВОГО СОТРУДНИКА ===\n");
    printf("Фамилия: ");
    scanf("%49s", arr[*size].surname);
    printf("Имя: ");
    scanf("%49s", arr[*size].name);
    printf("Отчество: ");
    scanf("%49s", arr[*size].otchestvo);
    printf("Должность: ");
    scanf("%49s", arr[*size].position);
    printf("Пол (муж/жен): ");
    scanf("%9s", arr[*size].gender);
    printf("Дата приема (день месяц год): ");
    scanf("%d %d %d",
        &arr[*size].hire_date.day,
        &arr[*size].hire_date.month,
        &arr[*size].hire_date.year);

    (*size)++;
    return 1;
}

// Вывод информации об одном сотруднике
int print_employee(Employee emp) {
    printf("┌────────────────────────────────────────────────────────────┐\n");
    printf("│ Фамилия:    %-40s │\n", emp.surname);
    printf("│ Имя:        %-40s │\n", emp.name);
    printf("│ Отчество:   %-40s │\n", emp.otchestvo);
    printf("│ Должность:  %-40s │\n", emp.position);
    printf("│ Пол:        %-40s │\n", emp.gender);
    printf("│ Дата приема: %02d.%02d.%-36d │\n",
        emp.hire_date.day, emp.hire_date.month, emp.hire_date.year);
    printf("└────────────────────────────────────────────────────────────┘\n");
    return 1;
}

// Вывод всех сотрудников
int print_all_employees(Employee* arr, int size) {
    if (size == 0) {
        printf("База данных пуста!\n");
        return 0;
    }

    printf("\n=== СПИСОК ВСЕХ СОТРУДНИКОВ (%d) ===\n", size);
    for (int i = 0; i < size; i++) {
        printf("\nСотрудник №%d:\n", i + 1);
        print_employee(arr[i]);
    }
    return size;
}

// Редактирование записи сотрудника
int edit_employee(Employee* arr, int size) {
    if (size == 0) {
        printf("База данных пуста!\n");
        return 0;
    }

    int index;
    printf("Введите номер записи для изменения (1-%d): ", size);
    scanf("%d", &index);

    if (index < 1 || index > size) {
        printf("Неверный номер записи!\n");
        return 0;
    }

    index--;

    printf("\nТекущие данные сотрудника №%d:\n", index + 1);
    print_employee(arr[index]);

    printf("\nВведите новые данные:\n");
    printf("Фамилия (%s): ", arr[index].surname);
    char buffer[100];
    getchar(); // Очистка буфера
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) strcpy(arr[index].surname, buffer);

    printf("Имя (%s): ", arr[index].name);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) strcpy(arr[index].name, buffer);

    printf("Отчество (%s): ", arr[index].otchestvo);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) strcpy(arr[index].otchestvo, buffer);

    printf("Должность (%s): ", arr[index].position);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) strcpy(arr[index].position, buffer);

    printf("Пол (%s): ", arr[index].gender);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) > 0) strcpy(arr[index].gender, buffer);

    printf("Дата приема (%02d.%02d.%d): ",
        arr[index].hire_date.day, arr[index].hire_date.month, arr[index].hire_date.year);
    int day, month, year;
    scanf("%d %d %d", &day, &month, &year);
    arr[index].hire_date.day = day;
    arr[index].hire_date.month = month;
    arr[index].hire_date.year = year;

    return 1;
}

// Поиск сотрудника по фамилии
int search_employee(Employee* arr, int size) {
    if (size == 0) {
        printf("База данных пуста!\n");
        return 0;
    }

    char surname[50];
    printf("Введите фамилию для поиска: ");
    scanf("%49s", surname);

    int found = 0;
    printf("\n=== РЕЗУЛЬТАТЫ ПОИСКА ===\n");
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].surname, surname) == 0) {
            printf("\nНайден сотрудник №%d:\n", i + 1);
            print_employee(arr[i]);
            found++;
        }
    }

    if (found == 0) {
        printf("Сотрудники с фамилией '%s' не найдены.\n", surname);
    }

    return found;
}

// Функции сравнения для сортировки
int compare_by_surname(const void* a, const void* b) {
    const Employee* empA = (const Employee*)a;
    const Employee* empB = (const Employee*)b;
    return strcmp(empA->surname, empB->surname);
}

int compare_by_position(const void* a, const void* b) {
    const Employee* empA = (const Employee*)a;
    const Employee* empB = (const Employee*)b;
    return strcmp(empA->position, empB->position);
}

int compare_by_date(const void* a, const void* b) {
    const Employee* empA = (const Employee*)a;
    const Employee* empB = (const Employee*)b;

    // Сначала сравниваем год
    if (empA->hire_date.year != empB->hire_date.year) {
        return empA->hire_date.year - empB->hire_date.year;
    }
    // Затем месяц
    if (empA->hire_date.month != empB->hire_date.month) {
        return empA->hire_date.month - empB->hire_date.month;
    }
    // Затем день
    return empA->hire_date.day - empB->hire_date.day;
}

// Сортировка сотрудников
int sort_employees(Employee* arr, int size) {
    if (size == 0) {
        printf("База данных пуста!\n");
        return 0;
    }

    printf("\n=== СОРТИРОВКА СОТРУДНИКОВ ===\n");
    printf("1. По фамилии (А-Я)\n");
    printf("2. По должности\n");
    printf("3. По дате приема (старые → новые)\n");
    printf("Выберите критерий сортировки: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        qsort(arr, size, sizeof(Employee), compare_by_surname);
        printf("Сортировка по фамилии выполнена.\n");
        break;
    case 2:
        qsort(arr, size, sizeof(Employee), compare_by_position);
        printf("Сортировка по должности выполнена.\n");
        break;
    case 3:
        qsort(arr, size, sizeof(Employee), compare_by_date);
        printf("Сортировка по дате приема выполнена.\n");
        break;
    default:
        printf("Неверный выбор!\n");
        return 0;
    }

    return 1;
}

// Показать сотрудников со стажем более 10 лет
int show_experienced_employees(Employee* arr, int size) {
    if (size == 0) {
        printf("База данных пуста!\n");
        return 0;
    }

    // Текущая дата (можно изменить)
    Date current_date = { 15, 12, 2025 };
    
    printf("\n=== СОТРУДНИКИ СО СТАЖЕМ БОЛЕЕ 10 ЛЕТ ===\n");
    
    int experienced_count = 0;
    for (int i = 0; i < size; i++) {
        int experience = calculate_experience(arr[i], current_date);
        if (experience > 10) {
            printf("\nСотрудник №%d:\n", i + 1);
            print_employee(arr[i]);
            printf("Стаж работы: %d лет\n", experience);
            experienced_count++;
        }
    }

    if (experienced_count == 0) {
        printf("Сотрудников со стажем более 10 лет не найдено.\n");
    }

    return experienced_count;
}
