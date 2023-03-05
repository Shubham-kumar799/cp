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
typedef priority_queue<pll, vpll, greater<pll>> mipqpi;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define fr(k, start, end) for (int k = start; k < end; k++)
#define frr(k, start, end) for (int k = start; k >= end; k--)
#define prDouble(x) cout << fixed << setprecision(10) << x
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
//   bool operator()(const pi &a, const pi &b)
//   {
//     int diff1 = a.second - a.first;
//     int diff2 = b.second - b.first;
//     return diff1 <= diff2;
//   }
// };

bool comp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
{
  if (a.first.second == b.first.second)
  {
    return a.first.first < b.first.first;
  }
  else if (a.first.first == b.first.first && a.first.second == b.first.second)
    return a.second > b.second;
  return

      a.first.second < b.first.second;
}

void toposort(queue<ll> &q, vi &inDeg, vi &par, map<int, vi> &graph)
{
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    for (auto nbr : graph[node])
    {
      inDeg[nbr]--;
      if (inDeg[nbr] == 0 && nbr != 1)
      {
        par[nbr] = node;
        q.push(nbr);
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  vb vis(n + 1);
  vll ways(n + 1, 0);
  ways[1] = 1;
  vi par(n + 1, -1);
  vi inDeg(n + 1);
  map<int, vi> graph;
  sti st;
  queue<ll> q;
  fr(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    graph[a].pb(b);
    inDeg[b]++;
  }

  fr(i, 2, n + 1)
  {
    if (inDeg[i] == 0)
      q.push(i);
  }
  toposort(q, inDeg, par, graph);
  q.push(1);
  par[n] = -1;
  toposort(q, inDeg, par, graph);
  if (par[n] == -1)
  {
    cout << "IMPOSSIBLE";
  }
  else
  {
    vi cyc;
    cyc.pb(n);
    for (int tv = n; tv != 1; tv = par[tv])
    {
      cyc.pb(par[tv]);
    }
    reverse(cyc.begin(), cyc.end());
    cout << cyc.size() << endl;
    for (auto i : cyc)
      cout << i << " ";
  }

  // if (par[n] != -1)
  // {
  // vi cyc;
  // cyc.pb(n);
  // for (int tv = n; tv != 1; tv = par[tv])
  // {
  //   cyc.pb(par[tv]);
  // }
  // reverse(cyc.begin(), cyc.end());
  // cout << cyc.size() << endl;
  // for (auto i : cyc)
  //   cout << i << " ";
  // }
  // else
  //   cout << "IMPOSSIBLE";

  return 0;
}
