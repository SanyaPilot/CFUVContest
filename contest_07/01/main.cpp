#include <iostream>

struct Time{
    short hours;
    short minutes;
    short seconds;
    
    void addSeconds(short count){
        seconds += count;
        if (seconds >= 60){
            count = seconds / 60;
            seconds %= 60;
        } else return;
        
        minutes += count;
        if (minutes >= 60){
            count = minutes / 60;
            minutes %= 60;
        } else return;
        
        hours += count;
        if (hours >= 60)
            hours = minutes = seconds = 0;
    }
};

bool operator==(const Time& lhs, const Time& rhs){
    return lhs.hours == rhs.hours &&
           lhs.minutes == rhs.minutes &&
           lhs.seconds == rhs.seconds;
}

bool operator!=(const Time& lhs, const Time& rhs){
    return not (lhs == rhs);
}

bool operator<(const Time& lhs, const Time& rhs){
    return lhs.hours * 3600 + lhs.hours * 60 + lhs.seconds < rhs.hours * 3600 + rhs.hours * 60 + rhs.seconds;
}

class IRunnable{
public:
    virtual void run() = 0;
};

class IClock{
public:
    virtual void add(IRunnable* client, Time time) = 0;
    virtual bool next() = 0;
};

// Начало вставленного кода
#include <queue>
class OSUpdater : public IRunnable {
public:
    void run() {
        std::cout << "OSUpdater\n";
    }
};

class Alarm : public IRunnable {
public:
    void run() {
        std::cout << "Alarm\n";
    }
};

class ActivityChecker : public IRunnable {
public:
    void run() {
        std::cout << "ActivityChecker\n";
    }
};

class Clock : public IRunnable, public IClock {
private:
    std::queue<std::pair<Time, IRunnable*>> tasks;
public:
    void add(IRunnable* client, Time time) {
        tasks.push({time, client});
    }
    bool next() {
        if (tasks.empty()) {
            return false;
        }
        auto cur = tasks.front();
        tasks.pop();
        std::string hours, minutes, seconds;
        if (cur.first.hours < 10) {
            hours = "0";
        }
        hours += std::to_string(cur.first.hours);
        if (cur.first.minutes < 10) {
            minutes = "0";
        }
        minutes += std::to_string(cur.first.minutes);
        if (cur.first.seconds < 10) {
            seconds = "0";
        }
        seconds += std::to_string(cur.first.seconds);
        std::cout << hours << ":" << minutes << ":" << seconds << " ";
        cur.second->run();
        return true;
    }
    void run() {
        while(next());
    }
};
// Конец вставленного кода

int main(){
    int monentum;
    std::cin >> monentum;
    srand(monentum);  // Фиксируем случайность
    
    IClock* clock = new Clock;
    IRunnable* timer = (Clock*)clock;
    
    Time t = {0, 0, 0}, midnight = {0, 0, 0};
    
    do{
        int type = rand() % 3;
        if (type == 0) clock->add(new OSUpdater, t);
        else if (type == 1) clock->add(new Alarm, t);
        else if (type == 2) clock->add(new ActivityChecker, t);
        t.addSeconds(3600 + rand() % 3600);
    }while(t != midnight);
    
    timer->run();
}
