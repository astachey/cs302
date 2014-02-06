DESCRIPTION: READ IN DATA FILE USING A WHILE LOOP AND COMPUTING TOTALS USING THE

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

struct ap_pair {
        float fruit_amount, tfruit_amount;
        float price, tprice;
};
struct ap_pair compute_total(const string file){
        ifstream fin;
        fin.open(file.c_str());
        struct ap_pair my_ap;
        string fruit;
        while (fin>> fruit >> my_ap.fruit_amount >> my_ap.price){
                my_ap.tfruit_amount += my_ap.fruit_amount;
                my_ap.tprice += (my_ap.fruit_amount * my_ap.price);
        }
        fin.close();
        return my_ap;
};

int main (int argc, char *argv[]) {
        if (argc != 2){
                cout <<" ERROR: Incorrect format." << endl;
        }
        else {
                const string file(argv[argc-1]);

                struct ap_pair my_ap=compute_total(file);
                cout << "total amount = " << my_ap.tfruit_amount << endl;
                cout << "total price = " << fixed << setprecision(2) << my_ap.tp
                //fin.close();
                return 0;
        }
}
