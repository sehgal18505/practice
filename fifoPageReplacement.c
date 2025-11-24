#include<stdio.h>
int main(){
	int frames[10],pages[10],p,f,pageFaults=0,replaceIndex=0,flag;

	printf("Enter number of pages:");
	scanf("%d", &p);
	printf("Enter reference string:");
	for(int i = 0;i< p;i++)
		scanf("%d", &pages[i]);

	printf("Enter number of frames:");
	scanf("%d", &f);
	for(int i = 0;i< f;i++)
		frames[i] = -1;

	printf("\nPage\tFrames\tStatus\n");

	for(int i = 0;i < p;i++){
		flag = 0;
		for(int j = 0;j< f; j++){
			if(frames[j]==pages[i]){
				flag = 1;
				break;
			}
		}
		printf("%d\t", pages[i]);
		if(flag == 0){
			frames[replaceIndex] = pages[i];
			replaceIndex = (replaceIndex + 1) % f;
			pageFaults++;
			for(int j = 0;j < f; j++){
				if(frames[j] != -1)
					printf("%d ", frames[j]);
				else
					printf("- ");
			}
			printf("\tPage Fault\n");
		}else{
			for(int j = 0; j < f; j++){
				if(frames[j] != -1)
					printf("%d ",frames[j]);
				else
					printf("- ");
			}
			printf("\tHit\n");
		}
	}
	printf("Total page faults:%d", pageFaults);
	printf("Total hits:%d", p - pageFaults);
	return 0;
}
