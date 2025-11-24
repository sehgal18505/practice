#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
typedef struct MessageBuffer{
	long msg_type;
	int value;
}message;

int main(){
	key_t key = ftok("file", 65);
	int msgid = msgget(key, 0666 | IPC_CREAT);
	int value = 5;
	int id = fork();
	if(!id){
		message m;
		msgrcv(msgid, &m, sizeof(m.value), 1, 0);
		printf("Child recieved:%d", m.value);
		msgctl(msgid, IPC_RMID, NULL);
	}else if(id >0){
		message m;
		m.msg_type = 1;
		m.value = value;
		msgsnd(msgid, &m, sizeof(m.value), 0);
	}else
		return -1;
	return 0;
}
