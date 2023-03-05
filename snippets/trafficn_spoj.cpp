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
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, k, s, t;
    map<int, vt<tuple<int, int, bool>>> graph;
    cin >> n >> m >> k >> s >> t;
    fr(i, 0, m)
    {
      int u, v, wt;
      cin >> u >> v >> wt;
      graph[u].pb({v, wt, 0});
    }
    fr(i, 0, k)
    {
      int u, v, wt;
      cin >> u >> v >> wt;
      graph[u].pb({v, wt, 1});
      graph[v].pb({u, wt, 1});
    }
    mipq<tuple<ll, int, bool>> pq;
    pq.push({0, s, 0});
    vvll dis(n + 1, vll(2, LLONG_MAX));
    dis[s][0] = 0;
    while (!pq.empty())
    {
      int node;
      ll distance;
      bool path;
      tie(distance, node, path) = pq.top();
      pq.pop();
      for (auto i : graph[node])
      {
        int nbr, wt;
        bool newPath;
        tie(nbr, wt, newPath) = i;
        if (path && newPath)
          continue;
        newPath = path | newPath;
        if (dis[nbr][newPath] > dis[node][path] + wt)
        {
          dis[nbr][newPath] = dis[node][path] + wt;
          pq.push({dis[nbr][newPath], nbr, newPath});
        }
      }
    }
    ll ans = min(dis[t][0], dis[t][1]);
    if (ans == LLONG_MAX)
      cout << -1;
    else
      cout << ans;
    cout << endl;
  }
  return 0;
}
