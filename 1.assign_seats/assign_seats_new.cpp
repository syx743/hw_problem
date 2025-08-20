#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define PII pair<int, int>
int maxseatsfunc(int seat, int station, int person, vector<PII> &bookings)
{
    sort(bookings.begin(), bookings.end(), [](const PII &a, const PII &b)
         { return (a.second - a.first) > (b.second - b.first); });
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < seat; i++)
    {
        heap.push(0);
    }
    int total = 0;
    for (const auto &booking : bookings)
    {
        int a = booking.first, b = booking.second;
        if (heap.top() <= a)
        {
            int temp = heap.top();
            heap.pop();
            total += (b - a);
            heap.push(b);
        }
    }
}
int main()
{
    int seat, station, person;
    cin >> seat >> station >> person;
    vector<PII> bookings(person);
    for (int i = 0; i < person; i++)
    {
        cin >> bookings[i].first >> bookings[i].second;
    }
    cout << maxseatsfunc(seat, station, person, bookings) << endl;
    system("pause");
    return 0;
}
