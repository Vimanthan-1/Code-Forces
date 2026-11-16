#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string check="666";
    for(int i{0};i<s.size();i+=3){
        for(int j{i};j<i+3;i++){
            if(s[j]!=check[j-i]){
                continue;
            }
        }

        
    }
}