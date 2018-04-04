#include<bits/stdc++.h>
#define pb push_back
#define be(v) v.begin(),v.end()
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define FORc(i,a,b,c) for(ll i=a;i<b;i+=c)
#define RFOR(i,a,b) for(ll i=a;i>b;--i)
#define RFORc(i,a,b,c) for(ll i=a;i>b;i-=c)
#define endl "\n"
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
//typedef int ll;
typedef pair<ll,ll> pp;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vi;

template<typename T>
bool scomp(T const &a,T const &b){
    return a<b;//asc
}

unordered_map<string,int> memo;
vi catalan;
string s;
int rans;

void calculate_catalan(ll n){
    catalan.assign(n+1,0);
    catalan[0]=1,catalan[1]=1;
    FOR(i,2,n+1){
        FOR(j,0,i){
            catalan[i]+=catalan[j]*catalan[i-j-1];
        }
    }
}

ll get_catalan_length(string const &s){
    assert(s.length()>0);
    return (s.length()-1)/2;
}

ll num_ways(string expr){
    assert(expr.length()!=0);
    if(expr.length()==1){return expr=="0"?1:0;}
    if(memo.find(expr)!=memo.end()){return memo[expr];}

    ll total_ways=0;
    FORc(i,1,expr.length(),2){
        string left_expr=expr.substr(0,i),right_expr=expr.substr(i+1);
        ll left_expr_0=num_ways(left_expr);
        ll right_expr_0=num_ways(right_expr);
        ll left_expr_1=catalan[get_catalan_length(left_expr)]-left_expr_0;
        ll right_expr_1=catalan[get_catalan_length(right_expr)]-right_expr_0;
        
        ll curr_ways_0=0;
        if(expr[i]=='|'){curr_ways_0+=left_expr_0*right_expr_0;}
        else if(expr[i]=='&'){curr_ways_0+=left_expr_0*right_expr_0+left_expr_0*right_expr_1+left_expr_1*right_expr_0;}
        else if(expr[i]=='^'){curr_ways_0+=left_expr_0*right_expr_0+left_expr_1*right_expr_1;}
        total_ways+=curr_ways_0;
    }
    memo[expr]=total_ways;
    return memo[expr];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>rans>>s;
    calculate_catalan(get_catalan_length(s));
    cout<<(rans?(catalan[get_catalan_length(s)]-num_ways(s)):num_ways(s));
    return 0;
}
