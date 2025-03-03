#include "pch.h"

#include "CP_GreatestCommonDivisor.h"
#include "CP_LowestCommonMultiple.h"

int main(int argc, char* argv[])
{
	long long a, b;
	cout << "请输入两个正整数：" << endl;
	cin >> a >> b;

	if (a <= 0 || b <= 0)
	{
		cout << "您输入的数字不是正整数" << endl;
		system("pause");
		return 0;
	}

	CP_GreatestCommonDivisor* pGCD = NULL;
	pGCD = new CP_GreatestCommonDivisor(a, b);
	CP_LowestCommonMultiple* pLCM = NULL;
	pLCM = new CP_LowestCommonMultiple(a, b);

	long long GCD = pGCD->mb_getGCD();
	long long LCM = pLCM->mb_getLCM(GCD);

	cout << a << "和" << b << "的最大公约数为：" << GCD << endl;
	cout << a << "和" << b << "的最小公倍数为：" << LCM << endl;

	// 验证部分
	cout << endl << "————————验证————————" << endl;
	bool isGCD = pGCD->mb_isGCD();
	bool isLCM = pLCM->mb_isLCM();
	cout << GCD << (isGCD ? "是" : "不是")<< a << "和" << b << "的最大公约数" << endl;
	cout << LCM << (isLCM ? "是" : "不是") << a << "和" << b << "的最小公倍数" << endl;
	cout << endl;
	// 验证部分结束

	delete pGCD; // 释放内存
	delete pLCM;

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}