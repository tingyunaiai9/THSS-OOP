#include "pch.h"

#include "CStudentSystem.h"

CStudentSystem::CStudentSystem() :
    m_head(NULL)
{
}

CStudentSystem::~CStudentSystem()
{
    SAFE_DELETE(m_head);
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF); // only in vs
}

void CStudentSystem::mb_printAllStudent()
{
    if(m_head == NULL)
    {
        cout << "No student information!" << endl;
        return;
    }

    if(m_head->m_previous == NULL)
    {
        cout << "No student information!" << endl;
        return;
    }

    CChainDoubleLink *p = m_head;
    int n = 1;
    do
    {
        cout << "[" << n << "] ID: " << p->m_data.mb_getId() << " Score: " << p->m_data.mb_getScore() << endl;
        p = p->m_next;
        n++;
    } while(p != m_head);
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
    m_head = new(nothrow) CChainDoubleLink;
    if(m_head == NULL)
    {
        cout << "Memory allocation failed!" << endl;
        return;
    }

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

    SAFE_DELETE(m_head);
}

void CStudentSystem::mb_addStudent()
{
    CStudent student;
    CChainDoubleLink *p = NULL;
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

        student.mb_setId(ID);
        student.mb_setScore(score);
        p = m_head->mb_createNode();
        if(p)
        {
            p->m_data = student;
            m_head->mb_sortById();
        }
    } while (ID != 0);
}

void CStudentSystem::mb_deleteStudentById()
{
    long long ID = 0;
    CChainDoubleLink *p = NULL;

    cout << "Please input student ID to delete: ";
    cin >> ID;

    if(ID <= 0)
    {
        cout << "Invalid ID!" << endl;
        return;
    }

    p = m_head->mb_findNodeById(ID);
    if(p == NULL)
    {
        cout << "Student not found!" << endl;
        return;
    }
    else
    {
        m_head->mb_deleteNode(p);
        cout << "Successfully deleted!" << endl;
    }
}

void CStudentSystem::mb_deleteStudentByScore()
{
    int score = 0;
    CChainDoubleLink *p = NULL;

    cout << "Please input student score to delete: ";
    cin >> score;

    if(score < 0)
    {
        cout << "Invalid score!" << endl;
        return;
    }

    p = m_head->mb_findNodeByScore(score);
    if(p == NULL)
    {
        cout << "Student not found!" << endl;
        return;
    }

    while(1)
    {
        p = m_head->mb_findNodeByScore(score);
        if(p == NULL)
        {
            break;
        }
        else
        {
            m_head->mb_deleteNode(p);
        }
    }
    cout << "Successfully deleted!" << endl;
}

void CStudentSystem::mb_showScoreById()
{
    long long ID = 0;
    CChainDoubleLink *p = NULL;

    cout << "Please input student ID to show score: ";
    cin >> ID;

    if(ID <= 0)
    {
        cout << "Invalid ID!" << endl;
        return;
    }

    p = m_head->mb_findNodeById(ID);
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
    CChainDoubleLink *p = NULL;

    cout << "Please input student score to show ID: ";
    cin >> score;

    if(score < 0)
    {
        cout << "Invalid score!" << endl;
        return;
    }

    p = m_head->mb_findNodeByScore(score);
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
    } while(p != m_head);
}

void CStudentSystem::mb_exit()
{
    cout << "Bye~" << endl;
}
