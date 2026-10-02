/*
tablouri nxn cu propr ca pe fiecare linie si coloana apare exact un element de 1
ex: n=2:
0 1
1 0

1 0
0 1
*/

#include <iostream>
#include <vector>
using namespace std;

// future improvement: nu mai cara matricea dupa tine
// poti afisa direct si in fisier si pe ecran
void tipar(vector<int> &sol, vector<vector<int>> &A, int n) {
    for(int i =0; i<n; i++){
        for (int j=0; j<n; j++)
            //da avem nevoie de 2 foruri altfel nu s-ar afisa toate 0
            // noi printam la (i, sol[i]) valoarea 1 si in rest 0
            // daca nu pun if e suprascrie daca fac doar A[i][sol[i]] = 1
            if (j == sol[i])
                A[i][j] = 1;
            else A[i][j] = 0;
    }

    for (int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    printf("\n");
}
int valid(int k, vector<int> &sol) {

    // o sa fie ca la permutari
    // in sol[i] avem de fapt indicele coloanei
    // trb sa fie diferiti intre ei neaparat
    // nu am cum sa repet intre linii aceasi pertare
    // cobor mereu pe nivelul anterior daca am epuizat varaintele pe nivelul curent
    // indici de la 0 nu 1!!
    int ev = 1;
    // poti pune sol[k] pentru ca am pornit de la 0 in main
    // nu il incluzi in acest for pentru ca el e val de ref
    for (int i=0; i<k; i++) {
        if (sol[k] == sol[i])
            ev = 0;
    }

    return ev;
}

void back(int k, vector<int> &sol, vector<vector<int>> &A, int n) {
    if (k == n) 
        tipar(sol, A, n);
    else {
        for (int i =0; i<n; i++) {
            //NU PUNE DE LA 0 LA 2 PENTRU CA NU LUCREZI CU VALORI CI CU PERMUTARI DE INDICI
            sol[k] = i;
            //luam pe rand gen fiecare varianta
            if (valid(k, sol)) 
                back(k+1, sol, A, n);
        }

    }
}

int main() {

    int n;
    cin>>n;
    // ca sa declari alocat matricea trb fauct cu tipul liniei care  e toto vector
    vector<vector<int>> A(n+1, vector<int>(n+1));
    vector<int> sol(n+1);

    back(0, sol, A, n);

    return 0;
}