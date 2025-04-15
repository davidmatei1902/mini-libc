// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char c;
	while ((c = *source) != '\0')
	{
		*destination = c;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char c;
	size_t counter = 0;
	while ((c = *source) != '\0' && counter < len)
	{
		*destination = c;
		destination++;
		source++;
		counter++;
	}

	while (counter < len)
	{
		*destination = '\0';
		destination++;
		counter++;
	}

	return destination;
}

char *strcat(char *destination, const char *source)
{
	while (*destination != '\0')
	{
		destination++;
	}
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t counter = 0;
	while (*destination != '\0')
	{
		destination++;
	}
	while (*source != '\0' && counter < len)
	{
		*destination = *source;
		destination++;
		source++;
		counter++;
	}

	*destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1) - (*str2);
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	size_t counter = 0;
	while ((*str1 == *str2) && counter < len)
	{
		str1++;
		str2++;
		counter++;
	}
	if (counter == len)
	{
		return 0;
	}
	return (*str1) - (*str2);
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == c)
		{
			return str;
		}
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	char *curr = NULL;
	while (*str != '\0')
	{
		if (*str == c)
		{
			curr = str;
		}
		str++;
	}
	return curr;
}

char *strstr(const char *haystack, const char *needle)
{
	if (*needle == NULL)
	{
		return haystack;
	}
	while (*haystack != '\0')
	{
		const char *h = haystack;
		const char *n = needle;

		while ((*h == *n) && *n != '\0')
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	const char *curr = NULL;
	if (*needle == NULL)
	{
		return haystack;
	}
	while (*haystack != '\0')
	{
		const char *h = haystack;
		const char *n = needle;

		while ((*h == *n) && *n != '\0')
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			curr = haystack;
		}
		haystack++;
	}
	if (curr != NULL)
	{
		return curr;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dst = (char *)destination;
	char *src = (char *)source;
	while (num)
	{
		*dst = *src;
		dst++;
		src++;
		num--;
	}
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dst = (char *)destination;
	const char *src = (const char *)source;

	if (dst < src || dst >= src + num)
	{
		while (num--)
		{
			*dst = *src;
			dst++;
			src++;
		}
	}
	else
	{
		// copy backwards
		dst += num;
		src += num;
		while (num--)
		{
			*(--dst) = *(--src);
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t counter = 0;
	char *char_ptr1 = (char *)ptr1;
	char *char_ptr2 = (char *)ptr2;

	while (*char_ptr1 == *char_ptr2 && (counter < num))
	{
		char_ptr1++;
		char_ptr2++;
		counter++;
	}
	if (counter == num)
	{
		return 0;
	}
	return (*char_ptr1) - (*char_ptr2);
}

void *memset(void *source, int value, size_t num)
{
	char *src = (char *)source;
	while (num)
	{
		*src = (unsigned char)value;
		src++;
		num--;
	}
	return source;
}
