#pragma once

#include "CStudent.h"

class CChainDoubleLink
{
public:
    CStudent m_data;
    CChainDoubleLink *m_previous; // 指向前一个结点。
    CChainDoubleLink *m_next;     // 指向后一个结点。

public:
    CChainDoubleLink();
    ~CChainDoubleLink();

    CChainDoubleLink* mb_createNode();
    void mb_deleteNode(CChainDoubleLink * p);
    CChainDoubleLink* mb_findNodeById(long long id);
    CChainDoubleLink* mb_findNodeByScore(int score);
    int  mb_getNodeNumber();
    void mb_sortById();
    void mb_sortByScore();
};
