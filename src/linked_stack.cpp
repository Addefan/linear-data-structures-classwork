#include "classwork/linked_stack.hpp"

#include <stdexcept>  // runtime_error

namespace classwork {

  LinkedStack::~LinkedStack() {
    Clear();
  }

  void LinkedStack::Push(int value) {
    // Write your code here ...
  }

  void LinkedStack::Pop() {
    // Write your code here ...
  }

  void LinkedStack::Clear() {
    // Write your code here ...
  }

  std::optional<int> LinkedStack::Peek() const {
    // Write your code here ...
    return std::nullopt;
  }

  bool LinkedStack::IsEmpty() const {
    // Write your code here ...
    return false;
  }

  int LinkedStack::size() const {
    // Write your code here ...
    return 0;
  }

}  // namespace classwork