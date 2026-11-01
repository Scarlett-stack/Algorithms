#include <iostream>
#include <string>
using namespace std;

void simplify(string &res, string &p, string &q) {
    // caut litera din q in p
    // daca exista nu o pun in res
    // folosim erase(index, cate chars sterg)

    for (char c : p) {
        size_t pos_in_q = q.find(c);
        // nu l-am gasit -> il pun in res
        if (pos_in_q == string::npos) {
            res+=c;
        } 
        else {
            //il simplific
            q.erase(pos_in_q, 1);
        }
    }
}
void validate(string &res, string &p, string &q) {
    if (q.length() == 0) {
        if (res.length() == 3) {
            if (res.find('s') != string::npos && res.find('i') != string::npos && res.find('x') != string::npos) {
                cout<<"YES";
            }
            else cout<<"NO";
        } else cout<<"NO";
    } else cout<<"NO";

    cout<<"\n";
}
int main() {

    int test_cases, n, m;
    cin>>test_cases;

    string p, q;
    string res; //aici pun rez simplificarii

    while (test_cases) {
        cin>>n>>m; //lens
        cin>>p>>q;
        
        simplify(res, p, q);

        //cout<<"dUPA SIMPLIFY res: "<<res<<" p: "<<p<<" q: "<<q<<"\n";

        validate(res, p, q);
        res.clear();
        test_cases--;
    }
    return 0;
}