//Lab -6 Implementation of single server queuing system
/*
Scenario:
    Grocery shop with single checkout counter
    Customer arrives in 1 to 8 min gap with equal probability
    Each customer takes 1 to 6 min of service time with equal probability
*/
/*
Activity 1: Create a simlation table for give nscenario for 20 customer and calculate:
            Average waiting time
            Average time spent in the system
            Average service time
            Server utilization
            Total idle time and percentage.
*/

/*
Algorithm:
    1. Create the structure customer with following:
        int arrival time
        int service time
        int start time
        int end time
    2. Generate customer, Arrival time, Service time, and store them in a structure.
    3. Calculate the service begin, service end time of each customer.
    4. Generate the statistics in tabular form with following
        Customer No., Interarrival time, Arrival time, Service time, Service begin time, Service end time, time spent, idle time
    5. Print the following performance parameters
        Average wait time
        Averaeg time spent
        Average service time
        server unitilization
        Total idle time and percentage
*/

#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define N 20 //numbre of customer

struct customer{
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

int main(){
    struct customer customer[N];
    int totalwaitingtime=0,totalservicetime=0,totaltimespent=0,totalidletime=0;

    srand(time(0));
    for (int i=0; i<N; i++){
        customer[i].customerno=i+1;
        //InterArrival time
        if(i==0)
            customer[i].interarrivaltime=0;
        else
            customer[i].interarrivaltime=rand()%8 +1;

        //Arrivalrrival time
        if(i==0)
            customer[i].arrivaltime=0;
        else
            customer[i].arrivaltime=customer[i-1].arrivaltime + customer[i].interarrivaltime;

        customer[i].servicetime = rand()%6 +1;

        if(i==0)
            customer[i].servicebegin=customer[i].arrivaltime;
        else
            customer[i].servicebegin=max(customer[i].arrivaltime, customer[i-1].serviceend);

        if(i==0)
            customer[i].idletime=customer[i].servicebegin;
        else
            customer[i].idletime=customer[i].servicebegin-customer[i-1].serviceend;
        
        customer[i].serviceend=customer[i].servicebegin+customer[i].servicetime;

        customer[i].waitingtime=customer[i].servicebegin-customer[i].arrivaltime;

        customer[i].timespent=customer[i].servicetime+customer[i].waitingtime;

        totalidletime+=customer[i].idletime;
        totalservicetime+=customer[i].servicetime;
        totaltimespent+=customer[i].timespent;
        totalwaitingtime+=customer[i].waitingtime;


    }

    //print;
    printf("\n%-10s %-18s %-10s %-12s %-12s %-12s %-12s %-14s %-10s\n",
        "Cust No", "Interarrival Time", "Arrival", "Service Time","Start Time", "End Time", "Wait Time", "Time Spent", "Idle");

    for(int i=0;i<N;i++){
        printf("%-10d %-18d %-10d %-12d %-12d %-12d %-12d %-14d %-10d\n",
            customer[i].customerno,customer[i].interarrivaltime,customer[i].arrivaltime,
            customer[i].servicetime,customer[i].servicebegin,customer[i].serviceend,
            customer[i].waitingtime,customer[i].timespent,customer[i].idletime);
    }

    //performance parameter:
    float avgwait=(float) totalwaitingtime/N;
    float avgservice=(float) totalservicetime/N;
    float avgspent=(float) totaltimespent/N;
    float serverutil=((float) totalservicetime/customer[N-1].serviceend)*100;
    float idlepercent=((float) totalidletime/customer[N-1].serviceend)*100;

    //Print;
    printf("\nPerformance Parameters:\n");
    printf("----------------------------------------\n");
    printf("Average waiting time:%.2f\n",avgwait);
    printf("Average Service time:%.2f\n",avgservice);
    printf("Average spent time:%.2f\n",avgspent);
    printf("Server utilization:%.2f\n",serverutil);
    printf("Idle Percentage:%.2f\n",idlepercent);

    return 0;
}