#include <iostream>
#include<math.h>
using namespace  std;

int compute_most_frequent_move(int x,int y, int z) {
    // daca sunt toate egale
    if (x == y && y == z ) 
        return x;
    if (x > y) {
        if (y >= z)
            return x;
    }
    else {
        // x <= y
        if (z > y)
            return z;
        else return y; // z <= y
    }
}

void build_string(int fr_move, int x, int y, int z, string &res) {
    string aux;
    char move;
    if (fr_move ==x) {
        //R
        move = 'P';
        aux = string(x, move); // RRR.. apoi vin restul
        // dar incerc asa
        for (int i = 0; i<y; i++)
            aux += 'P';
        for (int i=0; i<z; i++) 
            aux+= 'R';

    } else if (fr_move == y) {
        for (int i = 0; i<x; i++)
            aux += 'P';
        move = 'R';
        string temp = string(y, move);
        aux.append(temp);
        for (int i=0; i<z; i++) 
            aux+= 'R';
    
    } else if (fr_move == z) {
        move = 'S';

        for (int i=0; i<x; i++) {
            //vr sa pierd in fata Rock - pun P
            aux += 'P';
        }
        for (int i =0; i<y; i++) {
            // vr sa pierd in fata lui Sciss - pun R
            aux += 'R';
        }

        string temp2 = string(z, 'S');
        aux.append(temp2);
    }
     res = aux; //WA test 2
}

void sol2(int x, int  y, int z, string &res) {
    int total = z + y +z;

    int most_freq = max(x,y);
    most_freq = max(most_freq, z);
    char move;

    if (most_freq == x ) {
        move = 'P';
    } else  if (most_freq == y) {
        move = 'R';
    } else if (most_freq == z) {
        move = 'S';
    }

    res = string(total, move);


}
int main() {
    int test_cases;
    int x, y, z;

    string res;
    int sol_len;
    int fr_move;
    cin>>test_cases;
    while (test_cases) {
        cin>>x>>y>>z;
        sol_len = x + y + z;
        // R S P
        // care mtare a lui alice e cea mai frecventa? acolo atacam
        fr_move = compute_most_frequent_move(x,y,z);

        build_string(fr_move, x, y, z, res);
        // sol2(x,y,z, res);
        cout<<res<<"\n";
        res.clear();
        // printf("AAA");
        test_cases--;
    }
    return 0;
}