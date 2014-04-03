#ifndef _MINMAXHEAP_
#define _MINMAXHEAP_

class MinMaxHeap {
public:
  MinMaxHeap();
  virtual ~MinMaxHeap();

private:
  int log2( int i );
  void TrickleDown( int i );
  void TrickleDownMin( int i );
};

#endif
