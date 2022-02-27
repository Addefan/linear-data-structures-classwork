#pragma once

#include "classwork/node.hpp"             // None
#include "classwork/private/stack.hpp"    // Stack
#include "classwork/private/private.hpp"  // check_out_of_range

namespace classwork {

  /**
   * Структура данных "стек" на базе "связного списка".
   * Элементом стека является "узел" со значением.
   */
  struct LinkedStack : Stack {
   private:
    int size_{0};         // кол-во узлов в стеке
    Node* top_{nullptr};  // указатель на вершину стека

   public:
    /**
     * Деструктор ~ O(n).
     *
     * Высвобождает выделенную под стек память и устанавливает поля в нулевые значения.
     */
    ~LinkedStack() override;

    /**
     * Добавление элемента на вершину стека ~ O(1).
     *
     * @param value - значение добавляемого элемента.
     */
    void Push(int value) override;

    /**
     * Удаление элемента с вершины стека (конца массива) ~ O(1).
     *
     * @throws runtime_error при вызове метода над пустым стеком
     */
    void Pop() override;

    /**
     * Очистка стека ~ O(n).
     *
     * Высвобождает выделенную под стек память и устанавливает поля в нулевые значения.
     */
    void Clear() override;

    /**
     * Получение элемента с вершины стека ~ O(1).
     *
     * @return значение элемента или ничего в случае пустого стека
     */
    std::optional<int> Peek() const override;

    /**
     * Проверка пустоты стека.
     *
     * @return true - если стек пуст, false - в стеке есть элементы
     */
    bool IsEmpty() const override;

    /**
     * Возвращает размер стека.
     *
     * @return кол-во элементов в стеке
     */
    int size() const override;
  };

}  // namespace classwork