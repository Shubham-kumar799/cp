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

#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define fr(k, start, end) for (int k = start; k < end; k++)
#define frr(k, start, end) for (int k = start; k >= end; k--)
#define prDouble(x) cout << fixed << setprecision(1) << x
int toint(const string &s)
{
  stringstream ss;
  ss << s;
  int x;
  ss >> x;
  return x;
}

const ll INF = 1e17;
const ll NINF = -INF;
const int N = 1000000007;
const int M = 1e9 + 7;
const int S = 1e6 + 1;

// CUSTOM COMPARATOR FOR SETS
// struct comp
// {
//   bool operator()(const pi &u, const pi &v)
//   {
//     int diff1 = u.second - u.first;
//     int diff2 = v.second - v.first;
//     return diff1 <= diff2;
//   }
// };

class SGTree
{
  int *seg;
  int *lazy;

public:
  SGTree(int n)
  {
    seg = new int[4 * n + 1];
  }

  void build(int ind, int low, int high, vi &arr)
  {
    if (low == high)
    {
      seg[ind] = arr[low];
      return;
    }

    int mid = low + ((high - low) >> 1);
    build(2 * ind + 1, low, mid, arr);
    build(2 * ind + 2, mid + 1, high, arr);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

public:
  int query(int ind, int low, int high, int l, int r)
  {

    // LAZY PROPAGATION
    // if (lazy[ind] != 0)
    //     {
    //       seg[ind] += lazy[ind];
    //       // propagting the update to the children nodes
    //       if (low != high)
    //       {
    //         lazy[2 * ind + 1] += lazy[ind];
    //         lazy[2 * ind + 2] += lazy[ind];
    //       }
    //       lazy[ind] = 0;
    //     }

    // No Overlap
    if (low > r || high < l)
      return INT_MAX;

    // Complete Overlap
    if (low >= l && high <= r)
      return seg[ind];

    // Partial Overlap
    int mid = low + ((high - low) >> 1);
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return min(left, right);
  }

public:
  // DEFINE A LAZY ARRAY FIRST (USES LAZY PROPAGATION)
  void rangeUpdateLazy(int ind, int low, int high, int l, int r, int val)
  {

    // update previous remaining updates;
    if (lazy[ind] != 0)
    {
      seg[ind] = (high - low + 1) * lazy[ind];
      // propagting the update to the children nodes
      if (low != high)
      {
        lazy[2 * ind + 1] += lazy[ind];
        lazy[2 * ind + 2] += lazy[ind];
      }
      lazy[ind] = 0;
    }

    // no overlap
    if (high < l || low > r)
      return;

    // complete overlap
    if (low >= l && high <= r)
    {
      seg[ind] = (high - low + 1) * val;
      // propagating the update downwards
      if (low != high)
      {
        lazy[2 * ind + 1] += val;
        lazy[2 * ind + 2] += val;
      }
      return;
    }

    // Partial overlap
    int mid = low + ((high - low) >> 1);
    rangeUpdateLazy(2 * ind + 1, low, mid, l, r, val);
    rangeUpdateLazy(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

public:
  void update(int ind, int low, int high, int i, int val)
  {
    if (low == high)
    {
      seg[ind] = val;
      return;
    }

    int mid = low + ((high - low) >> 1);
    if (i <= mid)
      update(2 * ind + 1, low, mid, i, val);
    else
      update(2 * ind + 2, mid + 1, high, i, val);
    seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
  }

public:
  void rangeUpdate(int ind, int low, int high, int l, int r, vi &par, int p)
  {
    if (low == high)
    {
      if (low == p - 1 || par[low] != 0)
        return;
      seg[ind] = 0;
      par[low] = p;
      return;
    }

    int mid = low + ((high - low) >> 1);

    if (l <= mid && seg[2 * ind + 1])
    {
      rangeUpdate(2 * ind + 1, low, mid, l, min(mid, r), par, p);
    }
    if (r > mid && seg[2 * ind + 2])
    {
      rangeUpdate(2 * ind + 2, mid + 1, high, max(l, mid + 1), r, par, p);
    }
    seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
  }
};

int main()
{

  return 0;
}
