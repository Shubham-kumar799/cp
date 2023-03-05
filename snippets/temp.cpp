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

void djikstra(int src, vll &dis, vb &vis, vll &lastAdded, map<int, vpi> &graph)
{
  dis[src] = 0;
  lastAdded[src] = 0;
  mipq<tuple<ll, int, int>> pq;
  pq.push({0, 0, src});
  while (!pq.empty())
  {
    int node, lastEdge;
    tie(ignore, ignore, node) = pq.top();
    pq.pop();
    if (vis[node])
      continue;
    vis[node] = 1;
    for (auto i : graph[node])
    {
      int wt = i.ss;
      int nbr = i.ff;
      if ((dis[nbr] > dis[node] + wt || (dis[nbr] == dis[node] + wt && wt < lastAdded[nbr])))
      {
        dis[nbr] = dis[node] + wt;
        lastAdded[nbr] = wt;
        pq.push({dis[nbr], wt, nbr});
      }
    }
  }
}

ll prim(int src, int n, map<int, vpi> &graph)
{
  ll mst = 0;
  vb vis(n, 0);
  mipq<pair<ll, int>> pq;
  pq.push({0, src});
  while (!pq.empty())
  {
    int node = pq.top().ss;
    int wt = pq.top().ff;
    pq.pop();
    if (vis[node])
      continue;
    vis[node] = 1;
    mst += wt;
    for (auto i : graph[node])
    {
      int nbr = i.ff;
      int nbrwt = i.ss;
      if (vis[nbr])
        continue;
      pq.push({nbrwt, nbr});
    }
  }
  return mst;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, m;
    cin >> n >> m;
    map<int, vpi> graph;
    fr(i, 0, m)
    {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].pb({v, w});
      graph[v].pb({u, w});
    }

    vll dis(n, LLONG_MAX);
    vll lastAdded(n, LLONG_MAX);
    vb vis(n, 0);
    djikstra(0, dis, vis, lastAdded, graph);
    ll mst = prim(0, n, graph);
    ll djikSum = 0;
    bool flag = true;
    fr(i, 0, n)
    {
      if (!vis[i])
      {
        flag = false;
        break;
      }
      djikSum += lastAdded[i];
    }
    if (mst == djikSum && flag)
      cout << "YES";
    else
      cout << "NO";
    cout << endl;
  }
  return 0;
}
