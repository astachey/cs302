#ifndef SUPPORT_H
#define SUPPORT_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <map>

// header files
using namespace std;

typedef unsigned char uchar;
typedef enum { run_process1, run_process2 } pmode_t;

struct RGB { 
        // constructor/destructor 
        RGB(){
                R = 0;
                G = 0;
                B = 0;
        }
//      RGB (uchar, uchar, uchar);
                ~RGB(){}
        // operator< overload
        //      operator<(const rhs.txt);
        // distance() function
        double distance(const RGB& next);
        uchar R, G, B;

        RGB quantize(const int &Q);

};

class PPM {
        public:
                PPM();
                ~PPM();

                void read(const string &);
                void write(const string &);
                void write(const string &, const string &);
                void process(pmode_t, const string &);

        private:
                string magicid;
                int nrows, ncols;
                int maxvalue;
                vector<RGB> img;
                vector<RGB> qcolors;

                void read_qcolors(const string &);
                void process1();
                void process2();
};

#endif


