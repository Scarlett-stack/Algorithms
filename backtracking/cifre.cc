/*
se considera sirul cifrelor de la 0 la 9. Sa se genereze toate numerele
de n cifre care nu contin 3 cifre pare sau 3 cifre impare alaturate. 
Fiecare numar rezultat va fi scris pe o linie noua in cifre.out.
*/
#include <iostream>
#include <vector>

using namespace std;

void tipar(vector<int> &sol, int n) {
    for (int i=1; i<=n; i++){
        printf("%d", sol[i]);
    }
    printf("\n");
}

int valid(vector<int> &sol, int k) {

    // numarul nu poate incepe cu 0
    if (k == 1 && sol[k] == 0)
    if (k >= 3 && sol[k] % 2 == 0 && sol[k-1] % 2 == 0 && sol[k-2] % 2 == 0)
        return 0;
    
    if (k >= 3 && sol[k] % 2 == 1 && sol[k-1] % 2 == 1 && sol[k-2] % 2 == 1) 
        return 0;  

    return 1;
}

// n : lungimea vectorului sol
// k indicele din sol
void back(int k, vector<int> &sol, int n) {
    if (k == n+1) 
        tipar(sol, n);
    else {
        for (int i=0; i<=9; i++) {
            sol[k] = i;
            if (valid(sol, k)) {
                back(k+1, sol, n);
            }
        }
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> sol(n+1);

    back(1, sol, n);
    return 0;
}