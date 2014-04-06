#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "MinMaxHeap.hpp"

using namespace std;

int main(int argc, char **argv) {
  ifstream ifs;

  if( argc > 2 ) {
    ifs.open( argv[1], ifstream::in );
  } else {
    ifs.open( "test_data.txt", ifstream::in );
  }

  if(! ifs.good() ) {
    cerr << "Unable to open input file" << endl;
  }

  MinMaxHeap heap;
  string line;
  while( ifs >> line ) {
    int val = atoi( line.c_str() );
    heap.insert( val );
    //heap.print( cout );
    //cout << "-------------------------------------------------\n" << endl;
  }
  
  heap.print( cout );
  //heap.print( cout );
  //cout << "min was: " << heap.FindMin() << endl;
  //cout << "max was: " << heap.FindMax() << endl;
  //heap.DeleteMin();
  //heap.DeleteMax();
  //cout << "now min is: " << heap.FindMin() << endl;
  //cout << "now max is: " << heap.FindMax() << endl;
  //heap.print( cout );
  return 0;
}
