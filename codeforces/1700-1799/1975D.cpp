/**
 * @problem: 
 * @link: 
 * @author: Rahuldeb5
 * @date: 2024-
 **/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
 
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define R0F(i,a) ROF(i,a,0)
#define trav(a,x) for(auto& a: x)
#define sz(x) (int)x.size()
#define rsz resize
#define cl clear
 
using str = string;
template<class T> using V = vector<T>;
using vi = V<int>;
using pii = pair<int, int>;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,
            tree_order_statistics_node_update> indexed_set;
 
void setIO(string name = "") {  // name is nonempty for USACO file I/O
	cin.tie(0)->sync_with_stdio(0);
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin);  // see Input & Output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
 
signed main() {
    setIO();
    
    int t; cin >> t;
    while(t-- > 0) {
        int n; cin >> n;
        int a, b; cin >> a >> b; a--; b--;
        V<vi> adj(n);
        F0R(i, n-1) {
            int x, y; cin >> x >> y; x--; y--;
            adj[x].pb(y); adj[y].pb(x);
        }
        int ans {};
            
        // BFS 1 BABY!!!
        V<bool> visited(n, false);
        vi parent(n, -1);
 
        queue<int> q;
        visited[a] = true;
        q.push(a);
 
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
 
            if(cur == b) {
                break;
            }
            
            for(int ele : adj[cur]) {
                if(!visited[ele]) {
                    visited[ele] = true;
                    parent[ele] = cur;
                    q.push(ele);
                }
            }
        }
        vi boom;
        int temp = b;
        while(temp != a) {
            boom.pb(temp);
            temp = parent[temp]; 
        } boom.pb(a);
        
        ans += ceil((double)(sz(boom)-1) / 2.0);
        int target = boom[ans];
        
        // BFS 2 BABY
        V<bool> visited2(n, false);
        vi distance(n);
        distance[target] = 0;
        visited2[target] = true;
        queue<int> q2;
        q2.push(target);
        while(!q2.empty()) {
            int cur = q2.front(); q2.pop();

            for(int ele : adj[cur]) {
                if(!visited2[ele]) {
                    visited2[ele] = true;
                    distance[ele] = distance[cur] + 1;
                    q2.push(ele);
                }
            }
        }
        sort(all(distance));
        ans += 2*(n-1) - distance[sz(distance)-1];
        cout << ans << "\n";
    }
    
    return 0;
}
