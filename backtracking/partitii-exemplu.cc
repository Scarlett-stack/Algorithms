#include <iostream>
#include <vector>

using namespace std;

void tipar(vector<int> &A, vector<int> &sol, int nr, int n) {
    // nr = nr de submultimi din partitia curenta
    //n nr de elemente din vectorul A. dar si din sol!
    int i,j;
    for (i=1; i<=nr; i++) {
        // in partitia i afisez submutlimile
        // un element A[j] apartine paritiei i daca sol[j] == i si itterez prin j
        printf("{ ");
        for (j=0; j<n; j++) {
            if (sol[j] == i) {
                //daca elementul curent apartine de submultimea i
                printf("%d ", A[j]);
            }
        }
        printf("} ");
    }
    printf("\n");
}

void back_culegere(int k, int n, int nr, vector<int> &A, vector<int> &sol) {
    if (k == n) {
        // k e indexul din A si sol? mai are sens ce zic mai jos?
        // nu pot avea numar de submultimi din partitia curenta mai mare ca nr de elemente disponibil
        tipar(A, sol, nr, n);
        return;
    }
    else {
        // incepem sa iteram prin indicii submutlimilor din aprtitia curenta controlat de nr
        // poate sa incepa si de la 1 pentru ca nu am indiciele asta accesat in vreun vector
        for (int i=1; i<=nr; i++) {
            sol[k] = i; // asociez elementul k la submultimea i
            back_culegere(k+1, n, nr, A, sol); // nu schimb submultimea inca !
        }
        // ori nr e 0 si trb dat start la prima submultime 
        // ori s-a terminat for si trb oprit? nu inteleg ce e asta
        sol[k] = nr +1;
        back_culegere(k+1,n,nr + 1,A,sol); // am uitat saincrementez aici -> stack overflow
    }
}

int valid(int k, vector<int> &sol) {
    if (k == 0)
        return (sol[k] == 1);
    int max_posibil_pana_acum = 0;

    // sol[k] poate pune cel mult max(sol[0..k-1]) + 1 altfel omit submultimi
    for (int i = 0; i<k; i++) {
        if (sol[i] > max_posibil_pana_acum)
            max_posibil_pana_acum = sol[i];
    }

    return (sol[k] <= max_posibil_pana_acum + 1);
}

void tipar_2(vector<int> &A, vector<int> &sol, int n) {
    int i,j;
    // for (i=0; i < n; i++) {
    //     j = i; // ca sa pot s ail includ si pe primul
    //     printf(" {");
    //     while (j <n) {
    //         if (sol[j] == sol[i]) 
    //             printf("%d ", A[j]);
    //         j++;
    //     }
    //     printf("} ");
    // }
    // printf("\n");
    // nu cred ca este ok penteu ca pot fi amestecate ge 1 2 1

    int nr_submultimi = 0; 
    // il scoatem ca fiind maximul din vectorul sol
    for (i=0; i<n; i++) {
        if (sol[i] > nr_submultimi)
            nr_submultimi = sol[i];
    }
    // nr subultimi paritita curenta
    for (i =1; i<=nr_submultimi; i++) {
        printf("{ ");
        for (j=0; j<n; j++) {
            //acum iterez in vectori
            if (sol[j] == i) {
                printf("%d ", A[j]);
            }
        }
        printf("} ");
    }
    printf("\n");
}
void back(int k, int n, vector<int> &sol, vector<int> &A) {
    // cu pattern clasic
    if (k == n) {
        tipar_2(A, sol, n);
        return;
    }
    else {
        for (int i=1; i<=n; i++) {
            sol[k] = i;
            if (valid(k, sol)) 
                back(k+1, n,sol, A);
        }
    }


}
int main() {
    int n, x;
    cin>>n;
    vector<int>A;
    vector<int>sol(n);

    for (int i=0; i<n; i++) {
        cin>>x;
        A.push_back(x);
    }
    //back_culegere(0, n,0, A, sol);
    back(0,n,sol,A);
    return 0;
}