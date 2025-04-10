//Lab-4 Additive inverse, multiplicative invere and relatively prime number
//1.Write a c program to find additive inverse of numbers in Zn.
#include<stdio.h>

int main(){
    int n,a,i,j,additive_inverse[100],inverse;
    printf("Enter a number of terms to find additive inverse:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            inverse=((i+j)%n);
            if(inverse==0)
                additive_inverse[i]=j;
        }
    }
    printf("Enter the number to find additive inverse:");
    scanf("%d",&a);

    printf("The additive inverse of %d is %d.",a,additive_inverse[a]);
    return 0;
}