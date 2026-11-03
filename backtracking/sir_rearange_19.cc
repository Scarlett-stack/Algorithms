/*
consideram un sir de scaune in nr n. Se cere modaliattaile de aranjare a copiilor a.i
sa nu aiba aceiasi vecini ca in aranjamentul initial

n = 4
Ana Maria Ion Vlad

Out:
Maria Vlad Ana Ion
Ion Ana Vlad Maria 

Ok ma gandesc sa retin vecinii intr-un vector de vecini si verific in valid daca ce am pus anterior in sol este un vecin din
configuratia initiala

valid(sol, k, vecini, n) {
    ev = 1;
    if k == 0
        return 1
    if k == n - 1
        return 1
    if vecini[sol[k]].v1 == sol[k-1] || vecini[sol[k]].v2 == sol[k-1]
        ev = 0;
    return ev;
}

ok trebuie sa ne asiguram ca nu vizitam de 2 ori acelasi copil deci folosim vizitati
struct vecin { 
    int v1;
    int v2
}
back(int k, int n, sol, vecini, vizitat) {
    if k == n {
        tipar()
        return
    } else {
     for (int i =0, <n) {
        if (!vizitat[i]) {
            sol[k] = i;
            if (valid(sol, k, vecini, n)) {
                back(k+1, n, sol, vecni, vizaitat)
                }
            }
        }
    }
}

Se poate face mai inteligent cu o matrice de vecini.

copil1: v1 v2
copil2: v1 v2 etc

deci ar fi ceva de genu vector<vector<int>>?
Cum ar arata valid in cazul asta?
valid(sol, k, vecini) {
    // ce pun acum se afla printre vecinii lui sol[k-1]?
    if k == 0
        return 1;
    copil_curent = sol[k];
    copil_anterior = sol[k-1]

    for i = 0, <vecini[copil_curent].size() {
        if copil_anterior == vecini[copil_curent][i]
            return 0;
    }
    return 1;
}
*/
#include <bits/stdc++.h>
using namespace std;

void populate_neighs(vector<vector<int>> &vecini, vector<int> &students, int n) {
    for (int i =0; i<n; i++) {
        if (i ==0) {
            // e primul
            vecini[i].push_back(students[i+1]);
        }
        else if (i == n-1) {
            vecini[i].push_back(students[i-1]);
        } else {
            // e la interior deci am 2
            vecini[i].push_back(students[i-1]);
            vecini[i].push_back(students[i+1]);
        }
    }

    // printam
    // printf("begin print vecini \n");
    // for (int i =0; i<n; i++){
    //     printf("\n copil: %d \n", i);
    //     for (int j = 0; j<vecini[i].size(); j++) {
    //         printf("%d ", vecini[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("end print vecini \n");
    
}
void tipar(vector<string> &students, vector<int> &sol) {
    // ok deci stim sigur ca oridnea e aceasi deci ne orientam dupa indecsi
    for (int i =0 ; i<sol.size(); i++) {
        cout<<students[sol[i]]<<' ';
    }
    cout<<"\n";
}

bool valid(vector<int> &sol, int k, vector<vector<int>> &vecini) {
    if (k == 0)
        return true;
    
    int copil_curent = sol[k];
    int copil_anterior = sol[k - 1];

    for(int i =0 ; i< vecini[copil_curent].size(); i++) {
        if (copil_anterior == vecini[copil_curent][i])
            return false;
    }
    return true;
}
void back(int k, int n, vector<int> &sol,  vector<vector<int>> &vecini, vector<string> &students, vector<int> &vizitati) {
    if (k == n) {
        tipar(students,sol);
        return;
    } else {
        for (int i =0; i<n; i++){
            if (!vizitati[i]) {
                sol[k] = i;
                if (valid(sol, k, vecini)) {
                    vizitati[i] = 1;
                    back(k+1, n, sol, vecini, students, vizitati);
                    vizitati[i] = 0;
                }
            }
        }
    }
}
int main() {

    int n, x;
    cin>>n;

    vector<string> names;
    vector<int> students;
    vector<vector<int>> vecini(n);
    vector<int> vizitati(n, 0);
    vector<int> sol(n);

    string name;
    for (int i =0; i<n; i++) {
        cin>>name;
        names.push_back(name);
        students.push_back(i);
    }
    populate_neighs(vecini, students, n);
    back(0,n, sol, vecini, names, vizitati);
    return 0;
}
/*
4
0 1 2 3
1 3 0 2 
2 0 3 1 
citeste direct numele
4
Ana Maria Ion Vlad
Maria Vlad Ana Ion 
Ion Ana Vlad Maria 
*/