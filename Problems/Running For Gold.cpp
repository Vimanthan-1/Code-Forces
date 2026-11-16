//https://codeforces.com/group/ibNhxWfOek/contest/341358/problem/B

//Startt from a current_king as 1
//Check with next
//If a winner Move i and change curr king
//At the end Check with all 

#include <iostream>
#include <vector>
using namespace std;
int check_champ(){
    int curr_king=0;
    int n;
    cin>>n;
    cout<<endl;
    vector<vector<int>> data(n,vector<int>(5,0));
    for(int i{0};i<n;i++){
        for(int j{0};j<5;j++){            
            cin>>data[i][j];
        }
    }

    int counter=0;
    while(counter<n && curr_king<n){
        int diff_1=0;
        int diff_2=0;
        for(int i{0};i<5;i++){
            if(data[counter][i]<data[curr_king][i]){
                diff_1++;
            }else{
                diff_2++;
            }
        }

        if(diff_1>=3){
            curr_king=counter;
        }
        counter++;
    }


    int count=0;
    bool isok=false;
    while(count<n){
        int diff_1=0;
        int diff_2=0;
        for(int i{0};i<5;i++){
            if(data[count][i]<data[curr_king][i]){
                diff_1++;
            }else{
                diff_2++;
            }
        }

        if(diff_1>=3){
            isok=true;
        }
        count++;
    }

    if(isok) return -1;
    else return curr_king+1;
}
int main(){
    int t;
    cin>>t;
    for(int i{0};i<t;i++){
        int ans=check_champ();
        cout<<ans<<endl;
    }
}