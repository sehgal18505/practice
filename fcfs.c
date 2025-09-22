#include<stdio.h>
#include<stdlib.h>

typedef struct Process{
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
}process;

void swap(process *p1, process *p2){
    process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sortByArrivalTime(process processes[], int numberOfProcesses){
    for(int i = 0; i < numberOfProcesses - 1; i++){
        for(int j = 0; j < numberOfProcesses - i - 1; j++){
            if(processes[j].arrivalTime > processes[j+1].arrivalTime)
                swap(&processes[j], &processes[j+1]);
        }
    }
}

void calculateTime(process processes[], int numberOfProcesses){
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;
    for(int i = 1; i < numberOfProcesses; i++){
        if(processes[i-1].completionTime < processes[i].arrivalTime){
            processes[i].completionTime = processes[i].arrivalTime + processes[i].burstTime;
        }
        else{
            processes[i].completionTime = processes[i-1].completionTime + processes[i].burstTime;
        }
    }

    for(int i = 0; i < numberOfProcesses; i++){
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    printf("P_ID\tArrival_Time\tBurst_Time\tWaiting_Time\tTurnaround_Time\n");
    for(int i = 0; i < numberOfProcesses; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].turnAroundTime);
    }
    printf("Average waiting time = %f\nAverage turnaround time = %f\n", (float)totalWaitingTime / numberOfProcesses, (float)totalTurnAroundTime / numberOfProcesses);
}


int main(){
    int numberOfProcesses;
    printf("Enter number of processes: ");
    scanf("%d", &numberOfProcesses);
    process *processes = (process *)malloc(sizeof(process));
    printf("Enter details of processes(ID, Arrival Time, Burst Time)");
    for(int i = 0; i < numberOfProcesses; i++){
        scanf("%d", &processes[i].pid);
        scanf("%d", &processes[i].arrivalTime);
        scanf("%d", &processes[i].burstTime);
    }
    sortByArrivalTime(processes, numberOfProcesses);
    calculateTime(processes, numberOfProcesses);

    return 0;
}
