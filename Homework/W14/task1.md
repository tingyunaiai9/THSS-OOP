# Week14

## 1 题目分析

题目要求使用工厂方法模式实现一个学生学号与成绩的管理系统。

## 2 实现思路

### 思路概述

在 Week6 作业功能实现的基础上，本次代码的实现思路为：

设计工厂类，使用单体模式，确保只有一个工厂类在运行。

工厂类管理一个双向链表，用于管理产品类中需要及删除的结点。

对链表类新增了移除及插入功能，及不改变该结点储存的学生信息，仅修改前后指针，以达成结点在两个链表之间的转移。

在产品类需要结点时，通过工厂类申请，如果工厂类中已有对应的所需学号及成绩的结点，则将该结点转移到产品类中，否则新申请一个结点，转移到产品类的链表中。

在产品类删除节点时，将该结点转移至工厂类管理的双向链表中。

在程序中添加
```cpp
_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
```
检查是否存在内存泄漏，经调试，无内存泄漏。


### 具体实现思路


1. 设计 $\text{CStudent}$ 类，实现学生学号、成绩的存储与提取

2. 重构了 $\text{CChainDoubleLink}$ 类

   在 Week6 的基础上，将双向链表的实现拆分为 $\text{CChainDoubleLinkNode}$ 与 $\text{CChainDoubleLink}$ 类，进行进一步的抽象。

   $\text{CChainDoubleLinkNode}$ 储存结点的内容及前后结点信息

   $\text{CChainDoubleLink}$ 实现双向链表的管理，包括结点的创建、删除、移除、插入、搜索、排序等功能

3. 设计 $\text{CStudentSystem}$ 类，实现学生管理系统的创建、删除、交互即其相应功能

4. 设计 $\text{CFactoryMethodStudentSystem}$ 类，该类为工厂类，管理一个储存产品类暂时不需要的结点的双向链表。

   该类通过静态成员变量储存了唯一的实例化对象，配合构造函数、析构函数实现了单体模式的实现，确保只有一个工厂类在运作。

   ```cpp
   class CFactoryMethodStudentSystem
   {
   private:
      CChainDoubleLink *m_factoryHead; // 保存不在用的学生学号与成绩表单

   private:
      CFactoryMethodStudentSystem();

   public:
      ~CFactoryMethodStudentSystem();

   public:
      static CFactoryMethodStudentSystem *mbs_getFactoryInstance();

   public:
      CChainDoubleLinkNode* mb_createNode(long long id, int score);
      void mb_deleteNode(CChainDoubleLinkNode * p);
   };
   ```

   在产品类中可以调用该函数获得该单例的指针。
   ```cpp
   CFactoryMethodStudentSystem::mbs_getFactoryInstance()
   ```
   `mb_createNode` 与 `mb_deleteNode` 用于申请与删除产品类中的结点，在create过程中，若对应结点存在，则转移，否则申请新的结点；在delete过程中，将产品中结点回收至工厂类。


5. 在程序中添加以下代码，在程序运行时打开内存泄漏检查。
   ```cpp
   _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
   ```


5. $\text{CDefine.h}$ 中包含无需改动的代码体。结合 $\text{CDefine.cpp pch.h pch.cpp}$ 实现预编译，加快后续编译速度。

6. 头文件中都含有 `#progma once` 指令，保证头文件只被编译一次。

## 3 代码运行方法

 平台：Visual Studio 2022

 x64 release

## 4 测试报告

### 4.1 学号、成绩输入

#### 4.1.1 执行指令1: 添加若干位学生(学号 成绩)，以0结束。其中要求学号为正整数，成绩非负

##### 4.1.1.1 正常情况

##### 4.1.1.2 学号有误

* 在学号有误时，将改行整行读取。避免学号、成绩一起输入时读取下一学号有误。

##### 4.1.1.3 成绩有误

#### 4.1.2 执行指令2: 删除第1位指定学号的学生。其中要求学号为正整数

##### 4.1.2.1 正常情况

##### 4.1.2.2 学号有误

#### 4.1.3 执行指令3: 删除所有指定成绩的学生。其中要求成绩非负

##### 4.1.3.1 正常情况

##### 4.1.3.2 成绩有误

#### 4.1.4 执行指令4: 显示第1位指定学号的学生的成绩。其中要求学号为正整数

##### 4.1.4.1 正常情况

##### 4.1.4.2 学号有误

#### 4.1.5 执行指令5: 显示所有指定成绩的学生的学号。其中成绩非负

##### 4.1.5.1 正常情况

##### 4.1.5.2 成绩有误

### 4.2 多人情况

#### 4.2.1 执行指令2: 删除第1位指定学号的学生

#### 4.2.2 执行指令3: 删除所有指定成绩的学生

#### 4.2.3 执行指令4: 显示第1位指定学号的学生的成绩

#### 4.2.4 执行指令5: 显示所有指定成绩的学生的学号

### 4.3 单人情况

### 4.4 无人情况

#### 4.4.1 没有添加学生

#### 4.4.2 添加学生后删除

### 4.5 无对应学生情况

### 4.6 排序测试
