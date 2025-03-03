## 1 题目分析

题目要求设计日历类，它的数据包括年、月、日。日历要求符合公元历法。通过日历类的实例对象可以设置/获取/输出其所记录的年月日，并且可以计算给定$n$天之后的年月日。

## 2 实现思路

1. 设计 $\text{CCalendar}$ 类
   ```cpp
   class CCalendar
   {
   private:
      int m_year;
      int m_month;
      int m_day;

   public:
      CCalendar();
      void mb_addDate(long long n);
      void mb_showDate();

      int mb_getYear(int year);
      int mb_getMonth(int month);
      int mb_getDay(int day);

   private:
      void mb_setYear(int year);
      void mb_setMonth(int month);
      void mb_setDay(int day);

      bool mb_isLeapYear(int year);
      int mb_getDayOfMonth(int year, int month);
   };
   ```

   其中将成员变量 `m_year`,`m_month`,`m_day`访问方式设为**private**，通过成员函数 `mb_setYear`,`mb_getYear`等函数**设置**、**获取**年、月、日。成员函数`mb_showDate`**输出**年、月、日。

2. 成员函数`mb_addDate`以及`mb_isLeapYear`,`mb_getDayOfMonth`实现计算给定$n$天之后的年月日。

3. 设计 $\text{CCalendarApplication}$ 类，成员函数 `mb_run` 实现题目要求的用户交互功能。

4. $\text{CDefine.h}$ 中包含无需改动的代码体。结合 $\text{CDefine.cpp pch.h pch.cpp}$ 实现预编译，加快后续编译速度。

5. 头文件中都含有 `#progma once` 指令，保证头文件只被编译一次。

6. 输入输出使用英文，避免中文编码潜在的问题。

## 3 算法模型

我们现行的公历为格里高利历（Gregorian calendar），按照以下规则计算：

1. 公元 1582 年 10 月 15 日（含）以后：适用格里高利历。当年份是 400 的倍数，或日期年份是 4 的倍数但不是 100 的倍数时，该年为闰年。

2. 公元 1582 年 10 月 5 日（含）至 10 月 14 日（含）：不存在，该年 10 月 4 日之后为 10 月 15 日。

3. 公元 1582 年 10 月 4 日（含）以前：适用儒略历，每月天数与格里高利历相同，但只要年份是 4 的倍数就是闰年。

4. 公元零年并不存在，即公元前 1 年的下一年是公元 1 年。

考虑到代码的适用性与可复用性，算法将计算起点平移至公元前 4713 年 1 月 1 日。
```cpp
n += 2460370; // 29 2 2024 -> 1 1 4713 BC
for (int i = 3; i < m_month; i++)
   n += mb_getDayOfMonth(2024, i);
n += m_day;
```

设计函数`mb_isLeapYear`用于判断闰年，`mb_getDayOfMonth`返回某年某月的天数。

计算年份时，按 1582.10.4 及以前、1582.10.15 及以后进行分类：

1. 1582.10.4 及以前：每4年都有闰年

2. 1582.10.15 及以后：需减去消失的10天；特判年份为 100 时的情况

将以400、4为单位的年份周期确定后，采用遍历确定准确年份。

设年份数值为$x$，$x\leq0$时，表示**公元前**$x$年，实现提高要求。

计算月份时，采用遍历方式
```cpp
for (int i = 1; n >= mb_getDayOfMonth(year, i); i++)
{
   month++;
   n -= mb_getDayOfMonth(year, i);
}
```

计算日期：此时剩余的$n$的值加上临时变量$day$


## 4 代码运行方法

 平台：Visual Studio 2022

 x64 release

## 5 测试报告

注：测试时间为2024年3月22日

1. 小范围向后日期
   ```
   Today: 22 3 2024
   Please input n for the date n days later: 1
   1 days later: 23 3 2024
   ```
   ```
   Today: 22 3 2024
   Please input n for the date n days later: 100
   100 days later: 30 6 2024
   ```
   ```
   Today: 22 3 2024
   Please input n for the date n days later: 10
   10 days later: 1 4 2024
   ```
   ```
   Today: 22 3 2024
   Please input n for the date n days later: 365
   365 days later: 22 3 2025
   ```

2. 0
   ```
   Today: 22 3 2024
   Please input n for the date n days later: 0
   0 days later: 22 3 2024
   ```

3. 闰年
   ```
   Today: 22 3 2024
   Please input n for the date n days later: 365+365+365+366
   365 days later: 22 3 2025
   ```

4. 小范围向前日期
   ```
   Today: 22 3 2024
   Please input n for the date n days later: -22
   -22 days later: 29 2 2024
   ```
   ```
   Today: 22 3 2024
   Please input n for the date n days later: -366
   -366 days later: 22 3 2023
   ```

5. 大范围向后日期
   ```
   Today: 22 3 2024
   Please input n for the date n days later: 72269
   72269 days later: 2 2 2222
   ```
   ![22220202](22220202.jpg)

6. 大范围向前日期
   ```
   Today: 22 3 2024
   Please input n for the date n days later: -161232
   -161232 days later: 4 10 1582
   ```
   ![15821004](15821004.jpg)
   ```
   Today: 22 3 2024
   Please input n for the date n days later: -161231
   -161231 days later: 15 10 1582
   ```
   ![15821015](15821015.jpg)
   ```
   Today: 22 3 2024
   Please input n for the date n days later: -2460392
   -2460392 days later: 1 1 4713 BC
   ```
   * 此次测试为计算原点：公元前 4713 年 1 月 1 日

## 6 提高部分

通过使用儒略日，能够准确计算公元前日期。

## 7 参考资料

1. [CSP-S2020]

2. https://zh.wikipedia.org/wiki/%E5%85%AC%E5%8E%86
