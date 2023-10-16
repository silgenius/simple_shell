#include "main.h"

/**
 * i_arr - increases the value of size_t integer by 12
 * @val: number to be increased
 * Return: doubled value
 */

size_t i_arr(size_t *val)
{
	size_t db_val;

	*val += 12;
	db_val = *val;
	return (db_val);
}
