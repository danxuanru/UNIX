#include "apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>

void put_pull_rod(int signum);
void fish_eating();
void exit_game(int signum);
void fish_escape();

int fishNum = 0;	// counting fish number
int boolean = 0;	// used as a boolean

int main(void){

	struct sigaction sig_put_pull_rod;
	sig_put_pull_rod.sa_handler = put_pull_rod;
	
	struct sigaction sig_exit_game;
	sig_exit_game.sa_handler = exit_game;

	//write your code here

	struct sigaction sig_fish_escape;
	sig_fish_escape.sa_handler = fish_escape;

	sigaction(SIGTSTP, &sig_exit_game, NULL);	// catch ctrl+z exit game
	sigaction(SIGINT, &sig_put_pull_rod, NULL); // catch ctrl+c exit game
	sigaction(SIGALRM, &sig_fish_escape, NULL);  // alarm expire
	srand(time(NULL));

	while(1){
		
		printf("Fishing rod is ready!\n");
		//boolean = 0;
		pause();
		sleep(rand() % 10);

		if(boolean == 1){

			// random fish eat
			printf("A fish is biting, pull the fishing rod\n");
			alarm(10);
			pause();

			fish_eating();
		}
	}
	return 0;
}


void put_pull_rod(int signum){
	if (boolean == 0)
	{
		printf("\nPut the fishing rod\n");
		printf("Bait into water, waiting fish...\n");
		boolean = 1;
		
	}
	else if(boolean == 1){
		alarm(0); // close alarm
		printf("\nPull the fishing rod\n");
		boolean = 0;
	}
	return;
}

void fish_eating(){
	

	if(boolean == 0) {
		printf("Catch a Fish!\n");
		fishNum++;
		printf("Totally caught fishes: %d\n", fishNum);
		
	}
	boolean = 0;
	
}

void exit_game(int signum){ 
	printf("\nTotally caught fishes: %d\n", fishNum);
	exit(0);
}

void fish_escape(){
	printf("The fish was escaped!\n");
	return;
}