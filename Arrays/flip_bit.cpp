#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin>>s;
    ulli n=s.length(),maxim=0,count_1=0,auxcount;
    for(ulli i=0;i<n;i++){
        if(s[i]=='0'){
            if(i>0&&s[i-1]=='1' || i<n-1&&s[i+1]=='1'){
                i++,count_1++,auxcount=0;
                while(s[i]=='1'){auxcount++,i++;}
                maxim=max(maxim,count_1+auxcount);
                count_1=auxcount,i--;
            }else{count_1=0;}
        }else{count_1++;}
        maxim=max(maxim,count_1);
    }
    cout<<maxim;
    return 0;
}

