#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        char info;        // symbol
        int num;          // frequency of the symbol
        Node* lc;
        Node* rc;
        Node() {
            this->num = 0;
            this->info = '\n';
            lc = NULL;
            rc = NULL;
        }
        Node( char info, int num ) {
            this->info = info;
            this->num = num;
            lc = NULL;
            rc = NULL;
        }
};
Node* root;

class Comp {
    public :
        bool operator () ( const Node* a, const Node* b ) {
            return a->num > b->num;
        }
};

string encode( string message ) {
    string msg = message;
    sort( msg.begin(), msg.end() );
    string::iterator st = unique( msg.begin(), msg.end() );
    vector<Node*> ctr; 
    for( string::iterator it = msg.begin(); it != st; it++ ) {
        Node *x = new Node( *it, count( message.begin(), message.end(), *it ) );
        ctr.push_back(x);
    }
    sort( ctr.begin(), ctr.end(), Comp() );
    root = new Node();
    Node *currroot = root;
    int p = 0;
    while( p < ctr.size()-2 ) {
        Node* ele = ctr[p];
        currroot -> lc = ele;
        currroot -> rc = new Node();
        currroot = currroot -> rc;
        p++;
    }
    currroot -> lc = ctr[p];
    currroot -> rc = ctr[p+1];
    string encoded;
    for( string::iterator it = message.begin(); it != message.end(); ++it ) {
        Node* temprc;
        currroot = root;
        while( currroot -> lc != NULL) {
            if( currroot -> lc -> info == *it ) {
                encoded.push_back('0');
                temprc = NULL;
                break;
            }
            else {
                currroot = currroot -> rc;
                temprc = currroot -> rc;
                encoded.push_back('1');
            }
        }
        if( temprc != NULL && temprc -> num != 0) {
            encoded.push_back('1');
        }
    }
    return encoded;
}

string decode( string msg ) {
    string decoded;
    Node* currroot = root;
    for( string::iterator it = msg.begin(); it != msg.end(); ++it ) {
        if( currroot -> lc == NULL ) {
            decoded.push_back( currroot -> info );
            currroot = root;
        }
        if( *it == '0' ) {
            currroot = currroot -> lc;    
        }
        else if( *it == '1' ) {
            currroot = currroot -> rc;
        }
    }
    decoded.push_back( currroot -> info );
    return decoded;
}

int main() {
    string msg;
    cout << "Enter the message : ";
    cin >> msg;
    cout << "The encoded message is : " << encode (msg);
    cout << "\nThe decoded message is : " << decode (encode(msg));
    return 0;
}
