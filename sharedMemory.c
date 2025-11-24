#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
int main(){
	key_t key = ftok("file", 65);
	int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
	int value = 5;
	int id = fork();
	if(!id){
		int *val = (int *) shmat(shmid, NULL, 0);
		printf("Child recieved %d", *val);
		 shmdt(val);
	}else if(id > 0){
		int *val = (int *) shmat(shmid, NULL, 0);
		*val = value;
		shmdt(val);
	}else
		return -1;
	return 0;
}
