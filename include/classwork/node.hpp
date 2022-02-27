#pragma once

namespace classwork {

  /**
   * Структура "узел".
   * Оболочка над значением и указателем на следующий узел.
   */
  struct Node {
    // поля структуры
    int value{0};         // значение узла
    Node* next{nullptr};  // указатель на следующий узел

    /**
     * Создание узла со значением и указателем на следующий узел.
     *
     * @param value - значение узла
     * @param next - указатель на следующий узел
     */
    explicit Node(int value, Node* next = nullptr);
  };

}  // namespace classwork