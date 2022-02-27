#pragma once

namespace classwork {

  /**
   * Структура данных "массив переменной длины".
   *
   * Характеризуется своей емкостью (capacity) и фактическим кол-ом элементов (size).
   * Все элементы находятся последовательно в памяти, что гарантируется доступ к ним за O(1).
   */
  struct DynamicArray {
   private:
    // поля структуры
    int size_{0};      // размер (кол-во элементов в массиве)
    int capacity_{0};  // емкость (кол-во ячеек под элементы в массиве)
    int* data_{nullptr};  // указатель на начало непрерывного блока памяти под массив

   public:
    // константы структуры
    static constexpr int kInitCapacity = 10;  // начальная емкость массива
    static constexpr int kNotFoundIndex = -1;  // индекс ненайденного элемента в массиве
    static constexpr int kCapacityGrowthCoefficient = 5;  // коэффициент увеличения размера массива

    /**
     * Создание массива определенной емкости.
     *
     * Выделенные ячейки массива инициализируются нулевым значением.
     *
     * @param capacity - начальная емкость массива
     * @throws invalid_argument при указании неположительной емкости массива
     */
    explicit DynamicArray(int capacity = kInitCapacity);

    /**
     * Деструктор ~ O(1).
     *
     * Высвобождает выделенную под массив память и устанавливает поля в нулевые значения.
     */
    ~DynamicArray();

    /**
     * Добавление элемента в конец массива ~ O(1) или O(n).
     *
     * При недостаточной емкости массив расширяется с сохранением элементов.
     *
     * @param value - значение добавляемого элемента
     */
    void Add(int value);

    /**
     * Вставка элемента в массив по индексу ~ O(n).
     *
     * Все элементы, находящиеся на позиции вставки и справа от нее, сдвигаются на единицу вправо.
     * При недостаточной емкости массив расширяется с сохранением элементов.
     *
     * @param index - позиция вставки нового элемента в массив
     * @param value - значение вставляемого элемента
     * @throws out_of_range при передаче индекса за пределами массива
     */
    void Insert(int index, int value);

    /**
     * Увеличение емкости массива ~ O(n).
     *
     * @param new_capacity - новая емкость массива
     * @throws invalid_argument при указании новой емкости массива меньше и равному предыдущей
     */
    void Resize(int new_capacity);

    /**
     * Изменение значения элемента массива по индексу ~ O(1).
     *
     * @param index - индекс изменяемого элемента массива
     * @param value - новое значение элемента массива
     * @throws out_of_range при передаче индекса за пределами массива
     */
    void Set(int index, int value);

    /**
     * Удаление элемента массива по индексу ~ O(n).
     *
     * Все элементы, стоящие справа от удаленного элемента, сдвигаются влево на единицу.
     * Освободившаяся ячейка массива устанавливается в нулевое значение.
     *
     * @param index - индекс удаляемого элемента массива
     * @return значение удаленного элемента массива
     * @throws out_of_range при передаче индекса за пределами массива
     */
    int Remove(int index);

    /**
     * Очистка массива ~ O(n).
     *
     * Все ячейки массива устанавливаются в нулевое значение.
     * Емкость массива остается прежней, размер массива обнуляется.
     */
    void Clear();

    /**
     * Получение элемента массива по индексу ~ O(1).
     *
     * @param index - индекс элемента массива
     * @return значение элемента массива
     * @throws out_of_range при передаче индекса за пределами массива
     */
    int Get(int index) const;

    /**
     * Поиск индекса первого вхождения элемента с указанным значением ~ O(n).
     *
     * @param value - значение элемента массива
     * @return индекс найденного элемента или kNotFoundIndex - при его отсутствии
     */
    int IndexOf(int value) const;

    /**
     * Проверка наличия элемента в массиве по значению ~ O(n).
     *
     * @param value - значение элемента массива
     * @return true - при наличии элемента в массиве, false - при его отсутствии
     */
    bool Contains(int value) const;

    /**
     * Проверка пустоты массива ~ O(1).
     * Массив считается пустым, если в нем нет фактических элементов.
     *
     * @return true - если массив пустой, false - в массиве есть элементы
     */
    bool IsEmpty() const;

    /**
     * Возвращает фактический размер массива ~ O(1).
     *
     * @return количество элементов в массиве
     */
    int size() const;

    /**
     * Возвращает емкость массива ~ O(1).
     *
     * @return количество выделенных ячеек в массиве
     */
    int capacity() const;
  };

  // внутренние проверки
  static_assert(DynamicArray::kInitCapacity > 0, "DynamicArray initial capacity must have a positive value");
  static_assert(DynamicArray::kCapacityGrowthCoefficient > 1, "DynamicArray growth rate must be greater than one");

}  // namespace classwork