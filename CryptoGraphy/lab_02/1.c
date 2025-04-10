//lab -2 classical cryptography
//1. Write a c program to implement otp cipher

#include<stdio.h>
#include<string.h>
int main(){
    char pt[100],ct[100],key[100];
    int i,ptlen;
    printf("OTP Cipher:\n");
    printf("Enter plaintext:");
    scanf("%s",pt);
    ptlen=strlen(pt);
    printf("Enter key of length %d:",ptlen);
    scanf("%s",key);
    if(strlen(key) != ptlen){
        printf("The length of key is not equal to length of plaintext, They must be equal (i.e %d).",ptlen);
        return 0;
    }

    //encryption:
    printf("\n--------Encryption----------\n");
    printf("PlainText:%s\nKey:%s\n",pt,key);
    for(i=0;i<ptlen;i++){
        ct[i]=(((pt[i]-97)+(key[i]-97))%26)+97;
    }
    ct[i] = '\0';
    printf("Ciphertext:%s\n",ct);

    //decryption:
    printf("\n----Decryption-----\n");
    printf("CipherText:%s\nKey:%s\n",ct,key);
    for(i=0;i<strlen(ct);i++){
        pt[i]=(((ct[i]-97)-(key[i]-97)+26)%26)+97;
    }
    printf("Plaintext:%s\n",pt);
    return 0;
}