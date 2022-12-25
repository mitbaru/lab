#include <iostream>
#include <iomanip>

using namespace std;

#include "session_data.h"
#include "file_reader.h"
#include "const.h"
#include "filter.h"

void output(session_data* session_info) {
    /********** вывод читателя **********/
    cout << "Студент........: ";
    // вывод фамилии
    cout << session_info->student.last_name << " ";
    // вывод первой буквы имени
    cout << session_info->student.first_name[0] << ". ";
    // вывод первой буквы отчества
    cout << session_info->student.middle_name[0] << ".";
    cout << '\n';
    /********** вывод предмета **********/
    cout << "Предмет...........: ";
    cout << session_info->sub_name.first_name << " ";
    cout << session_info->sub_name.second_name;
    cout << "\n";
    /********** вывод даты экзамена **********/
    // вывод года
    cout << "Дата экзамена.....: ";
    cout << setw(4) << setfill('0') << session_info->exam_date.year << '-';
    // вывод месяца
    cout << setw(2) << setfill('0') << session_info->exam_date.month << '-';
    // вывод числа
    cout << setw(2) << setfill('0') << session_info->exam_date.day;
    cout << '\n';
    /********** вывод оценки **********/
    cout << "Оценка...: ";
    cout << session_info->exam_mark.num;
    cout << '\n';
    cout << '\n';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Лабораторная работа №9. GIT\n";
    cout << "Вариант №8. Итог сессии\n";
    cout << "Автор: Артём Политыко\n\n";
    session_data* session_info[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", session_info, size);

        for (int i = 0; i < size; i++)
        {
            output(session_info[i]);
        }

        bool (*check_function)(session_data*) = NULL;
        int item;
        cout << "(1)Итоги сессии по предмету История Беларуси:\n" << "(2)Итоги сессии студентов с баллом выше 7:\n";
        cin >> item;
        switch (item) {
        case 1:
            check_function = check_subject;
            break;
        case 2:
            check_function = check_mark;
            break;
        default:
            throw "  ";
        }

        if (check_function) {
            int new_size;
            session_data** filtered = filter(session_info, size, check_function, new_size);
            for (int i = 0; i < new_size; ++i) {
                output(filtered[i] + 0);
            }
            delete[] filtered;
        }

        for (int i = 0; i < size; i++)
        {
            delete session_info[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    return 0;
};