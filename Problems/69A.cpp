#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int tot_x=0,tot_y=0,tot_z=0;
    int x,y,z;

    
    for (int i = 0; i < n; i++)
    {   
        cin>>x>>y>>z;
        tot_x+=x;
        tot_y+=y;
        tot_z+=z;
    }

    if(tot_x==0 && tot_y==0 && tot_z==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }

    return 0;    
}