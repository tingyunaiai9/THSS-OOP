#pragma once

#include "CStudent.h"

class CChainDoubleLinkNode
{
public:
    CStudent m_data;
    CChainDoubleLinkNode *m_previous; // 指向前一个结点。
    CChainDoubleLinkNode *m_next;     // 指向后一个结点。

public:
    CChainDoubleLinkNode();
    ~CChainDoubleLinkNode();

};

class CChainDoubleLink
{
public:
    CChainDoubleLinkNode* m_head;

public:
    CChainDoubleLink();
    ~CChainDoubleLink();

    CChainDoubleLinkNode* mb_createNode(long long id = 0, int score = 100);
    void mb_deleteNode(CChainDoubleLinkNode* p);
    void mb_dropNode(CChainDoubleLinkNode* p);
    void mb_insertNode(CChainDoubleLinkNode* p);

    CChainDoubleLinkNode* mb_findNodeById(long long id);
    CChainDoubleLinkNode* mb_findNodeByScore(int score);
    CChainDoubleLinkNode* mb_findNode(long long id, int score);
    int  mb_getNodeNumber();
    void mb_sortById();
    void mb_sortByScore();
};
