//2. Write a C program to find multiplicative inverse of any numbers in Zn using Extended Euclidean algorithm.

#include<stdio.h>
int main(){
    int r1,n,b,r2,t1=0,t2=1,q,r,t,inverse;
    printf("Enter number of terms:");
    scanf("%d",&n);
    printf("Enter number to find multiplicatuve inverse:");
    scanf("%d",&b);
    r1=n;
    r2=b;
    while(r2>0){
        q=r1/r2;
        r=r1-q*r2;
        r1=r2;
        r2=r;
        t=t1-t2*q;
        t1=t2;
        t2=t;

        if(r1==1){
            inverse=t1%n;
            break;
        }
        
    }

    if(inverse<0){
        inverse=inverse+n;
    }
    if(inverse>n)
        printf("The multiplicative inverse doesnot exist.");
    else
        printf("The multiplicative inverse of %d is %d.",b,inverse);
    return 0;

}