#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

typedef unsigned int uint;
typedef vector<uint> VU;
typedef vector< VU > VVU;


int cost(string &a, string &b) {
  
  uint n = a.size() + 1;
  uint m = b.size() + 1;
  
  VVU Cost(n, VU(m));
  
  for (uint i = 0; i < n; ++i) Cost[i][0] = 3*i;
  for (uint i = 0; i < m; ++i) Cost[0][i] = 3*i;
  
  for (uint i = 1; i < n; ++i) {
    for (uint j = 1; j < m; ++j) {
      uint c = UINT_MAX;
      uint d = a[i-1] == b[j-1] ? 0 : 1;
      
      if (Cost[i-1][j] + 2 + d < c) c = Cost[i-1][j] + 2 + d;
      if (Cost[i][j-1] + 2 + d < c) c = Cost[i][j-1] + 2 + d;
      if (Cost[i-1][j-1] + 6*d < c) c = Cost[i-1][j-1] + 6*d;
      
      Cost[i][j] = c;
    }
  }
  
  return Cost[n-1][m-1];
}

int main()
{
  string a, b;
  
  while (cin >> a >> b) {
    cout << cost(a, b) << endl;
  }
}

