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
  }
  
  heap.print( cout );
  int min = heap.FindMin();
  cout << "min was: " << min << endl;
  int max = heap.FindMax();
  cout << "max was: " << max << endl;
  heap.DeleteMin();
  heap.DeleteMax();
  return 0;
}
