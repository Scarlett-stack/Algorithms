/* pseudocod

-- cum ara arata un valid pt asta?
back(k, p_ramas, sol, m) 
    if k == m-1:
        tipar()
    else {
        // cum fac sa asigur ca variez indicii pe care pun 1 si nu am mereu aceasi solutie?
        for i in 0, <m-1
            if p_ramas > 0:
                sol[k] = 1
                p_ramas--;
            else sol[k] = 0
            back(k+1, sol, p_ramas)
            p_ramas = p
            //cumva trebuie resetat indicele care are deja 1
            // pentru ca daca las 1 unde exista deja
            // si p_ramas e pus din nou pe p
            // eu adaug 1 in plus inutil

    }
back(0, p-1, sol, m-1)

back(k, p_ramas, sol){
    if k == m-1:
        if p_ramas == 0
            tipar()
        return
    else {
        // nu cumva inseamna ca o sa pun invariabil 1 pe pozitii consecutive daca p ramas > 1?
        if p_rams > 0:
            sol[k] = 1
            back(k+1, p_ramas-1, sol)
        sol[k] = 0
        back(k+1, p_ramas, sol)
        
    }
}
 */

#include <iostream>
#include <vector>
using namespace std;

void tipar(vector <int> &sol, int m) {
    for (int i = m-1; i>=0; i--)
        // nu le mai fac conversia afisez direct
        printf("%d ", sol[i]);
    printf("\n");
}

void back(int k, int p_ramas, int m, vector<int> &sol) {
    if (k == m - 1){
        if (p_ramas == 0)
            tipar(sol, m);
        return;
    }
    else {
        if (p_ramas > 0)
        {
            sol[k] = 1;
            back(k + 1, p_ramas-1, m, sol);
        }
        // cand se intaorce din apelul de mai sus resetez pozitia
        // si trec la urmatorul 1!
        sol[k] = 0;
        back(k+1, p_ramas, m, sol);
    }
}
int main() {

    int m, p;
    cin>>m>>p;

    vector<int> sol(m);
    sol[m - 1] = 1; // asta e msb
    back(0, p-1, m, sol);
    return 0;
}