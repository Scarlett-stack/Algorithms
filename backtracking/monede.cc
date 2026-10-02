#include <iostream>
#include <vector>
using namespace std;

void tipar(vector<int> &sol, int k) {
    // NU ICLUDEM SI K!!
    // pentru ca e deja pe nivelul n si nu pun nimic acolo
    for (int i=0; i<k; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

void back(int k, int n, vector<int> &sol, vector<int> &types, int s_interim, int Sum) {
    if (s_interim == Sum) {
        tipar(sol, k);
        return;
    }
    else {
        sol[k] = -1;
        while (sol[k] * types[k] + s_interim < Sum && k < n) {
            sol[k]++;
            s_interim += types[k] * sol[k];
            back(k+1, n, sol, types, s_interim, Sum);
            s_interim -= types[k]*sol[k];
        }
    }
}
int main() {
    int Sum;
    int n;
    cin>>n; // n tipuri de monede
    cin>>Sum;

    vector<int>sol(n);
    vector<int>types(n);

    // for (int i=0; i<n; i++) {
    //     types[i] = i+1;
    // }
    // trebuie citite si valorile
    int x;
    for (int i=0; i<n; i++) {
        cin>>x;
        types[i] = x;
    }
    back(0, n, sol, types, 0, Sum);
}