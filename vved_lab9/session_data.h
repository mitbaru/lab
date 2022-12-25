#pragma once
#ifndef SESSION_DATA_H
#define SESSION_DATA_H

#include "const.h"

struct date
{
    int day;
    int month;
    int year;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct mark
{
    int num;
};

struct subject
{
    char first_name[MAX_STRING_SIZE];
    char second_name[MAX_STRING_SIZE];
};

struct session_data
{
    person student;       //reader
    date exam_date;           //start
    mark exam_mark;              //finish
    subject sub_name;        //author
};

#endif