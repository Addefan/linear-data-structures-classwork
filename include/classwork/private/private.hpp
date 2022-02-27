#pragma once

#include <sstream>    // stringstream
#include <stdexcept>  // out_of_range

namespace classwork::internal {

  inline void check_out_of_range(int index, int min, int max) {
    if (index >= min && index < max) {
      return;
    }

    std::stringstream ss("index is out of range: ");
    ss << '[' << min << ',' << max << ']';
    throw std::out_of_range(ss.str());
  }

}  // namespace classwork::internal