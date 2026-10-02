#include <iostream>
#include <vector>
using namespace std;
/*
* se citeste n nr nat si S nr nat . Sa se afiseze toate submultimiled e suma S
* formate din cifrele lui n. 
* pe fiecare linie = cifrele dintr-o submultime generata
*/
void decompose(int n, vector<int> &cifre, int &nr_cifre) {
    vector<int> frequencies(10);

    int i=0, j;
    while (n > 0) {
        if (frequencies[n%10] == 0)
            frequencies[n%10] = 1;
        n/=10;
    }

    // cifre nu are alocat spatiu de acea facem cu push back
    // daca am fi folosit vectori normali
    // nu declaram de 10 ci de cati de 1 apar in frequnecies dimensiunea
    while (i < 10) {
        if (frequencies[i] == 1) {
            cifre.push_back(i);
        }
        i++;
    }
    nr_cifre = cifre.size();
    
}
// int valid(int k, int S, vector<int> &sol) {
//     // trebuie sa nu fie mai mare ca S
//     int s_prim = 0;
//     for(int i=0; i<k; i++){
//         s_prim += sol[i];
//         if (s_prim > S)
//             return 0;
//     }
//     s_prim += sol[k];

//     if (s_prim > S)
//         return 0;
//     return 1;
// }
void tipar(vector<int> &sol, int k) {
    // avand dimensiune variabila solutiile
    // ne duce pana la k !
    for (int i=0; i<k; i++) {
        // de ce pana la k
        // tu treci cu back(k+1, s+ cifre[i] ...) la nivelul urmator
        // DAR daca intri in ramura de tipar
        // adica ai suma S
        // esti deja pe nivelul urmator desi nu il pui la solutie
        // deci de aiai nu te duci pana in k inclusiv
        printf("%d ",sol[i]);
    }
    printf("\n");
}
void back(int k, int start_index, int nr_cifre, int sum_intermediar, int S, vector<int> &cifre, vector<int> &sol) {
    if (sum_intermediar > S)
        return;
    if (sum_intermediar == S) {
        tipar(sol, k);
        return;
    }
    else {
        // folosim un index ca sa fortam inaintarea si sa prevenim revenirea in cazurile deja vizitate
        for (int i = start_index; i < nr_cifre; i++) {
            sol[k] = cifre[i]; // bagam o cifra
            back(k+1, i+1, nr_cifre, sum_intermediar + cifre[i], S, cifre, sol);
        }
    }
}
int main() {

    int n, S;
    int nr_cifre;
    
    cin>>n>>S;
  
    vector<int> cifre;
    decompose(n, cifre, nr_cifre);
      vector<int> sol(nr_cifre);
    back(0, 0, nr_cifre, 0, S, cifre, sol);
    return 0;
}