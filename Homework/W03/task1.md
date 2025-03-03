## 1 题目分析

程序循环接受命令

各命令对应一种图形或总结退出功能


## 2 实现思路

1. 在 CP_Shape.h 中，定义了基类 CP_Shape，题目所需具体图形由该基类派生，符合**是关系原则**。
   ```
   class CP_Shape
   {
   public:
      CP_Shape();

   public:
      virtual void mb_hintInfo() {};
      virtual void mb_resultInfo() {};

   protected:
      virtual void mb_calculate(double side) {};

   public:
      static int s_shape_count;
      static double s_total_perimeter;
      static double s_total_area;

   protected:
      double m_side;
      double m_perimeter;
      double m_area;
   };
   ```

   在基类 CP_Shape 中，将 mb_hintInfo()、mb_resultInfo()、mb_calculate(double side) 三个函数设置为虚函数，以实现多态性。

   此外，这三个函数功能分别为提示用户输入图形参数、输出结果、计算图形周长与面积。三个成员变量 m_side、m_perimeter、m_area 分别为图形边长、周长、面积。这三个函数与三个成员变量子类具体图形中都需要使用，符合**扩展性原则**。

2. 子类继承基类 CP_Shape。以正三角形为例

   类定义
   ```
   class CP_RegularTriangle :public CP_Shape
   {
   public:
      virtual void mb_hintInfo();
      virtual void mb_resultInfo();

   protected:
      virtual void mb_calculate(double side);
   };
   ```

   具体函数实现
   ```
   void CP_RegularTriangle::mb_hintInfo()
   {
      double side = 0;
      cout << "请输入正三角形的边长：";
      cin >> side;

      mb_calculate(side);
   }

   void CP_RegularTriangle::mb_resultInfo()
   {
      cout << "该正三角形的周长：" << m_perimeter << endl;
      cout << "该正三角形的面积：" << m_area << endl;
      cout << endl;
   }

   void CP_RegularTriangle::mb_calculate(double side)
   {
      m_side = side;
      m_perimeter = 3 * side;
      m_area = (pow(3, 0.5) / 4) * pow(side, 2);

      s_total_perimeter += m_perimeter;
      s_total_area += m_area;
   }
   ```

   通过虚函数的设置，实现多态性。

3. 图形总个数、总周长、总面积的实现

   在 CP_Shape.h 中，CP_Shape 类中，声明用于统计的三个静态变量。这三个静态变量属于类CP_Shape。
   ```
   public:
	static int s_shape_count;
	static double s_total_perimeter;
	static double s_total_area;
   ```

   在 CP_Shape.cpp 中，定义并初始化三个静态变量。
   ```
   int CP_Shape::s_shape_count = 0;
   double CP_Shape::s_total_perimeter = 0;
   double CP_Shape::s_total_area = 0;
   ```

   为实现图形总个数的统计，在 CP_Shape 的构造函数中添加语句
   ```
   CP_Shape::CP_Shape()
   {
      s_shape_count++;
   }
   ```
   这样，每次在实例化子类对象的过程中，实例化基类对象时调用 CP_Shape 的构造函数，使计数+1。

   图形总周长与图形总面积的统计，在函数 mb_calculate 函数中实现。
   ```
   s_total_perimeter += m_perimeter;
   s_total_area += m_area;
   ```
   在计算获得相应图形的周长与面积之后，加到总周长与总面积中。

4. CP_ShapeMain.cpp 中完成指令的读取与对应对象的调用。while循环中嵌套switch，用变量 is_continue 控制while循环。用基类型的指针 p_shape 指向不同的子类，体现面向对象编程的优势。
   ```
   int main(int argc, char* argv[])
   {
      bool is_continue = 1;
      int cmd = 0;

      CP_Shape* p_shape = NULL;


      while (is_continue)
      {
         cout << "请输入指令：";
         cin >> cmd;

         switch (cmd)
         {
         case 0:
            is_continue = 0;
            cout << "图形总个数：" << CP_Shape::s_shape_count << endl;
            cout << "图形总周长：" << CP_Shape::s_total_perimeter << endl;
            cout << "图形总面积：" << CP_Shape::s_total_area << endl;
            break;

         case 1:
            p_shape = new CP_RegularTriangle;
            break;

         ……

         default:
            cout << "输入有误，请重新输入" << endl << endl;
            break;
         }

         if (p_shape != NULL)
         {
            p_shape->mb_hintInfo();
            p_shape->mb_resultInfo();
            delete p_shape;
            p_shape = NULL;
         }
      }

      _CrtDumpMemoryLeaks();
      return 0;
   }
   ```

5. CP_Define.h 中包含无需改动的代码体。结合 CP_Define.cpp pch.h pch.cpp 实现预编译，加快后续编译速度。

6. 头文件中都含有 #progma once 指令，保证头文件只被编译一次。

7. CP_Define.h 中包含命令 #pragma execution_character_set("utf-8")，控制中文编码

## 3 算法模型

注：设各正多边形的边长为 a

### 正三角形

周长 $C = 3 \times a$

面积 $S = \frac{\sqrt 3}{4} \times a^2$

### 正方形

周长 $C = 4 \times a$

面积 $S = a^2$

### 正五边形

周长 $C = 5 \times a$

面积 $S = 5 \times \frac{a^2}{4 \tan{36^\circ}}$

### 正六角形

周长 $C = 6 \times a$

面积 $S = 6 \times \frac{\sqrt 3}{4} \times a^2$

### 圆

设圆半径为r

周长 $C = 2 \pi r$

面积 $S = \pi r^2$

## 4 代码运行方法

 平台：Visual Studio 2022

 x64 release

 编码：utf-8

## 5 测试报告
```
请输入指令：1
请输入正三角形的边长：1
该正三角形的周长：3
该正三角形的面积：0.433013

请输入指令：2
请输入正方形的边长：2
该正方形的周长：8
该正方形的面积：4

请输入指令：3
请输入正五边形的边长：2.2
该正五边形的周长：11
该正五边形的面积：8.32711

请输入指令：4
请输入正六边形的边长：1
该正六边形的周长：6
该正六边形的面积：2.59808

请输入指令：5
请输入圆的半径：1
该圆的周长：6.28319
该圆的面积：3.14159

请输入指令：666
输入有误，请重新输入

请输入指令：0
图形总个数：5
图形总周长：34.2832
图形总面积：18.4998
```

* 输入不是指定指令范围内的数字时，会提示输入有误。具有一定的鲁棒性。

## 6 提高部分

分析采用C语言与C++编写上述程序，在程序扩展性方面的区别。

c++中由于多态性，在实现一个基类后可以扩展出大量不同子类，且重复互通的功能不用增加代码，在工程量上较小。

此外，在此次作业中运用由基类指针类型定义的指针指向子类，使得指令转换部分较为通用方便，如需增加指令，也可以轻易扩展。
