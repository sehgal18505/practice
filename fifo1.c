#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
	int value = 5;
	mkfifo("write", 0666);
	int fd = open("write", O_WRONLY);
	write(fd, &value, sizeof(int));
	close(fd);
	return 0;
}
