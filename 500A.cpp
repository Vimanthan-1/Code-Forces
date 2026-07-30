#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n,target;
    cin>>n>>target;
    vector<int> portals(n+1,0);
    for(int i{1};i<n;i++){
        cin>>portals[i];
    }

    vector<int> vis(n+1,0);
    queue<long long> q;
    vis[1]=1;
    long long curr=1+portals[1];
    while(curr<target){
        curr=curr+portals[curr];
    }

    if(curr==target){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }


}