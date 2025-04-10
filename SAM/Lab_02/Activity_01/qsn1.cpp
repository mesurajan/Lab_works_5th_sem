//Lab-2 Related with random Number Generation
//1. Use Linear Congruential Method(LCM) to generate random numbers. Write a C/C++ program to generates random numbers.
#include<stdio.h>
int main(){
    int n,a,c,m,nod,r[100];
    printf("Enter how manu numbers(iteration):");
    scanf("%d",&n);
    
    printf("Enter R0:");
    scanf("%d",&r[0]);


    printf("\nEnter value of a:");
    scanf("%d",&a);

    printf("Enter value of c:");
    scanf("%d",&c);

    printf("Enter value of m:");
    scanf("%d",&m);
/*
    printf("Enter no of digits in each number:");
    scanf("%d",&nod);
    if(nod==1)
        m=10;

    if(nod==2)
        m=100;

    if(nod==3)
        m=1000;
    
    if(nod==4)
        m=10000;
*/
    for(int i=0;i<n;i++){
        r[i+1]=((r[i]*a)+c)%31;
    }
    printf("Answer:\n{");
    for(int i=0;i<n;i++){
    printf(" %d ",r[i]);
    }

    printf("}");
    
    return 0;

}