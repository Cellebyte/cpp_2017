
/*
 *  @author Marcel Fest
 */
#include "ProcessChain.h"
Duration ProcessChain::CalcChainDuration()
{
    Duration whole = Duration();
    int i=0;
    while(pChain[i])
    {
        whole=Duration::Add(whole,(*pChain[i]).TimeSpan());
        i++;
    }
    return whole;
}

ProcessChain::~ProcessChain()
{

    for(int i=0;i<MaxProcesses;i++)
        delete pChain[i];
    delete[] *pChain;
}
bool ProcessChain::Insert(const Process& arg)
{
    for(int i=0; i < MaxProcesses; i++)
    {
        if(! pChain[i])
        {
            pChain[i] = new Process(0,""); //fixed
            *pChain[i] = arg;
            return true;
        }
    }
    return true;
}
std::ostream& operator<<(std::ostream& os, const ProcessChain& arg)
{
    os << arg.name << ":\n";
    int i=0;
    while(arg.pChain[i])
    {
        os << *arg.pChain[i] << '\n';
        i++;
    }
    Duration a = const_cast<ProcessChain&>(arg).CalcChainDuration();
    os << "Whole Duration: " << a;
    return os;
}
