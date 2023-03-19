#include <stdio.h>

int main()
{
    int size, process[10], startTime[10], turnAroundTime[10], i;
    double avgWT = 0.0, avgTat = 0.0;
    printf("\t\t\t\tFCFS Algorithm[*This Program Can Calculate Upto 10 Process*]");
start:
    printf("\nEnter Number of Process:");
    scanf("%d", &size);
    if (size > 0)
    {
        // printf("Enter Process Burst Time");
        for (i = 0; i < size; i++)
        {
            printf("\nEnter Burst Time for %d Process:", i + 1);
            scanf("%d", &process[i]);
        }
        printf("\n Process\tBurst Time \tWaiting Time \tTurnAround Time\n");
        startTime[0] = 0;
        turnAroundTime[0] = process[0];
        for (i = 0; i < size; i++)
        {
            startTime[i + 1] = startTime[i] + process[i];
            turnAroundTime[i + 1] = turnAroundTime[i] + process[i + 1];
            printf("Process %d\t     %d\t\t     %d\t\t      %d\n", i + 1, process[i], startTime[i], turnAroundTime[i]);
            avgWT += startTime[i];
            avgTat += turnAroundTime[i];
        }
        printf("\nAverage Waiting Time:%.2lf\n", (avgWT / size));
        printf("\nAverage Waiting Time:%.2lf", (avgTat / size));
    }
    else
    {
        printf("Invalid Size.");
        goto start;
    }
    return 0;
}