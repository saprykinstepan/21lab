@echo off
echo Компиляция проекта База данных сотрудников...
gcc -std=c99 -o employees.exe main.c database.c fileio.c utils.c
if %errorlevel% equ 0 (
    echo Компиляция успешно завершена!
    echo Для запуска программы введите: employees.exe
) else (
    echo Ошибка компиляции!
    pause
)
