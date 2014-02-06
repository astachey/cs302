DESCRIPTION: READ IN DATA FILE USING A WHILE LOOP AND COMPUTING TOTALS USING THE

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

struct ap_pair {
        float tamount, price;
};
struct ap_pair compute_total(){
        struct ap_pair my_ap;
        string a;
        float b, c;
        float famount, tamount, price;
        while (cin >> a >> b >> c){
                famount= b*c;
                my_ap.tamount += b;
                my_ap.price += famount;
        }
        return ( my_ap);
};

int main () {
        struct ap_pair my_ap=compute_total();
        cout << "total amount = " << my_ap.tamount << endl;
        cout << "total price = " << fixed << setprecision(2) << my_ap.price << e
}

