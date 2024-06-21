/**
* @problem: Building Teams
* @link: https://cses.fi/problemset/task/1668
* @author: Rahul Deb
* @date: 2024-06-20 20:03
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
#define R0F(i,a) ROF(i,a,0)
#define trav(a,x) for(auto& a: x)
#define sz(x) (int)x.size()

using str = string;
template<class T> using V = vector<T>;
using vi = V<int>;
using pii = pair<int, int>;

vi team;
V<vi> adj;
bool possible = true;

void dfs(int a, int curr) {
    if(team[a] == 0) {
        team[a] = curr;
    } else {
        return;
    }

    trav(x, adj[a]) {
        dfs(x, curr+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    int n, m; cin >> n >> m;
    team.resize(n+1, 0);
    adj.resize(n+1);

    F0R(i, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    FOR(i, 1, n+1) {
        if(team[i] == 0) dfs(i, 1);
    }

    FOR(i, 1, sz(adj)) {
        trav(x, adj[i]) {
            if((team[i] % 2)  == (team[x] % 2)) {
                possible = false;
                break;
            }
        }
        if(!possible) break;
    }

    if(!possible) {
        cout << "IMPOSSIBLE";
    } else {
        FOR(i, 1, n+1) {
            cout << (team[i] % 2) + 1 << " ";
        }
    }
    
    return 0;
}
