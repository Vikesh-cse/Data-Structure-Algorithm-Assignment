#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool can_attend_all(vector<pair<int, int>> events) {

    sort(events.begin(), events.end());

    for (int i = 1; i < events.size(); i++) {

        if (events[i].first < events[i - 1].second)
            return false;
    }

    return true;
}

int min_rooms_required(vector<pair<int, int>> events) {

    if (events.empty())
        return 0;

    sort(events.begin(), events.end());

    priority_queue<
        int,
        vector<int>,
        greater<int>
    > minHeap;

    minHeap.push(events[0].second);

    for (int i = 1; i < events.size(); i++) {

        int start = events[i].first;
        int end = events[i].second;

        if (start >= minHeap.top()) {
            minHeap.pop();
        }

        minHeap.push(end);
    }

    return minHeap.size();
}

int main() {

    vector<pair<int, int>> events = {
        {9, 10},
        {9, 12},
        {10, 11},
        {11, 12}
    };

    cout << "Can attend all: "
         << (can_attend_all(events) ? "True" : "False")
         << endl;

    cout << "Minimum rooms required: "
         << min_rooms_required(events)
         << endl;

    return 0;
}
