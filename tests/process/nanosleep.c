// SPDX-License-Identifier: BSD-3-Clause

#include <internal/time.h>
#include <stdio.h>

int main(void)
{
	struct timespec wait = {10, 0};

	nanosleep(&wait, NULL);

	return 0;
}
