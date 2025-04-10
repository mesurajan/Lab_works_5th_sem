// Lab -6 (RSA , Elgaal and diffie hellman key exchange)
//1. Write a c program to implement Diffie hellman key exchange algorithm
#include <stdio.h>
#include <math.h>

int modulo(int a, int b, int mod){
    int res = 1;
    while(b > 0){
        if(b & 1)
            res = (res * a) % mod;
        a=(a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int p, g, xa, ya, xb, yb, ka, kb;
    printf("Enter prime number (p):");
    scanf("%d", &p);
    printf("Enter primitive root of p:");
    scanf("%d", &g);
    printf("Enter the random number Xa < p:");
    scanf("%d", &xa);
    printf("Enter the random number Xb < p:");
    scanf("%d", &xb);
    ya = modulo(g, xa, p);
    yb = modulo(g, xb, p);
    printf("The Private key of User A is %d.\n",ya);
    printf("The Private key of User B is %d.\n",yb);
    ka = modulo(yb, xa, p);
    kb = modulo(ya, xb, p);

    printf("The key for user a is %d.\n", ka);
    printf("The key for user b is %d.", kb);
    return 0;
}
