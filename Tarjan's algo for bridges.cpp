#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define mod 1000000007
#define md 998244353 
#define INF INT_MAX
#define vl vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vpl vector<pl>
#define vpi vector<pi>
#define ml map<ll,ll>
#define mi map<int,int>
#define m(a,b) map<a,b>
#define rep(i,n) for(int i=1;i<=n;i++)
#define mxn 100005
#define printfloat(y) cout<<fixed<<setprecision(9)<<y<<endl;
#define YesNo(f) if(f){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;continue;}
#define setval(a,val) memset(a,val,sizeof(a)) 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
vi adj[mxn];
int tIme=0;
vi disc;  //discovery time of u
vi low;   //'low' node of u
vpi bridges;    //articulation points
void dfsBridges(int node,int parent){
    low[node]=disc[node]=++tIme;

    for(auto child: adj[node]){
        if(child==parent){//we don't want to go back through the same path.
            continue; 	  // if we go back is because we found another way back
        }
        if(!disc[child]){   // if V has not been discovered before
            dfsBridges(child,node);  // recursive DFS call
            if(disc[node]<low[child]){	// condition to find a bridge
                bridges.pb(mp(node,child));
            }
            low[node]=min(low[node],low[child]);//low[v] might be
                                            	// an ancestor of u
        }else{  //if v was already discovered
            // means that we found an ancestor
            low[node]=min(low[node],disc[child]); // finds the ancestor with
                                                  // the least discovery time
        }
    }
}
void findBridges(int n){
    low=disc=vector<int>(mxn);
    bridges.clear();
    tIme=0;
    for(int u=1;u<=n;u++){
        if(!disc[u]){
            dfsBridges(u,u);
        }
    }
}
int main()
{
    fastIO;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int t=1;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m;
        rep(i,n){
            adj[i].clear();
        }
        for(int i=0;i<m;i++){
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        findBridges(n);
        for(auto i: bridges){
            cout<<i.F<<" "<<i.S<<endl;
        }
    }

return 0;
}