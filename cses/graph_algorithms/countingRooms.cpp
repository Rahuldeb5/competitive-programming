/**
* @problem: Counting Rooms
* @link: https://www.cses.fi/problemset/task/1192
* @author: Rahul Deb
* @date: 2024-06-14 22:13
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

V<V<bool>> visited;
V<str> grid;
int n, m;

V<pii> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int x, int y) {
    visited[x][y] = true;

    FOR(i, 0, sz(d)) {
        if(x+d[i].F < n && y+d[i].S < m && x+d[i].F >= 0 && y+d[i].S >= 0) {
            if(grid[x+d[i].F][y+d[i].S] == '.' && visited[x+d[i].F][y+d[i].S] == false) {
                dfs(x+d[i].F, y+d[i].S);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
    
    cin >> n >> m;
    visited.resize(n, V<bool>(m, false));
    grid.resize(n);
    
    FOR(i, 0, n) {
        cin >> grid[i];
    }

    int ans {};

    FOR(i, 0, n) {
        FOR(j, 0, m) {
            if(grid[i][j] == '.' && !visited[i][j]) {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans;
    
    return 0;
}
