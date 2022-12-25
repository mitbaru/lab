#include "file_reader.h"
#include "const.h"

#include <fstream>
#include <cstring>

date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

mark convert1(char* str)
{
    mark result;
    char* context = NULL;
    char* str_number = strtok_s(str, " ", &context);
    result.num = atoi(str_number);
    return result;
}

void read(const char* file_name, session_data* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            session_data* item = new session_data;
            file >> item->student.last_name;
            file >> item->student.first_name;
            file >> item->student.middle_name;
            file >> tmp_buffer;
            item->exam_date = convert(tmp_buffer);
            file >> tmp_buffer;
            item->exam_mark = convert1(tmp_buffer);
            file >> item->sub_name.first_name;
            file >> item->sub_name.second_name;
            file.read(tmp_buffer, 1); // чтения лишнего символа пробела
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}