/*
lista citita formata din n cuvinte. se construieste cu aceste cuvinte (nu trb toate neaparat)
cel mai lung sir in care fiecare cuvant folosit in sir are ultima litera mai mica in sesn lexicografic
decat prima litera a cuvantului urmator

ex:
n=4
ana, capat, repede, merge

trebuie sa obtin:
ana repede merge
  |<|    |<| -- am marcat prima si ultima obsrva ca sunt in ordine lexi.

Ce ma gandeam eu:
- in sol[k] = cuvinte[i]
- valid ar arata ceva de genu:
- verific cu k-1 pentru ca pe k am solutia curenta PROPUSA
valid(k, sol) {
    // mai usor daca k e 0 retunrezi direct true
    if k == 0
        return 1;
    ev = 1;
    if (sol[k-1][strlen(sol[k-1]) -1] >= sol[k][0]) {
        //atunci se rupe lantul
        ev = 0;
    }
    return ev;
}

Bun dar nu pot ajunge in valid daca am doar un cuvant. Deci orice solutie cu un singur cuvant in ea
e valida!!

Cum arata restul?
Ce conditie de oprire pun daca lungimea lui sol variaza?
Cum stiu ca e solutia de lungime max (lungime se refera aici la nr de cuvine incluse)
DE asemenea vom presuspune ca nu rebuie neapatart sa luam pe rand si sa ignoram ce aveam inainte
O solutie poate incepe cu orice cuvant
Deci o sa facem cu permutari adica o sa avem nevoie de un vector de vizitati

max_len = maximul la care ne raportam asta este updated
sol_max[] = vectorul in care pastram solutia gasita !! Atentie e daor de rezerva si copiez primele k chestii din sol aici

back(k, sol, cuvinte, vizitat) {
    // tot trb sa ne asiguram ca nu depasim n
    // TIPAR FACI DOAR LA ALEA VALIDE
    if k == n
        return;
    else {
        //iteram prin cuvinte
        for (i=0, <n) {
            if (vizitat[i] == 0) {
                // adica daca nu l-am pus deja
                // il pun si verific daca e valid
                sol[k] = cuvant[i]
                if (valid(k, sol)) {
                    // daca e singur sau daca respeta valid
                    // pot trece mai departe
                    // dar mai intai update la max len
                    if k+1 > max_len
                        max_len = k+1
                    // de ce sa fie k+1 aici nu are sens
                    // BA DA ARE SENS! PENTRU CA K PRONESTE DE LA 0 DAR LUNGIMEA NU POATE FI 0!!!
                    // totusi nu inseamna ca asta e solutia finala
                    // deci tot ne trebuie un vector intermediar cu care sa comparam max_len
                    // copiem ce avem in sol acuma in sol_max
                    copy(sol, sol_max, k)
                    // copy nu e bun aici pentru ca trb sa ma asigur ca max len e updatat deci il bag in if
                    // marchez ca vizitez si bag in sol
                    vizitat[i] = 1
                    sol[k] = cuvinte[i]
                    // intrebare apelul pt niv urmator unde se face?
                    // aici in valid? cred ca da. Pentru ca si un singur cuvant e solutie
                    // ramurile se construiesc de la 0 sau de la i
                    back(k+1, cuvinte, vizitat)
                    vizitat[i] = 0
                    // eu nu inteleg cum se opreste nebunia asta daca am solutie care e buna si nu e de lung n
                }
            }
        }
    }
}
*/
#include <iostream>
#include <string>
#include<vector>
using namespace std;

// string in c++ este MUTABIL
void copy(vector<std::string> &sol, vector<std::string> &sol_max, int max_len) {
    // ATENTIE!!! TEBUIE REDIMENSIONAT INAINTE PENTRU CA AVEM DE AFACE CU SOLUTII DE L DIFERIT
    sol_max.resize(max_len);
    for (int i=0; i<max_len; i++) {
        sol_max[i] = sol[i]; 
    }
}

void tipar(vector<std::string> &sol_max, int max_len) {
    vector<std::string>::iterator it;
    for (it = sol_max.begin(); it != sol_max.end(); it++) {
        cout<<*it<<' ';
    }
    cout<<"\n";
}

int valid(vector<std::string> &sol, int k) {
    if (k==0)
        return 1;
    int ev = 1;
    char first_char_current_word =  sol[k].front();
    char last_letter_previous_word = sol[k-1][sol[k-1].length() - 1];

    printf("PT %s: \n", sol[k].c_str());
    printf("prima litera cuvant curent: %c \n", first_char_current_word);
    printf("ultima litera cuvant anterior: %c \n", last_letter_previous_word);

    if (first_char_current_word <= last_letter_previous_word)
        ev = 0;
    return ev;
}

void back(int k, int n,int &max_len, vector<std::string> &sol, vector<std::string> &sol_max,vector<std::string> &cuvinte, vector<int> &vizitat) {
    // cand apelez tipar
    if (k == n) {
        return;
        // nu dau aici tipar nu am garantie ca am solutie de max_len
        // sau pot sa printez aceasi solutie de mai multe ori
    }
    else {
        //iteram prin cuvinte
        for (int i = 0; i<n; i++) {
            if (!vizitat[i]) {
                // daca nu l-am mai pus
                // verific daca am solutie pana acuma AICI SI ACUM
                // pentru ca pot si de un singur cuvant considera solutia!!
                // ok acuma punem cuvantul
                sol[k] = cuvinte[i];
                if (valid(sol, k)) {   
                    // SA NU PUI AICI CUVANTUL PT CA
                    // ajungi in valid cu k 0 intoarce 1, dar eu nu am pus nimic inca
                    // trec la k=1 ABIA ACUM PUN CUVANT 
                    // teoetic tot 1 ar trb sa intorc dar nu are sens sa mai includ si 0!!
                    if (k + 1 > max_len) {
                        // conditia actuala obliga la salvarea primei aparitii max_len maxim
                        // daca am mai multe posibilitati de acelasi max_len posibil?
                        // atunci imi trb o matrice de stringuri
                        max_len = k + 1;
                        // si salvam solutia curenta in sol_max pentru ca o putem pierde altfel
                        copy(sol, sol_max, max_len);
                    }
                    vizitat[i] = 1;
                    back(k+1, n, max_len, sol, sol_max, cuvinte, vizitat);
                    vizitat[i] = 0;
                }
            }
        }
    } 
}
int main() {

    int n;
    cin>>n;

    string input_s;
    vector<std::string> cuvinte;
    vector<std::string> sol_max;
    vector<std::string> sol;
    for (int i=0; i<n; i++) {
        cin>>input_s;
        //oare trb sa ii fac clear?
        // adica concateneaza sau ce?
        // nu le concateneaza e ok
        cuvinte.push_back(input_s);
    }

    printf("din main:");
    for (int i =0; i<n; i++)
        printf("%s ", cuvinte[i].c_str());
    sol.resize(n); // idk ma mai gandesc aici
    int max_len = 0;
    vector<int> vizitat(n,0);
    
    back(0, n, max_len, sol, sol_max, cuvinte, vizitat);

    tipar(sol_max, max_len);
    //cout<<input_s<<"\n";
    return 0;
}