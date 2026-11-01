#include <iostream>
#include <vector>
using namespace std;

// cum gandim valid?
// sa nu fie pe aceasi coloana: sol[k] ==  sol[i]
bool is_valid(int k, vector<int> &sol) {
    for (int i=0; i<k; i++) {
        if (sol[k] == sol[i] || abs(k-i) == abs(sol[k] - sol[i]))
            return 0;
    }
    return 1;
}
void tipar(vector <int> &sol,int n) {
    for (int i =0; i<n; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}
void back(int k, int n, int m, vector<int> &sol) {
    if (k == n) {
        // am pus tote cele n dame
        tipar(sol, n);
        return;
    } else {
        for (int i =0; i<m; i++) {
            sol[k] = i;
            if (is_valid(k, sol)) {
                back(k+1, n, m, sol);
            }
        }
    }
}
int main() {
    int n = 4, m = 4; // Tablă 4x4
    vector<int> sol(n, 0);

    back(0, n, m, sol);
    return 0;
}