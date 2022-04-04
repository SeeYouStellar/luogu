/*
 * @Author: xinyu Li
 * @Date: 2022-03-27 10:30:17
 * @LastEditTime: 2022-03-27 12:50:43
 * @Description: 
 * @FilePath: \helloworld\luogu\P1002.cpp
 * chaos is a ladder
 * #include<bits/stdc++.h>
 * using namespace std;
 */
#include<bits/stdc++.h>
using namespace std;
int dx, dy, mx, my;
long long dp[25][25];
int x[9]={-2, 2, -1, 1, -2, 2, -1, 1, 0};
int y[9]={-1, -1, -2, -2, 1, 1, 2, 2, 0};
vector<pair<int, int>> v;
int main()
{
    cin>>dx>>dy>>mx>>my;
    fill(dp[0], dp[0]+dy+1, 1);
    for(int i=0;i<=dx;i++) dp[i][0]=1;
    for(int i=0;i<9;i++){
        if(mx+x[i]>=0 && my+y[i]>=0 && mx+x[i]<=dx && my+y[i]<=dy){
            v.push_back(make_pair(mx+x[i], my+y[i]));
            dp[mx+x[i]][my+y[i]]=0;
            if(mx+x[i]==0)
                for(int j=my+y[i];j<=dy;j++) dp[0][j]=0;
            if(my+y[i]==0)
                for(int j=mx+x[i];j<=dx;j++) dp[j][0]=0;
        }
    }
    // for(int i=0;i<=dx;i++){
    //     for(int j=0;j<=dy;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=1;i<=dx;i++){
        for(int j=1;j<=dy;j++){
            int k;
            for(k=0;k<v.size();k++){
                if(v[k].first==i && v[k].second==j) break;
            }
            if(k!=v.size())continue;
            int flag =1;
            for(int k=0;k<v.size();k++){
                if(v[k].first==i-1 && v[k].second==j) {flag=0;break;}
            }
            dp[i][j] = flag?dp[i-1][j]:0;
            flag=1;
            for(int k=0;k<v.size();k++){
                if(v[k].first==i && v[k].second==j-1) {flag=0;break;}
            }
            dp[i][j] += flag?dp[i][j-1]:0;
        }
    }
    // for(int i=0;i<=dx;i++){
    //     for(int j=0;j<=dy;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<dp[dx][dy]<<endl;
    system("pause");
}