#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;
typedef string str;
typedef float fl;
typedef double dd;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> ppi;
typedef tuple<int, int, int> ti;
typedef tuple<ll, ll, ll> tll;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<dd> vd;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pi> vpi;
typedef vector<ti> vti;
typedef vector<tll> vtll;
typedef vector<pll> vpll;
typedef vector<vc> vvc;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vd> vvd;
typedef stack<int> sti;
typedef stack<pi> stpi;
typedef stack<char> stc;
typedef queue<int> qi;
typedef queue<ll> qll;
typedef queue<pi> qpi;
typedef set<int> si;
typedef set<char> sc;
typedef set<ll> sll;
typedef set<pi> spi;
typedef set<pll> spll;
typedef multiset<int> msi;
typedef multiset<ll> msll;
typedef map<int, int> mi;
typedef map<pi, int> mpi;
typedef map<ll, ll> mll;
typedef map<int, vi> mivi;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
template <class T>
using mipq = priority_queue<T, vector<T>, greater<T>>;
template <class T>
using maxq = priority_queue<T>;
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using vt = vector<T>;

#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define fr(k, start, end) for (int k = start; k < end; k++)
#define frr(k, start, end) for (int k = start; k >= end; k--)
#define prDouble(x) cout << fixed << setprecision(6) << x
#define all(x) x.begin(), x.end()

template <class T>
void prV(vector<T> &v)
{
  for (auto i : v)
    cout << i << " ";
  cout << endl;
}

const ll INF = 1e9;
const ll NINF = -INF;
const int M = 1e9 + 7;
const int S = 1e5 + 5;
const ll MOD = 998244353;

void solve() {}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
