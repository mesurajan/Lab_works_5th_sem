//3. Write a C program to test whether two positive integer are relatively prime number prime or not using Euclidean algorithm
#include<stdio.h>
int main(){
    int n1,n2,gcd,r1,r2,q,r;
    printf("Enter two numbers t ofind if its relatively prime number:");
    scanf("%d%d",&n1,&n2);

    if(n1>n2){
        r1=n1;
        r2=n2;
    }
    else{
        r1=n2;
        r2=n1;
    }
    while(r2>0){
        q=r1/r2;
        r=r1-q*r2;
        r1=r2;
        r2=r;
    }
    gcd=r1;
    if(gcd==1){
        printf("The GCD of %d and %d is %d. So, they are relatively prime number.",n1,n2,gcd);
    }
    else{
        printf("The GCD of %d and %d is %d. So, they are not relatively prime number.",n1,n2,gcd);
    }
    return 0;
}