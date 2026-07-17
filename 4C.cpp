#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    unordered_map<string,int> freq;
    int n;
    cin>>n;
    for(int i{0};i<n;i++){
        string s;
        cin>>s;
        auto it=freq.find(s);
        if(it==freq.end()){
            cout<<"OK"<<endl;
            freq[s]++;
        }else{
            string num=to_string(freq[s]);
            freq[s]++;
            cout<<s+num<<endl;
        }
    }
}