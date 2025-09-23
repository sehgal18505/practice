#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid;
    int burstTime;
    int waitingTime;
    int endTime;
    int turnAroundTime;
} process;

void swap(process *p1, process *p2) {
    process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sortByBurstTime(process processes[], int numberOfProcesses) {
    for (int i = 0; i < numberOfProcesses - 1; i++) {
        for (int j = 0; j < numberOfProcesses - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void calculateTime(process processes[], int numberOfProcesses) {
    int totalWaitingTime = 0, totalTurnAroundTime = 0;
    processes[0].endTime = processes[0].burstTime;
    for (int i = 1; i < numberOfProcesses; i++) {
        processes[i].endTime = processes[i - 1].endTime + processes[i].burstTime;
    }
    processes[0].waitingTime = 0;
    for (int i = 1; i < numberOfProcesses; i++) {
        processes[i].waitingTime = processes[i - 1].endTime;
        totalWaitingTime += processes[i].waitingTime;
    }

    for (int i = 0; i < numberOfProcesses; i++) {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    printf("P_ID\tBurst_Time\tWaiting_Time\tTurn_Around_Time\n");
    for (int i = 0; i < numberOfProcesses; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burstTime, processes[i].waitingTime, processes[i].turnAroundTime);
    }
    printf("Average waiting time = %f\nAverage turnaround time = %f", (float)totalWaitingTime / numberOfProcesses, (float)totalTurnAroundTime / numberOfProcesses);
}

int main() {
    int numberOfProcesses;
    printf("Enter number of processes: ");
    scanf("%d", &numberOfProcesses);
    process *processes = (process *)malloc(sizeof(process));
    printf("Enter details of the processes(pid, burst time):\n");
    for (int i = 0; i < numberOfProcesses; i++) {
        scanf("%d %d", &processes[i].pid, &processes[i].burstTime);
    }

    sortByBurstTime(processes, numberOfProcesses);
    calculateTime(processes, numberOfProcesses);
}
