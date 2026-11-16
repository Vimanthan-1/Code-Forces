#include <iostream>
using namespace std;
int main(){
    int n,m,a,b;
    int sum=0;
    cin>>n>>m>>a>>b;

    /* if(m*a<b){
        sum+=n*a;
    }else{
        sum+=(n/b)+((n%b)*a);
    } */

    int sol=(m*a<b)?(n*a):((n/m)*b+min(((n%m)*a),b));
    cout<<sol<<endl;
}