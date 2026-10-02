#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct elev {
    float h; //height
    string name;
};
int valid(int k, vector<int> &sol, vector<elev> &elevi) {
    int ev = 1;
    int i;
    for (i=1; i<k; i++) {
        // ne asiguram ca respectam ordinea crescatorare
        // SI UNICITATE ADICA NU FOLOSIM ACELASI ELEV DE 2 ORI
        // NU PUNEM IN ACELASI IF
        // DE CE? AH AI PUS-O PROST
        // TREBUIE S FIE CAZURILE PROASE IN IF NU CELE BUNE
        if (elevi[sol[k]].h < elevi[sol[i]].h || sol[k] == sol[i])
            ev = 0;
    }
    return ev;
}

void tipar(vector <elev> &elevi, vector<int>&sol, int n) {
    for (int i=1; i<=n; i++)
        // trb convertit acest string la c string
        printf("%s ",elevi[sol[i]].name.c_str());
    printf("\n");
}
void back(int k, int n, vector<elev> &elevi, vector<int> &sol) {
    if (k == n + 1) {
        tipar(elevi, sol, n);
    }
    else {
        for (int i=1; i<=n; i++){
            sol[k] = i;
            // o sa fie sortati dupa citire
            if (valid(k, sol, elevi)) {
                back(k+1, n, elevi, sol);
            }
        }
    }
}
int main() {

    int n;
    cin>> n;
    cin.get();
    vector<elev> elevi(n+1);
    vector<int> sol(n+1);
    for (int i = 1; i<=n; i++) {
        cin>>elevi[i].name >> elevi[i].h;
    }

    // for (int i = 1; i<=n; i++) {
    //     cout<<elevi[i].name <<elevi[i].h;
    // }

    back(1, n, elevi, sol);
    return 0;
}