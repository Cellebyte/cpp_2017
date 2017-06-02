
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
        whole=Duration::Add(whole,pChain[i]->TimeSpan());
        i++;
    }
    return whole;
}

ProcessChain::~ProcessChain()
{

    /*for(int i=0;i<MaxProcesses;i++)
        delete pChain[i];
    delete[] *pChain;*/
}
bool ProcessChain::Insert(const Process& arg)
{

    for(int i=0; i < MaxProcesses; i++)
    {
        std::cout << arg << '\n';
        if(! pChain[i])
        {
            std::cout << "Before" << '\n';
            *pChain[i] = arg;
            std::cout << "Done" << '\n';
            return true;
        }
    }
    return false;
}
std::ostream& operator<<(std::ostream& os, const ProcessChain& arg)
{
    os << arg.name << ":\n";
    int i=0;
    std::cout << "I'm an op" << '\n';
    while(arg.pChain[i])
    {
        os << arg.pChain[i] << '\n';
        i++;
    }
    //os << "Whole Duration:" << arg.CalcChainDuration();
    return os;
}
