#pragma once

#include "classwork/private/stack.hpp"    // Stack
#include "classwork/private/private.hpp"  // check_out_of_range

namespace classwork {

  /**
   * Структура данных "стек" на базе "массива переменной длины".
   */
  struct ArrayStack : Stack {
   private:
    // поля структуры
    int size_{0};         // кол-во элементов на стеке
    int capacity_{0};     // кол-во выделенных ячеек памяти
    int* data_{nullptr};  // указатель на выделенный участок памяти

   public:
    // константы структуры
    static constexpr int kInitCapacity = 10;
    static constexpr int kCapacityGrowthCoefficient = 5;

    /**
     * Создание стека определенной емкости ~ O(n).
     *
     * Выделенные ячейки стека инициализируются нулевым значением.
     *
     * @param capacity - начальная емкость стека
     * @throws invalid_argument при указании неположительной емкости массива
     */
    explicit ArrayStack(int capacity = kInitCapacity);

    /**
     * Деструктор ~ O(1).
     *
     * Высвобождает выделенную под стек память и устанавливает поля в нулевые значения.
     */
    ~ArrayStack() override;

    /**
     * Добавление элемента на вершину стека (конец массива) ~ O(1) или O(n).
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
     * Емкость стека снижается до значения kInitCapacity.
     * Все ячейки стека устанавливаются в нулевое значение, размер стека обнуляется.
     */
    void Clear() override;

    /**
     * Получение элемента с вершины стека (конца массива) ~ O(1).
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