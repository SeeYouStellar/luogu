#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
int main()
{
    char ch;
    int w = 0, l = 0, ww = 0, ll = 0;
    while(ch=getchar()){   
        if(ch == 'E'){
            printf("%d:%d\n", w, l);
            v.push_back(make_pair(ww, ll));
            break;
        }else if(ch=='\n') continue;
        
        if(ch=='W') {w++;ww++;}
        else if(ch=='L') {l++;ll++;}   //输入可能有空格，故这里不能用else

        if((abs(w-l))>=2 && (w>=11 || l>=11)) {printf("%d:%d\n", w, l);l=w=0;}
        if((abs(ww-ll))>=2 && (ww>=21 || ll>=21)) {v.push_back(make_pair(ww, ll));ww=ll=0;}
    }   
    printf("\n");
    for(auto i:v)
        printf("%d:%d\n", i.first, i.second);
    system("pause");
}

