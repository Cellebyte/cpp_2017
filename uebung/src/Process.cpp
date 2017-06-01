
/*
 *  @author Marcel Fest
 */
#include "Process.h"
Process::~Process()
{
    delete(pDuration);
}
std::ostream& operator<<(std::ostream& os, const Process& arg)
{
    os << arg.id << " | " << arg.name << " | " << arg.pDuration;
    return os;
}
const Duration& Process::TimeSpan()
{
    return *pDuration;
}
void Process::TimeSpan(Duration& arg)
{
    pDuration = &arg;
}
