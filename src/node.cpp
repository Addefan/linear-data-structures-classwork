#include "classwork/node.hpp"

namespace classwork {

  Node::Node(int value, Node* next) : value{value}, next{next} {}

  DoubleNode::DoubleNode(int value, Node *prev, Node *next) : value{value}, prev{prev}, next{next} {}
}  // namespace classwork