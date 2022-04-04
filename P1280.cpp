#include<bits/stdc++.h>
using namespace std;
int n, k, dp[10000+10], s[10000+10], t[10000+10], e[10000+10];
int main()
{
    scanf("%d %d", &n, &k);
    for(int i=1;i<=k;i++){
        scanf("%d %d", &s[i], &t[i]);
        e[i]=s[i]+t[i]-1;
    }
    for(int i=n;i>=1;i--){
        int MAX = -1;
        for(int j=1;j<=k;j++){
            if(s[j]==i) 
                MAX = max(dp[e[j]+1], MAX);
        }
        dp[i] = (MAX==-1)?dp[i+1]+1:MAX;
    }
    printf("%d\n", dp[1]);
    system("pause");
}