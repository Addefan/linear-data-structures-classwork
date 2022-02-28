#pragma once

#include <optional>

namespace classwork {

  /**
   * Интерфейс "очередь".
   * "Первый вошел, первый вышел" - FIFO.
   */
  struct Queue {
    /**
     * Деструктор.
     *
     * Высвобождает выделенную память в зависимости от способа реализации.
     */
    virtual ~Queue() = default;

    /**
     * Добавление элемента в конец очереди.
     *
     * @param value - значение добавляемого элемента
     */
    virtual void Enqueue(int value) = 0;

    /**
     * Удаление элемента из начала очереди.
     *
     * @return true - операция успешна, false - операция невозможна (очередь пустая)
     */
    virtual bool Dequeue() = 0;

    /**
     * Очистка очереди.
     *
     * Поведение зависит от способа реализации.
     */
    virtual void Clear() = 0;

    /**
     * Получение элемента в начале очереди.
     *
     * @return значение элемента или ничего в случае пустой очереди
     */
    virtual std::optional<int> front() const = 0;

    /**
     * Получение элемента в конце очереди.
     *
     * @return значение элемента или ничего в случае пустой очереди
     */
    virtual std::optional<int> back() const = 0;

    /**
     * Проверка пустоты очереди.
     *
     * @return true - если очередь пуста, false - в очереди есть элементы
     */
    virtual bool IsEmpty() const = 0;

    /**
     * Возвращает размер очереди.
     *
     * @return кол-во элементов в очереди
     */
    virtual int size() const = 0;
  };

}  // namespace classwork