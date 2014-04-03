#include "MinMaxHeap.hpp"

MinMaxHeap::MinMaxHeap() {
}

MinMaxHeap::~MinMaxHeap() {
}

int MinMaxHeap::log2( int i ) {
  int counter = 0;
  while( ( i = (i >> 1) ) ) ++counter;
  return counter;
}

void MinMaxHeap::TrickleDown( int i ) {
  const int level = log2( i );
  if( level & 1 ) {
    TrickleDownMax( i );
  } else {
    TrickleDownMin( i );
  }
}

void MinMaxHeap::TrickleDownMin( int i ) {
  const int child1 = 2*i;
  const int child2 = child1 + 1;
  int m;
  
  if( ( child1 <= max_ ) && ( child2 <= max_ ) && ( A_[child1] != EMPTY ) && ( A_[child2] != EMPTY ) ) { // if has children then
    const int grandchild1_1 = 2*child1;
    const int grandchild2_1 = grandchild1_1 + 1;
    const int grandchild1_2 = 2*child2;
    const int grandchild2_2 = grandchild1_2 + 1;

    m = ( child1 < child2 ) ? child1 : child2;
    m = ( grandchild1_1 < m ) ? grandchild1_1 : m;
    m = ( grandchild2_1 < m ) ? grandchild2_1 : m;
    m = ( grandchild1_2 < m ) ? grandchild1_2 : m;
    m = ( grandchild2_2 < m ) ? grandchild2_2 : m;
    
    if( ( m == grandchild1_1 ) || ( m == grandchild1_2 ) || ( m == grandchild2_1 ) || ( m == grandchild2_2 ) ) { // if A[m] is a grandchild of A[i] then
      //
      // A_[m] is a granchild of A_[i]
      //
      if( A_[m] < A_[i] ) {
	int tmp = A_[m];
	A_[m] = A_[i];
	A_[i] = tmp;
	
	const int parent = m / 2;
	if( A_[m] > A_[parent] ) { // if A[m] > A[parent(m)] then
	  int tmp = A_[m];
	  A_[m] = A_[parent];
	  A_[parent] = tmp;
	} // end if( A[m] > A[parent(m)] )
	TrickleDownMin( m );
      } // end if( A[m] < A[i] )
      else {
	//
	// A[m] is a child of A[i]
	//
	if( A[m] < A[i] ) {
	  int tmp = A[m];
	  A[m] = A[i];
	  A[i] = tmp;
	} // end if A[m] < A[i]
      } // end else
    } // end if A[m] is a grandchild of A[i]
  } // end if A[i] has children
}

void MinMaxHeap::TrickleDownMax( int i ) {
  const int child1 = 2*i;
  const int child2 = child1 + 1;
  int m;
  
  if( ( child1 <= max_ ) && ( child2 <= max_ ) && ( A_[child1] != EMPTY ) && ( A_[child2] != EMPTY ) ) { // if has children then
    const int grandchild1_1 = 2*child1;
    const int grandchild2_1 = grandchild1_1 + 1;
    const int grandchild1_2 = 2*child2;
    const int grandchild2_2 = grandchild1_2 + 1;

    m = ( child1 > child2 ) ? child1 : child2;
    m = ( grandchild1_1 > m ) ? grandchild1_1 : m;
    m = ( grandchild2_1 > m ) ? grandchild2_1 : m;
    m = ( grandchild1_2 > m ) ? grandchild1_2 : m;
    m = ( grandchild2_2 > m ) ? grandchild2_2 : m;
    
    if( ( m == grandchild1_1 ) || ( m == grandchild1_2 ) || ( m == grandchild2_1 ) || ( m == grandchild2_2 ) ) { // if A[m] is a grandchild of A[i] then
      //
      // A_[m] is a granchild of A_[i]
      //
      if( A_[m] > A_[i] ) {
	int tmp = A_[m];
	A_[m] = A_[i];
	A_[i] = tmp;
	
	const int parent = m / 2;
	if( A_[m] < A_[parent] ) { // if A[m] < A[parent(m)] then
	  int tmp = A_[m];
	  A_[m] = A_[parent];
	  A_[parent] = tmp;
	} // end if( A[m] < A[parent(m)] )
	TrickleDownMin( m );
      } // end if( A[m] > A[i] )
      else {
	//
	// A[m] is a child of A[i]
	//
	if( A[m] > A[i] ) {
	  int tmp = A[m];
	  A[m] = A[i];
	  A[i] = tmp;
	} // end if A[m] > A[i]
      } // end else
    } // end if A[m] is a grandchild of A[i]
  } // end if A[i] has children
}


