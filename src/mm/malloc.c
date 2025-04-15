// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <internal/syscall.h>
#include <errno.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}
	mem_list_add(ret, size);
	return ret;
}

void *calloc(size_t nmemb, size_t size)
{
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);

	if (ret == MAP_FAILED)
	{
		errno = ENOMEM;
		return NULL;
	}
	mem_list_add(ret, size);
	memset(ret, 0, nmemb * size);
	return ret;
}

void free(void *ptr)
{
	if (!ptr)
		return;

	struct mem_list *item = mem_list_find(ptr);
	if (!item)
	{
		errno = EINVAL;
		return;
	}

	if (munmap(ptr, item->len) == -1)
	{
		errno = EINVAL;
		return;
	}

	mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
		return malloc(size);

	struct mem_list *item = mem_list_find(ptr);
	if (!item)
	{
		errno = EINVAL;
		return NULL;
	}

	if (item->len == size)
		return ptr;

	void *new_ptr = malloc(size);
	if (!new_ptr)
		return NULL;

	size_t copy_size = size < item->len ? size : item->len;
	memcpy(new_ptr, ptr, copy_size);
	free(ptr);

	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	return realloc(ptr, total);
}
