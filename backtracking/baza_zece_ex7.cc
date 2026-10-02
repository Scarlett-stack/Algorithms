#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 *consideram sirul primelor m cifre distincte ale unui nr n. (cele mai mici)
 * sa se scrie pe o singura linie toate numerele a caror scriere in baza 10 foloseste numai sirul
 * primelor m cifre din n.  
 */

void decompose(int n,int m, vector<int> &frequencies, vector<int> &cifre) {
    int copie_n = n;
    while (n > 0) {
        if (frequencies[n%10] == 0)
            frequencies[n%10] = 1;
        n/=10;
    }
    //printf("*****************\n");
    //sortam pt primele m cele mai mici
    // nu pot sorta o sa sucesc indicii
    // for(int i=0; i<10; i++)
    //     printf("%d ", frequencies[i]);
    // printf("end print freqs decomopose \n");
    int i =0, j=0;
    //ce naiba fac cu copie_n??
    while (i < 10 && j < m) {
        if (frequencies[i] == 1) {
            // TREBUIE J AICI
            cifre[j] = i;
            j++;
        }  
        i++;
    }
}

int valid(int k, vector<int> &sol) {
    //valid e daca nu am 0 pe prima pozitie
    if (sol[0] == 0) {
        return 0; 
    }
    return 1;
}
void back(int k, int m, vector<int> &cifre, vector<int> &sol) {
    if (k == m) { // nu > pt ca m incepe de la 1
        return;
        // noi afisam si solutii partiale deci nu are sens sa afisam aici
    }

    for (int i = 0; i<m; i++) {
        // nu poate sa fie i 
        // tu iei primele m cifre din vectorul freqs
        sol[k] = cifre[i]; 
       // printf("ce am pus in sol: %d", sol[k]);
        if (valid(k, sol)) {
            // afisam
            // ma gandeam sa initializez cu -1 acolo unde nu am pus cifra
            // ba nu. Ma duc pana in k inlcusiv pt ca si el incepe de la 0
            for (int j=0; j<=k; j++)
                printf("%d", sol[j]);
            printf(" ");
        back(k+1,m , cifre, sol);
        }
    }
}
int main() {

    int n,m;
    cin>>n>>m;

    vector<int> frequencies(10);
    vector<int> cifre(m);
    vector<int> sol(m);

    decompose(n,m,frequencies, cifre);
    // printf("vectroul de cifre pana la m\n");
    // for(int i=0; i<m; i++)
    //     printf("%d ", cifre[i]);
    // printf("end print 1\n");
    back(0, m, cifre, sol);
    return 0;
}