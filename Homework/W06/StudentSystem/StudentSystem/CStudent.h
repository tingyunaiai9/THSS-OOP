#pragma once

class CStudent
{
private:
    long long m_ID;
    int m_score;

public:
    CStudent(int id = 0, int score = 100)
        :m_ID(id), m_score(score) { }

    void mb_setId(long long id);
    void mb_setScore(int score);
    long long mb_getId() const;
    int mb_getScore() const;
};

extern void gb_swapStudent(CStudent &a, CStudent &b);
