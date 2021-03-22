// quick sort
#pragma once

#include <algorithm>

template <typename T>
void sortQuick(const T beg, const T end){
  if(beg == end) return;
  T pivot = end - 1;
  T rightP = beg;
  for(T leftP = beg; leftP != pivot; ++leftP){
    if(*leftP < *pivot){
      std::iter_swap(leftP, rightP++);
    }
  }
  std::iter_swap(pivot, rightP);
  sortQuick(beg, rightP);
  sortQuick(rightP + 1, end);
}