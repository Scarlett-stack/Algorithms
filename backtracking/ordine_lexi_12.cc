/*
se considera un sir de n litere mici distincte.
sa se genereze toate cuvinyele care verifica:
    - un cuvant contine exact m litere din sirul celor n
    - literele din care este format apar in ordine lexicografica

*/

#include <iostream>
#include <vector>
using namespace std;

void tipar(vector<char> &sol, int n) {
    for (int i=0; i<n; i++)
        {
            printf("%c ", sol[i]);
        }
    printf("\n");
}

int valid(vector<char> &sol, int k) {
    // ca la permutari
    // nu vrem sa punem ce avem deja dar nici ce e mai mic decat ce avem deja
    int ev =1; 
    for (int i=0; i<k; i++) {
        if (sol[i] == sol[k] || sol[i] > sol[k]) 
        {   
            ev =0;
            break;
        }            
    }
    return ev;
}
void back(int k, int n, int m, vector<char> &sol, vector<char> &letters) {
    if (k == m) {
        tipar(sol, m);
        return;
    }
    else {
        for (int i=0; i<n; i++) {
            sol[k] = letters[i];
            if (valid(sol, k)) {
                back(k+1, n, m, sol, letters);
            }
        }
    }
}
int main() {

    int n, m;
    char letter;
    cin>>n>>m;

    vector<char> letters;
    for (int i=0; i<n; i++)
    {
        cin>>letter;
        letters.push_back(letter);
    }
    vector<char> sol(m);

    back(0,n,m,sol,letters);
    
    return 0;
}