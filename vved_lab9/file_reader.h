#pragma once
#ifndef FILE_READER_H
#define FILE_READER_H

#include "session_data.h"

void read(const char* file_name, session_data* array[], int& size);

#endif