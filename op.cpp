/*Author - Saikia*/
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define N 998244353
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
#define INF 1000000000

struct trienode{
    struct trienode *child[26]; //initialised the children array
    int counter=-1; //to mark if its the end of a string or to assign a value, like in case of a map.
};

/*struct trienode* getNode(void){
    struct trienode* temp = new trienode;
    temp->counter= -1; //assigning -1 to denote it is not end of word.
    for(int i=0; i<26; i++){
        temp->child[i] = NULL;
    } 
    return temp;
}*/

void insert(struct trienode* root, string key, int val){
    struct trienode* temp = root;
    for(int i=0; i<key.size(); i++){
        int index = key[i]-'a';
        if(temp->child[index] == NULL){
            temp->child[index] = new trienode();
        }
        temp = temp->child[index];
    }
    temp->counter=val; //assign 0 as indicator or some value if used as a map.
}
int search(struct trienode* root, string key){
    struct trienode* temp = root;
    for(int i=0; i<key.size(); i++){
        int index= key[i]-'a';
        if(temp->child[index] == NULL){
            //checking in the if statement, if it is NULL, keyword not present.
            return -1;
        }
        temp=temp->child[index];
    }
    if(temp == NULL){return -1;}
    return temp->counter;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    /*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    */
    struct trienode *root = new trienode(); //initialising root node.
    ll a;
    cin>>a;
    REP(i, 0, a){
        string b;
        int c;
        cin>>b>>c;
        insert(root, b, c);
    }
    int q;
    cin>>q;
    REP(i, 0, q){
        string b;
        cin>>b;
        cout<<search(root, b)<<endl;
    }
}