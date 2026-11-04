/*
se da n nr naturl. sa se generezes toate sirurile de paranteze rotunde care se inchid corect.
ok deci eu ma gandesc sa codez ( ca fiind -1
si ) ca fiind +1. SI fac suma si daca suma finala e 0 si sirul are lungimea n atunci tipar
Acuma intrebarea mai interesanta e cum putem face pruning la chestia asta

back(k, n, sol, sum_interim) {
    if (sum_interim < 0) {
    return 
        }
    if (k == n) {
        if (sum_interim == 0) {
            tipar()
        } else return
    } else {
        for (int i =0; i<2; i++) {
            sol[k]  = sign[i];
            back(k+1, n, sol, sum_interim + sol[k])
        }
     }
} 

PRUNING: deci daca am sum_interim < 0 garantat nu are sens sa continuam. Trb sa ne gandim si l a cazu )(  care ar fi valid conform logicii noastre, dar nu e asa!
- daca N este impar nu are sens sa pronesti algoritmul pt ca garantat nu  inchisi ztate paramteze;e
*/
#include <bits/stdc++.h>
using namespace std;

void tipar(vector<int> &sol) {
    for (int i = 0; i<sol.size(); i++) {
        if (sol[i] == 1) 
            printf("(");
        else printf(")");
    }
    printf("\n");
}
void back(int k, int n, vector<int> &sol, int sum_interim, vector<int> &signs) {
       //printf("sol[k] %d la k = %d", sol[k], k);
   
    if (sum_interim < 0) {
        return; 
        //inseamna ca am ))) deci nu le pot inchide oricum
    }


    if (k == n) {
        if (sum_interim == 0) {
            tipar(sol);
            return;
        }
    }  else {
            for (int i =0; i<2; i++) {
                sol[k] = signs[i];
                // printf("AICI??\n");
                back(k+1, n, sol, sum_interim + sol[k], signs);
            }
        }
}
int main() {
    int n;
    cin>>n;

    vector<int> sol(n);
    vector<int>signs;
    signs.push_back(1);
    signs.push_back(-1);

    if (n % 2== 1)
        cout<<"nope";
    else back(0,n,sol,0,signs);
    return 0;
}