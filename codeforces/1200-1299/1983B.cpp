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
        int n, m; cin >> n >> m;
        vi rowOne(n), colOne(m), rowTwo(n), colTwo(m);
        F0R(i, n) {
            str s; cin >> s;
            F0R(j, m) {
                rowOne[i] += (int)(s[j] - '0');
                colOne[j] += (int)(s[j] - '0');
            }
        } F0R(i, n) {
            str s; cin >> s;
            F0R(j, m) {
                rowTwo[i] += (int)(s[j] - '0');
                colTwo[j] += (int)(s[j] - '0');
            }
        }
        bool works = true;
        F0R(i, n) {
            if(rowOne[i] % 3 != rowTwo[i] % 3) {
                works = false;
                break;
            }
        } F0R(i, m) {
            if(colOne[i] % 3 != colTwo[i] % 3) {
                works = false;
                break;
            }
        }
        if(works) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
        
    }
    
    return 0;
}

