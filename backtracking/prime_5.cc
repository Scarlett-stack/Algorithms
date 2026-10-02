#include <iostream>
#include <vector>
using namespace std;

/* primele m numere prime de cel putin 2 cifre.
 * sa se scrie in prime.out toate sirurile de n nr prime distincte alese din cele m
 */

bool is_prime(int number) {
    int d = 2;
    bool prime = true;
    // un nr prime e divizibil cu 1 si el insusi
    while (d*d <= number && prime) {
        if (number % d == 0)
            prime = false;
        d++;
    }
    return prime;
}
void find_first_m_primes(int m, vector<int> &primes) {

    // incepem de la 10 in sus
    int i = 0;
    int number = 11;

    while(i < m) {
        if (is_prime(number) == true) {
            // ai initializat vectorul cu ()
            // cand dai push back se aloca de la final inca un slot
            // deci nu e bine
            // primes.push_back(number);
            primes[i] = number;
            printf("am pushuit %d %d\n", primes[i], number);
            i++; // trebuie aici pentru ca numara numerele prime nu si restul
        }
        number++;
        printf("din while: %d si %d\n", i, number);
    }
}

void tipar(vector<int>& sol,int n,  vector<int> &primes) {
    // sol[i] = indice din primes
    for (int i =1; i<=n; i++) {
        // scad 1 pentru ca am pus pe nivelul k indici incepand de la 1
        printf("%d ", primes[sol[i] -1]);
    }
    printf("\n");
}

int valid(int k, vector<int> &sol) {
    int i;
    int ev = 1;
    for (i=1; i<k; i++) 
        if (sol[k] == sol[i])
            ev = 0;
    return ev;
}
void back(int k, int n, int m, vector<int> &sol, vector<int> &primes) {
    if (k == n + 1) {
        tipar(sol,n, primes);
    }
    else {
        for (int i = 1; i<=m; i++) {
            //init
            sol[k] = i;
            if (valid(k, sol))
                back(k+1, n, m, sol, primes);
        }
    }
}
int main() {

    int n, m;

    cin>>n>>m;
    vector<int> primes(m+1);
    vector<int> sol(n+1);

    find_first_m_primes(m, primes);

    printf("primes: \n");
    for (int i = 0; i<m; i++)
        printf("%d ", primes[i]);
    
        printf("end primes \n");
    back(1,n,m,sol,primes);
    return 0;
}