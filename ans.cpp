#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <utility>
#include <iterator>
#include <cmath>
#include <time.h>
#include <iomanip>
using namespace std;
#define MOD = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef vector<int> Vi;  typedef vector<Vi> VVi;
typedef vector<ll> Vll;  typedef vector<Vll> VVll;
typedef vector<bool> Vb; typedef vector<Vb> VVb;
typedef vector<string> Vs;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<V<T>>;
#define rep(i, a, b) for(ll i = a; i < (ll)(b); i ++)
#define drep(i, a, b, d) for(ll i = a; i >= (ll)(a); i += (ll)d)
#define rrep(i, a, b) for(ll i = b-1; i >= (ll)(a); i --)
#define prec(d) cout << fixed << setprecision(d);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[8] = {-1, 0, 1,-1, 1, -1, 0, -1};
const string br = "\n";
class UnionFind
{
public:
    explicit UnionFind(ll n) : ps(n, (ll)-1), n(n) {}
    int find(int i) { if(ps[i] < 0) return i; ps[i] = find(ps[i]); return ps[i]; }
    void merge(int a, int b)
    {
        int x = find(a), y = find(b); if(x == y) return;
        if(-ps[x] < -ps[y]) swap(a, b);
        ps[x] += ps[y]; ps[y] = x;
    }
    bool connected(int a, int b) { return (find(a) == find(b)); }
    ll size(int a) { return -(ps[find(a)]); }
    VVll groups()
    {
        VVll tree(n), ret;
        rep(i, 0, n) tree[find(i)].emplace_back(i);
        rep(i, 0, n) if (!tree[i].empty()) ret.emplace_back(tree[i]);
        return ret;
    }
private: Vi ps; ll n;
};
template<typename T> VV<T> rotate(VV<T> m)
{
    int h = m.size(), w = m.at(0).size(); VV<T> r(w, V<T>(h));
    rep(i, 0, w)rrep(j, 0, h) r[i][h-j-1] = m[j][i];
    return r;
} // rotates vector of vectors clockwise
template<typename T> VV<T> shift(VV<T> m, int n, bool vertical = false) {
    int h = (int)m.size(), w = (int)m.at(0).size(); VV<T> r(h);
    if(vertical) rep(i, 0, h) r[i] = m[(i + n) % h];
    else rep(i, 0, h)rep(j, 0, w) r[i].push_back(m[i][(j + n) % w]);
    return r;
} // shifts vector of vectors
Vs shift(Vs m, int n, bool vertical = true)
{
    int h = (int)m.size(), w = (int)m.at(0).size(); Vs r(h);
    if(vertical) rep(i, 0, h) r[i] = m[(i + n) % h];
    else rep(i, 0, h)rep(j, 0, w) r[i].push_back(m[i][(j + n) % w]);
    return r;
} // shifts vector of strings
ll StoI(string s)
{
    int n = (int)s.size(), begin = (s[0] == '-' ? 1 : 0); ll ret = 0;
    rep(i, begin, n-1) { ret += s[i]-48; ret *= 10; }
    ret += s[n-1]-48; return (begin ? -ret : ret);
} // converts string to integer
bool isPal(string s)
{
    int n = (int)s.size(); bool check = true;
    rep(i, 0, n/2) if(s[i] != s[n - 1 - i]) check = false;
    return check;
} // judges if s is palindrome or not
ll Pow(ll a, ll b)
{
    ll ret = 1;
    while(b > 0) { if(1 & b) ret *= a; a *= a; b >>= 1; }
    return ret;
}
template<typename T> void qsort(V<T> &vec, ll a = 0, ll b = -1)
{
    ll head = a, tail = ((b < 0) ? vec.size() : b + 1);
    sort(vec.begin() + head, vec.begin() + tail);
}
template<typename T> void msort(V<T> &vec, ll a = 0, ll b = -1)
{
    ll head = a, tail = ((b < 0) ? vec.size() : b + 1);
    stable_sort(vec.begin() + head, vec.begin() + tail);
}
template<typename T> ll bsearch(V<T> vec, T value, bool not_sorted = false)
{
    if(not_sorted) sort(vec.begin(), vec.end());
    auto itr = lower_bound(vec.begin(), vec.end(), value);
    return ((itr != vec.end()) ? (itr - vec.begin()) : -1);
}
void yesno(bool b = true, const string& yes = "Yes", const string& no = "No") { cout << (b ? yes : no) << "\n"; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // write below

}