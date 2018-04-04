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
typedef pair<ulli,ulli> pp;
typedef vector<vector<ulli>> matrix;
typedef vector<ulli> vi;

ulli n;
struct box{
    ulli h,w,d;
};
vector<box> vb;

bool scomp(box const &a,box const &b){
    return a.h<b.h;//asc
}

vi memo;

ulli max_h(ulli idx){
    if(idx<0){return 0;}
    ulli maxim=0;
    FOR(i,0,idx){
        if(vb[idx].h>vb[i].h && vb[idx].w>vb[i].w && vb[idx].d>vb[i].d){
            maxim=max(maxim,max_h(i));
        }
    }
    memo[idx]=maxim+vb[idx].h;
    return memo[idx];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    vb.resize(n);
    memo.assign(n,-1);
    ulli maxim=0;
    FOR(i,0,n){cin>>vb[i].h>>vb[i].w>>vb[i].d;}
    sort(be(vb),scomp);
    FOR(k,0,n){
        maxim=max(maxim,max_h(k));
    }
    cout<<maxim;
    return 0;
}
