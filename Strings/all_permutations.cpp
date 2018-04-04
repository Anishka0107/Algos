#include<bits/stdc++.h>
#define pb push_back
#define be(v) v.begin(),v.end()
#define FOR(i,a,b) for(ulli i=a;i<b;++i)
#define RFOR(i,a,b) for(ulli i=a;i>b;--i)
#define endl "\n"
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
//typedef unsigned long long int int;
typedef pair<int,int> pp;
typedef vector<vector<int>> matrix;
typedef vector<int> vi;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin>>s;
    sort(be(s));
    while(true){
        cout<<s<<endl;
        ulli i=s.length()-2,j=s.length()-1;
        while(i>=0){
            if(s[i]<s[i+1]){break;}
            i--;
        }
        if(i==-1){break;}
        while(j>i){
            if(s[i]<s[j]){break;}
            j--;
        }
        swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end());
    }
    return 0;
}
