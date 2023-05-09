#include "apue.h"

int main(void)
{

	int c, counter=0; 
	
	while( (c = fgetc(stdin)) != EOF ) {
		counter++;
		if (putc(c, stdout) == EOF)
			err_sys("output error");
	}
	if(ferror(stdin))
		err_sys("input error");
	printf("loop iterations: %d", counter);
	exit(0);
}

