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

int main()
{
  int n, r;
  cin >> n >> r;
  vi h(n + 1);
  vi price(n + 1);
  mivi graph;
  fr(i, 1, n + 1) cin >> h[i];
  fr(i, 1, n + 1) cin >> price[i];
  fr(i, 0, n)
  {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }

  // solving
  // dir - up = 1;
  // dir - down = 2;
  vvll dis(n + 1, vll(3, LLONG_MAX));
  mipq<tuple<ll, int, int>> pq;
  dis[1][1] = dis[1][2] = price[1];
  pq.push({price[1], 1, 1});
  pq.push({price[1], 2, 1});
  while (!pq.empty())
  {
    int node, dir;
    ll cost;
    tie(cost, dir, node) = pq.top();
    pq.pop();
    // cout << node << " " << dir << " " << cost << endl;
    for (auto nbr : graph[node])
    {
      ll newCost = cost;
      int newDir = dir;
      if (h[node] >= h[nbr])
      {
        if (dir == 1)
        {
          newDir = 2;
          newCost += price[node];
        }
        if (dis[nbr][newDir] > newCost)
        {
          dis[nbr][newDir] = newCost;
          pq.push({newCost, newDir, nbr});
        }
      }
      newCost = cost;
      newDir = dir;
      // downwards
      if (h[node] <= h[nbr])
      {
        // move upwards
        if (dir == 2)
        {
          newDir = 1;
          newCost += price[node];
        }
        if (dis[nbr][newDir] > newCost)
        {
          dis[nbr][newDir] = newCost;
          pq.push({newCost, newDir, nbr});
        }
      }
    }
  }
  ll ans = min(dis[n][1], dis[n][2]);
  if (ans >= LLONG_MAX)
    cout << -1;
  else
    cout << ans;
  return 0;
}
