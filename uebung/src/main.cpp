/*
 *  @author Marcel Fest
 */

#include "ProcessChain.h"
#include <iostream>

int main()
{
    Duration* a = new Duration(10,4,30);
    Duration* c = new Duration(1,1,1);
    ProcessChain* d =new ProcessChain("TestChain");
    Process* p1 =new Process(1,"TestProcess1");
    Process* p2 =new Process(2,"TestProcess2");
    Process* p3 =new Process(3,"TestProcess3");
    Process* p4 =new Process(4,"TestProcess4");
    p1->TimeSpan(*a);
    p2->TimeSpan(*a);
    p3->TimeSpan(*c);
    p4->TimeSpan(*c);
    if (!(*d).Insert(*p1)) return 1;
    if (!(*d).Insert(*p4)) return 1;
    if (!(*d).Insert(*p3)) return 1;
    if (!(*d).Insert(*p2)) return 1;

    std::cout << *d << '\n';
}
