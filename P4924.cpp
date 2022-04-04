#include<bits/stdc++.h>
using namespace std;
int x, y, r, z, n, m, aa[510][510];
void Invert(int r)
{
    int tmp[510][510];
    for(int i=x-r;i<=x+r;i++)
        for(int j=y-r;j<=y+r;j++) tmp[i][j] = aa[i][j];
    int x1 = x+r, y1 = y-r;
    int x0 = x-r, y0 = y-r;
    for(int i=0;i<2*r+1;i++){
        for(int j=0;j<2*r+1;j++){
            aa[x0+i][y0+j] = tmp[x1-j][y1];
        }
        y1++;
        x1=x+r;
    }
}
void Revert(int r)
{
    int tmp[510][510];
    for(int i=x-r;i<=x+r;i++)
        for(int j=y-r;j<=y+r;j++) tmp[i][j] = aa[i][j];
    int x1 = x-r, y1 = y+r;
    int x0 = x-r, y0 = y-r;
    for(int i=0;i<2*r+1;i++){
        for(int j=0;j<2*r+1;j++){
            aa[x0+i][y0+j] = tmp[x1+j][y1];
        }
        y1--;
        x1=x-r;
    }
}
int main()
{
    cin>>n>>m;
    int index = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            aa[i][j]=index++;
    while(m--){
        cin>>x>>y>>r>>z;
        if(z) Revert(r);
        else Invert(r);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<aa[i][j];
            if(j<n) cout<<" "; 
        }
        cout<<endl;
    }  
    system("pause");
}   