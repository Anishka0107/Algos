#include<bits/stdc++.h>

// to view clean output locally, pass ONLINE_JUDGE as parameter D (eg: g++ template.cpp -std=c++14 -Wall -DONLINE_JUDGE < input.txt > output.txt)
#ifndef ONLINE_JUDGE
#define ONLINE_JUDGE false
#endif

#define derr(debug_input) if(not ONLINE_JUDGE) cerr<<"\nDEBUGGING\tLINE "<<__LINE__<<": "<<#debug_input<<" -> "<<debug_input<<"\n"
#define endl "\n"
#define cinstr(s) getline(cin,s)
#define bigint __int128_t
#define ubigint __uint128_t
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template<class T>
bool scomp(const T &a,const T &b){
    return a<b;
}

const ll mod=1e9+7;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void run_for_test(){

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int _t=1;
    //cin>>_t;
    int T=_t;
    while(_t--){
        derr("Case #"<<T-_t<<": ");
        run_for_test();
    }
    return 0;
}
