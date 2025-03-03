#include "pch.h"

#include "CChainDoubleLink.h"

CChainDoubleLinkNode::CChainDoubleLinkNode() :
    m_previous(NULL), m_next(NULL)
{
}

CChainDoubleLinkNode::~CChainDoubleLinkNode()
{
}

CChainDoubleLink::CChainDoubleLink() :
    m_head(NULL)
{
}

CChainDoubleLink::~CChainDoubleLink()
{
    if(m_head == NULL)
        return;

    CChainDoubleLinkNode *p = m_head;
    CChainDoubleLinkNode *q;
    do
    {
        q = p->m_next;
        p->m_previous = NULL;
        SAFE_DELETE(p);
        p = q;
    }while(p != m_head);
}

CChainDoubleLinkNode* CChainDoubleLink::mb_createNode(long long id, int score)
{
    CChainDoubleLinkNode *pNew = NULL;
    pNew = new(nothrow) CChainDoubleLinkNode;
    if(pNew == NULL) //内存分配失败
    {
        cout << "Memory allocation failed!" << endl;
        return NULL;
    }

    pNew->m_data.mb_setId(id);
    pNew->m_data.mb_setScore(score);
    pNew->m_previous = NULL;
    pNew->m_next = NULL;

    mb_insertNode(pNew);

    return pNew;

}

void CChainDoubleLink::mb_deleteNode(CChainDoubleLinkNode * p)
{
    if(m_head == NULL)
        return;
    else if(p == NULL)
        return;
    else if(p == m_head)
    {
        if(m_head->m_previous == m_head) // only one
        {
            SAFE_DELETE(m_head);
            m_head = NULL;
            return;
        }

        m_head = m_head->m_next;
    }

    CChainDoubleLinkNode* q = m_head;
    do
    {
        if(p == q)
        {
            p->m_previous->m_next = p->m_next;
            p->m_next->m_previous = p->m_previous;

            // p->m_previous = p;
            // p->m_next = NULL;
            SAFE_DELETE(p);
            return;
        }
        q = q->m_next;
    }while(q != m_head);
}

void CChainDoubleLink::mb_dropNode(CChainDoubleLinkNode * p)
{
    if(m_head == NULL)
        return;
    else if(p == NULL)
        return;
    else if(p == m_head)
    {
        if(m_head->m_previous == m_head) // only one
        {
            m_head = NULL;
            return;
        }

        m_head = m_head->m_next;
    }

    CChainDoubleLinkNode* q = m_head;
    do
    {
        if(p == q)
        {
            p->m_previous->m_next = p->m_next;
            p->m_next->m_previous = p->m_previous;

            // p->m_previous = p;
            // p->m_next = NULL;
            return;
        }
        q = q->m_next;
    }while(q != m_head);
}

void CChainDoubleLink::mb_insertNode(CChainDoubleLinkNode * p) // 插入this之前
{
    if(p == NULL)
        return;
    else if(m_head == NULL)
    {
        m_head = p;
        m_head->m_previous = m_head;
        m_head->m_next = m_head;
        return;
    }
    else
    {
        m_head->m_previous->m_next = p;
        p->m_previous = m_head->m_previous;
        p->m_next = m_head;
        m_head->m_previous = p;
    }
}

CChainDoubleLinkNode* CChainDoubleLink::mb_findNodeById(long long id)
{
    if(m_head == NULL)
        return NULL;

    CChainDoubleLinkNode *p = m_head;
    do
    {
        if(p->m_data.mb_getId() == id)
            return p;
        p = p->m_next;
    }while(p != m_head);
    return NULL;
}

CChainDoubleLinkNode* CChainDoubleLink::mb_findNodeByScore(int score)
{
    if(m_head == NULL)
        return NULL;

    CChainDoubleLinkNode *p = m_head;
    do
    {
        if(p->m_data.mb_getScore() == score)
            return p;
        p = p->m_next;
    }while(p != m_head);
    return NULL;
}

CChainDoubleLinkNode* CChainDoubleLink::mb_findNode(long long id, int score)
{
    if(m_head == NULL)
        return NULL;

    CChainDoubleLinkNode *p = m_head;
    do
    {
        if(p->m_data.mb_getId() == id && p->m_data.mb_getScore() == score)
            return p;
        p = p->m_next;
    }while(p != m_head);
    return NULL;
}

int CChainDoubleLink::mb_getNodeNumber()
{
    if(m_head == NULL)
        return 0;

    int count = 0;
    CChainDoubleLinkNode *p = m_head;
    do
    {
        count++;
        p = p->m_next;
    }while(p != m_head);
    return count;
}

void CChainDoubleLink::mb_sortById()
{
    if(mb_getNodeNumber() < 2)
        return;

    CChainDoubleLinkNode *p = m_head;
    CChainDoubleLinkNode *q, *q1;
    do
    {
        q = m_head->m_previous;
        do
        {
            q1 = q->m_previous;
            if(q1->m_data.mb_getId() > q->m_data.mb_getId())
            {
                gb_swapStudent(q->m_data, q1->m_data);
            }
            q = q1;
        } while (q!=p);
        p = p->m_next;
    }while(p != m_head->m_previous);
}

void CChainDoubleLink::mb_sortByScore()
{
    if(mb_getNodeNumber() < 2)
        return;

    CChainDoubleLinkNode *p = m_head;
    CChainDoubleLinkNode *q, *q1;
    do
    {
        q = m_head->m_previous;
        do
        {
            q1 = q->m_previous;
            if(q1->m_data.mb_getScore() > q->m_data.mb_getScore())
            {
                gb_swapStudent(q->m_data, q1->m_data);
            }
            q = q1;
        } while (q!=p);
        p = p->m_next;
    }while(p != m_head->m_previous);
}
