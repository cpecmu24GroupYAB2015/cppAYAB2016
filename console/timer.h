#ifndef TIMER_H
#define TIMER_H
class Timmer{
    private:
        int time0;
        bool activeTimeCout=true;
    public:
        Timmer();
        bool defTime(int);
};
#endif
