#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef set<int> si;
typedef set<ll> sll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

#define endl "\n"
#define ff first
#define ss second
#define pb push_back

const int N = 10000007;

// Matrix multiplication (ONE BASED INDEXING)
vvll mpow(vvll a, ll b, ll m)
{
  int n = a.size();
  int nn = a[0].size();
  vvll ans(n, vll(nn, 0));
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < nn; j++)
    {
      if (i == j)
        ans[i][j] = 1;
    }
  }
  while (b > 0)
  {
    if (b & 1)
    {
      ans = mmul(ans, a, m);
    }
    a = mmul(a, a, m);
    b >>= 1;
  }

  return ans;
}

int main()
{

  return 0;
}