#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int main(){
    vector<vector<int>> v={{1,4},{2,8},{3,4}};
    int n=v.size();
    sort(v.begin(),v.end());
    for(auto i:v){
        cout<<i[0]<<" "<<i[1]<<endl;
    }

    stack<vector<int>> s;
    s.push(v[0]);
    for(int i{1};i<v.size();i++){
            vector<int> curr=s.top();
            vector<int> loop=v[i];
            if(loop[0]>=curr[0] && (loop[1]<=curr[1] || loop[1]>curr[1])){
                continue;
            }
            else{
                s.push(loop);
            }
    }

    cout<<s.size()<<" ";
}