//4. Find the period of the generator for a=13, m=64, and X0=1,2,3,4 using the multiplicative congruential method and show the result 
//   as follows. Your program should print the minimum and maximum cycle length detected for which value of seeds.

#include<stdio.h>
int main(){
    int x1[100],x2[100],x3[100],x4[100];
    int a=13,m=64,c=0;
    int i=0,j=0,k=0,l=0;
    x1[0]=1,x2[0]=2,x3[0]=3,x4[0]=4;
    int max,min;

    do {
        x1[i+1] = (x1[i] * a + c) % m;
        i++;
    } while (x1[i] != x1[0] && i < 100);

    do {
        x2[j+1] = (x2[j] * a + c) % m;
        j++;
    } while (x2[j] != x2[0] && j < 100);

    do {
        x3[k+1] = (x3[k] * a + c) % m;
        k++;
    } while (x3[k] != x3[0] && k < 100);

    do {
        x4[l+1] = (x4[l] * a + c) % m;
        l++;
    } while (x4[l] != x4[0] && l < 100);

    //max cycle length:
    if(i>=j && i>=k && i>=l){
        max=i;
    }
    else if(j>=i && j>=k && j>=l){
        max=j;
    }
    else if(k>=i && k>=j && k>=l){
        max=k;
    }
    else{
        max=l;
    }
    //min cycle length:
    if(i<=j && i<=k && i<=l)
        min=i;
    else if(j<=i && j<=k && j<=l)
        min=j;
    else if(k<=i && k<=j && k<=l)
        min=k;
    else
        min=l;

    
    printf("i\tX1\tX2\tX3\tX4\n");
    for (int o = 0; o <= max; o++) {
        printf("%d\t",o);
        if(o<=i)
            printf("%d",x1[o]);
        printf("\t");
        if(o<=j)
            printf("%d",x2[o]);
        printf("\t");
        if(o<=k)
            printf("%d",x3[o]);
        printf("\t");
        if(o<=l)
            printf("%d",x4[o]);
        
        printf("\n");
    }

    //Cycle Length:
    printf("Max Cycle length: %d\n Min cycle length: %d",max,min);

    return 0;
}