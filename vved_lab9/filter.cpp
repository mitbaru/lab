#include "filter.h"
#include "cstring"
#include <iostream>

session_data** filter(session_data* array[], int size,
	bool (*check)(session_data* element), int& result_size) {
	session_data** result = new session_data * [size];
	result_size = 0;
	for (int i = 0; i < size; ++i) {	
		if (check(array[i])) {
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_subject(session_data* element) {
	return strcmp(element->sub_name.first_name, "История") == 0 &&
		strcmp(element->sub_name.second_name, "Беларуси") == 0;
}

bool check_mark(session_data* element) {
	return element->exam_mark.num > 7;
}