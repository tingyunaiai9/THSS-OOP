## 1 题目分析

 题目要求使用面向对象的技术，实现在控制台窗口输出字符串组成一个漂亮的图案。

## 2 实现思路

* 将图案相关功能作为一个类，在 CP_CatPattern.h 中声明。

    ```
    class CP_CatPattern
    {
    public:
        CP_CatPattern(char a = '*') : m_char(a) {}
        ~CP_CatPattern() {}

        void mb_drawCatPattern();

    private:
        char m_char;
    };
    ```

  * 将成员函数 mb_drawCatPattern 设为public，便于调用。

  * 将成员变量 m_char 设为private，保护数据。

  * 构造函数中设定 m_char 值，默认为*。

* 在 CP_CatPattern.cpp 中完成对成员函数 mb_drawCatPattern 的定义。

* 在 CP_CatPatternMain.cpp 中通过实例化对象并调用成员函数实现题目要求。

    ```
    int main(int argc, char* argv[])
    {
        CP_CatPattern cat('+');
        cat.mb_drawCatPattern();
        system("pause");
        return 0;
    }
    ```

  * 在实例化对象 cat 时，可以通过构造函数对 m_char 赋不同的值，实现图案的多样性。

* CP_Define.h 中包含无需改动的代码体。结合 CP_Define.cpp pch.h pch.cpp 实现预编译，加快后续编译速度。

* 头文件中都含有 #progma once 指令，保证头文件只被编译一次。

## 3 代码运行方法

 平台：Visual Studio 2022

 x64 release

## 4 运行结果分析

输出了一只可爱的猫猫！让人看了能够收获好心情。

```
    *     *
  *  *   *  *
  *   ***    *   **
  *          *  *  *
  *  +  +    *  *   *
  *          *   *  *
   *        **    * *
    *         *   * *
    *          ***  *
    *           *  *
    *           ***
    *   *  *   *
    *   *  *   *
    ************
```

通过改变实例化对象时对 m_char 的赋值，可以实现猫猫眼睛符号的变化。

```
    *     *
  *  *   *  *
  *   ***    *   **
  *          *  *  *
  *  @  @    *  *   *
  *          *   *  *
   *        **    * *
    *         *   * *
    *          ***  *
    *           *  *
    *           ***
    *   *  *   *
    *   *  *   *
    ************
```
