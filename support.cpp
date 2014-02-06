// header files
#include <cmath>
#include "support.h"
using namespace std;


//RGB::RGB(uchar _R = 0, uchar _G= 0, uchar _B = 0){
//  R = _R;
//  G = _G;
//  B = _B;

//  return;
//}/

// RGB::operator<()
// RGB::distance()
double RGB::distance(const RGB& next){
    double dist = sqrt(pow((double)R - next.R, 2)) + (pow((double)G - next.G, 2))+(pow((double)B - next.B, 2));
}
RGB RGB::quantize(const int &Q){
    RGB tmp;
    tmp.R = Q*(R/Q);
    tmp.G = Q*(G/Q);
    tmp.B = Q*(B/Q);
    return tmp;
}

PPM::PPM() {
    magicid = "P6";
    nrows = 0;
    ncols = 0;
    maxvalue = 255;
}

PPM::~PPM() { }

void PPM::read(const string & fname)
{
    ifstream fin;
    if(fname.substr(fname.find_last_of(".")+1) == "ppm"){
        fin.open(fname.c_str());
        if(!fin.is_open()){
            cerr << "Unable to open file."<<endl;
        }
    }

    else{
        cerr << "Invalid file name." <<endl;
        exit (1);
    }
    // extract suffix: must be ppm
    // open fname: check status
    string magicid;
    int nrows, ncols, maxval;
    fin >> magicid >> nrows >> ncols >> maxvalue;
    if (magicid!= "P6"){
        cerr << "Magic Number for ppm file is not P6. Exiting. " << endl;
        exit(1);
    }
    // read magicid: must be P6
    // read ncols, nrows: check status

    // read maxvalue: must be 255
    if (maxvalue != 255){
        cerr << "Max value does not equal 255. "<< endl;
        exit(1);
    }
    int npixels = (ncols*nrows);
    int nbytes = 3 * npixels;
    img.assign(nbytes, RGB());
    // allocate space for 3*npixels in img vector
    // read 3*npixels bytes into img: check status
    if(img.size()!=nbytes){
        cerr<< "Error creating image vector. Exiting."<<endl;
        exit(1);
    }
    fin.read((char* ) img.data(), nbytes);


    // close input file
    fin.close();
}

void PPM::write(const string & fname)
{
    // open fname: check status
    ofstream fout;
    fout.open( fname.c_str());
    if(!fout.is_open()){
        cerr << "Unable to open output file. Exiting."<<endl;
        exit (1);
    }
    // write header
    fout << magicid << endl << ncols << " " << nrows << endl << maxvalue << endl;
    int npixels = ncols*nrows;
    // write 3*npixels from img vector
    int nbytes = 3 * npixels;
fout.write(( char* ) img.data(), nbytes);

    // close output file
    fout.close();
}

void PPM::write(const string & fname, const string & addon)
{
    // new_fname: image.ppm -> image_addon.ppm
    string noext = fname.substr(0, fname.size() - 4);
    string newfile = noext + "_" + addon + ".ppm";

    // call write(new_fname);
    write(newfile);

    return;
}

void PPM::process(pmode_t pmode, const string &fname)
{
    // read qcolors in fname
    //int _R, _G, _B;
    //ifstream colsin;
    //colsin.open(fname.c_str());
    //if(!colsin.is_open()){
    //      cerr << "Could not open filename to process. Exiting now."<<endl;
    //  }
    //  while ( colsin ) {
    //      qcolors.push_back(RGB());
    //      while (colsin.get()!= '\n' && !colsin.eof()) {}
    //  }
    //  colsin.close();
    read_qcolors(fname);

    // run proper process mode
    if( pmode == run_process1){
        process1();
    }
    else if(pmode == run_process2){
        process2();
    }
else{
        cerr<< "No valid process to run. Exiting now." << endl;
        exit(1);
    }
    return;

}

void PPM::process1()
{
    // for each pixel {
    for( int i = 0; i < img.size(); i++){
        map<int, RGB> colormap;
        //   find  closest qcolor 
        for( int j = 0; j< colormap.size(); j++){
            //   set pixel color to closest qcolor
            colormap.insert( pair< int, RGB >( img[i].distance ( colormap[j]), colormap[j]));
        }
        img[i] = colormap.begin() -> second;
    }

    // }
}

void PPM::process2()
{
    // for each pixel {
    vector<map<int, RGB> > histo(qcolors.size());
    map< int, float> qmap;
    map< int, float> :: iterator iqmap;
    for( int i = 0; i < img.size(); i++){
        map<int, RGB> colormap;

        //   find closest qcolor
        for( int j = 0; j< colormap.size(); j++){
            qmap[j] = img[i].distance(qcolors[j]);
        }
        iqmap = min_element(qmap.begin(), qmap.end());
         //   update qcolor histogram of pixel color/8 counts
        RGB tmp;
        tmp = img[i].quantize(8);
        //   save closest qcolor index
        //for (int i; i < iqmap.size(); i++){
        //  if (iqmap[i]==histo[i]){
        //      iqmap->second++;
        //  }
        //  else{
        //      histo[iqmap -> first].insert (tmp,1);
        //  }
        // }
        //
        // for each qcolor {
        //   find highest count pixel value/8 
        //   replace qcolor with highest count pixel value/8
        // }
        //
        // for each pixel {
        //   set pixel color to qcolor[closest qcolor index]
        // }
}
}

void PPM::read_qcolors(const string &fname)
{
    // open fname: check status
    RGB tmp;
    ifstream fin;
    fin.open(fname.c_str());
    if(!fin.is_open()){
        cerr<< "Unable to open file. Exiting."<< endl;
        exit(1);
    }
    int r, g, b;
    string buffer;

    // 
    // while (more data0 {
    //   read R G B values
fin >> r >> g >> b >> buffer >> buffer;
    while(fin){
        tmp.R = r;
        tmp.G = g;
        tmp.B = b;
        //   save to qcolors vector
        qcolors.push_back (tmp);
        fin >> r >> g >> b >> buffer >> buffer;
    }
    // }
    // 
    // close input file
    fin.close();
}
                                                              
