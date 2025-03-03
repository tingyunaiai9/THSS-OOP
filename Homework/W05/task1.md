## 1 题目分析

题目要求编写复数类，实现加减乘除、++--等运算符重载。

## 2 实现思路

1. 设计 $\text{CComplex}$ 类
   ```cpp
   class CComplex
   {
   private:
      double m_real;
      double m_imaginary;

   public:
      CComplex(double real = 0, double imaginary = 0);

   private:
      double mb_getReal() const;
      double mb_getImaginary() const;

   public:
      void mb_show(string str = "") const;

   // + - * / == != << >> overload to be friend
   public:
      friend CComplex operator + (const CComplex& c1, const CComplex& c2);
      ……
      friend bool operator == (const CComplex& c1, const CComplex& c2);
      ……
      friend istream& operator >> (istream& is, CComplex& c);

   // ++ -- += -= *= /= overload to be member function
   public:
      CComplex operator ++ ();
      CComplex operator ++ (int);
      ……
      CComplex operator += (const CComplex& c);
      ……
   };
   ```

   实现了 +, -, *, /, ==, !=, >>, <<, ++, --, +=, -=, *=, /= 的函数重载。

2. 其中以友元全局函数的形式，设计了 +, -, *, /, ==, !=, >>, << 的函数重载。
   ```cpp
   CComplex operator + (const CComplex& c1, const CComplex& c2)
   {
      CComplex c3;
      c3.m_real = c1.m_real + c2.m_real;
      c3.m_imaginary = c1.m_imaginary + c2.m_imaginary;
      return c3;
   }
   ```

   以成员函数的形式，设计了 ++, --, +=, -=, *=, /= 的函数重载。
   ```cpp
   CComplex CComplex::operator ++ ()
   {
      ++m_real;
      return (*this);
   }
   ```

3. 考虑到题目要求的“加减乘除”为具有对称性的二元运算，即参与运算的两个元地位等价，故设置为友元全局函数。而 ++, += 等运算，一元运算依赖于该元，而二元运算不具有对称性，故设计为成员函数形式重载。

   其中选择将对称二元运算重载为友元全局函数，可保证类似 $(CComplex)c + (float)f$ 和 $(float)f + (CComplex)c$ 的运算得到正确的结果，具体情形请见测试报告。

4. 输入流与输出流的重载中进行了较为完备的划分，对虚部与实部是否为0、虚部是否为-1或1等特殊情况进行特判，实现了符合平日数学形式的复数表达的输入与输出。

5. $\text{CDefine.h}$ 中包含无需改动的代码体。结合 $\text{CDefine.cpp pch.h pch.cpp}$ 实现预编译，加快后续编译速度。

6. 头文件中都含有 `#progma once` 指令，保证头文件只被编译一次。

7. 输入输出使用英文，避免中文编码潜在的问题。

## 3 算法模型

由复数运算法则，设两复数 $c_1 = a_1+b_1i$ , $c_2 = a_2+b_2i$，则

$$c_1+c_2 = (a_1+a_2) + (b_1+b_2)i$$
$$c_1-c_2 = (a_1-a_2) + (b_1-b_2)i$$
$$c_1 \times c_2 = (a_1 \times a_2 - b_1 \times b_2) + (a_1 \times b_2 + a_2 \times b_1)i$$
$$c_1 \div c_2 = \frac{a_1 \times a_2 + b_1 \times b_2}{a_2^2+b_2^2} + \frac{a_2 \times b_1 - a_1 \times b_2}{a_2^2+b_2^2}i$$

而 ++、--运算分别对实部进行 +1 和 -1

## 4 代码运行方法

 平台：Visual Studio 2022

 x64 release

## 5 测试报告

### 5.1 + - * / 的重载

调用函数`mb_CComplexTest1`,`mb_CComplexTest1Plus`进行测试

#### 5.1.1 两个复数均为纯实数(除数非零)
```
Please input two complex numbers to test + - * / :
123.456 654.321
c1 = 123.456
c2 = 654.321

c1 + c2 = 777.777
c1 - c2 = -530.865
c1 * c2 = 80779.9
c1 / c2 = 0.188678
```
```
Please input two complex numbers to test + - * / :
1 0
c1 = 1
c2 = 0

c1 + c2 = 1
c1 - c2 = 1
c1 * c2 = 0
Error: DIVISOR CANNOT BE ZERO!
c1 / c2 = 0
```
* 在除法运算中对除数为0的情况进行判断，并返回0

#### 5.1.2 两个复数均为纯虚数
```
Please input two complex numbers to test + - * / :
22.2i i
c1 = 22.2i
c2 = i

c1 + c2 = 23.2i
c1 - c2 = 21.2i
c1 * c2 = -22.2
c1 / c2 = 22.2
```

#### 5.1.3 两个复数一个为纯实数，一个为纯虚数
```
Please input two complex numbers to test + - * / :
222.222 111.111i
c1 = 222.222
c2 = 111.111i

c1 + c2 = 222.222+111.111i
c1 - c2 = 222.222-111.111i
c1 * c2 = 24691.3i
c1 / c2 = -2i
```

#### 5.1.4两个复数一个为纯实数，一个为 $a+bi$ 形式，$ab \neq 0$

##### 5.1.4.1 对称友元全局函数，两个运算元均为CComplex类型
```
Please input two complex numbers to test + - * / :
i 12
c1 = i
c2 = 12

c1 + c2 = 12+i
c1 - c2 = -12+i
c1 * c2 = 12i
c1 / c2 = 0.0833333i
```

##### 5.1.4.2 一个运算元为CComplex类型，一个运算元为float类型
```
Please input a complex number to test + - * / :
2i 0.5
Please input a float number to test + - * / :
c1 = 2i
f1 = 0.5

c1 + 0.5 = 0.5+2i
0.5 + c1 = 0.5+2i
c1 - 0.5 = -0.5+2i
0.5 - c1 = 0.5-2i
c1 * 0.5 = i
0.5 * c1 = i
c1 / 0.5 = 4i
0.5 / c1 = -0.25i
```
使用友元全局函数，使得 $c1 + 0.5$ 与 $0.5 + c1$ 运算能够将 float型的0.5自动转化为CComplex类型。而如果使用成员函数，在 $0.5 + c1$ 的运算上会报错。

#### 5.1.5两个复数一个为纯虚数，一个为 $a+bi$ 形式，$ab \neq 0$
```
Please input two complex numbers to test + - * / :
0.5i 2+3i
c1 = 0.5i
c2 = 2+3i

c1 + c2 = 2+3.5i
c1 - c2 = -2-2.5i
c1 * c2 = -1.5+i
c1 / c2 = 0.115385+0.0769231i
```

#### 5.1.6 两个复数均为 $a+bi$ 形式，$ab \neq 0$
```
Please input two complex numbers to test + - * / :
100+12.5i 100-12.5i
c1 = 100+12.5i
c2 = 100-12.5i

c1 + c2 = 200
c1 - c2 = 25i
c1 * c2 = 10156.2
c1 / c2 = 0.969231+0.246154i
```

### 5.2 == != 的重载

调用函数`mb_CComplexTest2`进行测试

#### 5.2.1 相等情况
```
Please input two complex numbers to test == != :
i i
c1 = i
c2 = i

test ==: c1 == c2
test !=: c1 == c2
```
```
Please input two complex numbers to test == != :
12.34 12.34
c1 = 12.34
c2 = 12.34

test ==: c1 == c2
test !=: c1 == c2
```
```
Please input two complex numbers to test == != :
123+456i 123+456i
c1 = 123+456i
c2 = 123+456i

test ==: c1 == c2
test !=: c1 == c2
```

#### 5.2.2 不等情况
```
Please input two complex numbers to test == != :
0 -i
c1 = 0
c2 = -i

test ==: c1 != c2
test !=: c1 != c2
```
```
Please input two complex numbers to test == != :
12.12-i 34.5-i
c1 = 12.12-i
c2 = 34.5-i

test ==: c1 != c2
test !=: c1 != c2
```

### 5.3 ++ -- 的重载

调用函数`mb_CComplexTest3`进行测试

#### 5.3.1 纯虚数
```
Please input a complex number to test ++ -- :
1.1i
c1 = 1.1i

c1 = 1.1i  c1++ = 1.1i  c1 = 1+1.1i
c1 = 1.1i  ++c1 = 1+1.1i  c1 = 1+1.1i
c1 = 1.1i  c1-- = 1.1i  c1 = -1+1.1i
c1 = 1.1i  --c1 = -1+1.1i  c1 = -1+1.1i
```

#### 5.3.2 纯实数
```
Please input a complex number to test ++ -- :
2.2
c1 = 2.2

c1 = 2.2  c1++ = 2.2  c1 = 3.2
c1 = 2.2  ++c1 = 3.2  c1 = 3.2
c1 = 2.2  c1-- = 2.2  c1 = 1.2
c1 = 2.2  --c1 = 1.2  c1 = 1.2
```

#### 5.3.3 $a+bi$ 形式，$ab \neq 0$
```
Please input a complex number to test ++ -- :
900000+800000i
c1 = 900000+800000i

c1 = 900000+800000i  c1++ = 900000+800000i  c1 = 900001+800000i
c1 = 900000+800000i  ++c1 = 900001+800000i  c1 = 900001+800000i
c1 = 900000+800000i  c1-- = 900000+800000i  c1 = 899999+800000i
c1 = 900000+800000i  --c1 = 899999+800000i  c1 = 899999+800000i
```

### 5.4 += -= *= /= 的重载

调用函数`mb_CComplexTest4`,`mb_CComplexTest4Plus`进行测试

#### 5.4.1 参数为 CComplex 类型
```
Please input two complex numbers to test += -= *= /= :
1+i 2+i
c1 = 1+i
c2 = 2+i

c1 += c2 = 3+2i
c1 -= c2 = -1
c1 *= c2 = 1+3i
c1 /= c2 = 0.6+0.2i
```
类似于 4.1

#### 5.4.2 参数为 float 类型
```
Please input a complex number to test += -= *= /= :
1.9+2.2i
Please input a float number to test += -= *= /= :
1.5
c1 = 1.9+2.2i
f1 = 1.5

c1 += 1.5 = 3.4+2.2i
c1 -= 1.5 = 0.4+2.2i
c1 *= 1.5 = 2.85+3.3i
c1 /= 1.5 = 1.26667+1.46667i
```
