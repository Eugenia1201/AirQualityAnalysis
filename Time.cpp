#include<iostream>
#include<string>
#include <sstream>
#include "Time.h"

using namespace std;

Time::Time()
{
    hour=0;
    minute=0;
    second=0;
}
Time::Time(int hh, int mm, int ss)
{
    hour=hh;
    minute=mm;
    second=ss;
}
Time::Time(const string& timeStr) {
    std::istringstream iss(timeStr);
    char delimiter;
    iss >> hour >> delimiter >> minute >> delimiter >> second;
}
Time::~Time()
{
    //none
}
int Time::getHour() const {
    return hour;
}

int Time::getMinute() const {
    return minute;
}

int Time::getSecond() const {
    return second;
}
void Time::setTime(int hh, int mm, int ss)
{
    hour=hh;
    minute=mm;
    second=ss;
}
void Time::setHour(int hh)
{
    hour=hh;
}
void Time::setMinute(int mm)
{
    minute=mm;
}
void Time::setSecond(int ss)
{
    second=ss;
}
istream & operator >>( istream & input, Time & T )
{
    string time,sHH,sMM;
    int position, hh, mm;

    getline(input,sHH,':');
    getline(input,sMM,'\n');

    hh=stoi(sHH);
    mm=stoi(sMM);

    T.setHour(hh);
    T.setMinute(mm);
    return input;
}
ostream & operator <<( ostream & os, const Time & T )
{
    os<<T.getHour()<<":"<<T.getMinute()<<":"<<T.getSecond();
    return os;
}
bool Time::operator==(const Time& otherTime) const {
    return hour == otherTime.getHour();
}