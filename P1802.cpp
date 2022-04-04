/*
 * @Author: xinyu Li
 * @Date: 2022-03-27 09:31:43
 * @LastEditTime: 2022-03-27 10:14:39
 * @Description: 
 * @FilePath: \helloworld\luogu\P1802.cpp
 * chaos is a ladder
 * #include<bits/stdc++.h>
 * using namespace std;
 */
#include<bits/stdc++.h>
using namespace std;
long long dp[1010][1010],w[1010], l[1010];
int n, x, u[1010];
int main()
{
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>l[i]>>w[i]>>u[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){   //这里注意等于j=0时的dp[i][j]!=0
            if(u[i]>j)
                dp[i][j] = dp[i-1][j]+l[i];
            else
                dp[i][j] = max(dp[i-1][j]+l[i], dp[i-1][j-u[i]]+w[i]);
        }
    }
    printf("%lld\n", 5*dp[n][x]);
    system("pause");
}