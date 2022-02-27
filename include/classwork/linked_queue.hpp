#pragma once

#include "classwork/node.hpp"           // Node
#include "classwork/private/queue.hpp"  // Queue

namespace classwork {

  /**
   * Структура данных "очередь" на базе "связного списка".
   * Элементом очереди является "узел" со значением.
   */
  struct LinkedQueue : Queue {
   private:
    int size_{0};           // кол-во узлов в очереди
    Node* front_{nullptr};  // указатель на начало очереди
    Node* back_{nullptr};   // указатель на конец очереди

   public:
    /**
     * Деструктор ~ O(n).
     *
     * Высвобождает выделенную под очередь память и устанавливает поля в нулевые значения.
     */
    ~LinkedQueue() override;

    /**
     * Добавление элемента в конец очереди ~ O(1).
     *
     * @param value - значение добавляемого элемента
     */
    void Enqueue(int value) override;

    /**
     * Удаление элемента с начала очереди ~ O(1).
     *
     * @return true - операция успешна, false - операция невозможна (очередь пуста)
     */
    bool Dequeue() override;

    /**
     * Очистка очереди ~ O(n).
     *
     * Высвобождает выделенную под очередь память и устанавливает поля в нулевые значения.
     */
    void Clear() override;

    /**
     * Получение элемента с начала очереди ~ O(1).
     *
     * @return значение элемента или ничего в случае пустой очереди
     */
    std::optional<int> front() const override;

    /**
     * Получение элемента с конца очереди ~ O(1).
     *
     * @return значение элемента или ничего в случае пустой очереди
     */
    std::optional<int> back() const override;

    /**
     * Проверка пустоты очереди.
     *
     * @return true - если очередь пуста, false - в очереди есть элементы
     */
    bool IsEmpty() const override;

    /**
     * Возвращает размер очереди.
     *
     * @return кол-во элементов в очереди
     */
    int size() const override;
  };

}  // namespace classwork