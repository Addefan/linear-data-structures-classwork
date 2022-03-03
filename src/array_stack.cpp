#include "classwork/array_stack.hpp"

#include <algorithm>  // copy, fill
#include <stdexcept>  // invalid_argument

namespace classwork {

  ArrayStack::ArrayStack(int capacity) {

    // выбрасываем ошибку, если указана неположительная емкость массива
    if (capacity <= 0) {
      throw std::invalid_argument("capacity is not positive");
    }

    // Write your code here ...
  }

  ArrayStack::~ArrayStack() {

    // Write your code here ...
  }

  void ArrayStack::Push(int value) {

    // Write your code here ...
  }

  bool ArrayStack::Pop() {

    // Write your code here ...
    return false;
  }

  void ArrayStack::Clear() {

    // Write your code here ...
  }

  std::optional<int> ArrayStack::Peek() const {

    // Write your code here ...
    return std::nullopt;
  }

  bool ArrayStack::IsEmpty() const {
    return false;
  }

  int ArrayStack::size() const {
    return 0;
  }

  int ArrayStack::capacity() const {
    return 0;
  }

  bool ArrayStack::Resize(int new_capacity) {

    // Write your code here ...
    return false;
  }

}  // namespace classwork
