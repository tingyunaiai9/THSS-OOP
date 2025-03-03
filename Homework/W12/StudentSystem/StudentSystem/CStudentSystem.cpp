#include <pch.h>

#include "CStudentSystem.h"

CStudentSystem::CStudentSystem()
{
    m_studentMap.clear();
}

CStudentSystem::~CStudentSystem()
{
    m_studentMap.clear();
}

void CStudentSystem::mb_addOneStudent(long long id, int score)
{
    m_studentMap[id] = score;
}

void CStudentSystem::mb_deleteOneStudent(long long id)
{
    m_studentMap.erase(id);
}

void CStudentSystem::mb_changeScore(long long id, int score)
{
    m_studentMap[id] = score;
}

int CStudentSystem::mb_getScore(long long id)
{
    return m_studentMap[id];
}

void CStudentSystem::mb_printMainMenu()
{
    cout << endl;
    cout << "Main Menu:" << endl;
    cout << "   [ 1] Add student from file" << endl;
    cout << "   [ 2] Add student from keyboard" << endl;
    cout << "   [ 3] Delete one student" << endl;
    cout << "   [ 4] Delete all students" << endl;
    cout << "   [ 5] Change the student's score" << endl;
    cout << "   [ 6] Show the student's score" << endl;
    cout << "   [ 7] Show all students" << endl;
    cout << "   [ 8] Save data to file" << endl;
    cout << "   [-1] Exit" << endl;
    cout << endl;
    cout << "Please input the command: ";
}

void CStudentSystem::mb_run()
{
    int command = 0;

    while (command != -1)
    {
        mb_printMainMenu();
        cin >> command;
        switch (command)
        {
        case 1:
            mb_addFromFile();
            break;
        case 2:
            mb_addFromKey();
            break;
        case 3:
            mb_deleteFromKey();
            break;
        case 4:
            mb_deleteAll();
            break;
        case 5:
            mb_change();
            break;
        case 6:
            mb_showScore();
            break;
        case 7:
            mb_showAll();
            break;
        case 8:
            mb_saveToFile();
            break;
        case -1:
            mb_exit();
            return;
        default:
            cout << "Invalid command!" << endl;
            break;
        }
    }
}

void CStudentSystem::mb_addFromFile()
{
    string fileName;
    cout << "Please input the file name: ";
    cin >> fileName;

    ifstream fin(fileName);
    if (!fin.is_open())
    {
        cout << "Failed to open the file!" << endl;
        return;
    }

    string str, idStr, scoreStr;
    long long id;
    int score;

    while(getline(fin, str))
    {
        idStr = str.substr(0, str.find(' '));
        scoreStr = str.substr(str.find_last_of(' ') + 1);

        if(idStr.empty() || scoreStr.empty())
        {
            cout << "Invalid data in file!" << endl;
            fin.close();
            return;
        }
        else if(idStr.find_first_not_of("0123456789") != string::npos || scoreStr.find_first_not_of("0123456789") != string::npos)
        {
            cout << "Invalid data in file!" << endl;
            fin.close();
            return;
        }
        else
        {
            id = stoll(idStr);
            score = stoi(scoreStr);
            mb_addOneStudent(id, score);
        }
    }

    fin.close();
    cout << "Successfully added students from file!" << endl;
}

void CStudentSystem::mb_addFromKey()
{
    long long id;
    int score;

    cout << "Please input students' id and score (input 0 to exit) : " << endl;

    while (true)
    {
        cin >> id;
        if (id == 0)
            break;

        cin >> score;
        mb_addOneStudent(id, score);
    }
}

void CStudentSystem::mb_deleteFromKey()
{
    long long id;
    cout << "Please input the student's id: ";
    cin >> id;

    if (m_studentMap.find(id) == m_studentMap.end())
    {
        cout << "The student is not found!" << endl;
        return;
    }

    mb_deleteOneStudent(id);
    cout << "Successfully deleted" << endl;
}

void CStudentSystem::mb_deleteAll()
{
    m_studentMap.clear();
    cout << "Successfully deleted all students!" << endl;
}

void CStudentSystem::mb_change()
{
    long long id;
    int score;
    cout << "Please input the student's id: ";
    cin >> id;

    if (m_studentMap.find(id) == m_studentMap.end())
    {
        cout << "The student is not found!" << endl;
        return;
    }

    cout << "Please input the new score: ";
    cin >> score;
    mb_changeScore(id, score);
    cout << "Successfully changed the score!" << endl;
}

void CStudentSystem::mb_showScore()
{
    long long id;
    cout << "Please input the student's id: ";
    cin >> id;

    if (m_studentMap.find(id) == m_studentMap.end())
    {
        cout << "The student is not found!" << endl;
        return;
    }

    cout << "The student's score is: " << mb_getScore(id) << endl;
}

void CStudentSystem::mb_showAll()
{
    if (m_studentMap.empty())
    {
        cout << "No student!" << endl;
        return;
    }

    cout << "All students:" << endl;
    for (auto it = m_studentMap.begin(); it != m_studentMap.end(); it++)
    {
        cout << "   " << it->first << " : " << it->second << endl;
    }
}

void CStudentSystem::mb_saveToFile()
{
    string fileName;
    cout << "Please input the file name: ";
    cin >> fileName;

    ofstream fout(fileName);
    if (!fout.is_open())
    {
        cout << "Failed to open the file!" << endl;
        return;
    }

    for (auto it = m_studentMap.begin(); it != m_studentMap.end(); it++)
    {
        fout << it->first << " " << it->second << endl;
    }

    fout.close();
    cout << "Successfully saved data to file!" << endl;
}

void CStudentSystem::mb_exit()
{
    m_studentMap.clear();
    cout << "Exit the system!" << endl;
    cout << "Bye~" << endl;
}
