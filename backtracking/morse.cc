#include <iostream>
# include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

void tipar(vector <int> &sol, int n) {
    for(int i=1; i<=n; i++) {
        if (sol[i] == 1) // nu pune '1' ca e ascii 49 plus ca nu e int
            printf("-");
        else printf(".");
    }
    printf("\n");
}

int valid(int k, vector <int> &sol, int n) {
    // good practice pe viitor:
    // merge sa pui mai bine in if conditia buna de validare adica cea
    // cu return code 1
    // pentru ca poate sa iti scape mai ales daca nu pui indicii bine la apel
    // si sa fie din greseala valid
    if (k==1 && sol[k] == 1)
        return 0;
    
    if (k==n && sol[k] == 1)
        return 0;
    
    return 1;
}

void back(int k, vector <int> &sol, int n) {
    if (k == n + 1)
        tipar(sol, n);
    else {
        for (int i = 1; i<= 2; i++) {
            sol[k] = i;
            if (valid(k, sol,n)) {
                back(k+1, sol, n);
            }
        }

    }
}
int main() {

    int n;
    cin>>n;

    vector <int> sol(n+1);

    back(1, sol, n);
    
    return 0;
}