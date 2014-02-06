DESCRIPTION: READ IN DATA FILE USING A WHILE LOOP AND COMPUTING TOTALS USING THE

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

class APC{
        public:
                APC(const string &file);
                string fruit;
                struct ap_pair {
                        float fruit_amount, price;
                        float tfruit_amount, tprice;
                };

                void print_total();
                ap_pair compute_total();
                ~APC();
        private:
                ap_pair my_ap;
                ifstream fin;
};
APC::APC(const string &file){
        fin.open(file.c_str());
        if(!fin.is_open()){
                cout<< "Could not open file"<< endl;
                exit (1);
        }
}

APC::~APC(){
        fin.close();
}

void APC::print_total(){
        cout<< "Total amount: " << my_ap.tfruit_amount<< endl;
        cout << "Total price: " << fixed << setprecision(2) << my_ap.tprice << endl;
}

APC::ap_pair APC::compute_total(){

        while (fin>> fruit >> my_ap.fruit_amount >> my_ap.price){
                my_ap.tfruit_amount += my_ap.fruit_amount;
                my_ap.tprice += (my_ap.fruit_amount * my_ap.price);
        }
        return my_ap;
};

int main (int argc, char *argv[]) {
        if (argc != 2){
                cout <<" ERROR: Incorrect format. Please enter the name of the program
        }
        else {
                string file(argv[argc-1]);
                APC fruit(file);
                fruit.compute_total();
                fruit.print_total();
        return 0;
        }

