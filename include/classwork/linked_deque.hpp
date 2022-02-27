#pragma once

#include "classwork/node.hpp"           // DoubleNode
#include "classwork/private/queue.hpp"  // Queue

namespace classwork {

  /**
   * Структура данных "двухсторонняя очередь".
   * Элементами являются "узлы" со значением.
   *
   * Расширяет возможности очереди операциями добавления в начало и удаления с конца.
   */
  struct LinkedDeque : Queue {
   private:
    int size_{0};  // кол-во элементов
    DoubleNode* front_{nullptr};  // начало
    DoubleNode* back_{nullptr};

   public:
    ~LinkedDeque() override;

    void Enqueue(int value) override;

    void EnqueueFront(int value);

    bool Dequeue() override;

    bool DequeueBack();

    void Clear() override;

    std::optional<int> front() const override;

    std::optional<int> back() const override;

    bool IsEmpty() const override;

    int size() const override;
  };

}  // namespace classwork