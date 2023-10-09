#include "main.h"

/**
 * _realloc - reallocates a block of memory using malloc and free
 * @ptr: pointer to memory previously allocated
 * @old_size: size of allocated space for ptr
 * @new_size: new size of memory block
 * Return: void
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int x;
	char *pointer, *temp;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		pointer = malloc(new_size);
		if (pointer == NULL)
			return (NULL);
		free(ptr);
		return (pointer);
	}
	if (ptr != NULL && new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	pointer = malloc(new_size);
	if (pointer == NULL)
		return (NULL);
	temp = ptr;
	for (x = 0; x < (new_size > old_size ? old_size : new_size); x++)
		pointer[x] = temp[x];
	free(ptr);
	return (pointer);
}

/**
 * _memset - fills first n bytes of s with b
 * @s: pointer to memory area
 * @b: character for fill
 * @n: number of bytes
 * Return: pointer to s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x = 0;

	for (; x < n; x++)
		s[x] = b;
	return (s);
}
