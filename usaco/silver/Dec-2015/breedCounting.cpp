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
    
    int n, q; cin >> n >> q;
    V<vi> arr(3, vi(1, 0)); 
    F0R(i, n) {
        int x; cin >> x;
        arr[x-1].pb(arr[x-1][i] + 1);
    }
    F0R(i, q) {
        int a, b; cin >> a >> b;
        cout << arr[0][b]-arr[0][a]+1 << arr[1][b]-arr[1][a]+1 << arr[2][b]-arr[2][a]+1 << "\n";
    }
    
    return 0;
}

