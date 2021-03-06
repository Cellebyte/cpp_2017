/*
 *  @author Marcel Fest
 */

#pragma once
#include <iostream>
class Duration
{
    unsigned int h = 0;
    unsigned int m = 0;
    unsigned int s = 0;
    bool isDirty = false;
    public:
        Duration(): h(0), m(0),s(0){};
        Duration(unsigned int h, unsigned int m, unsigned int s): h(h), m(m), s(s){};
        virtual ~Duration() {};
        void SetDirty();
        Duration operator+ (const Duration &rhs);
        friend std::ostream& operator<< (std::ostream& os, const Duration& arg);
        static Duration Add(const Duration& arg1, const Duration& arg2);
};
