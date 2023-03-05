#include <iostream>
#include <vector>

using namespace std;

int getCatalan(int n, vector<int> &catalan)
{
  if (n <= catalan.size())
    return catalan[n];
  for (int i = 2; i <= n; i++)
  {
    catalan.push_back(0);
    for (int k = 0; k < i; k++)
    {
      catalan[i] += catalan[k] * catalan[i - k - 1];
    }
  }
  return catalan[n];
}

int main()
{
  int n = 10;
  vector<int> catalan;
  catalan.push_back(1);
  catalan.push_back(1);
  getCatalan(n, catalan);

  return 0;
}