// bubble sort
#pragma once

#include <algorithm>

template <typename T>
void sortBubble(const T beg, const T end){
  for(size_t idx = 1; beg != end - idx; ++idx){
    for(T tempBeg = beg; tempBeg != end - idx; ++tempBeg){
      if(*(tempBeg + 1) < *tempBeg){
        std::iter_swap(tempBeg + 1, tempBeg);
      }
    }
  }
}