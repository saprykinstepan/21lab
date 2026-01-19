// Сортировка пузырьком по фамилии
void sort_by_surname(Employee* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j].surname, arr[j+1].surname) > 0) {
                // Обмен местами
                Employee temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Сортировка пузырьком по должности
void sort_by_position(Employee* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(arr[j].position, arr[j+1].position) > 0) {
                Employee temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Сортировка пузырьком по дате приема
void sort_by_date(Employee* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Сравниваем год
            if (arr[j].hire_date.year > arr[j+1].hire_date.year) {
                Employee temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            // Если год одинаковый, сравниваем месяц
            else if (arr[j].hire_date.year == arr[j+1].hire_date.year) {
                if (arr[j].hire_date.month > arr[j+1].hire_date.month) {
                    Employee temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
                // Если месяц одинаковый, сравниваем день
                else if (arr[j].hire_date.month == arr[j+1].hire_date.month) {
                    if (arr[j].hire_date.day > arr[j+1].hire_date.day) {
                        Employee temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }
    }
}

// Обновленная функция sort_array
int sort_array(Employee* arr, int size) {
    int choice;
    printf("1. По фамилии\n2. По должности\n3. По дате\nВыбор: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: 
            sort_by_surname(arr, size);
            break;
        case 2: 
            sort_by_position(arr, size);
            break;
        case 3: 
            sort_by_date(arr, size);
            break;
        default: 
            return 0;
    }
    return 1;
}
