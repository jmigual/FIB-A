#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VI;

int main()
{
    int m;

    while (cin >> m) {
        // Read input
        VI V(m);
        for (int &x : V) cin >> x;
    }
}

