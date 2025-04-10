//3. Write a recursive progrtam to calculate sum upto nth term.
#include<iostream>
using namespace std;
int nthsum(int x){
    if(x==0 || x==1){
        return x;
    }
    else{
        return(x + nthsum(x-1));
    }
}

int main(){
    int n, i=0;
    cout << "Enter the number of terms to add : ";
    cin >> n;
    cout<<" Sum is:"<<nthsum(n);
   return 0;
}