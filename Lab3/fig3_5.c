#include "apue.h"
#include <fcntl.h>

#define BUFFSIZE 16384

int main(void)
{
	int n;
	char buf[BUFFSIZE];

	int devNull = open("/dev/null", O_WRONLY);
	while (fsync(n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
		if (write(devNull, buf, n) != n)
			err_sys("write error");

	if (n < 0)
		err_sys("read error");

	exit(0);
}
