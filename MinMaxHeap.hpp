#ifndef _MINMAXHEAP_
#define _MINMAXHEAP_

#include <iostream>
#include <climits>

using namespace std;

class MinMaxHeap {
public:
  MinMaxHeap();
  virtual ~MinMaxHeap();

  void insert( int i );
  int FindMax();
  int FindMin();
  void DeleteMax();
  void DeleteMin();
  void print( std::ostream& os );

private:
  int log2( int i );
  void TrickleDown( int i );
  void TrickleDownMin( int i );
  void TrickleDownMax( int i );
  void BubbleUp( int i );
  void BubbleUpMax( int i );
  void BubbleUpMin( int i );

  int current_;
  int max_;
  int * A_;
};

#endif
