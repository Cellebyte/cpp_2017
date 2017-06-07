
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
    int argID= const_cast<Process&>(arg).id;
    for(int i=0; i < MaxProcesses; i++)
    {
        if(! pChain[i])
        {
            pChain[i] = new Process(0,""); //fixed
            *pChain[i] = arg;
            std::cout << "Process inserted: " << arg << '\n';
            return true;
        } else if(argID==pChain[i]->id){
            std::cerr << "Process ID already exists in chain: " << arg << '\n';
            return false;
        }
    }
    return false;
}
std::ostream& operator<<(std::ostream& os, const ProcessChain& arg)
{

    os << arg.name << ":\n";

    Duration d = const_cast<ProcessChain&>(arg).CalcChainDuration();
    os << "Whole Duration: " << d << '\n';

    std::list<Process>sortingList;


    sortingList.push_front(*arg.pChain[0]);
    int i=1;
    while(arg.pChain[i])
    {
        for (std::list<Process>::iterator proc = sortingList.begin(); proc != sortingList.end(); ){
            if(arg.pChain[i]->id>proc->id){
                sortingList.insert (++proc, *arg.pChain[i]);
                break;
            } else{++proc;}
        }
        i++;
    }

    //sortingList.sort();
    for (std::list<Process>::iterator proc = sortingList.begin(); proc != sortingList.end(); ++proc){
        os << *proc << '\n';
    }

    return os;
}
