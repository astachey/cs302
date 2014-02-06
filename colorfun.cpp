// header files LOCATED IN SUPPORT.H

using namespace std;

#include "support.h"

int main(int argc, char *argv[])
{
        // perform command line argument checking
        pmode_t pmode;
        string colorsfile;
        string imgfile;
        if (argc == 1){
                cerr << "Not enough arguments given. Check proper usage." << end
                exit (1);
        }
        if (argc > 5) {
                cerr << "Too many arguments given. Check proper usage." << endl;
                exit (1);
        }

        // -1 : process mode = process1 [optional]
        if(argv[1] == "-1"){
                pmode = run_process1;
        }
        // -2 : process mode = process2 [optional]
        else if( argv[1] == "-2"){
                pmode = run_process2;
        }
        else{
                cerr << "First argument is incorrect. Please select -1 or -2."<<
        }
        // -c qc_x.txt : qcolors fname  [optional]
        // last argument : image fname  [required]
                imgfile = argv[argc -1];
// instantiate image object
                PPM ppmfile;
        // read image data
                ppmfile.read(imgfile);
        // process image data
                ppmfile.process( pmode, colorsfile); 
        // write result to file
                ppmfile.write( imgfile, colorsfile.substr( 0, colorsfile.size() 
                return 0;
}
