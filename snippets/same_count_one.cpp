#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
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

int main()
{
  int t, n, m, x;
  cin >> t;
  while (t--)
  {
    ll one = 0;
    cin >> n >> m;
    vector<vector<int>> data(n + 1, vector<int>(m + 1, 0));
    map<int, int> rowToCount;
    vector<pair<int, int>> sorted;
    for (int i = 1; i <= n; i++)
    {
      int oneInRow = 0;
      for (int j = 1; j <= m; j++)
      {
        cin >> x;
        data[i][j] = x;
        if (x == 1)
          oneInRow++;
      }
      one += oneInRow;
      rowToCount[i] = oneInRow;
      sorted.pb({oneInRow, i});
    }
    vector<pair<int, pair<int, int>>> ans;
    sort(sorted.begin(), sorted.end(), greater<pair<int, int>>());
    ll op = 0;
    int needed = 0;
    if (one % n != 0)
    {
      cout << -1 << endl;
      continue;
    }
    needed = one / n;
    for (int i = 0, j = sorted.size() - 1; i < sorted.size() && j >= 0;)
    {
      int srcRow = sorted[i].second;
      int destRow = sorted[j].second;
      if (rowToCount[destRow] == needed || rowToCount[srcRow] == needed)
        break;
      for (int k = 1; k <= m; k++)
      {
        if (data[srcRow][k] == 0)
          continue;
        op++;
        ans.pb({destRow, {srcRow, k}});
        rowToCount[srcRow]--;
        rowToCount[destRow]++;
        if (rowToCount[destRow] == needed || rowToCount[srcRow] == needed)
          break;
      }
      if (rowToCount[destRow] == needed)
        j--;
      if (rowToCount[srcRow] == needed)
        i++;
    }
    // printing answer;
    cout << op << endl;
    for (int i = 0; i < ans.size(); i++)
    {
      int dest = ans[i].first;
      int src = ans[i].second.first;
      int pos = ans[i].second.second;
      cout << dest << " " << src << " " << pos << endl;
    }
  }
  return 0;
}
