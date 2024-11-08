

class Time
{
    int hours, minutes, seconds;
    static unsigned int counter;

public:
    Time();
    Time(int h, int m, int s);
    Time(const Time& t);
    ~Time();

    Time& operator= (const Time& other);

    int GetHours() const;
    int GetMinutes() const;
    int GetSeconds() const;

    void SetHours(int h);
    void SetMinutes(int m);
    void SetSeconds(int s);
    void PrintTime();
    static int GetCount();

    void Normalize();
    int ToSeconds();
    Time operator+ (int s);
    Time operator+= (int s);
    Time operator- (int s);
    Time operator-= (int s);

    bool operator== (const Time& t);
    bool operator!= (const Time& t);
    bool operator< (const Time& t);
    bool operator> (const Time& t);
    bool operator<= (const Time& t);
    bool operator>= (const Time& t);
};
