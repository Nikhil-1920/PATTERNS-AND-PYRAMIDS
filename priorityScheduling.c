#include <stdio.h>

int main(void) {

    int totalProcs, procNum[20], procPriority[20];
    int arrivalTime[20], burstTime[20], waitTime[20];
    int turnAroundTime[20], totalTurnAroundTime = 0;
    int i, j, pos, totalWaitTime = 0, tempVal = 0;
    int avgWaitTime, avgTurnAroundTime;
    
    printf("\nEnter the total number of processes: ");
    scanf("%d", &totalProcs);

    printf("\nEnter the priority, arrival time and burst time of each process.\n");

    for(i = 0; i < totalProcs; i++) {
        printf("\nProcess[%d]\n", i + 1);
        printf("What is process priority? ");
        scanf("%d", &procPriority[i]);
        printf("What is arrival time(in ms)? ");
        scanf("%d", &arrivalTime[i]);
        printf("What is burst time(in ms)? ");
        scanf("%d", &burstTime[i]);
        procNum[i] = i + 1;
    }

    // sorting process number, priority, burst time in ascending order 
    // using selection sort
    // Here, lesser number corresponds to higher priority
    for(i = 0; i < totalProcs; i++) {
        pos = i;
        for(j = i + 1; j < totalProcs; j++) {
            if(procPriority[j] < procPriority[pos])
                pos = j;
        }
 
        tempVal = procPriority[i];
        procPriority[i] = procPriority[pos];
        procPriority[pos] = tempVal;
 
        tempVal = burstTime[i];
        burstTime[i] = burstTime[pos];
        burstTime[pos] = tempVal;

        tempVal = procNum[i];
        procNum[i] = procNum[pos];
        procNum[pos] = tempVal;
    }
    
    // waiting time for first process is 0
    waitTime[0] = 0;            

    for(i = 1; i < totalProcs; i++) {
        waitTime[i] = 0;
        for(j = 0; j < i; j++) 
            waitTime[i] += burstTime[j];

        totalWaitTime += waitTime[i];
    }

    // average waiting time
    avgWaitTime = totalWaitTime / totalProcs;

    printf("-----------------------------------------------------------------------------------------------");
    printf("\nProcess ID\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("-----------------------------------------------------------------------------------------------");
    
    for(i = 0; i < totalProcs; i++) {
        turnAroundTime[i] = burstTime[i] + waitTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        printf("\nProcess[%d]\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", procNum[i], procPriority[i],
            arrivalTime[i], burstTime[i], waitTime[i], turnAroundTime[i]);
    }
    
    // average turnaround time 
    avgTurnAroundTime = totalTurnAroundTime / totalProcs; 
    printf("-----------------------------------------------------------------------------------------------");
    printf("\nAverage Waiting Time = %dms\n", avgWaitTime);
    printf("\nAverage Turnaround Time = %dms\n", avgTurnAroundTime);
    return 0;
}