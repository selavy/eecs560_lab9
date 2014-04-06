#include <iostream>
#include <vector>
#include <fstream>
#include "MinMaxHeap.hpp"
#include "MyHeapUtils.hpp"

using namespace std;

int main( int argc, char **argv ) {
  ifstream ifs;
  
  if( argc > 2 ) {
    ifs.open( argv[1], ifstream::in );
  } else {
    ifs.open( "test_data.txt", ifstream::in );
  }

  if(! ifs.good() ) {
    cerr << "Unable to open input file" << endl;
    return 0;
  }

  vector<int> container;
  string line;
  while( ifs >> line ) {
    int val = atoi( line.c_str() );
    container.push_back( val );
  }

  //
  // Make heap using the MinMaxHeap constructor
  //
  MinMaxHeap heap( &container[0], container.size() );
  
  vector<int> result = heap.getVectorRepresentation();
  print_tree( result );
  cout << endl << "-------------------------------------------------------------------------" << endl;
  return 0;
}
