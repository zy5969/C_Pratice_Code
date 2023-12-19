/*************************************************************************
	> File Name: queue-push.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 18 Dec 2023 11:16:54 AM CST
 ************************************************************************/

#include<iostream>
#include <queue>
#include <string>
using namespace std;

struct Event
{
    int priority{};
    char data{' '};
 
    friend bool operator<(Event const& lhs, Event const& rhs)
    {
        return lhs.priority < rhs.priority;
    }
 
    friend ostream& operator<<(ostream& os, Event const& e)
    {
        return os << '{' << e.priority << ", '" << e.data << "'}";
    }
};
 
int main()
{
    priority_queue<Event> events;
 
    cout << "Fill the events queue:\t";
 
    for (auto const e : {Event{6,'L'}, {8,'I'}, {9,'S'}, {1,'T'}, {5,'E'}, {3,'N'}})
    {
        cout << e << ' ';
        events.push(e);
    }
 
    cout << "\nProcess events:\t\t";
 
    for (; !events.empty(); events.pop())
    {
        Event const& e = events.top();
        cout << e << ' ';
    }
 
    cout << '\n';
}

