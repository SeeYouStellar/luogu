#include<bits/stdc++.h>
using namespace std;
int a[510], b[510], c[510];
string sa, sb;
int main()
{
    int tmp = 0;
    cin>>sa>>sb;
    for(int i=0; i<sa.length(); i++) a[i] = sa[sa.length()-i-1]-'0';
    for(int i=0; i<sb.length(); i++) b[i] = sb[sb.length()-i-1]-'0';
    int i=0, aa, bb;
    while(i<max(sa.length(), sb.length())){
        aa = (i>=sa.length())?0:a[i];
        bb = (i>=sb.length())?0:b[i];
        
        c[i++] = (aa+bb+tmp)%10;
        tmp = (aa+bb+tmp)/10;
    }
    if(tmp)
        c[i++] = tmp;
    for(int j=i-1;j>=0;j--) cout<<c[j];
    cout<<endl;
    system("pause");
}