/*
 * @Author: xinyu Li
 * @Date: 2022-03-24 09:25:18
 * @LastEditTime: 2022-03-24 11:35:12
 * @Description: 
 * @FilePath: \helloworld\luogu\P2096.cpp
 * chaos is a ladder
 */
#include<bits/stdc++.h>
using namespace std;
// int vis[22], g[22][22], n, v[22], maxw, w;
// vector<int> tmp, path;
// void dfs(int root)
// {
//     vis[root] = 1;
//     if(w>maxw) {
//         maxw = w;
//         path=tmp;    
//     }
//     for(int i=root+1;i<=n;i++){
//         if(!vis[i] && g[root][i]){
//             tmp.push_back(i);
//             w+=v[i];
//             dfs(i);
//             w-=v[i];
//             tmp.pop_back();
//         }   
//     }
// }
// void DFStravel()
// {
//     for(int i=1;i<=n;i++){
//         memset(vis,0,sizeof(vis));
//         if(!vis[i]){
//             w = v[i];
//             tmp.clear();
//             tmp.push_back(i);
//             dfs(i);
//         }
//     }
// }
// int main(){
//     cin>>n;
//     fill(g[0], g[0]+22*22, 1);
//     for(int i=1;i<=n;i++)
//         cin>>v[i];
//     for(int i=1;i<=n;i++){
//         for(int j=i+1;j<=n;j++){
//             cin>>g[i][j];
//             g[j][i] = g[i][j];
//         }
//     }
//     DFStravel();
//     for(int i=0;i<path.size();i++){
//         cout<<path[i];
//         if(i<path.size()-1) cout<<" ";
//     }
//     cout<<endl;
//     cout<<maxw<<endl;
//     system("pause");
// }
int dp[22], n, Prev[22], maxw, besti;  //dp[i]:从上往下到i点为止最大地雷数
vector<int> g[22];
void ff(int root){
    if(root==0){
        return ;
    }
    ff(Prev[root]);
    if(Prev[root]!=0) cout<<" ";
    cout<<root;
    
}
int main()
{
    cin>>n;
    int a;
    for(int i=1;i<=n;i++) {cin>>a;g[i].push_back(a);}
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            cin>>a;
            g[i].push_back(a);
        }
    dp[1]=g[1][0];
    maxw=dp[1];
    besti=1;
    Prev[1]=0;
    int MAX, u;
    for(int i=2;i<=n;i++){
        MAX = 0;
        u = 0;
        for(int j=i-1;j>=1;j--)
            if(dp[j] > MAX && g[j][i-j]) {MAX = dp[j];u=j;}
        if(u!=0) 
            dp[i] = MAX+g[i][0];
        else 
            dp[i] = g[i][0];
        if(maxw<dp[i]) {maxw = dp[i];besti=i;}
        Prev[i] = u;
    }
    ff(besti);
    cout<<endl;
    cout<<maxw<<endl;
    system("pause");
}