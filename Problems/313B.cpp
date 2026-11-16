#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    int n = s.size();

    vector<int> dp(n, 0);

    dp[0]=0;

    for (int i{0}; i < n-1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i+1] = dp[i] + 1;
        }
        else
        {
            dp[i+1] = dp[i];
        }
    }
 
    for (int i{0}; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        cout << abs(dp[r-1] - dp[l-1]) << endl;
    }
}