#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

// Загрузка сотрудников из файла
int load_employees(Employee* arr, int* size, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Файл '%s' не найден. Создаю тестовые данные...\n", filename);
        
        // Создаем тестовые данные
        Employee test_data[] = {
            {"Иванов", "Иван", "Иванович", "Инженер", "муж", {10, 5, 2010}},
            {"Петрова", "Мария", "Сергеевна", "Бухгалтер", "жен", {15, 8, 2012}},
            {"Сидоров", "Алексей", "Петрович", "Менеджер", "муж", {20, 3, 2015}},
            {"Кузнецова", "Ольга", "Викторовна", "Директор", "жен", {5, 1, 2005}},
            {"Васильев", "Дмитрий", "Александрович", "Программист", "муж", {12, 11, 2018}}
        };
        
        *size = 5;
        for (int i = 0; i < *size; i++) {
            arr[i] = test_data[i];
        }
        
        // Сохраняем тестовые данные в файл
        save_employees(arr, *size, filename);
        return *size;
    }
    
    *size = 0;
    while (fread(&arr[*size], sizeof(Employee), 1, file) == 1 && *size < MAX_EMPLOYEES) {
        (*size)++;
    }
    
    fclose(file);
    return *size;
}

// Сохранение сотрудников в файл
int save_employees(Employee* arr, int size, const char* filename) {
    if (size == 0) {
        printf("Нет данных для сохранения!\n");
        return 0;
    }
    
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Ошибка при создании файла '%s'!\n", filename);
        return 0;
    }
    
    int saved_count = 0;
    for (int i = 0; i < size; i++) {
        if (fwrite(&arr[i], sizeof(Employee), 1, file) == 1) {
            saved_count++;
        }
    }
    
    fclose(file);
    return saved_count;
}

// Функция input_file (чтение из файла)
int input_file(const char* filename, Employee* arr) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Файл '%s' не найден!\n", filename);
        return 0;
    }
    
    int count = 0;
    while (count < MAX_EMPLOYEES && fread(&arr[count], sizeof(Employee), 1, file) == 1) {
        count++;
    }
    
    fclose(file);
    
    if (count == 0) {
        printf("Файл пуст или произошла ошибка чтения.\n");
    }
    
    return count;
}

// Функция output_file (запись в файл)
int output_file(const char* filename, Employee* arr, int n) {
    if (n <= 0) {
        printf("Нет данных для записи!\n");
        return 0;
    }
    
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Ошибка при создании файла '%s'!\n", filename);
        return 0;
    }
    
    int written_count = 0;
    for (int i = 0; i < n; i++) {
        if (fwrite(&arr[i], sizeof(Employee), 1, file) == 1) {
            written_count++;
        }
    }
    
    fclose(file);
    return written_count;
}
