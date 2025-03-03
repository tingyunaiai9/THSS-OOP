#include "pch.h"

#include "CFactoryMethodStudentSystem.h"

CFactoryMethodStudentSystem::CFactoryMethodStudentSystem()
{
    m_factoryHead = NULL;

    m_factoryHead = new(nothrow) CChainDoubleLink;
    if(m_factoryHead == NULL)
    {
        cout << "Memory allocation failed!" << endl;
        return;
    }
}

CFactoryMethodStudentSystem::~CFactoryMethodStudentSystem()
{
    SAFE_DELETE(m_factoryHead);
}

CFactoryMethodStudentSystem * CFactoryMethodStudentSystem::mbs_getFactoryInstance()
{
    static CFactoryMethodStudentSystem instance;

    return &instance;
}

CChainDoubleLinkNode* CFactoryMethodStudentSystem::mb_createNode(long long id, int score)
{
    if(m_factoryHead)
    {
        CChainDoubleLinkNode* p = m_factoryHead->mb_findNode(id, score);
        if(p != NULL)
        {
            m_factoryHead->mb_dropNode(p);
            return p;
        }
        else
        {
            CChainDoubleLinkNode *pNew = NULL;
            pNew = new(nothrow) CChainDoubleLinkNode;
            if(pNew == NULL)
            {
                cout << "Memory allocation failed!" << endl;
                return NULL;
            }

            pNew->m_data.mb_setId(id);
            pNew->m_data.mb_setScore(score);

            return pNew;
        }
    }

    return NULL;



    // if(m_factoryHead)
    // {
    //     if(m_head->m_data.mb_getId() == id && m_head->m_data.mb_getScore() == score)
    //     {
    //         CChainDoubleLinkNode* p = m_head;
    //         m_head = m_head->m_next;
    //         p->m_previous = NULL;
    //         p->m_next = NULL;
    //         return p;
    //     }
    //     else
    //     {
    //         CChainDoubleLinkNode *p = m_head->m_next;

    //         while(p != m_head)
    //         {
    //             if(p->m_data.mb_getId() == id && p->m_data.mb_getScore() == score)
    //             {
    //                 m_head->mb_dropNode(p);
    //                 p->m_previous = NULL;
    //                 p->m_next = NULL;
    //                 return p;
    //             }
    //             p = p->m_next;
    //         }
    //     }
    // }

    // // no find
    // CChainDoubleLinkNode *pNew = NULL;
    // pNew = new(nothrow) CChainDoubleLinkNode;
    // if(pNew == NULL)
    // {
    //     cout << "Memory allocation failed!" << endl;
    //     return NULL;
    // }

    // pNew->m_data.mb_setId(id);
    // pNew->m_data.mb_setScore(score);

    // return pNew;
}

void CFactoryMethodStudentSystem::mb_deleteNode(CChainDoubleLinkNode * p)
{
    if(m_factoryHead)
    {
        m_factoryHead->mb_insertNode(p);
    }
}
