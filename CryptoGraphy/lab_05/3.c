//3. Write a C program to find primitive root of any prime number.

#include<stdio.h>

int Power(int a, int j,int p) {
    int result = 1;
    for (int i = 0; i < j; i++) {
        result = (result*a)%p;
    }
    return result;
}

int main(){
    int a,p,i,j,k,l,m,count1,count2;
    printf("Enter any prime number:");
    scanf("%d",&p);
    printf("Enter any number less that p:");
    scanf("%d",&a);

    int rem[p-1],temp[p-1];
    count1=0;
    for(i=1,j=0;i<p;i++,j++){
        rem[j]=Power(a,i,p);
        count1++;
        printf("\nThe value of res[%d]=%d",j,rem[j]);
        
    }
    printf("\n Total count1=%d",count1);

    count2=0;
    for(i=0;i<p-1;i++){
        for(j=0;j<i;j++){
            if(rem[i]==rem[j]){
                printf("\n%d is not primitive root of %d.",a,p);
                return 0;
            }
            
        }
        count2++;
    }

    printf("\n Total count2=%d",count2);

    if(count1==count2)
        printf("\n%d is primitive root of %d.",a,p);
    
    return 0;
}