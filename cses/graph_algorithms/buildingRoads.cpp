/**
* @problem: Building Roads
* @link: https://cses.fi/problemset/task/1666
* @author: Rahul Deb
* @date: 2024-06-15 09:31
**/

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using ll = long long;

#define F first
#define S second
#define all(x) x.begin(), x.end()
#define pb push_back
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define FORE(i,a,b) for(int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for(int i = (a); i >= (b); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for(auto& a: x)
#define sz(x) (int)x.size()

using str = string;
template<class T> using V = vector<T>;
using vi = V<int>;
using pii = pair<int, int>;

V<vi> adj;
V<bool> visited;

void dfs(int x) {
    visited[x] = true;

    F0R(j, sz(adj[x])) {
        if(!visited[adj[x][j]]) {
            dfs(adj[x][j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    int n, m; cin >> n >> m;

    visited.resize(n+1, false);
    adj.resize(n+1);

    F0R(i,m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    int ans {};
    vi road;

    FOR(i,1,n+1) {
        if(!visited[i]) {
            ans++;
            if(i > 1) {
                road.pb(i);
            }
            dfs(i);
        }
    }


    cout << (--ans) << "\n";
    F0R(i, sz(road)) {
        cout << 1 << " " << road[i] << "\n";
    }
    
    return 0;
}
