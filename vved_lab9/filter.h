#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "session_data.h"

session_data** filter(session_data* array[], int size,
	bool (*check)(session_data* element), int& result_size);

bool check_subject(session_data* element);

bool check_mark(session_data* element);

#endif