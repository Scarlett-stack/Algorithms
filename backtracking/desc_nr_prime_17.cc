/*
se considera n nr natural. Sa se genereze toate modurile de scriere a lui n
ca suma de nr prime.

Ex:
n = 4

Out:
2 2 2 2 de 7 ori
3 3 3 3 2
3 3 3 5
3 11
7 7


*/

#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int nr) {
    int d = 2;
    //bool is_prime = true;
    while (d*d <= nr) {
        if (nr % d == 0) {
            return false;
        }
        d++;
    }
    return true;
}
void tipar(vector<int> &sol) {
    for (int i =0; i<sol.size(); i++)
        printf("%d ", sol[i]);
    printf("\n");
}
void back(int k, int start_index, vector<int> &sol, int sum_interim, int S) {
    // valid e is_prime
    // iei numere mai mici ca n deci iterezi efectiv pana in n
    // OK BUN dar cum facem sa evitam repetirii de genul:
    // 5 2 2 2 3 si 5 2 2 3 2 
    // adica astea ar fi permutari dar eu nu vreau neaparat permutari deci folosim o relatie de ordine!
    if (sum_interim == S) {
        // gasit
        tipar(sol); // nu stim dimensiunea!!
        return;
    }
    if (sum_interim > S) {
        return;
    } else {
        // iterez pana in n
        // pentru relaia de ordine fortam inceperea de la un anumkt index! e mult mai eficient decat a transmite vectorul bakc n forth intre functii
        for (int i = start_index; i<S; i++) {
            if (is_prime(i)) {
                sol.push_back(i); // nt sure here cu alocare pentru ca nu stiu cum sa fac cu pushback si popback?
                back(k+1, i, sol, sum_interim + sol[k], S); // neaparat i pentru ca asa stiu ca e prim si e valid. sart index poate sa fi ramas si sa nu se fi deplasat
                sol.pop_back(); // inseamna ca a dat return si nu e bun sau a printat si mergem la next
            }
        }
    }
}
int main() {

    int n;
    cin>>n;

    vector<int> sol;
    
    back(0, 2, sol, 0, n);

    return 0;
}