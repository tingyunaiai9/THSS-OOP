#pragma once

#include "CChainDoubleLink.h"

class CStudentSystem
{
public:
    CChainDoubleLink *m_systemHead;
public:
    CStudentSystem();
    ~CStudentSystem();

    void mb_printAllStudent();
    void mb_printMainMenu();

    void mb_run();
    void mb_addStudent();
    void mb_deleteStudentById();
    void mb_deleteStudentByScore();
    void mb_showScoreById();
    void mb_showIdByScore();
    void mb_exit();
};
