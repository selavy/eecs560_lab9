#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "MinMaxHeap.hpp"

using namespace std;

int main(int argc, char **argv) {
  ifstream ifs;
  vector<int> container;

  if( argc > 2 ) {
    ifs.open( argv[1], ifstream::in );
  } else {
    ifs.open( "test_data.txt", ifstream::in );
  }

  if(! ifs.good() ) {
    cerr << "Unable to open input file" << endl;
    return 0;
  }

  MinMaxHeap heap;
  string line;
  while( ifs >> line ) {
    int val = atoi( line.c_str() );
    heap.insert( val );
    container.push_back( val );
  }

  MinMaxHeap heap2( &container[0], container.size() );
  heap.print( cout );
  int upperLimit = container.size() / 8;
  for( int i = 0; i < upperLimit; ++i ) {
    int min = heap.FindMin();
    if( min != heap2.FindMin() ) {
      cout << heap2.FindMin() << ": min didn't match!!" << endl;
    }
    int max = heap.FindMax();
    if( max != heap2.FindMax() ) {
      cout << heap2.FindMax() << ": max didn't match!!" << endl;
    }
    cout << "min: " << heap.FindMin() << endl;
    cout << "max: " << heap.FindMax() << endl;
    heap.DeleteMin();    heap2.DeleteMin();
    heap.DeleteMax();    heap2.DeleteMax();
  }

  heap.insert( 5 ); heap2.insert( 5 );
  heap.insert( 100 ); heap2.insert( 100 );
  heap.insert( -200 ); heap2.insert( -200 );
  heap.insert( -500 ); heap2.insert( -500 );

  for( int i = 0; i < upperLimit; ++i ) {
    int min = heap.FindMin();
    if( min != heap2.FindMin() ) {
      cout << heap2.FindMin() << ": min didn't match!!" << endl;
    }
    int max = heap.FindMax();
    if( max != heap2.FindMax() ) {
      cout << heap2.FindMax() << ": max didn't match!!" << endl;
    }
    cout << "min: " << heap.FindMin() << endl;
    cout << "max: " << heap.FindMax() << endl;
    heap.DeleteMin();     heap2.DeleteMin();
    heap.DeleteMax();     heap2.DeleteMax();
  }

  return 0;
}
