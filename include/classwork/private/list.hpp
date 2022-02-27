#pragma once

namespace classwork {

  /**
   * Интерфейс "абстрактный список".
   */
  struct List {

    virtual ~List() = default;

    virtual void Add(int value) = 0;

    virtual void Insert(int index, int value) = 0;

    virtual void Set(int index, int new_value) = 0;

    virtual int Remove(int index) = 0;

    virtual void Clear() = 0;

    virtual int Get(int index) const = 0;

    virtual int IndexOf(int value) const = 0;

    virtual bool Contains(int value) const = 0;

    virtual bool IsEmpty() const = 0;

    virtual int size() const = 0;
  };

}  // namespace classwork