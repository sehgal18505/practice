#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	int fd[2],to_write,to_read;
	if(!pipe(fd)){
		int id = fork();
		if(id == 0){//child
			close(fd[0]);
			scanf("%d", &to_write);
			write(fd[1], &to_write, sizeof(int));
			close(fd[1]);
		}else if(id > 0){//parent
			close(fd[1]);
			read(fd[0], &to_read, sizeof(int));
			printf("Parent got:%d", to_read);
			close(fd[0]);
		}else{
			return -1;//fork failed
		}
	}else{
		return -2;
	}
}










