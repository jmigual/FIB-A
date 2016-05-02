#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef vector< VI > VVI;

int cost(string &a, string &b) {
    
    int n = a.size() + 1;
    int m = b.size() + 1;
    
    VVI Cost(n, VI(m));
    
    for (int i = 0; i < n; ++i) Cost[i][0] = 3*i;
    for (int i = 0; i < m; ++i) Cost[0][i] = 3*i;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            
            Cost[i][j] = Cost[i][j-1] + 1;
            
        }
    }
    
    return 0;
}

int main()
{
    string a, b;
    
    while (cin >> a >> b) {
        cout << cost(a, b);
    }
}

