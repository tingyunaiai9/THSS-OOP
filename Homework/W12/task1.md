# Week 12

## 1 题目分析

题目要求实现学生成绩表单的编辑与存储系统。

该系统需包含主界面的用户交互、数据的读取与储存、数据的添加与修改删除等功能。

## 2 实现思路

设计 `CStudentSystem` 类，封装系统所需功能

```cpp
class CStudentSystem
{
private:
	std::map<long long, int> m_studentMap;

public:
	CStudentSystem();
	~CStudentSystem();

private:
	void mb_addOneStudent(long long id, int score);
	void mb_deleteOneStudent(long long id);
	void mb_changeScore(long long id, int score);
	int mb_getScore(long long id);

	void mb_printMainMenu();

	void mb_addFromFile();
	void mb_addFromKey();
	void mb_deleteFromKey();
	void mb_deleteAll();
	void mb_change();
	void mb_showScore();
	void mb_showAll();
	void mb_saveToFile();
	void mb_exit();

public:
	void mb_run();
};
```

1. 程序中采用 STL 库中的键值对容器 `map` 储存当前成绩表单，充分利用了 `map` 自动建立 key－value 对应关系的特性，建立题目所需的学号与成绩**一一对应**。同时利用 `map` 自动按照 key 排序的特性，便于成绩表单的展示与存储。

2. 在各功能模块中设置合理的提示，并具有一定的鲁棒性，能够处理一些非法情况，如查找、删除时学生不存在、输入指令有误等情况。

3. 拆分程序所需的每个指令为一个函数，程序逻辑清晰。

4. 将学号设置为 `long long` 以应对学号更长的情况。


## 3 代码运行方法

 平台：Visual Studio 2022

 x64 release

## 4 测试报告

### 测试样例设计思路

对指令 1~8 及 -1 分别测试，测试正常情况、极端情况（空、不存在等）、错误情况。

### 测试

#### 指令1：接受文件名的输入，并从该文件中读取成绩表单，并添加到当前成绩表单中

```
Please input the file name: test.txt
Successfully added students from file!

All students:
   2022222222 : 100
   2023000000 : 90
   2023011111 : 90
   2023012175 : 100
```

文件不存在时
```
Please input the file name: text2.txt
Failed to open the file!
```

文件格式有误时
```
test.txt内容（包含非法学号）：
2022222222 100
aaa2023000000 90
2023011111 90
2023012175 100

Please input the file name: test.txt
Invalid data in file!
```

#### 指令2：接受学号和成绩的输入，并将其添加到当前成绩表单中

```
Please input students' id and score (input 0 to exit) :
2023011111 90
2023000000 90
2022222222 99
2023012175 100
2023012345 99
0

All students:
   2022222222 : 99
   2023000000 : 90
   2023011111 : 90
   2023012175 : 100
   2023012345 : 99
```

#### 指令3：接受学号的输入，并从当前成绩表单中删除该学号及其成绩

```
Please input the student's id: 2023012345
Successfully deleted

All students:
   2022222222 : 99
   2023000000 : 90
   2023011111 : 90
   2023012175 : 100
```

对应学生不存在时
```
Please input the student's id: 111111
The student is not found!
```

#### 指令4：删除在当前成绩表单中的所有学号及其成绩

```
Successfully deleted all students!
```


#### 指令5：接受学号和成绩的输入，并在当前成绩表单中将该学号对应的成绩改为新输入的成绩

```
Please input the student's id: 2022222222
Please input the new score: 100
Successfully changed the score!

All students:
   2022222222 : 100
   2023000000 : 90
   2023011111 : 90
   2023012175 : 100
```

对应学生不存在时
```
Please input the student's id: 123456
The student is not found!
```

#### 指令6：接受学号的输入，并输出该学号对应的成绩

```
Please input the student's id: 2023012175
The student's score is: 100
```

对应学生不存在时
```
Please input the student's id: 666666
The student is not found!
```

#### 指令7：显示所有的学号及其对应的成绩

```
All students:
   2022222222 : 99
   2023000000 : 90
   2023011111 : 90
   2023012175 : 100
   2023012345 : 99
```

成绩表单为空
```
No student!
```

#### 指令8：接受文件名的输入，并将当前成绩表单保存到该文件中

```
Please input the file name: test.txt
Successfully saved data to file!

test.txt内容：
2022222222 100
2023000000 90
2023011111 90
2023012175 100
```

#### 指令-1：退出

```
Exit the system!
Bye~
```
