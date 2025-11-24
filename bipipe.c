#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int fd1[2],fd2[2],id,child,parent;
	if(!pipe(fd1) && !pipe(fd2)){
		id = fork();
		if(!id){//child
			sleep(1);
			close(fd2[0]);
			close(fd1[1]);
			read(fd1[0], &child, sizeof(int));
			printf("Recieved at child:%d\n", child);
			child++;
			write(fd2[1], &child, sizeof(int));
			printf("Written incremented value %d to parent from child\n", child);
			close(fd2[0]);
			close(fd1[0]);
		}else if(id > 0){//parent
			close(fd2[1]);
			close(fd1[0]);
			scanf("%d", &parent);
			write(fd1[1], &parent, sizeof(int));
			printf("Written initial value %d to child from parent\n", parent);
			read(fd2[0], &parent, sizeof(int));
			printf("Recieved incremented value %d from child at parent\n", parent);
			close(fd1[1]);
			close(fd2[0]);
			wait(NULL);
		}else
			return -1;
	}else
		return -2;
}








