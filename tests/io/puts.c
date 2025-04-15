// SPDX-License-Identifier: BSD-3-Clause

#include <stdio.h>
#include <string.h>

#define EOF -1

size_t puts(const char *str)
{
	size_t len = strlen(str);

	if (write(1, str, len) < 0)
		return EOF;

	if (write(1, "\n", 1) < 0)
		return EOF;

	return 1;
}

int main(void)
{
	puts("Hello, World!");

	return 0;
}
