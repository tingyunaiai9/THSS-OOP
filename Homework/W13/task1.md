# Week 13

## 1 题目分析

题目要求分析该字符串的格式，检查它是否符合整数的表示格式。

1. 若符合，则输出该整数
2. 若不符合，则抛出异常，分析原因

## 2 实现思路

在编程过程中，以整型 `Int` 型为整数格式。

将字符串转化为整数的异常划分为以下5种情况：

1. 字符串为空
   $$  $$


2. 字符串中含有 $\text{+-0123456789}$ 之外的字符，或仅含有正负号

   例如
   $$ \text{hello world} $$
   $$ a123 $$
   $$ - $$

3. 字符串中含有多个 $\text{+-}$ 符号，或正负号位置错误

   例如
   $$ +++123 $$
   $$ -+-123 $$
   $$ 12+3 $$


4. 字符串中数字含有前置0

   例如
   $$ 0123 $$

5. 字符串表示数字超过 `Int` 型范围

   例如
   $$ 12345678900 $$

若字符串为异常情况，则设置所的数字为0。

根据分析出的5种划分方式，创建类 `CExceptionBase` 及其子类，用于抛出异常的类型

1. CExceptionEmptyString
2. CExceptionInvalidChar
3. CExceptionInvalidSign
4. CExceptionInvalidZero
5. CExceptionInvalidLength

以下为各情况判断方法：

1. 字符串为空情况，通过字符串 $\text{str}$ 的大小进行判断
2. 字符串中含有 $\text{+-0123456789}$ 之外的字符，通过 `find_first_not_of` 实现
3.  $\text{+-}$ 符号错误，通过比较 $\text{+-}$ 第一次出现的位置与最后出现的位置实现
4. 字符串中数字含有前置0，通过判断符号位后一位数字是否为0实现
5. 字符串表示数字超过 `Int` 型范围，通过结合字符串的长度与转换为 `long long` 类型进行数值比较，判断是否超出范围

## 3 代码运行方法

 平台：Visual Studio 2022

 x64 release

## 4 测试报告

### 测试样例设计思路

根据对字符串异常划分的5种情况，进行分别测试

### 测试

#### 正常情况

```
Please enter a number: 12
The number is: 12
```

```
Please enter a number: +1
The number is: 1
```

```
Please enter a number: -1
The number is: -1
```

```
Please enter a number: 0
The number is: 0
```

```
Please enter a number: 2147483647
The number is: 2147483647
```

```
Please enter a number: -2147483648
The number is: -2147483648
```

#### 字符串空

```
Please enter a number:
Empty string
The number is: 0
```

#### 含有非法字符

```
Please enter a number: hello world
Invalid character
The number is: 0
```

```
Please enter a number: 123 45
Invalid character
The number is: 0
```

```
Please enter a number: 1@%3
Invalid character
The number is: 0
```

```
Please enter a number: +
Invalid character
The number is: 0
```


#### 正负号错误

```
Please enter a number: ++1
Invalid sign
The number is: 0
```

```
Please enter a number: 1+2
Invalid sign
The number is: 0
```



#### 前置0

```
Please enter a number: 007
Invalid zero
The number is: 0
```

```
Please enter a number: +0
Invalid zero
The number is: 0
```

#### 数值溢出

```
Please enter a number: 2147483648
Invalid length
The number is: 0
```

```
Please enter a number: -2147483649
Invalid length
The number is: 0
```
