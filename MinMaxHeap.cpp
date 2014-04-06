#include "MinMaxHeap.hpp"

MinMaxHeap::MinMaxHeap() : current_( 1 ), max_( 100 ) {
  A_ = new int[ max_ + 1 ];
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
  if( current_ == 1 ) {
    return 0; // error condition, throw exception?
  }
  else if( current_ == 2 ) {
    return A_[1];
  }
  else {
    if( current_ > 3 ) {
      return ( A_[2] > A_[3] ) ? A_[2] : A_[3];
    } else {
      return A_[2];
    }
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
  // TODO
  //
}

void MinMaxHeap::DeleteMin() {
  //
  // TODO
  //
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
  if( level & 1 ) { // if on an odd level => max
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
  // the children and grandchildren
  //
  if( childL < current_ ) {
    m = childL;
    if( ( childR < current_ ) && ( A_[childR] < A_[m] ) ) {
      m = childR;
      if( ( grandchildL_L < current_ ) && ( A_[grandchildL_L] < A_[m] ) ) {
	m = grandchildL_L;
	if( ( grandchildL_R < current_ ) && ( A_[grandchildL_R] < A_[m] ) ) {
	  m = grandchildL_R;
	}
      }
      if( ( grandchildR_L < current_ ) && ( A_[grandchildR_L] < A_[m] ) ) {
	m = grandchildR_L;
	if( ( grandchildR_R < current_ ) && ( A_[grandchildR_R] < A_[m] ) ) {
	  m = grandchildR_R;
	}
      }
    }
  } else {
    // has no children
    return;
  }
  
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
  } // end if A[m] is a grandchild of A[i]
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
  // in the array with the lowest value out of
  // the children and grandchildren
  //
  if( childL < current_ ) {
    m = childL;
    if( ( childR < current_ ) && ( A_[childR] > A_[m] ) ) {
      m = childR;
      if( ( grandchildL_L < current_ ) && ( A_[grandchildL_L] > A_[m] ) ) {
	m = grandchildL_L;
	if( ( grandchildL_R < current_ ) && ( A_[grandchildL_R] > A_[m] ) ) {
	  m = grandchildL_R;
	}
      }
      if( ( grandchildR_L < current_ ) && ( A_[grandchildR_L] > A_[m] ) ) {
	m = grandchildR_L;
	if( ( grandchildR_R < current_ ) && ( A_[grandchildR_R] > A_[m] ) ) {
	  m = grandchildR_R;
	}
      }
    }
  } else {
    // has no children
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
      if( A_[m] < A_[parent] ) { // if A[m] > A[parent(m)] then
	int tmp = A_[m];
	A_[m] = A_[parent];
	A_[parent] = tmp;
      } // end if( A[m] > A[parent(m)] )
      TrickleDownMax( m );
    } // end if( A[m] < A[i] )
    else {
      //
      // A[m] is a child of A[i]
      //
      if( A_[m] > A_[i] ) {
	int tmp = A_[m];
	A_[m] = A_[i];
	A_[i] = tmp;
      } // end if A[m] < A[i]
    } // end else
  } // end if A[m] is a grandchild of A[i]
}

void MinMaxHeap::BubbleUp( int i ) {
  const int level = log2( i );
  if( ( level & 1 ) == 0 ) { // if level is even => min level
    const int parent = i / 2;
    if( ( parent >= 1 ) && A_[i] > A_[parent] ) {
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
      BubbleUpMin( grandparent );
    }
  }
}

