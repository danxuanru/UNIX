#include <stdio.h>
#include "apue.h"

void accumulation(int d_sum);

int main()
{
	FILE* sum;
	int total_sum=0;
	pid_t pid[5];
	int year=5, week=52, day=7;

	sum = fopen("sum.txt", "w");
	fprintf(sum, "%d\n", 0);
	fclose(sum);

	/**********************************************************/

	TELL_WAIT();
	char tmp[128];
	int i;

	for (i = 0; i < year; i++)
	{
		
		if((pid[i] = fork()) < 0)
			err_sys("fork error");
		
		else if(pid[i] == 0){

			for (int w = 1; w <= week; w++){
				// open txt file
				sprintf(tmp, "%d-%02d.txt", i+1, w);
				FILE* file = fopen(tmp, "r");

				// accumulation
				int data, d_sum;

				for (int d = 0; d < day; d++){
					d_sum = 0;
					for (int n = 0; n < 96; n++)
					{
						fscanf(file, "%d", &data);
						d_sum += data;
					}
					WAIT_PARENT();
					accumulation(d_sum);
					TELL_PARENT(getppid());
				}
				fclose(file);
			}
			return 0;
		}

		// for (int k = 0; k < 52 * 7; k++)
		// {
		// 	TELL_CHILD(pid[i]);
		// 	WAIT_CHILD();
		// }
	}

	for (int k = 0; k < 5*52*7; k++){
		TELL_CHILD(pid[i]);
		WAIT_CHILD();
	}
		

	/**********************************************************/

	sum = fopen("sum.txt", "r");
	fscanf(sum, "%d", &total_sum);
	printf("Day_Average = %d\n",total_sum/(year*week*day));
	fclose(sum);

	return 0;
}

void accumulation(int d_sum)    //Accumulating the daily sum to "sum.txt".
{
	FILE* sum;
	int tmp=0;

	sum = fopen("sum.txt", "r+");
	fscanf(sum, "%d", &tmp);

	tmp += d_sum;

	rewind(sum);
	fprintf(sum, "%d", tmp);
	fclose(sum);

	return;
}
