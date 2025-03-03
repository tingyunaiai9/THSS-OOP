#include "pch.h"

#include "CP_Shape.h"

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

		case 2:
			p_shape = new CP_Square;
			break;

		case 3:
			p_shape = new CP_RegularPentagon;
			break;

		case 4:
			p_shape = new CP_RegularHexagon;
			break;

		case 5:
			p_shape = new CP_Circle;
			break;

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

	//_CrtDumpMemoryLeaks();
	return 0;
}
