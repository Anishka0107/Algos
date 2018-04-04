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
vector<matrix> ans;

bool is_safe(const matrix& board,ulli r,ulli c){
    if(r<0 || r>=n || c<0 || c>=n){return false;}
    FOR(i,0,n){if(board[r][i]==1){return false;}else if(board[i][c]==1){return false;}}
    for(int i=r,j=c;i>=0&&j>=0;i--,j--){if(board[i][j]==1){return false;}}
    for(int i=r,j=c;i>=0&&j<n;i--,j++){if(board[i][j]==1){return false;}}
    return true;
}

bool all_n_queens(ulli r,matrix &board){
    if(r==n){ans.pb(board);return true;}
    bool retval=false;
    FOR(j,0,n){
        if(is_safe(board,r,j)){
            board[r][j]=1;
            bool val=all_n_queens(r+1,board);
            board[r][j]=0;
            if(val){retval=true;}
        }
    }
    return retval;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    matrix board(n,vi(n,0));
    all_n_queens(0,board);
    for(auto& ansv:ans){
        for(auto& vi:ansv){
            for(auto& vj:vi){
                cout<<vj<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
