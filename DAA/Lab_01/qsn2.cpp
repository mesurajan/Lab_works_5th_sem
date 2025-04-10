
//2.Write a recursive program to calculate factorial of a number.
#include<iostream>
using namespace std;
int fact(int x){
    if(x==1||x==2){
        return x;
    }
    else{
        return (x*fact(x-1));
    }
}
int main(){
    int x,result;
    cout << "Enter the number to find factorial : ";
    cin>>x;
    result=fact(x);
    cout<<"Factorial of "<<x<< " is " <<result;
    return 0;

}