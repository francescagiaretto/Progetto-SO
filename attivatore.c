#include "library.h"

int semid;

int main(int argc, char* argv[]) {
	
	semid = semget(atoi(argv[1]), 2, IPC_CREAT | 0666);
	check_error();
	
	sem.sem_num = STARTSEM;
 	sem.sem_op = -1;
  	semop(semid, &sem, 1);
	check_error();

	printf("\n\n\nTEST ATTIVATORE\n\n\n");
	// ? come comunicare che bisogna fare una scissione? SEGNALE

	// semaforo che controlla n atomi da decidere (possono lavorare 3 atomi insieme)
	// in caso di riuscita execvesu atomo

	/*
			Ciclo STEP_ATTIVATORE volte e ogni volta controllo se posso continuare ad attivare sennò stop
	*/

}