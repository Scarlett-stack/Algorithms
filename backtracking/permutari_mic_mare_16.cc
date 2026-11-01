/*Vector A cu n nr intregi
Sa se genereze toate permutarile acestuia care respecta:
    - min elem si max elem raman pe pzozitiile lor initiale
Ex:
n = 4
A =(3,23, 2,1)

Out:
3 23 2 1
   |   |
   max  min
2 23 3 1

Observam ca pastram si vectorul initial in solutie

valid(k, min_poz, max_poz) {
    if k == min_poz || k == max_poz
        return 0
    ev = 1;
    for i=0,<k {
        if sol[k] == sol[i] {
        ev = 0;
        break
        }
    }
    return ev
}

back(k, n, sol, min_poz, max_poz, A, viz) {
    if k == n {
        tipar()
        // am deja solutie pentru ca valid garanteaza corectitudinea
        return
    } else {
        for i=0,<n {
        if (valid(k, min_poz, max_poz, sol, viz)) {
            sol[k] = A[i]
            viz[i] = 1
            back(k+1,n, sol,min_poz, max_poz, A, viz)
            viz[i] = 0;
        }
        }

     }
}
*/
#include <iostream>
#include <vector>
using namespace std;

void compute_min_max_pos(vector<int> &A,int n, int &min_pos, int &max_pos) {
    int max_v = 0;
    int min_v = 9999;

    int j, k;
    for (int i =0; i<n; i++) {
        if (A[i] > max_v) {
            max_v = A[i];
            j = i;
        }
        if (A[i] < min_v) {
            min_v = A[i];
            k = i;
        }
    }
    min_pos = k;
    max_pos = j;
}

void tipar(vector<int> &sol, int n) {
    for (int i =0; i<n; i++)
        printf("%d ", sol[i]);
    printf("\n");
}

int valid(int k, int min_pos, int max_pos) {
    if (k == max_pos || k == min_pos)
        return 0;
    return 1;
}
// void back(int k, int n , vector<int> &A, vector<int> &sol, vector<int> &vizitat, int min_pos, int max_pos) {
//     if (k == n) {
//         tipar(sol, n);
//         return;
//     } else {
       
//         for (int i =0; i<n; i++) {
//             if (valid(i, min_pos, max_pos) && !vizitat[i]) {
//              vizitat[i] = 1;
//              sol[k] = A[i];
//              back(k+1, n, A, sol, vizitat, min_pos, max_pos);
//              vizitat[i] = 0;
//               printf("k: %d sol[k] %d\n", k, sol[k]);
//             }
//         }
//     }
// }
// de ce nu e suficienta doar asa?
// pentru ca tu nu permiti incrementarea lui k daca i ajunge pe una din poziitile alea
// deci k nu ajunge niciodata sa fie egal cu n deci nu se apeleaza tiparul!!
void back(int k, int n , vector<int> &A, vector<int> &sol, vector<int> &vizitat, int min_pos, int max_pos) {
    if (k == n) {
        tipar(sol, n);
        return;
    } else {
        if (k == min_pos) {
            // o pun in sol si am grija sa inc k
            vizitat[min_pos] = 1;
            sol[k] = A[min_pos];
            back(k+1, n, A, sol, vizitat, min_pos,max_pos);
            // vizitat[min_pos] = 0; // nu cred ca mai e necesar
            return;
        }
        if (k == max_pos) {
            vizitat[max_pos] = 1;
            sol[k] = A[max_pos];
            back(k+1, n, A, sol, vizitat, min_pos, max_pos);
            return;
        }

        //altfel interez normal si skip la alea
        for (int i =0; i<n; i++) {
            if (!vizitat[i] && valid(i, min_pos, max_pos)) {
                sol[k] = A[i];
                vizitat[i] = 1;
                back(k+1, n, A, sol, vizitat, min_pos, max_pos);
                vizitat[i] = 0;
            }
        }
    }
}
// valid se testeaz ape un element deja pus
int main() {

    int n;
    cin>>n;
    vector<int> sol(n);
    vector<int> vizitat(n, 0);
    vector<int> A;
    int x;

    for (int i =0; i<n; i++) {
        cin>>x;
        A.push_back(x);
    }
    int max_pos =0, min_pos =0;
    compute_min_max_pos(A, n, min_pos, max_pos);

    cout<<"min si max pos: "<<max_pos<<' '<<min_pos<<"\n";
    sol[max_pos] = A[max_pos];
    sol[min_pos] = A[min_pos];
    back(0,n,A,sol,vizitat,min_pos, max_pos);
    return 0;
}