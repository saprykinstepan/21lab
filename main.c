#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "database.h"
#include "fileio.h"
#include "utils.h"

int main() {
    setlocale(LC_ALL, "Russian");

    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;
    int result;

    do {
        printf("\n=== МЕНЮ БАЗЫ ДАННЫХ СОТРУДНИКОВ ===\n");
        printf("1. Загрузить из файла\n");
        printf("2. Добавить сотрудника\n");
        printf("3. Показать всех сотрудников\n");
        printf("4. Изменить запись\n");
        printf("5. Поиск по фамилии\n");
        printf("6. Сортировка\n");
        printf("7. Сохранить в файл\n");
        printf("8. Показать сотрудников со стажем > 10 лет\n");
        printf("9. Выход\n");
        printf("====================================\n");
        printf("Выбор: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
        case 1:
            result = load_employees(employees, &count, "employees.bin");
            printf("Загружено записей: %d\n", result);
            break;
        case 2:
            result = add_employee(employees, &count);
            if (result == 1) printf("Сотрудник добавлен успешно!\n");
            else printf("Ошибка: массив полон!\n");
            break;
        case 3:
            result = print_all_employees(employees, count);
            printf("Выведено записей: %d\n", result);
            break;
        case 4:
            result = edit_employee(employees, count);
            if (result == 1) printf("Запись изменена успешно!\n");
            else printf("Ошибка изменения записи!\n");
            break;
        case 5:
            result = search_employee(employees, count);
            printf("Найдено записей: %d\n", result);
            break;
        case 6:
            result = sort_employees(employees, count);
            if (result == 1) printf("Сортировка выполнена успешно!\n");
            else printf("Ошибка сортировки!\n");
            break;
        case 7:
            result = save_employees(employees, count, "employees_new.bin");
            printf("Сохранено записей: %d\n", result);
            break;
        case 8:
            result = show_experienced_employees(employees, count);
            printf("Найдено сотрудников со стажем > 10 лет: %d\n", result);
            break;
        case 9:
            printf("Выход из программы...\n");
            break;
        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }

        if (choice != 9) {
            printf("\nНажмите Enter для продолжения...");
            getchar();
        }

    } while (choice != 9);

    return 0;
}
