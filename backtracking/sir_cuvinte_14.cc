/*
se da n nr nat <10 si m <20 . Se cere cel mai lung cuvant format prin concatenarea cuvintelor date in care:
- nici o litera nu apare de mai mult de m ori
Nu conteaza ordinea in care sunt concateate cuvintele. 

Ex:
n = 5
m = 3
cand poate frunza pica toamna

out:
poatefrunzacand

eu ma gandeam asa la valid:

sol, sol_max vectoru de strinuguri
k - nivelul curent
max_len - lungimea maxima a solutiei in nr de cuvinte, sau nu e in numar de cuvinte? nu prea stiu ce sa zic aici

valid(sol, k, freq, m) {
    recompute(freq, sol, k, add=True)
    ev = 1
    for i =0,<26 {
        if freq[i] > m {
            ev = 0
            break
        }
    }
    return ev
}

recompute(freq, sol, k, add=True){
    if add == True {
        for i=0;<strlen(sol[k]) {
            # nu e asa usor ca nu e map
            # nu compara cu frq[i] 
            # ascii cod a: 97 - 97 % 26?
            # ascii b: 98 - 97 = 1 , cred ca e suficient sa scad
            freq[sol[k][i] - 97]++
        }
    } else {
        # e false deci il scadem pe asta curent adaugat?
        for (i=0; <strlen(sol[k])) {
            freq[sol[k][i] - 97]--
        }
     }
}
compute_current_len(sol, k){
    int len = 0
    # care naiba e echivalentul in string din c++??
    # trebuie inclus si k PENTRU CA E DEJA IN VECTOR
    for i=0;<=k {
        len+=strlen(sol[i])
    }
    return len
}
back(sol, sol_max, k, n,m, max_len) {
    if k == n
        return
    else {
        for i =0,<n {
            if (!vizitat[i]) {
                sol[k] = cuvinte[i]
                current_len = compute_curr_len(sol, k)
                if (valid(sol, freq,k)) {
                    if (current_len > max_len) {
                        max_len = current_len
                        copy(sol_max, sol, max_len)
                    }
                    vizitat[i] = 1
                    back(k+1, sol, sol_max, n, m, max_len)
                    vizitat[i] = 0
                }
                recompute(freq, sol, k, add=False)
            }
        }
    }
}

============FOARTE IMPORTANT ===================
Desi initial te-ai gandit la pass by ref la max_len pentru ca aveai nevoie de asta ca sa printezi solutia finala
AI NEVOIE DE EA ORICUM
DE CE?
Daca pui pass by value transmiti max len cu 0 initial (asa si la ref)
Bun dar pe parcurs se modifica. Apelurile o modifica! Noi avem nevoie de a single source of truth pentru valoarea ei.
Eu banuiesc ca se duce in mai multe ramuri si cand ajunge la una cu 3 compara cu 0 iese 3. Face back. NU SE RETINE MAX DELOC PENTRU CA SE DISTRUGE STIVA AIA DE LA APELUL ANTERIOR
SI SE PIERDE VALOARE LUI MAX!! DECI PRACTIC FARA REFERINAT TU O SA AI MEREU O COMBINATIE INTRE ULTIMELE CUVINTE VALIDE DAR ASTA NU INSEAMNA CA E SO STRINGUL DE LUNGIME MAXIMA

ESTE FOARTE IMPORTANT LA PROBLEME CARE CALC MAXIMUL SA RETII MEREU ORI GLOBAL ORI REFERINTA VALOARE CU CARE O COMPARI SI O SETEZI!!!!!!!!!!!!!!!
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int valid(vector<std::string> &sol, int k, vector<int>& freq, int m) {
    // m e pragul
    int ev = 1;
    for (int i=0; i<26; i++) {
        if (freq[i] > m)
        {
            ev = 0;
            break;
        }
    }
    return ev;
}

//nu mai trimitem tot vectorul trimitem doar cuvatul curent
void recompute(vector<int> &freq, string &cuvant, bool add) {
    if (add == true) {
        for (char c : cuvant) {
            // nu pune direct -97 pentu ca trb reconversie la int
            // daca lasi direct cu 'a' e mai clar
            freq[c - 'a']++;
        }
    }
    else {
        for (char c: cuvant) {
            freq[c - 'a']--;
        }
    }
}
int compute_current_len(vector<std::string> &sol, int k) {
    int len = 0;
    for (int i=0; i<=k; i++) {
        len+=sol[i].length();
    }
    return len;
}

void copy(const vector<string> &sol, vector<string> &sol_max, int nr_cuvinte) {
    sol_max.resize(nr_cuvinte);
    for (int i = 0; i < nr_cuvinte; i++) {
        sol_max[i] = sol[i];
    }
}

void back(vector<std::string> &sol, vector<std::string> &sol_max,vector<std::string> &cuvinte, vector<int> &vizitat, vector<int> &freq, int k, int n, int m, int max_len, int current_len) {
    if (k == n)
        return;
    else {
        for (int i=0; i<n; i++) {
            if (!vizitat[i]) {
                sol[k] = cuvinte[i];
                current_len = compute_current_len(sol, k);
                recompute(freq, sol[k], true);
                if (valid(sol, k, freq, m)) {
                    //printf("e valid\n");
                    if (current_len > max_len) {
                        max_len = current_len;
                        copy(sol, sol_max, k+1);
                    }
                    vizitat[i] = 1;
                    back(sol, sol_max, cuvinte, vizitat, freq, k+1, n, m, max_len, current_len);
                    vizitat[i] = 0;
                }
                recompute(freq, sol[k], false);
            }
        }
    }
}

// lasa ca ma duc cu iterator ca mie lene sa mai bag o variabila
void tipar(vector<std::string> &sol_max) {
    for (auto it = sol_max.begin(); it != sol_max.end(); ++it) {
        cout<<*it;
    }
    cout<<"\n";
}
int main() {

    int n, m;
    cin>>n>>m;

    vector<std::string> cuvinte;
    vector<std::string> sol_max;
    vector<int> freq(26, 0);
    vector<std::string> sol(n);
    vector<int> vizitat(n, 0);
    string x;
    for (int i=0; i<n; i++) {
        cin>>x;
        cuvinte.push_back(x);
    }

    int max_len = 0;
    back(sol, sol_max, cuvinte, vizitat, freq, 0, n, m, max_len, 0);

    tipar(sol_max);
    return 0;
}   