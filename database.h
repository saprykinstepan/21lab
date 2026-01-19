#ifndef DATABASE_H
#define DATABASE_H

#define MAX 100

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char surname[50];
    char name[50];
    char otchestvo[50];
    char position[50];
    char gender[10];
    Date hire_date;
} Employee;

// Добавление нового сотрудника
int add_employee(Employee* arr, int* size);

// Вывод одного сотрудника
void print_employee(Employee emp);

// Вывод всех сотрудников
int print_all(Employee* arr, int size);

// Редактирование записи
int edit_employee(Employee* arr, int size);

// Поиск по фамилии
int search_employee(Employee* arr, int size);

// Меню сортировки
int sort_array(Employee* arr, int size);

// Сортировка по фамилии
void sort_by_surname(Employee* arr, int size);

// Сортировка по должности
void sort_by_position(Employee* arr, int size);

// Сортировка по дате приема
void sort_by_date(Employee* arr, int size);

#endif
