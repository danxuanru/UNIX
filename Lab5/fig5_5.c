#include "apue.h"

int main(void)
{
	char buf[MAXLINE];
	int counter = 0;

	setvbuf(stdin, buf, _IONBF, MAXLINE); //_IOFBF _IOLBF _IONBF
	while( (fgets(buf,MAXLINE,stdin)) != NULL ) {
		counter++;
		if (fputs(buf, stdout) == EOF)
			err_sys("output error");
	}
	if(ferror(stdin))
		err_sys("input error");
	printf("loop iterations: %d", counter);
	exit(0);
}

