
/*
 *  @author Marcel Fest
 */
#include "ProcessChain.h"
Duration ProcessChain::CalcChainDuration()
{
    Duration whole;
    int i=0;
    while(pChain[i])
    {
        whole=Duration::Add(whole,(pChain[i])->TimeSpan());
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
    for(int i=0; i< MaxProcesses; i++)
    {
        if(! pChain[i])
        {
            *(pChain[i])=arg;
            return true;
        }
    }
    return false;
}
std::ostream& operator<<(std::ostream& os, const ProcessChain& arg)
{
    os << arg.name << ":\n";
    int i=0;
    while((arg.pChain)[i])
    {
        os << &(arg.pChain)[i] << '\n';
        i++;
    }
    //os << "Whole Duration:" << arg.CalcChainDuration();
    return os;
}
