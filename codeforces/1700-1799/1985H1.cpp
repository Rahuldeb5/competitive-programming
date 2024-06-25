/**
* @problem: H1. Maximize the Largest Component (Easy Version)
* @link: https://codeforces.com/problemset/problem/1985/H1
* @author: Rahul Deb
* @date: 2024-06-15 20:48
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

V<str> graph; 
V<vi> idGrid; // start off with -1s
vi componentSize; // push back

V<V<bool>> visited;

int n, m; // x value is m, y value is n

V<vi> dxy = {{-1,0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int y, int x, int id) {
    visited[y][x] = true;
    idGrid[y][x] = id;
    int count = 1;

    trav(ele, dxy) {
        if((ele[0] + x >= 0 && ele[0] + x < m) && (ele[1] + y >= 0 && ele[1] + y < n)) {
            if(graph[y+ele[1]][x+ele[0]] == '#' && !visited[y+ele[1]][x+ele[0]]) {
                count += dfs(y+ele[1], x + ele[0], id);
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(nullptr);
        
    int t; cin >> t;
    
    while(t-- > 0) {
        cin >> n >> m;

        graph.clear();
        F0R(i, n) {
            str x; cin >> x;
            graph.pb(x);
        }
        visited.clear();
        visited.resize(n, V<bool>(m, false));
        idGrid.clear();
        idGrid.resize(n, vi(m, -1));
        componentSize.clear();

        int id {};

        F0R(i, n) { // y values
            F0R(j, m) { // x values
                if(graph[i][j] == '#' && !visited[i][j]) {
                    componentSize.pb(dfs(i, j, id));
                    id++;
                }
            }
        }

        int ans = max(n, m);

        F0R(i, n) { // going through each row
            multiset<int> alreadyAdded;
            int sum {}; int count {}; // finds sum and dots

            F0R(j, m) {
                if(idGrid[i][j] != -1) {
                    auto it = alreadyAdded.find(idGrid[i][j]);
                    if(it == alreadyAdded.end()) { // element not in multiset
                        sum += componentSize[idGrid[i][j]];
                        alreadyAdded.insert(idGrid[i][j]);
                    }
                }
                if(i-1 >= 0 && idGrid[i-1][j] != -1) {
                    auto it = alreadyAdded.find(idGrid[i-1][j]);
                    if(it == alreadyAdded.end()) { // element not in multiset
                        sum += componentSize[idGrid[i-1][j]];
                        alreadyAdded.insert(idGrid[i-1][j]);
                    }
                }
                if(i+1 < n && idGrid[i+1][j] != -1) {
                    auto it = alreadyAdded.find(idGrid[i+1][j]);
                    if(it == alreadyAdded.end()) { // element not in multiset
                        sum += componentSize[idGrid[i+1][j]];
                        alreadyAdded.insert(idGrid[i+1][j]);
                    }
                }
                if(idGrid[i][j] == -1) count++;
            }
            ans = max(ans, sum+count);
        }
        
        F0R(j, m) { // going through each column
            multiset<int> alreadyAdded;
            int sum {}; int count {}; // finds sum and dots

            F0R(i, n) {
                if(idGrid[i][j] != -1) {
                    auto it = alreadyAdded.find(idGrid[i][j]);
                    if(it == alreadyAdded.end()) { // element not in multiset
                        sum += componentSize[idGrid[i][j]];
                        alreadyAdded.insert(idGrid[i][j]);
                    }
                }
                if(j-1 >= 0 && idGrid[i][j-1] != -1) {
                    auto it = alreadyAdded.find(idGrid[i][j-1]);
                    if(it == alreadyAdded.end()) { // element not in multiset
                        sum += componentSize[idGrid[i][j-1]];
                        alreadyAdded.insert(idGrid[i][j-1]);
                    }
                }
                if(j+1 < m && idGrid[i][j+1] != -1) {
                    auto it = alreadyAdded.find(idGrid[i][j+1]);
                    if(it == alreadyAdded.end()) { // element not in multiset
                        sum += componentSize[idGrid[i][j+1]];
                        alreadyAdded.insert(idGrid[i][j+1]);
                    }
                }
                if(idGrid[i][j] == -1) count++;
            }
            ans = max(ans, sum+count);
        }
        cout << ans << "\n";
    }

    return 0;
}
