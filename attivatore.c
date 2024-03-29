#include "library.h"

int semid, shmid, msgid;

int main(int argc, char* argv[]) {
	pid_t new_pid; int n_new_pid = 0;
	semid = atoi(argv[1]);
	shmid = atoi(argv[2]);
	msgid = atoi(argv[3]);

	message_buffer * mymessage; 
	int * array_new_atoms = malloc(N_ATOM_INIT*sizeof(pid_t));


  	data_buffer * shmem_ptr = (data_buffer *) shmat(shmid, NULL, 0);
  	TEST_ERROR;


	struct timespec step_nanosec;
  	step_nanosec.tv_sec = 0;           // seconds   
  	step_nanosec.tv_nsec = STEP_ATTIVATORE;   // nanoseconds
	
	sem.sem_num = STARTSEM;
 	sem.sem_op = -1;
  	semop(semid, &sem, 1);
	TEST_ERROR;

	//printf("ATTIVATORE: %d, shmid: %d, semid: %d\n\n", getpid(), shmid, semid);



	msgrcv(msgid, &mymessage, sizeof(pid_t)+1, PID_TYPE, 0);
	array_new_atoms[0] = atoi(mymessage->message);
	printf("%d\n\n", array_new_atoms[0]);





	while(1);

	//! bisogna decidere il criterio per cui si continua ad attivare (es. numero max di atomi)

	/*
	Ciclo STEP_ATTIVATORE volte e ogni volta controllo se posso continuare ad attivare sennò stop

	for ( ; 1 ;) {
		for(int i = 0; i < sizeof(pid_atoms[]); i++) {
			kill(pid_atoms[i], SIGCHLD);
		} 
		nanosleep(&step_nanosec, NULL);
	}
	
	new_pid = msgrcv(msgid, &mymessage, sizeof(pid_t), MSG_NOERROR);

	realloc(array_new_atoms, sizeof(pid_t) * n_new_pid);

	int n_atoms = rand() % (pid_atoms + 1);

	/* altra implementazione

	int n_atoms = rand() % (pid_atoms + 1);
	for(int i = 0; i < n_atoms; i++) {
		choose a random pid_atoms[] to divide
		invia comando di scissione a pid_atoms[chosen] con msgsnd() di tipo scissione;
	} 
	nanosleep(&step_nanosec, NULL);

	*/

	// printf("\n\n\nTEST ATTIVATORE\n\n\n");

	// semaforo che controlla n atomi da decidere (possono lavorare 3 atomi insieme)
}