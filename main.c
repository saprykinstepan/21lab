#include <stdio.h>
#include <locale.h>
#include "database.h"
#include "fileio.h"
#include "utils.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    Employee employees[MAX];
    int count = 0;
    int choice;
    int result;
    
    do {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Загрузить из файла\n");
        printf("2. Добавить сотрудника\n");
        printf("3. Показать всех\n");
        printf("4. Изменить запись\n");
        printf("5. Поиск по фамилии\n");
        printf("6. Сортировка\n");
        printf("7. Сохранить в файл\n");
        printf("8. Стаж > 10 лет\n");
        printf("9. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);
        clear_buffer();
        
        switch(choice) {
            case 1:
                result = load_from_file(employees, &count, "employees.bin");
                printf("Загружено: %d\n", result);
                break;
            case 2:
                if (add_employee(employees, &count))
                    printf("Добавлено\n");
                break;
            case 3:
                result = print_all(employees, count);
                printf("Всего: %d\n", result);
                break;
            case 4:
                if (edit_employee(employees, count))
                    printf("Изменено\n");
                break;
            case 5:
                result = search_employee(employees, count);
                printf("Найдено: %d\n", result);
                break;
            case 6:
                if (sort_array(employees, count))
                    printf("Отсортировано\n");
                break;
            case 7:
                result = save_to_file(employees, count, "new_employees.bin");
                printf("Сохранено: %d\n", result);
                break;
            case 8:
                show_experienced(employees, count);
                break;
            case 9:
                printf("Выход\n");
                break;
            default:
                printf("Неверный выбор\n");
        }
        
    } while(choice != 9);
    
    return 0;
}
