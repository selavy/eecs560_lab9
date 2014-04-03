#include <iostream>

int log2( int i ) {
  int counter = 0;
  while( (i = (i >> 1))) {
    ++counter;
  }
  return counter;
}

using namespace std;

int main(int argc, char **argv) {
  cout << log2( 0 ) << log2( 2 ) << " " << log2( 10 ) << " " << log2( 100 ) << endl;
  return 0;
}
