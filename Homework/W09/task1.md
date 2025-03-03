## 1 题目分析

题目要求使用面向对象的技术

* 接受来自控制台窗口输入的一系列整数。

* 采用算法(algorithm)库的sort函数对这些整数进行排序(不去重)，并输出排序结果。

* 采用集合(set)对这些整数进行排序(去重)，并输出排序结果。

## 2 实现思路

1. 自定义 `CInt` 类，重载了 加减乘除、大于小于等运算符

2. 定义 `CSort` 类，实现题目所需功能。`CSort` 成员变量包含一个向量与一个集合。成员函数 `mb_getNum` 实现提示用户输入整数，并将用户输入储存到向量与集合中；成员函数 `mb_sort` 调用 `sort` 函数对向量中的整数进行排序，集合中默认为排序好的，并输出向量中不去重的排序结果与集合中去重的排序结果。
   ```cpp
   class CSort
   {
   public:
      vector<CInt> m_vec;
      set<CInt> m_set;

   public:
      CSort();
      void mb_getNum();
      void mb_sort();
   };
   ```

## 3 代码运行方法

 平台：Visual Studio 2022

 x64 release

## 4 测试报告

### 4.1 测试思路

为此程序设计了5组测试数据，分别为

1. 无整数输入
2. 无重复有序输入
3. 无重复无序输入
4. 有重复有序输入
5. 有重复无序输入

### 4.2 测试

1. 无整数输入
   ```
   Enter the number of elements: 0
   Enter the elements:
   Sorted vector:
   Sorted set:
   ```

2. 无重复有序输入
   ```
   Enter the number of elements: 10
   Enter the elements: 1 2 3 4 5 6 7 8 9 10

   Sorted vector: 1 2 3 4 5 6 7 8 9 10
   Sorted set: 1 2 3 4 5 6 7 8 9 10
   ```

3. 无重复无序输入
   ```
   Enter the number of elements: 15
   Enter the elements: 87 674 32 74 13 68 90 43 22 222 423 65 66 99 100

   Sorted vector: 13 22 32 43 65 66 68 74 87 90 99 100 222 423 674
   Sorted set: 13 22 32 43 65 66 68 74 87 90 99 100 222 423 674
   ```

4. 有重复有序输入
   ```
   Enter the number of elements: 10
   Enter the elements: 1 1 2 2 2 4 5 6 6 8

   Sorted vector: 1 1 2 2 2 4 5 6 6 8
   Sorted set: 1 2 4 5 6 8
   ```

5. 有重复无序输入
   ```
   Enter the number of elements: 12
   Enter the elements: 1 700 88 2 34 2 90 88 23 233 88 2

   Sorted vector: 1 2 2 2 23 34 88 88 88 90 233 700
   Sorted set: 1 2 23 34 88 90 233 700
   ```

## 5 提高部分

模仿vector并编写类模板MyVector，实现vector的主要功能

### 5.1 实现思路

使用类模板，实现了 `CMyVector` 的编写。其中成员变量包含数组的头指针，长度及容量。实现了不同的构造函数、对长度与容量的处理、向量元素引用、向量元素插入与删除、向量交换等功能。

```cpp
template <typename T>

class CMyVector
{
private:
    T* m_pVector;
    size_t m_size;
    size_t m_capacity;

public:
    // 构造函数
    CMyVector<T>();
    CMyVector<T>(size_t n, const T& value = T());
    CMyVector<T>(const CMyVector<T>& other);
    ~CMyVector<T>();

    // 基本信息
    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    // 改变向量长度与容量
    void reserve(size_t n);
    void resize(size_t n, const T& value = T());
    void clear();

    // 向量元素引用
    T& operator[](size_t index);
    T& at(size_t index);
    T& front();
    T& back();

    // 向量元素插入与删除
    void push_back(const T& value);
    void pop_back();
    void insert(size_t index, const T& value);
    void erase(size_t index);

    void swap(CMyVector<T>& other);
};
```

### 5.2 提高部分测试

使用 `GetTickCount` 函数，测试部分功能经过较多次操作所需时间。

```
CMyVector push_back time: 109ms
vector push_back time: 938ms

CMyVector pop_back time: 31ms
vector pop_back time: 688ms

CMyVector insert time: 62ms
vector insert time: 16ms

CMyVector erase time: 62ms
vector erase time: 47ms
```

可见，自己编写的 `MyVector` 类，在 `push_back` 与 `pop_back` 函数上效率较高，可能是由于少考虑了一些特殊情况。

而在 `insert` 与 `erase` 函数上效率较低，推测原因为采取数组存储数据，修改下标操作较复杂，改进方法可以采用链表储存。
