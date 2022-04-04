#include<bits/stdc++.h>
using namespace std;
int r;
vector<pair<int, int>> dp[1001];
int main()
{
    cin>>r;
    int a;
    for(int i=1;i<=r;i++){
        for(int j=0;j<i;j++){
            scanf("%d", &a);
            dp[i].push_back(make_pair(a,0));
        }
    }
    int MAX = dp[1][0].second;
    dp[1][0].second = dp[1][0].first;
    for(int i=2;i<=r;i++){
        for(int j=0;j<i;j++){
            dp[i][j].second = max((j-1>=0)?dp[i-1][j-1].second:0, (j<i-1)?dp[i-1][j].second:0)+dp[i][j].first;
            if(MAX < dp[i][j].second) MAX = dp[i][j].second;
        }
    }
    
    cout<<MAX<<endl;
    system("pause");
}
