/*
 * @Author: xinyu Li
 * @Date: 2022-03-22 11:27:07
 * @LastEditTime: 2022-03-29 23:22:07
 * @Description: 
 * @FilePath: \helloworld\luogu\P1303.cpp
 * chaos is a ladder
 * #include<bits/stdc++.h>
 * using namespace std;
 */
#include<bits/stdc++.h>
using namespace std;
string sa, sb;
int a[2000+10], b[2000+10], c[2010*2010];
int main()
{
    int i, j;
    string oper;
    cin>>sa>>sb>>oper;
    for(i=0; i<sa.length(); i++) a[i] = sa[sa.length()-i-1]-'0';
    for(j=0; j<sb.length(); j++) b[j] = sb[sb.length()-j-1]-'0';
    if((i==1 && sa[0]-'0'==0) || (j==1 && sb[0]-'0'==0)) printf("0\n");
    else{
        int index;
        fill(c, c+2000+10, 0);
        for(int k=0;k<j;k++){
            int tmp = 0;
            index = k;
            for(int kk=0;kk<i;kk++){
                int tt = tmp;
                tmp = (b[k]*a[kk]+tmp+c[index])/10;
                c[index] = (b[k]*a[kk]+tt+c[index])%10;
                index++;
            }
            while(tmp){
                int tt = tmp;
                tmp = (tmp+c[index])/10;
                c[index] = (tt+c[index])%10;
                index++;
            }
        }
        for(int k=index-1;k>=0;k--)cout<<c[k];
        cout<<endl;
    }
    system("pause");
}