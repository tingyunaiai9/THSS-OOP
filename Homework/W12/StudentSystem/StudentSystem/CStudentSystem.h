#pragma once

#include <map>

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
