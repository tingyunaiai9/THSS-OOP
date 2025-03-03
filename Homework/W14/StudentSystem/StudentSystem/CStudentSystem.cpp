#include "pch.h"

#include "CStudentSystem.h"
#include "CFactoryMethodStudentSystem.h"

CStudentSystem::CStudentSystem()
{
    m_systemHead = NULL;

    m_systemHead = new(nothrow) CChainDoubleLink;
    if(m_systemHead == NULL)
    {
        cout << "Memory allocation failed!" << endl;
        return;
    }
}

CStudentSystem::~CStudentSystem()
{
    SAFE_DELETE(m_systemHead);
}

void CStudentSystem::mb_printAllStudent()
{
    if(m_systemHead->mb_getNodeNumber() == 0)
    {
        cout << "No student information!" << endl;
        return;
    }

    CChainDoubleLinkNode *p = m_systemHead->m_head;
    int n = 1;
    do
    {
        cout << "[" << n << "] ID: " << p->m_data.mb_getId() << " Score: " << p->m_data.mb_getScore() << endl;
        p = p->m_next;
        n++;
    } while(p != m_systemHead->m_head);
}

void CStudentSystem::mb_printMainMenu()
{
    cout << "\nMain Menu:\n";
    cout << "\t[1]: Add student information\n";
    cout << "\t[2]: Delete student information by ID\n";
    cout << "\t[3]: Delete student information by score\n";
    cout << "\t[4]: Show student information by ID\n";
    cout << "\t[5]: Show student information by score\n";
    cout << "\t[6]: Show all student information\n";
    cout << "\t[-1]: Exit\n";
    cout << "Please input your choice: ";
}

void CStudentSystem::mb_run()
{
    int cmd;
    do
    {
        mb_printMainMenu();
        cin >> cmd;
        cout << endl;
        if(cmd > 6 || cmd < -1 || cmd == 0 || cin.fail())
        {
            cout << "Invalid command!" << endl;
        }

        switch(cmd)
        {
        case 1:
            mb_addStudent();
            break;
        case 2:
            mb_deleteStudentById();
            break;
        case 3:
            mb_deleteStudentByScore();
            break;
        case 4:
            mb_showScoreById();
            break;
        case 5:
            mb_showIdByScore();
            break;
        case 6:
            mb_printAllStudent();
            break;
        case -1:
            mb_exit();
            break;
        }
    } while (cmd != -1);
}

void CStudentSystem::mb_addStudent()
{
    CStudent student;
    CChainDoubleLinkNode *p = NULL;
    long long ID = 0;
    int score = 0;
    do
    {
        cout << "Please input student ID (0 to exit): ";
        cin >> ID;
        if(ID < 0)
        {
            cout << "Invalid ID!" << endl;
            string tmp;
            getline(cin, tmp);
            continue;
        }
        else if(ID == 0)
        {
            break;
        }

        cout << "Please input student score:          ";
        cin >> score;
        if(score < 0)
        {
            cout << "Invalid score!" << endl;
            continue;
        }

        CFactoryMethodStudentSystem* factory = CFactoryMethodStudentSystem::mbs_getFactoryInstance();
        p = factory->mb_createNode(ID, score);
        if(p)
        {
            m_systemHead->mb_insertNode(p);
            m_systemHead->mb_sortById();
        }
    } while (ID != 0);
}

void CStudentSystem::mb_deleteStudentById()
{
    long long ID = 0;
    CChainDoubleLinkNode *p = NULL;

    cout << "Please input student ID to delete: ";
    cin >> ID;

    if(ID <= 0)
    {
        cout << "Invalid ID!" << endl;
        return;
    }

    p = m_systemHead->mb_findNodeById(ID);
    if(p == NULL)
    {
        cout << "Student not found!" << endl;
        return;
    }
    else
    {
        CFactoryMethodStudentSystem* factory = CFactoryMethodStudentSystem::mbs_getFactoryInstance();
        m_systemHead->mb_dropNode(p);
        factory->mb_deleteNode(p);
        cout << "Successfully deleted!" << endl;
    }
}

void CStudentSystem::mb_deleteStudentByScore()
{
    int score = 0;
    CChainDoubleLinkNode *p = NULL;

    cout << "Please input student score to delete: ";
    cin >> score;

    if(score < 0)
    {
        cout << "Invalid score!" << endl;
        return;
    }

    p = m_systemHead->mb_findNodeByScore(score);
    if(p == NULL)
    {
        cout << "Student not found!" << endl;
        return;
    }

    while(1)
    {
        p = m_systemHead->mb_findNodeByScore(score);
        if(p == NULL)
        {
            break;
        }
        else
        {
            CFactoryMethodStudentSystem* factory = CFactoryMethodStudentSystem::mbs_getFactoryInstance();
            m_systemHead->mb_dropNode(p);
            factory->mb_deleteNode(p);
        }
    }
    cout << "Successfully deleted!" << endl;
}

void CStudentSystem::mb_showScoreById()
{
    long long ID = 0;
    CChainDoubleLinkNode *p = NULL;

    cout << "Please input student ID to show score: ";
    cin >> ID;

    if(ID <= 0)
    {
        cout << "Invalid ID!" << endl;
        return;
    }

    p = m_systemHead->mb_findNodeById(ID);
    if(p == NULL)
    {
        cout << "Student not found!" << endl;
        return;
    }
    else
    {
        cout << "Student ID: " << p->m_data.mb_getId() << " Score: " << p->m_data.mb_getScore() << endl;
    }

}

void CStudentSystem::mb_showIdByScore()
{
    int score = 0;
    CChainDoubleLinkNode *p = NULL;

    cout << "Please input student score to show ID: ";
    cin >> score;

    if(score < 0)
    {
        cout << "Invalid score!" << endl;
        return;
    }

    p = m_systemHead->mb_findNodeByScore(score);
    if(p == NULL)
    {
        cout << "Student not found!" << endl;
        return;
    }

    int n = 1;
    do
    {
        if (p->m_data.mb_getScore() == score)
        {
            cout << "[" << n << "] ID: " << p->m_data.mb_getId() << " Score: " << p->m_data.mb_getScore() << endl;
            n++;
        }
        p = p->m_next;
    } while(p != m_systemHead->m_head);
}

void CStudentSystem::mb_exit()
{
    cout << "Bye~" << endl;
}
