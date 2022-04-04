#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a, x, prev=0, sum=0;
    int n;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
        if(prev+a>x){
            sum+=a+prev-x;
            a=x-prev;
            
        }
        prev=a;
    }
    cout<<sum<<endl;
    system("pause");
}