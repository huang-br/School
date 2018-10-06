#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include <string.h>

int hash_by_length(const char* str);
int hash_by_sum(const char* str);
int hash_by_shifted_sum(const char* str);

#endif/*ndef HASH_FUNCTIONS_H*/
