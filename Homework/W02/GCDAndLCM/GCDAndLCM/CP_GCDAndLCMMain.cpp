#include "pch.h"

#include "CP_GreatestCommonDivisor.h"
#include "CP_LowestCommonMultiple.h"

int main(int argc, char* argv[])
{
	long long a, b;
	cout << "������������������" << endl;
	cin >> a >> b;

	if (a <= 0 || b <= 0)
	{
		cout << "����������ֲ���������" << endl;
		system("pause");
		return 0;
	}

	CP_GreatestCommonDivisor* pGCD = NULL;
	pGCD = new CP_GreatestCommonDivisor(a, b);
	CP_LowestCommonMultiple* pLCM = NULL;
	pLCM = new CP_LowestCommonMultiple(a, b);

	long long GCD = pGCD->mb_getGCD();
	long long LCM = pLCM->mb_getLCM(GCD);

	cout << a << "��" << b << "�����Լ��Ϊ��" << GCD << endl;
	cout << a << "��" << b << "����С������Ϊ��" << LCM << endl;

	// ��֤����
	cout << endl << "������������������֤����������������" << endl;
	bool isGCD = pGCD->mb_isGCD();
	bool isLCM = pLCM->mb_isLCM();
	cout << GCD << (isGCD ? "��" : "����")<< a << "��" << b << "�����Լ��" << endl;
	cout << LCM << (isLCM ? "��" : "����") << a << "��" << b << "����С������" << endl;
	cout << endl;
	// ��֤���ֽ���

	delete pGCD; // �ͷ��ڴ�
	delete pLCM;

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}