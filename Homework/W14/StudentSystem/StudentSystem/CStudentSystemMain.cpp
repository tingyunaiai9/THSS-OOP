#include "pch.h"

#include "CStudentSystem.h"

int main()
{
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF); // only in vs

    CStudentSystem studentSystem;
    studentSystem.mb_run();

    return 0;
}
