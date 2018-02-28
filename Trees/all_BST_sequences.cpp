#include<bits/stdc++.h>
#define pb push_back
#define be(v) v.begin(),v.end()
#define FOR(i,a,b) for(ulli i=a;i<b;++i)
#define endl "\n"
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
//typedef unsigned long long int int;
typedef pair<int,int> pp;
typedef vector<vector<int>> matrix;
typedef vector<int> vi;

class Node{
    public:
        int info;
        Node *lc,*rc;
        Node(int info){
            this->info=info;
            lc=rc=NULL;
        }
};

class Tree{
    public:
        Node* root;
        Tree(){
            root=NULL;
        }
        matrix allbstseq(Node*);
        void printallbstseq();
};

void Tree::printallbstseq(){
    matrix aux=allbstseq(root);
    for(auto& i:aux){
        for(auto& j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

matrix Tree::allbstseq(Node* curr){
    matrix ans,l,r;
    vi v;
    if(!curr){ans.pb(v);return ans;}
    if(!curr->lc&&!curr->rc){v.pb(curr->info);ans.pb(v);return ans;}
    l=allbstseq(curr->lc),r=allbstseq(curr->rc);
    vi done;
    FOR(i,0,l[0].size()){done.pb(0);}
    FOR(i,0,r[0].size()){done.pb(1);}
    FOR(i,0,l.size()){
        FOR(j,0,r.size()){
            do{
                int li=0,ri=0;
                v.clear();
                v.pb(curr->info);
                for(auto& d:done){
                    if(d){v.pb(r[j][ri++]);}
                    else{v.pb(l[i][li++]);}
                }
                ans.pb(v);
            }while(next_permutation(be(done)));
        }
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Tree t;
    t.root=new Node(7);
    t.root->lc=new Node(4);
    t.root->rc=new Node(11);
    //t.root->lc->lc=new Node(1);
    //t.root->rc->lc=new Node(10);
    t.root->rc->rc=new Node(21);
    t.printallbstseq();
    return 0;
}
