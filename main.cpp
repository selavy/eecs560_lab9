#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "MinMaxHeap.hpp"

using namespace std;

std::string do_padding (unsigned index, unsigned mlength){
  std::string padding;
  if (int((index-1)/2) != 0){
    return (int((index-1)/2) % 2 == 0) ?
    (do_padding(int((index-1)/2),mlength) + std::string(mlength+4,' ') + " ")  :
    (do_padding(int((index-1)/2),mlength) + std::string(mlength+3,' ') + " |") ;
  }
  return padding;
}


void printer (std::vector<int> const & tree, unsigned index, unsigned mlength){
  auto last = tree.size() - 1 ;
  auto  left = 2 * index + 1 ;
  auto  right = 2 * index + 2 ;
  std::cout << " " << tree[index] << " ";
  if (left <= last){
    auto llength = std::to_string(tree[left]).size();
    std::cout << "---" << std::string(mlength - llength,'-');
    printer(tree,left,mlength);
    if (right <= last) {
      auto rlength = std::to_string(tree[right]).size();
      std::cout << "\n" << do_padding(right,mlength) << std::string(mlength+ 3,' ') << " | ";
      std::cout << "\n" << do_padding(right,mlength) << std::string(mlength+ 3,' ') << " └" <<
      std::string(mlength - rlength,'-');
      printer(tree,right,mlength);
    }
  }
}


void print_tree (std::vector<int> & tree){
  unsigned mlength = 0;
  for (int & element : tree){
    auto clength = std::to_string(element).size();
    if (clength > mlength) {
      mlength = std::to_string(element).size();
    }
  }
  std::cout <<  std::string(mlength- std::to_string(tree[0]).size(),' ');
  printer(tree,0,mlength);
}

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
  for( int i = 0; i < 50; ++i ) {
    cout << "min: " << heap.FindMin() << endl;
    cout << "max: " << heap.FindMax() << endl;
    heap.DeleteMin();
    heap.DeleteMax();
  }

  /*
  std::vector<int> test;
  for(auto i =0; i<50; ++i){
    test.push_back(rand() % 1000 + 1);
  }
  std::make_heap(test.begin(),test.end());
  std::cout << "\n";
  print_tree(test);
  */

  heap.insert( 5 );
  heap.insert( 100 );
  heap.insert( -200 );
  heap.insert( -500 );

  for( int i = 0; i < 50; ++i ) {
    cout << "min: " << heap.FindMin() << endl;
    cout << "max: " << heap.FindMax() << endl;
    heap.DeleteMin();
    heap.DeleteMax();
  }

  return 0;
}
