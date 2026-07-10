#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    const int MAXP = 1000000;
    vector<char> is_prime(MAXP+1, true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<=MAXP;i++) if(is_prime[i]){
        for(int j=i*i;j<=MAXP;j+=i) is_prime[j]=false;
    }

    while(t--){
        long long x; cin>>x;
        if(x<=1){ cout<<"NO\n"; continue; }
        long long r = floor(sqrt((long double)x));
        if(r*r==x && r<=MAXP && is_prime[(int)r]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
