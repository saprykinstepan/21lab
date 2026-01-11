#ifndef DATABASE_H
#define DATABASE_H

#define MAX_EMPLOYEES 100

// Структура для даты
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Структура для сотрудника
typedef struct {
    char surname[50];
    char name[50];
    char otchestvo[50];
    char position[50];
    char gender[10];
    Date hire_date;
} Employee;

// Функции работы с базой данных
int add_employee(Employee* arr, int* size);
int print_all_employees(Employee* arr, int size);
int print_employee(Employee emp);
int edit_employee(Employee* arr, int size);
int search_employee(Employee* arr, int size);
int sort_employees(Employee* arr, int size);
int show_experienced_employees(Employee* arr, int size);

// Функции сравнения для сортировки
int compare_by_surname(const void* a, const void* b);
int compare_by_position(const void* a, const void* b);
int compare_by_date(const void* a, const void* b);

#endif // DATABASE_H
