/*
Se da A vector cu n nr intregi. Doua elemente ale sale formeaza o pereche in dezordine daca sunt
indeplinite simultan:
- i < j cu 1<=i<n si 1<j <= n
- a[i] > a[j]
Sa se genereze toate sirurile care contin acelasi nr de perechi in dezordine ca al vectorului initial.

Ex:

n = 4
A = (1,3,2,4) 

Out:
1 2 4 3
2 1 3 4

Ok cum fac sa nu repet inputul? Are sens sa fac o structura in care tin perechile si indicii lor?
Mai intai calculam nr de perechi initial

compute_initial_pairs(A, n) {
    num_pairs = 0
    for i = 0; <n-1
        for j = i+1; <= n-1 {
            if a[i] > a[j]
                num_pairs++;
        }
    return num_pairs
}

Bun si in valid singura conditie e sa am a[i] > a[j] si num_pairs_sol < num_pairs?

Ce stiu sigur: cand am n elemente inseamna ca am o solutie. Este valida? atunci printez
NU are sens sa apelezi valid in forma asta in timp ce construiesti sol. De ce? Pentru ca tu te duci pana in n
Dar sol nu e complet deci ai avea garbage in memorie si ai avea fals implicit. 
valid(sol, A, num_pairs) {

    // daca am fix acelasi vector nu e solutie
    for (i=0; i<n; i++) {
        if sol[i] == A[i]
            return 0;
    }
    int num_pairs_sol = 0

    for (i =0; i<n-1) {
        for (j=i+1; j<n; j++)
            if sol[i] > sol[j]
                num_pairs_sol++
    }
    if num_pairs_sol == num_pairs
        return 1
    return 0
    

}
back(k,n, sol, A, num_pairs) {
    if (k == n) {
        if (valid(sol,A, num_pairs)) {
            tipar()
        }
    } else {
     // ok cum stiu daca am aceasi solutie?
     // hai sa facem o smecherie 
     for (i=0; <n) {
        if (!vizitat[i]) {
            // nu il mai adaugam daca exista deja
            sol[k] = A[i]
            vizitat[i] = 1
            back(k+1, n, sol, A, num_pairs)
            vizitat[i] = 0
            

        }
     }
 }
}
*/

#include <iostream>
#include <vector>
using namespace std;

int compute_initial_pairs(vector <int> &A, int n) {
    int num_pairs = 0;
    for (int i =0 ;i <n-1; i++) {
        for (int j =i+1; j<n; j++) {
            if (A[i] > A[j])
                num_pairs++;
        }
    }
    return num_pairs;
}

int valid(vector<int> &A, vector<int> sol, int num_pairs, int n) {
    // for (int i=0; i<n; i++) {
    //     if (A[i] == sol[i]) {
    //         return 0;
    //     }
    // }
    // nu e corect cum verifici mai sus pentr ca daca ai macar un elemnt egal pe aceasi pozitii
    // da fals dar restul s-ar putea sa fie diferite
    // asa ca verificam daca acar unul e diferit atunci e ok

    int are_equals = 1;

    for (int i = 0; i<n; i++) {
        if (sol[i] != A[i]) {
             are_equals = 0;
             break;
        }      
    }

    if (are_equals == 1)
        return 0;

    // ok atunci nu sunt aceleasi solutii si putem verificanr de perechi
    int number_pairs_sol = compute_initial_pairs(sol, n);
    if (num_pairs == number_pairs_sol)
        return 1;
    return 0;
}

void tipar(vector<int> &sol, int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}
void back(int n, int k, vector<int> &sol, vector<int> &A, vector<int> &vizitat, int num_pairs) {
    if (k == n) {
        // am sol complet
        // dar e valid?
        if (valid(A, sol, num_pairs, n)) {
            tipar(sol, n);
        }
    } else {
        for (int i =0; i<n; i++) {
            if (vizitat[i] == 0) {
                // nu e deja adaugat
                sol[k] = A[i];
                vizitat[i] = 1;
                back(n, k+1, sol, A, vizitat, num_pairs);
                vizitat[i] = 0;
            }
        }
    }
}
int main() {

    int n,x;
    cin>>n;

    vector<int> A;
    for (int i=0; i<n; i++)
    {
        cin>>x;
        A.push_back(x);
    }

    vector<int> sol(n,0);
    vector<int> vizitat(n,0);
    int num_pairs = compute_initial_pairs(A, n);
    back(n, 0, sol, A, vizitat, num_pairs);
    
    return 0;
}