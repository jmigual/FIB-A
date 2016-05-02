#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef unsigned long long int ullong;
typedef vector<ullong> VL;
typedef vector< VL > VVL;

ulong calcMinimum(VL &N) {
    ullong n = N.size() - 1;
    
    // i-j value in Superior diagonal contains the cost for i, j to do the 
    // multiplication from M_i x M_i+1 x ... M_j
    VVL M(n, VL(n));
    
    // Multiplication to the same matrix is cost 0 because it's not a solution
    for (ullong i = 0; i < n; ++i) M[i][i] = 0;
    
    for (ullong length = 1; length < n; ++length) {
        for (ullong i = 0; i + length < n; ++i) {
            ullong j = i + length;
            
            // Set M[i][j] to infinite
            M[i][j] = LONG_LONG_MAX;
            
            for (ullong k = i; k < j; ++k) {
                
                // Get the minimum cost
                ullong cost = M[i][k] + M[k+1][j] + N[i]*N[k+1]*N[j+1];
                if (cost < M[i][j]) {
                    M[i][j] = cost;
                }
            }
        }
    }
    
    return M[0][n-1];
}

int main()
{
    int m;

    while (cin >> m) {
        // Read input
        VL N(m + 1);
        for (ullong &x : N) cin >> x;
        
        cout << calcMinimum(N) << endl;
    }
}

