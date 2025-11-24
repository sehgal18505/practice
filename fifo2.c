#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int value;
	int fd = open("write", O_RDONLY);
	read(fd, &value, sizeof(int));
	printf("Read:%d", value);
	close(fd);
	return 0;
}
