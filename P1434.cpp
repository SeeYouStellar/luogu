#include<bits/stdc++.h>
using namespace std;
int h[110][110], dp[110][110], r, c;
struct node{
    int x, y, height;
};
struct cmp{
    bool operator()(node a, node b){return a.height>b.height;}
};
priority_queue<node, vector<node>, cmp> pq;
int main()
{   
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>h[i][j];
            node a;
            a.x = i;
            a.y = j;
            a.height = h[i][j];
            pq.push(a);
            dp[i][j] = 1;
        }
    }
    int MAX = 1;
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();
        int x = top.x, y = top.y, height = top.height;
        dp[x][y] = max((height>h[x][y-1]?dp[x][y-1]+1:0), dp[x][y]);
        dp[x][y] = max((height>h[x][y+1]?dp[x][y+1]+1:0), dp[x][y]);
        dp[x][y] = max((height>h[x+1][y]?dp[x+1][y]+1:0), dp[x][y]);
        dp[x][y] = max((height>h[x-1][y]?dp[x-1][y]+1:0), dp[x][y]);
        if(MAX < dp[x][y]) MAX = dp[x][y];
    }
    cout<<MAX<<endl;
    system("pause");
}