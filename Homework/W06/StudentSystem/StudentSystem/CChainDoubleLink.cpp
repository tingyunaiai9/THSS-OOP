#include "pch.h"

#include "CChainDoubleLink.h"

CChainDoubleLink::CChainDoubleLink() :
    m_previous(NULL), m_next(NULL)
{
}

CChainDoubleLink::~CChainDoubleLink()
{
    if(m_previous == NULL)
        return;
    m_previous->m_next = NULL;
    SAFE_DELETE(m_next);
}

CChainDoubleLink* CChainDoubleLink::mb_createNode()
{
    if(m_previous == NULL) //head
    {
        m_previous = this;
        m_next = this;
        return this;
    }

    CChainDoubleLink *pNew = NULL;
    pNew = new(nothrow) CChainDoubleLink;
    if(pNew == NULL) //内存分配失败
    {
        cout << "Memory allocation failed!" << endl;
        return NULL;
    }
    CChainDoubleLink *p = m_previous;
    p->m_next = pNew;
    pNew->m_previous = p;
    pNew->m_next = this;
    m_previous = pNew;
    return pNew;
}

void CChainDoubleLink::mb_deleteNode(CChainDoubleLink * p)
{
    if(p == NULL)
        return;

    if(m_previous == NULL)
        return;

    if(p == this) //head
    {
        if(m_previous == this) //only one node
        {
            p->m_previous = NULL;
            return;
        }

        m_data = m_next->m_data;
        p = p->m_next;
    }

    CChainDoubleLink* q;
    for(q=m_next; ((q!=p) && (q!=this));)
    {
        if (q != NULL)
            q = q->m_next;
        else break;
    }

    // not found
    if (q == this)
        return;
    if (q != p)
        return;

    // delete p
    q = p->m_previous;
    q->m_next = p->m_next;
    q = p->m_next;
    q->m_previous = p->m_previous;
    p->m_previous = p;
    p->m_next = NULL;
    SAFE_DELETE(p);
}

CChainDoubleLink* CChainDoubleLink::mb_findNodeById(long long id)
{
    if(m_previous == NULL)
        return NULL;

    CChainDoubleLink *p = this;
    do
    {
        if(p->m_data.mb_getId() == id)
            return p;
        p = p->m_next;
    }while(p != this);
    return NULL;
}

CChainDoubleLink* CChainDoubleLink::mb_findNodeByScore(int score)
{
    if(m_previous == NULL)
        return NULL;

    CChainDoubleLink *p = this;
    do
    {
        if(p->m_data.mb_getScore() == score)
            return p;
        p = p->m_next;
    }while(p != this);
    return NULL;
}

int CChainDoubleLink::mb_getNodeNumber()
{
    if(m_previous == NULL)
        return 0;

    int count = 0;
    CChainDoubleLink *p = this;
    do
    {
        count++;
        p = p->m_next;
    }while(p != this);
    return count;
}

void CChainDoubleLink::mb_sortById()
{
    if(m_previous == NULL)
        return;

    if(m_previous == this)
        return;

    CChainDoubleLink *p = this;
    CChainDoubleLink *q, *q1;
    do
    {
        q = m_previous;
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
    }while(p != m_previous);
}

void CChainDoubleLink::mb_sortByScore()
{
    if(m_previous == NULL)
        return;

    if(m_previous == this)
        return;

    CChainDoubleLink *p = this;
    CChainDoubleLink *q, *q1;
    do
    {
        q = m_previous;
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
    }while(p != m_previous);
}
