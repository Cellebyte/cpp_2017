/*
 *  @author Marcel Fest
 */

#include "ProcessChain.h"
#include <iostream>

int main()
{
    Duration a = Duration(10,4,30);
    ProcessChain d = ProcessChain("TestChain");
    Process b = Process(1,"TestProcess");
    b.TimeSpan(a);
    d.Insert(b);
    std::cout << d << '\n';
}
