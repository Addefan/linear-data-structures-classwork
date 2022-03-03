#include "classwork/dynamic_array.hpp"

#include <algorithm>  // copy, fill
#include <stdexcept>  // invalid_argument

namespace classwork {

  DynamicArray::DynamicArray(int capacity) {

    // выбрасываем ошибку, если указана неположительная емкость массива
    if (capacity <= 0) {
      throw std::invalid_argument("capacity is not positive");
    }

    // Write your code here ...
  }

  DynamicArray::~DynamicArray() {

    // Write your code here ...
  }

  void DynamicArray::Add(int value) {

    // Write your code here ...
  }

  bool DynamicArray::Insert(int index, int value) {

    // Write your code here ...
    return false;
  }

  bool DynamicArray::Set(int index, int new_value) {

    // Write your code here ...
    return false;
  }

  std::optional<int> DynamicArray::Remove(int index) {

    // Write your code here ...
    return std::nullopt;
  }

  void DynamicArray::Clear() {

    // Write your code here ...
  }

  std::optional<int> DynamicArray::Get(int index) const {

    // Write your code here ...
    return std::nullopt;
  }

  std::optional<int> DynamicArray::IndexOf(int value) const {

    // Write your code here ...
    return std::nullopt;
  }

  bool DynamicArray::Contains(int value) const {
    return false;
  }

  bool DynamicArray::IsEmpty() const {
    return false;
  }

  int DynamicArray::size() const {
    return 0;
  }

  int DynamicArray::capacity() const {
    return 0;
  }

  bool DynamicArray::Resize(int new_capacity) {

    // Write your code here ...
    return false;
  }

}  // namespace classwork