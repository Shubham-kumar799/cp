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
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<dd> vd;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pi> vpi;
typedef vector<ti> vti;
typedef vector<pll> vpll;
typedef vector<vc> vvc;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vd> vvd;
typedef stack<int> sti;
typedef stack<pi> stpi;
typedef queue<int> qi;
typedef queue<pi> qpi;
typedef set<int> si;
typedef set<ll> sll;
typedef set<pi> spi;
typedef set<pll> spll;
typedef multiset<int> msi;
typedef map<int, int> mi;
typedef map<pi, int> mpi;
typedef map<ll, ll> mll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
template <class T>
using mipq = priority_queue<T, vector<T>, greater<T>>;
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
#define prDouble(x) cout << fixed << setprecision(12) << x
int toint(const string &s)
{
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}
void tointV(const string &s, vi &ans)
{
  stringstream ss;
  int x;
  str temp;
  ss << s;

  while (!ss.eof())
  {
    /* extracting word by word from stream */
    ss >> temp;
    /* Checking the given word is integer or not */
    if (stringstream(temp) >> x)
      ans.pb(x);
    /* To save from space at the end of string */
    temp = "";
  }
}

const ll INF = 1e9;
const ll NINF = -INF;
const int M = 1e9 + 7;
const int S = 1e6 + 1;

// CUSTOM COMPARATOR
// struct comp
// {
//   bool operator()(const pi &u, const pi &v)
//   {
//     int diff1 = u.second - u.first;
//     int diff2 = v.second - v.first;
//     return diff1 <= diff2;
//   }
// };

class FTree
{
  ll *bit;
  int n;

public:
  FTree(int _n)
  {
    bit = new ll[_n + 1];
    n = _n + 1;
    fr(i, 0, n) bit[i] = 0;
  }

public:
  void pointUpdate(int idx, int val)
  {
    for (idx; idx < n; idx += (idx & (-idx)))
    {
      bit[idx] += val;
    }
  }

public:
  ll sum(int idx)
  {
    ll res = 0;
    for (idx; idx > 0; idx -= (idx & (-idx)))
    {
      res += bit[idx];
    }
    return res;
  }

public:
  ll rangeQuery(int l, int r)
  {
    return sum(r) - sum(l - 1);
  }

public:
  void rangeUpdate(int l, int r, int delta)
  {
    pointUpdate(l, delta);
    pointUpdate(r + 1, -delta);
  }
};

int main()
{

  return 0;
}
