/*
 *  @author Marcel Fest
 */

#pragma once
#include <string>
#include <list>
#include <iostream>
#include "Process.h"
class ProcessChain
{
    static const int MaxProcesses = 100;
    std::string name;
    Process *pChain[MaxProcesses];
    Duration CalcChainDuration();
    public:
        ProcessChain(std::string name): name(name){};
        virtual ~ProcessChain();
        bool Insert(const Process& arg);
        friend std::ostream& operator<<(std::ostream& os, const ProcessChain& arg);
};
