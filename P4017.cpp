/*
 * @Author: xinyu Li
 * @Date: 2022-03-24 11:37:32
 * @LastEditTime: 2022-03-25 13:20:20
 * @Description: 最大食物链计数
 * @FilePath: \helloworld\luogu\P4017.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
int INF = 80112002, n, m;
vector<long> g[5001];
struct cmp{
    bool operator()(long a, long b) {return g[a][0]>g[b][0];}
};
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) {g[i].push_back(0);g[i].push_back(0);g[i].push_back(0);}  //0:入度 2:出度 1:到该点路径数量
    int a, b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b][0]++;
        g[a][2]++;
    }
    priority_queue<long, vector<long>, cmp> pq; 
    vector<long> out;  //记录终止节点数量
    for(int i=1;i<=n;i++){
        if(!g[i][0]) {g[i][1] = 1;pq.push(i);}
        if(!g[i][2]) out.push_back(i);
    }

    while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        for(int i=3;i<g[top].size();i++){
            
            g[g[top][i]][0]--;
            g[g[top][i]][1]+=g[top][1];
            g[g[top][i]][1]%=INF;  //防止数值太大导致溢出，溢出不会报错
            if(!g[g[top][i]][0]) 
                pq.push(g[top][i]);
        }
    }
    long sum = 0;
    for(int i=0;i<out.size();i++){
        sum=(sum+g[out[i]][1])%INF;
    }
    cout<<sum<<endl;
    system("pause");
}