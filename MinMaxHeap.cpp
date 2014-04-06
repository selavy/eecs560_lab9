#include "MinMaxHeap.hpp"

MinMaxHeap::MinMaxHeap() : current_( 1 ), max_( 500 ) {
  A_ = new int[ max_ + 1 ];
}

MinMaxHeap::MinMaxHeap( int A[], int size ) : current_( size ), max_( 500 ) {
  memcpy( A_ + 1, A, size );
  
  const int middle = size / 2;
  for( int i = middle; i >= 1; --i ) {
    TrickleDown( i );
  }
}

MinMaxHeap::~MinMaxHeap() {
  delete [] A_;
}

void MinMaxHeap::insert( int i ) {
  if( current_ >= max_ ) {
    //
    // Ran out of room
    //
    return;
  }

  A_[current_] = i;
  BubbleUp( current_++ );
}

int MinMaxHeap::FindMax() {
  if( current_ == 1 ) { // if no elements
    return 0; // error condition, throw exception?
  }
  else if( current_ == 2 ) { // if only 1 element
    return A_[1];
  }
  else if( current_ == 3 ) { // if only 2 elements
    return A_[2];
  }
  else { // else more than 2 elements
    return ( A_[2] > A_[3] ) ? A_[2] : A_[3];
  }
}

int MinMaxHeap::FindMin() {
  if( current_ > 1 )
    return A_[1];
  else
    return 0; // error condition, throw exception?
}

void MinMaxHeap::DeleteMax() {
  //
  // Fix Me
  //
  if( current_ == 1 ) {
    return; // error condition, throw exception?
  }
  else if( current_ == 2 ) { // if only 1 element
    --current_;
  }
  else if( current_ == 3 ) { // if only 2 elements
    --current_;
  }
  else { // else more than 2 elements
    int max_index = ( A_[2] > A_[3] ) ? 2 : 3;
    A_[max_index] = A_[--current_];
    TrickleDown( max_index );
  }
}

void MinMaxHeap::DeleteMin() {
  if( current_ <= 1 ) {
    //
    // nothing to remove
    //
    return;
  }

  A_[1] = A_[--current_];
  TrickleDown( 1 );
}

void MinMaxHeap::print( std::ostream& os ) {
  for( int i = 1; i < current_; ++i ) {
    os << A_[i] << std::endl;
  }
}

int MinMaxHeap::log2( int i ) {
  int counter = 0;
  while( ( i = (i >> 1) ) ) ++counter;
  return counter;
}

void MinMaxHeap::TrickleDown( int i ) {
  const int level = log2( i );
  if( level == 0 ) {
    TrickleDownMin( i );
  } else if( level & 1 ) { // if on an odd level => max
    TrickleDownMax( i );
  } else { // if on an even level => min
    TrickleDownMin( i );
  }
}

void MinMaxHeap::TrickleDownMin( int i ) {
  const int childL = 2*i;
  const int childR = childL + 1;
  const int grandchildL_L = 2*childL;
  const int grandchildL_R = grandchildL_L + 1;
  const int grandchildR_L = 2 * childR;
  const int grandchildR_R = grandchildR_L + 1;

  int m = 0;

  //
  // Check if has any children or grandchild
  // if none, then m will remain 0
  // otherwise, m will be set to the position
  // in the array with the lowest value out of
  // the children and grandchildren.
  //
  // This control logic depends on the fact that
  // if the node does not have a left child then
  // it does not have a right child, and if it
  // doesn't have a right child then it doesn't
  // have any grandchildren, etc.
  //
  if( EXISTS( childL ) ) { // if has left child
    m = childL;
    if( EXISTS( childR ) ) { // if has right child
      if( A_[childR] < A_[m] ) { // if should set m to right child
	m = childR;
      }
      if( EXISTS( grandchildL_L ) ) { // if has left left grandchild
	if( A_[grandchildL_L] < A_[m] ) { // if should set m to left left grandchild
	  m = grandchildL_L;
	}
	if( EXISTS( grandchildL_R ) ) { // if has left right grandchild
	  if( A_[grandchildL_R] < A_[m] ) { // if should set m to left right grandchild
	    m = grandchildL_R;
	  }
	  if( EXISTS( grandchildR_L ) ) { // if has right left grandchild
	    if( A_[grandchildR_L] < A_[m] ) { // if should set m to right left grandchild
	      m = grandchildR_L;
	    }
	    if( EXISTS( grandchildR_R ) && ( A_[grandchildR_R] < A_[m] ) ) { // if has right right grandchild and should set m to that
	      m = grandchildR_R;
	    }
	  }
	}
      }
    }
  }

  if( m == 0 ) {
    //
    // has no children
    //
    return;
  }
  
  //
  // m holds index to smallest child or grandchild of A[i]
  //
  if( ( m == grandchildL_L ) || ( m == grandchildL_R ) || ( m == grandchildR_L ) || ( m == grandchildR_R ) ) { // if A[m] is a grandchild of A[i] then
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
  } // end if A[m] is a grandchild of A[i]
  else {
    //
    // A[m] is a child of A[i]
    //
    if( A_[m] < A_[i] ) {
      int tmp = A_[m];
      A_[m] = A_[i];
      A_[i] = tmp;
    } // end if A[m] < A[i]
  } // end else
}

void MinMaxHeap::TrickleDownMax( int i ) {
  const int childL = 2*i;
  const int childR = childL + 1;
  const int grandchildL_L = 2*childL;
  const int grandchildL_R = grandchildL_L + 1;
  const int grandchildR_L = 2 * childR;
  const int grandchildR_R = grandchildR_L + 1;

  int m = 0;

  //
  // Check if has any children or grandchild
  // if none, then m will remain 0
  // otherwise, m will be set to the position
  // in the array with the highest value out of
  // the children and grandchildren
  //
  if( EXISTS( childL ) ) { // if has left child
    m = childL;
    if( EXISTS( childR ) ) { // if has right child
      if( A_[childR] > A_[m] ) { // if should set m to right child
	m = childR;
      }
      if( EXISTS( grandchildL_L ) ) { // if has left left grandchild
	if( A_[grandchildL_L] > A_[m] ) { // if should set m to left left grandchild
	  m = grandchildL_L;
	}
	if( EXISTS( grandchildL_R ) ) { // if has left right grandchild
	  if( A_[grandchildL_R] > A_[m] ) { // if should set m to left right grandchild
	    m = grandchildL_R;
	  }
	  if( EXISTS( grandchildR_L ) ) { // if has right left grandchild
	    if( A_[grandchildR_L] > A_[m] ) { // if should set m to right left grandchild
	      m = grandchildR_L;
	    }
	    if( EXISTS( grandchildR_R ) && ( A_[grandchildR_R] > A_[m] ) ) { // if has right right grandchild and should set m to that
	      m = grandchildR_R;
	    }
	  }
	}
      }
    }
  }

  if( m == 0 ) {
    //
    // has no children
    //
    return;
  }
  
  if( ( m == grandchildL_L ) || ( m == grandchildL_R ) || ( m == grandchildR_L ) || ( m == grandchildR_R ) ) { // if A[m] is a grandchild of A[i] then
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
      TrickleDownMax( m );
    } // end if( A[m] > A[i] )
  } // end if A[m] is a grandchild of A[i]
  else {
    //
    // A[m] is a child of A[i]
    //
    if( A_[m] > A_[i] ) {
      int tmp = A_[m];
      A_[m] = A_[i];
      A_[i] = tmp;
    } // end if A[m] > A[i]
  } // end else
}

void MinMaxHeap::BubbleUp( int i ) {
  const int level = log2( i );
  if( ( level & 1 ) == 0 ) { // if level is even => min level
    const int parent = i / 2;
    if( ( parent >= 1 ) && ( A_[i] > A_[parent] ) ) {
      int tmp = A_[i];
      A_[i] = A_[parent];
      A_[parent] = tmp;
      BubbleUpMax( parent );
    } else {
      BubbleUpMin( i );
    }
  } else { // else level is odd => max level
    const int parent = i / 2;
    if( ( parent >= 1 ) && ( A_[i] < A_[parent] ) )  {
      int tmp = A_[i];
      A_[i] = A_[parent];
      A_[parent] = tmp;
      BubbleUpMin( parent );
    } else {
      BubbleUpMax( i );
    }
  }
}

void MinMaxHeap::BubbleUpMin( int i ) {
  const int parent = i / 2;
  const int grandparent = parent / 2;
  if( ( grandparent >= 1 ) ) {
    if( A_[i] < A_[grandparent] ) {
      int tmp = A_[i];
      A_[i] = A_[grandparent];
      A_[grandparent] = tmp;
      BubbleUpMin( grandparent );
    }
  }
}

void MinMaxHeap::BubbleUpMax( int i ) {
  const int parent = i / 2;
  const int grandparent = parent / 2;
  if( ( grandparent >= 1 ) ) {
    if( A_[i] > A_[grandparent] ) {
      int tmp = A_[i];
      A_[i] = A_[grandparent];
      A_[grandparent] = tmp;
      BubbleUpMax( grandparent );
    }
  }
}

