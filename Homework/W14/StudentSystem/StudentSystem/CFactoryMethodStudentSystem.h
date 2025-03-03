#pragma once

#include "CChainDoubleLink.h"
#include "CStudent.h"
#include "CStudentSystem.h"

class CFactoryMethodStudentSystem
{
private:
    CChainDoubleLink *m_factoryHead; // 保存不在用的学生学号与成绩表单

private:
    CFactoryMethodStudentSystem();

public:
    ~CFactoryMethodStudentSystem();

public:
    static CFactoryMethodStudentSystem *mbs_getFactoryInstance();

public:
    CChainDoubleLinkNode* mb_createNode(long long id, int score);
    void mb_deleteNode(CChainDoubleLinkNode * p);
};
