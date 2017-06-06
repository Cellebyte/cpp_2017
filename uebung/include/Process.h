/*
 *  @author Marcel Fest
 */

#pragma once
#include <string>
#include <iostream>
#include "Duration.h"
class Process
{

    std::string name;
    Duration* pDuration = nullptr;
    public:
        int id;
        Process(int id, std::string name): id(id), name(name){};
        virtual ~Process();
        friend std::ostream& operator<<(std::ostream& os, const Process& arg);
        const Duration& TimeSpan();
        void TimeSpan(Duration& arg);
};
