// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

// SEEK_SET = 0
// SEEK_CUR = 1
// SEEK_END = 2

off_t lseek(int fd, off_t offset, int whence)
{
	if (fd < 0)
	{
		errno = EBADF;
		return -1;
	}

	if (whence < 0)
	{
		errno = EINVAL;
		return -1;
	}

	if (whence != SEEK_SET && offset < 0)
	{
		errno = EINVAL;
		return -1;
	}
	int ret = syscall(__NR_lseek, fd, offset, whence);
	if (ret < 0)
	{
		errno = -ret;
		return -1;
	}
	return ret;
}
