#pragma once

class CP_CatPattern
{
public:
    CP_CatPattern(char a = '*') : m_char(a) {}
    ~CP_CatPattern() {}

    void mb_drawCatPattern();

private:
    char m_char;
};