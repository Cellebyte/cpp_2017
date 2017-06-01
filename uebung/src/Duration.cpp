
/*
 *  @author Marcel Fest
 */
#include "Duration.h"

void Duration::SetDirty()
{
    isDirty=true;
}
Duration Duration::operator+ (const Duration &rhs)
{
    return Add(*this,rhs);
}
Duration Duration::Add(const Duration& arg1, const Duration& arg2)
{
    Duration result = Duration(arg1.h+arg2.h,arg1.m+arg2.m,arg1.s+arg2.s);
    return result;
}
std::ostream& operator<< (std::ostream& os, const Duration& arg)
{
    os << arg.h << ':' << arg.m << ':' << arg.s;
    return os;
}
