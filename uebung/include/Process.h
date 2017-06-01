/*
 *  @author Marcel Fest
 */

#pragma once
#include <string>
#include <iostream>
#include "Duration.h"
class Process
{
    int id;
    std::string name;
    Duration* pDuration = nullptr;
    public:
        Process(int id, std::string name): id(id), name(name){};
        virtual ~Process();
        friend std::ostream& operator<<(std::ostream& os, const Process& arg);
        const Duration& TimeSpan();
        void TimeSpan(Duration& arg);
};
