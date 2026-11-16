#include <iostream>
using namespace std;

int call(int n, int one, int two) {
    if (2 * one <= two)
        return n * one;

    return (n / 2) * two + (n % 2) * one;
}

int main(){
    int t;
    cin>>t;
    for(int i{0};i<t;i++){
        int n,one,two;
        cin>>n>>one>>two;
        cout<<call(n,one,two)<<endl;
    }

    return 0;
}