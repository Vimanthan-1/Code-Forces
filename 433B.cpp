#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> value(n,0);
    for(int i{0};i<n;i++){
        cin>>value[i];
    }

    vector<long long> prefix_sum(n,0);
    prefix_sum[0]=value[0];
    for(int i{1};i<n;i++){
        prefix_sum[i]=value[i]+prefix_sum[i-1];
    }

    vector<long long> sort_prefix(n,0);
    sort(value.begin(),value.end());
    sort_prefix[0]=value[0];
    for(int i{1};i<n;i++){
        sort_prefix[i]=value[i]+sort_prefix[i-1];
    }

    int m;
    cin>>m;

     /* for(auto i:prefix_sum){
        cout<<i<<" ";
    }

    cout<<"Soretd prefix :"<<endl;

    for(auto i:sort_prefix){
        cout<<i<<" ";
    }  */
    for(int i{0};i<m;i++){
        int t,l,r;
        cin>>t>>l>>r;
        long long tot=0;
        if(t==1){
            l-=1;
            r-=1;
            if(l==0){
                cout<<prefix_sum[r]<<endl;
            }else{
                tot=prefix_sum[r]-prefix_sum[l-1];
                cout<<tot<<endl;
            }
        }else{
            l-=1;
            r-=1;
            if(l==0){
                cout<<sort_prefix[r]<<endl;
            }else{
                tot=sort_prefix[r]-sort_prefix[l-1];
                cout<<tot<<endl;
            }
        }
    }
}
