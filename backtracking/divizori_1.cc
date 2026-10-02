#include <iostream>
# include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int compute_diviz(vector<int> &D, int x) {
    D.push_back(1);

    if (x>1)
        D.push_back(x);

    int d = 2;

    while(d <= x/2) {
        if (x%d == 0) 
            D.push_back(d);
        d++;
    }

    sort(D.begin(), D.end());
    for (int i = 0; i< D.size(); i++)
        cout<<D[i]<<' ';
    cout<<"\n";


    return D.size();
}

void tipar(vector <int> &sol, int m) {
    for(int i=1; i<=m; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

int valid(int k, vector <int> &sol) {
    // good practice pe viitor:
    // merge sa pui mai bine in if conditia buna de validare adica cea
    // cu return code 1
    // pentru ca poate sa iti scape mai ales daca nu pui indicii bine la apel
    // si sa fie din greseala valid
    if (k > 1 && sol[k] <= sol[k-1])
        return 0;
    return 1;
}

void back(int k, vector<int> &D, vector <int> &sol, int n_div, int m) {
    if (k == m + 1)
        tipar(sol, m);
    else {
        for (int i = 0; i< n_div; i++) {
            sol[k] = D[i];
            if (valid(k, sol)) {
                back(k+1, D, sol, n_div, m);
            }
        }

    }
}
int main() {

    int x, m,n;
    vector <int> D = {};
    cin>>x>>m;

    vector <int> sol(m+1);
    int n_div = compute_diviz(D, x);
    if (n_div < m) 
        printf("IMPOSIBIL\n");
    else {
        back(1, D, sol, n_div, m);
    }
    return 0;
}