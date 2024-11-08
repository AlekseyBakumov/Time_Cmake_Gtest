#include <iostream>
#include "Time.h"

unsigned int Time::counter = 0;

Time::Time() 
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
        counter++;
        std::cout << "Time object created using default constructor. Current counter: " << counter << std::endl;
    }
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    {
        if (h < 0 || h > 24 ||
            m < 0 || m > 60 ||
            s < 0 || s > 60)
            throw std::invalid_argument("Invalid argument for constructor");
        Normalize();
        counter++;
        std::cout << "Time object created using initializing constructor. Current counter: " << counter << std::endl;
    }
Time::Time(const Time& t)  : hours(t.GetHours()), minutes(t.GetMinutes()), seconds(t.GetSeconds())
    {
        Normalize();
        counter++;
        std::cout << "Time object created using copy constructor. Current counter: " << counter << std::endl;
    }
Time::~Time() 
    {
        counter--;
        std::cout << "Time object destroyed. Current counter: " << counter << std::endl;
    }

    Time& Time::operator= (const Time& other)  {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
        return *this;
    }

    int Time::GetHours() const { return hours; }
    int Time::GetMinutes() const { return minutes; }
    int Time::GetSeconds() const { return seconds; }

    void Time::SetHours(int h)
    {
        if (h < 0 || h > 24)
            throw std::invalid_argument("Invalid argument for set function");
        hours = h;

    }
    void Time::SetMinutes(int m)
    {
        if (m < 0 || m > 60)
            throw std::invalid_argument("Invalid argument for set function");
        minutes = m;

    }
    void Time::SetSeconds(int s)
    {
        if (s < 0 || s > 60)
            throw std::invalid_argument("Invalid argument for set function");
        seconds = s;

    }

    void Time::PrintTime() {
        std::cout
            << "H:" << this->GetHours()
            << " M:" << this->GetMinutes()
            << " S:" << this->GetSeconds()
            << std::endl;
    }

    void Time::Normalize()  {
        minutes += seconds / 60;
        seconds %= 60;
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;

        if (seconds < 0)
        {
            seconds += 60;
            minutes--;
        }

        if (minutes < 0)
        {
            minutes += 60;
            hours--;
        }

        if (hours < 0)
        {
            hours += 24;
        }
    }

    int Time::ToSeconds() { return ((GetHours() * 60) + GetMinutes()) * 60 + GetSeconds(); }

    Time Time::operator+ (int s) 
    {
        return Time(GetHours(), GetMinutes(), GetSeconds() + s);
    }
    Time Time::operator+= (int s) 
    {
        seconds += s;
        Normalize();
        return *this;
    }
    Time Time::operator- (int s) 
    {
        return Time(GetHours(), GetMinutes(), GetSeconds() - s);
    }
    Time Time::operator-= (int s)
    {
        seconds -= s;
        Normalize();
        return *this;
    }

    bool Time::operator== (const Time& t) 
    {
        return (GetSeconds() == t.GetSeconds()
            && GetMinutes() == t.GetMinutes()
            && GetSeconds() == t.GetSeconds());
    }
    bool Time::operator!= (const Time& t)
    {
        return !(*this == t);
    }
    bool Time::operator< (const Time& t)
    {
        if (GetHours() < t.GetHours()) return true;
        if (GetHours() > t.GetHours()) return false;
        if (GetMinutes() < t.GetMinutes()) return true;
        if (GetMinutes() > t.GetMinutes()) return false;
        if (GetSeconds() < t.GetSeconds()) return true;
        return false;
    }
    bool Time::operator> (const Time& t)
    {
        return (!(*this < t)) && (*this != t);
    }
    bool Time::operator<= (const Time& t) 
    {
        return !(*this > t);
    }
    bool Time::operator>= (const Time& t) 
    {
        return !(*this < t);
    }