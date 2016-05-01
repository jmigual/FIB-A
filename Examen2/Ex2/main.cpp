#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef vector< VI > VVI;

VVI calcMinimum(VI &N) {
    int n = N.size();
    
    // i-j value in Superior diagonal contains the cost for i, j to do the 
    // multiplication from M_i x M_i+1 x ... M_j
    // j-i value in Inferior diagonal contains the value k that makes the 
    // minimum cost for i-j multiplication
    // We use the inferior diagonal because always j > i
    VVI M(n, VI(n));
    
    // Multiplication to the same matrix is cost 0 because it's not a solution
    for (int i = 0; i < n; ++i) M[i][i] = 0;
    
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i < n - length + 1; ++i) {
            int j = i + length - 1;
            
            // Set M[i][j] to infinite
            M[i][j] = INT_MAX;
            
            for (int k = i; k < j; ++k) {
                int cost = M[i][k] + M[k+1][j] + N[i]*N[k+1]*N[j+1];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                    M[j][i] = k;
                }
            }
        }
    }
    
    return M;
}

int main()
{
    int m;

    while (cin >> m) {
        // Read input
        VI N(m);
        for (int &x : N) cin >> x;
    }
}

