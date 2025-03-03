## 1 题目分析

题目要求使用面向对象程序设计实现一个学生学号与成绩的管理系统。

## 2 实现思路

1. 设计 $\text{CStudent}$ 类，实现学生学号、成绩的存储与提取
   ```cpp
   class CStudent
   {
   private:
      long long m_ID;
      int m_score;

   public:
      CStudent(int id = 0, int score = 100)
         :m_ID(id), m_score(score) { }

      void mb_setId(long long id);
      void mb_setScore(int score);
      long long mb_getId() const;
      int mb_getScore() const;
   };
   ```

2. 设计 $\text{CChainDoubleLink}$ 类，实现双向链表的存储、创建、删除、查找、排序
   ```cpp
   class CChainDoubleLink
   {
   public:
      CStudent m_data;
      CChainDoubleLink *m_previous;
      CChainDoubleLink *m_next;

   public:
      CChainDoubleLink();
      ~CChainDoubleLink();

      CChainDoubleLink* mb_createNode();
      void mb_deleteNode(CChainDoubleLink * p);
      CChainDoubleLink* mb_findNodeById(long long id);
      CChainDoubleLink* mb_findNodeByScore(int score);
      int  mb_getNodeNumber();
      void mb_sortById();
      void mb_sortByScore();
   };
   ```
   * 构造函数 `CChainDoubleLink` 中将两个成员指针变量置空
   * 析构函数 `~CChainDoubleLink` 中实现整条双向链表的删除
   * 成员函数 `mb_createNode` 创建一个新节点
   * 成员函数 `mb_deleteNode` 删除指定节点
   * 成员函数 `mb_findNodeById` 通过ID搜索节点
   * 成员函数 `mb_findNodeByScore` 通过score搜索节点
   * 成员函数 `mb_getNodeNumber` 得到节点总数
   * 成员函数 `mb_sortById` 通过ID升序排序
   * 成员函数 `mb_sortByScore` 通过score升序排序

3. 设计 $\text{CStudentSystem}$ 类，实现学生管理系统的创建、删除、交互即其相应功能
   ```cpp
   class CStudentSystem
   {
   public:
      CChainDoubleLink *m_head;
   public:
      CStudentSystem();
      ~CStudentSystem();

      void mb_printAllStudent();
      void mb_printMainMenu();

      void mb_run();
      void mb_addStudent();
      void mb_deleteStudentById();
      void mb_deleteStudentByScore();
      void mb_showScoreById();
      void mb_showIdByScore();
      void mb_exit();
   };
   ```
   * 构造函数 `CStudentSystem` 将成员指针变量置空
   * 析构函数 `~CStudentSystem` 释放内存并检查内存泄漏问题
   * 成员函数 `mb_printAllStudent` 输出系统中学生信息
   * 成员函数 `mb_printMainMenu` 输出主菜单
   * 成员函数 `mb_run` 实现题目要求的用户交互功能
   * 成员函数 `mb_addStudent` 实现指令1: 添加若干位学生(学号 成绩)，以0结束。其中学号为正整数，成绩非负
   * 成员函数 `mb_deleteStudentById` 实现指令2: 删除第1位指定学号的学生。其中学号为正整数
   * 成员函数 `mb_deleteStudentByScore` 实现指令3: 删除所有指定成绩的学生。其中成绩非负
   * 成员函数 `mb_showScoreById` 实现指令4: 显示第1位指定学号的学生的成绩。其中学号为正整数
   * 成员函数 `mb_showIdByScore` 实现指令5: 显示所有指定成绩的学生的学号。其中成绩非负
   * 成员函数 `mb_exit` 输出退出信息

4. $\text{CDefine.h}$ 中包含无需改动的代码体。结合 $\text{CDefine.cpp pch.h pch.cpp}$ 实现预编译，加快后续编译速度。

5. 头文件中都含有 `#progma once` 指令，保证头文件只被编译一次。

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
