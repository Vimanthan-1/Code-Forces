#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <utility>
using namespace std;

string digitSum(string s, int k)
{
    if (s.size() <= k)
        return s;

    
    
    int tot=0;
    while (s.size() > k)
    {
        int curr = 0;
        string test = "";
        int n = s.size();
        for (int i{0}; i < ceil(1.0 * n / k); i++)
        {

            string temp = (curr + k > n) ? s.substr(curr, n - curr) : s.substr(curr, k);
            int sum = 0;
            for (int j{0}; j < temp.size(); j++)
            {
                sum += temp[j] - '0';
            }
            tot+=sum;
            test += to_string(sum);
            curr += k;
        }
        s=test;
    }
    return s;
}

int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    string res=digitSum(s,k);
    cout<<res<<endl;
    return 0;
}