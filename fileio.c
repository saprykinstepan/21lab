#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

int load_from_file(Employee* arr, int* size, char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        printf("Файл не найден, создаю данные...\n");
        
        // Первый тестовый сотрудник
        strcpy(arr[0].surname, "Иванов");
        strcpy(arr[0].name, "Иван");
        strcpy(arr[0].otchestvo, "Иванович");
        strcpy(arr[0].position, "Инженер");
        strcpy(arr[0].gender, "муж");
        arr[0].hire_date.day = 10;
        arr[0].hire_date.month = 5;
        arr[0].hire_date.year = 2010;
        
        // Второй тестовый сотрудник
        strcpy(arr[1].surname, "Петрова");
        strcpy(arr[1].name, "Мария");
        strcpy(arr[1].otchestvo, "Сергеевна");
        strcpy(arr[1].position, "Бухгалтер");
        strcpy(arr[1].gender, "жен");
        arr[1].hire_date.day = 15;
        arr[1].hire_date.month = 8;
        arr[1].hire_date.year = 2012;
        
        *size = 2;
        save_to_file(arr, *size, filename);
        return 2;
    }
    
    *size = 0;
    while (fread(&arr[*size], sizeof(Employee), 1, f) == 1) {
        (*size)++;
        if (*size >= MAX) break;
    }
    
    fclose(f);
    return *size;
}

int save_to_file(Employee* arr, int size, char* filename) {
    if (size == 0) return 0;
    
    FILE* f = fopen(filename, "wb");
    if (!f) return 0;
    
    int saved = 0;
    for (int i = 0; i < size; i++) {
        if (fwrite(&arr[i], sizeof(Employee), 1, f) == 1) {
            saved++;
        }
    }
    
    fclose(f);
    return saved;
}

int input_file(char* filename, Employee* arr) {
    FILE* f = fopen(filename, "rb");
    if (!f) return 0;
    
    int count = 0;
    while (count < MAX && fread(&arr[count], sizeof(Employee), 1, f) == 1) {
        count++;
    }
    
    fclose(f);
    return count;
}

int output_file(char* filename, Employee* arr, int n) {
    if (n <= 0) return 0;
    
    FILE* f = fopen(filename, "wb");
    if (!f) return 0;
    
    int written = 0;
    for (int i = 0; i < n; i++) {
        if (fwrite(&arr[i], sizeof(Employee), 1, f) == 1) {
            written++;
        }
    }
    
    fclose(f);
    return written;
}
