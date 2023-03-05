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

// // FOR SPARSE TABLE
// const int K = 16;
// const int MAXN = 1e5 + 1;

// // SPARSE TABLE
// int spt[5][K + 1][MAXN + 1];

// // LOG DP ARRAY
// int log_2[MAXN + 1];

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

// void buildLog()
// {
//   log_2[1] = 0;
//   fr(i, 2, MAXN + 1)
//   {
//     log_2[i] = log_2[i / 2] + 1;
//   }
// }

// void buildTable(vi &data)
// {
//   int n = data.size();
//   copy(data.begin(), data.end(), spt[0]);
//   copy(data.begin(), data.end(), sptMi[0]);
//   for (int i = 1; i <= K; i++)
//   {
//     for (int j = 1; j + (1 << i) <= n; j++)
//     {
//       spt[i][j] = max(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
//       sptMi[i][j] = min(sptMi[i - 1][j], sptMi[i - 1][j + (1 << (i - 1))]);
//     }
//   }
// }

// int queryMax(int l, int r, int first)
// {
//   int i = log_2[r - l + 1];
//   return max(spt[first][i][l], spt[first][i][r - (1 << i) + 1]);
// }

// int queryMin(int l, int r)
// {
//   int i = log_2[r - l + 1];
//   return min(sptMi[i][l], sptMi[i][r - (1 << i) + 1]);
// }

bool comp(ti &a, ti &b)
{
  int a1, a2, b1, b2;
  tie(a1, a2, ignore) = a;
  tie(b1, b2, ignore) = b;
  if (a1 == b1)
    return a2 >= b2;
  return a1 <= b1;
}

int main()
{
  int n;
  cin >> n;
  vti data;
  fr(i, 1, n + 1)
  {
    int a, b;
    cin >> a >> b;
    data.pb({a, b, i});
  }
  sort(data.begin(), data.end(), comp);
  int ans = -1;
  int maxi = INT_MIN;

  // cout << endl;
  // fr(i, 0, n) cout << get<0>(data[i]) << " " << get<1>(data[i]) << " " << get<2>(data[i]) << endl;
  // cout << endl;
  fr(i, 0, n)
  {
    int start, end, ind;
    tie(start, end, ind) = data[i];
    if (end <= maxi)
    {
      ans = ind;
      break;
    }

    if (i + 2 < n && end >= get<0>(data[i + 1]) && get<1>(data[i + 1]) >= get<0>(data[i + 2]) && get<1>(data[i + 1]) <= get<1>(data[i + 2]))
    {
      ans = get<2>(data[i + 1]);
      break;
    }

    maxi = end;
  }
  cout << ans;
  return 0;
}
