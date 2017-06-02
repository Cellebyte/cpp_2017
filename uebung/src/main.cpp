/*
 *  @author Marcel Fest
 */

#include "ProcessChain.h"
#include <iostream>

int main()
{
    Duration* a = new Duration(10,4,30);
    Duration* c = new Duration(1,1,1);
    Duration sum = *a + *c;
    std::cout << sum << '\n';
    std::cout << *a << '\n';
    ProcessChain* d =new ProcessChain("TestChain");
    Process* b =new Process(1,"TestProcess");
    b->TimeSpan(*a);
    if (!(*d).Insert(*b)) return 1;
    std::cout << *d << '\n';
}
