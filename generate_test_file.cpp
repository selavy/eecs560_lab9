#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 25
#define FILE_NAME "test_data.txt"

int main( int argc, char **argv ) {
  int n = N;
  ofstream ofs;

  if( argc > 1 ) {
    n = atoi( argv[1] );
  }

  if( argc > 2 ) {
    ofs.open( argv[2], ofstream::out | ofstream::trunc );
  } else {
    ofs.open( FILE_NAME, ofstream::out | ofstream::trunc );
  }

  if(! ofs.good() ) {
    cerr << "Unable to open input file." << endl;
    return 0;
  }

  srand( time( NULL ) );

  for( int i = 0; i < n; ++i ) {
    ofs << ( rand() % (8*n) ) - (4*n) << endl;
  }

  ofs.close();
  return 0;
}
