/*
Activity 2:
    Modify the program of activiry 1. and calculate:
        Average waiting time
        Minimum waiting time
        Maximum waiting time
        Average number of customer in the system
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20 //number of customers

struct customer {
    int customerno;
    int arrivaltime;
    int servicetime;
    int starttime;
    int endtime;
    int interarrivaltime;
    int servicebegin;
    int waitingtime;
    int serviceend;
    int timespent;
    int idletime;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    struct customer customer[N];
    int totalwaitingtime = 0, totalservicetime = 0, totaltimespent = 0, totalidletime = 0;
    int minwait = 10000, maxwait = 0;

    srand(time(0));

    for (int i = 0; i < N; i++) {
        customer[i].customerno = i + 1;

        // Interarrival time
        if (i == 0)
            customer[i].interarrivaltime = 0;
        else
            customer[i].interarrivaltime = rand() % 8 + 1;

        // Arrival time
        if (i == 0)
            customer[i].arrivaltime = 0;
        else
            customer[i].arrivaltime = customer[i - 1].arrivaltime + customer[i].interarrivaltime;

        // Service time
        customer[i].servicetime = rand() % 6 + 1;

        // Service begin
        if (i == 0)
            customer[i].servicebegin = customer[i].arrivaltime;
        else
            customer[i].servicebegin = max(customer[i].arrivaltime, customer[i - 1].serviceend);

        // Idle time
        if (i == 0)
            customer[i].idletime = customer[i].servicebegin;
        else
            customer[i].idletime = customer[i].servicebegin - customer[i - 1].serviceend;

        // Service end
        customer[i].serviceend = customer[i].servicebegin + customer[i].servicetime;

        // Waiting time
        customer[i].waitingtime = customer[i].servicebegin - customer[i].arrivaltime;

        // Time spent in system
        customer[i].timespent = customer[i].servicetime + customer[i].waitingtime;

        // Update totals
        totalidletime += customer[i].idletime;
        totalservicetime += customer[i].servicetime;
        totaltimespent += customer[i].timespent;
        totalwaitingtime += customer[i].waitingtime;

        // Min/Max waiting time tracking
        if (customer[i].waitingtime < minwait)
            minwait = customer[i].waitingtime;
        if (customer[i].waitingtime > maxwait)
            maxwait = customer[i].waitingtime;
    }

    // Output table
    printf("\n%-10s %-18s %-10s %-12s %-12s %-12s %-12s %-14s %-10s\n",
        "Cust No", "Interarrival Time", "Arrival", "Service Time", "Start Time",
        "End Time", "Wait Time", "Time Spent", "Idle");

    for (int i = 0; i < N; i++) {
        printf("%-10d %-18d %-10d %-12d %-12d %-12d %-12d %-14d %-10d\n",
            customer[i].customerno, customer[i].interarrivaltime, customer[i].arrivaltime,
            customer[i].servicetime, customer[i].servicebegin, customer[i].serviceend,
            customer[i].waitingtime, customer[i].timespent, customer[i].idletime);
    }

    // Performance calculations
    float avgwait = (float) totalwaitingtime / N;
    float avgservice = (float) totalservicetime / N;
    float avgspent = (float) totaltimespent / N;
    float serverutil = ((float) totalservicetime / customer[N - 1].serviceend) * 100;
    float idlepercent = ((float) totalidletime / customer[N - 1].serviceend) * 100;
    float avgcustinsys = (float) totaltimespent / customer[N - 1].serviceend;

    // Output performance parameters
    printf("\nPerformance Parameters:\n");
    printf("----------------------------------------\n");
    printf("Average Waiting Time     : %.2f minutes\n", avgwait);
    printf("Minimum Waiting Time     : %d minutes\n", minwait);
    printf("Maximum Waiting Time     : %d minutes\n", maxwait);
    printf("Average Service Time     : %.2f minutes\n", avgservice);
    printf("Average Time Spent       : %.2f minutes\n", avgspent);
    printf("Server Utilization       : %.2f%%\n", serverutil);
    printf("Idle Time Percentage     : %.2f%%\n", idlepercent);
    printf("Average # of Cust. in Sys: %.2f\n", avgcustinsys);

    return 0;
}