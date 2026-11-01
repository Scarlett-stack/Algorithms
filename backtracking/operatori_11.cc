/*
se da un sir de n numere , n<10. Plaseaza in fata fiecarei valori 
unul din operatorii +, -, * astfel ca expresia rezultata sa aiba valoarea S

S=5, n=4
2 8 1 4
+2 +8 -1 -4

Cum ma gandesc eu :

conditite de oprire: s_interim == S
IN sol[i] retin ce operator aplic elem a[i].
Dar problema e ca am nevoie si de urmatorul eleemnt 

back(k, s_interim, S, sol, a)
if s_interim == S:
    tipar()
    return;
else {
    // avem o problema la *
    // pe asta il inlumtim cu suma interimara sau doar cu elementul anterior??
    // daca e a doua varianta e mai complicat
    // ok deci ideea e sa inmultim doar cu elementul anterior deci trb scazut din suma 
    // si adaugat inmultit cu asta nou
    // INTREBARE: CUM FAC APELURILE RECURSIVE?
    // var1: in fiecare if, si stiu cand se intoarce ca trb sa scad , adun sau idk
    // trb scapat de ultima operatie daca se intoarce
    // mai e o varianta sa retinem ultimul termen cu tot cu semn?
    for j =0,<3 {
    // iteram prin semne
        sol[k] = semn[j];

        if (j == 0) // +
        {
        s_interim = s_interim + a[k];
        back(k+1, s_interim, S, sol, a)
        //resetam ca se intoarce si nu il mai ia
        s_interim -= a[k]
        }
        else if j == 1 // -
        {
        s_interim -= a[k]
        back(k+1, s_interim, S, sol, a)
        s_interim += a[k]
        }
            
        else if k > 0 //ca sa pot accesa anteriorul
        {
            s_interim -= a[k-1];
            s_interim += a[k]*a[k-1]
            back(k+1, s_interim, S, sol, a)
            s_interim -= a[k]*a[k+1]
            s_interim += a[k-1]
            //efectiv in oglinda a ec am modifcat inainte de apel
        }
    }
}

// se poate renunta la for si seta pe rand apoi apel de back si tot asa
// dar prefer cu for ca asa m-am obisnuit
*/

#include <iostream>
#include <vector>

using namespace std;

void tipar(vector<char> &sol, vector<int> &a, int k) {
    // k trb sa fie n e o solutie la care folosim tot vectorul a
    for (int i=0; i<k; i++) {
        printf("%c%d ", sol[i], a[i]);
    }
    printf("\n");
}
void back(int k, int n, int s_interim, int S, int last_term, vector<char> &sol, vector<int> &a) {
    if (k == n) {
        if (s_interim == S)
            tipar(sol, a, n);
        return;
    }
    else {
        for (int j=0; j<3; j++) {
            if (j == 0) {
                sol[k] = '+';
                back(k+1, n, s_interim + a[k], S, a[k], sol, a);
            }
            else if (j == 1) {
                // -
                sol[k] = '-';
                back(k+1, n, s_interim - a[k], S, -a[k], sol, a);
            }
            else if (j == 2 && k != 0) {
                // *
                sol[k] = '*';
                back(k+1, n, (s_interim - last_term) + last_term*a[k], S, last_term * a[k], sol, a);
            }
        }
    }
}
int main() {

    int n,x,S;
    vector<int>a;
    cin>>n>>S;
    for (int i=0; i<n; i++) {
        cin>>x;
        a.push_back(x);
    }
  
    vector<char> sol(n);

    back(0, n, 0, S,0, sol, a);
    return 0;
}