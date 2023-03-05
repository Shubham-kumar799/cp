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
vvll mmul(vvll a, vvll b, ll m)
{
  int r1 = a.size();
  int r2 = b.size();
  int c2 = b[0].size();
  vvll rslt(r1, vll(c2));
  for (int i = 1; i < r1; i++)
  {
    for (int j = 1; j < c2; j++)
    {
      rslt[i][j] = 0;
      for (int k = 1; k < r2; k++)
      {
        rslt[i][j] = (rslt[i][j] + (a[i][k] * b[k][j]) % m) % m;
      }
    }
  }

  return rslt;
}

int main()
{

  return 0;
}