#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <algorithm>

void demonstrateVector() {
    std::cout << "\n==== VECTOR DEMONSTRATION ====\n";
    std::vector<int> vec = {10, 20, 30, 40};

    vec.push_back(50);  // Add element at end
    vec.insert(vec.begin() + 2, 25);  // Insert at specific position
    vec.pop_back();  // Remove last element
    vec.erase(vec.begin());  // Remove first element

    std::cout << "Vector Elements: ";
    for (int v : vec) std::cout << v << " ";
    
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity();
    vec.resize(6, 100);
    std::cout << "\nAfter Resize: ";
    for (int v : vec) std::cout << v << " ";

    std::cout << "\nFront: " << vec.front() << ", Back: " << vec.back();
    std::sort(vec.begin(), vec.end());
    std::cout << "\nSorted Vector: ";
    for (int v : vec) std::cout << v << " ";
}

void demonstrateQueue() {
    std::cout << "\n\n==== QUEUE DEMONSTRATION ====\n";
    std::queue<int> q;
    q.push(10); q.push(20); q.push(30); 

    std::cout << "Front: " << q.front() << ", Back: " << q.back();
    q.pop();
    std::cout << "\nAfter pop, Front: " << q.front();
}

void demonstrateStack() {
    std::cout << "\n\n==== STACK DEMONSTRATION ====\n";
    std::stack<int> s;
    s.push(10); s.push(20); s.push(30);

    std::cout << "Top: " << s.top();
    s.pop();
    std::cout << "\nAfter pop, Top: " << s.top();
}

void demonstrateDeque() {
    std::cout << "\n\n==== DEQUE DEMONSTRATION ====\n";
    std::deque<int> d;
    d.push_back(10); d.push_front(20); d.push_back(30);

    std::cout << "Front: " << d.front() << ", Back: " << d.back();
    d.pop_front();
    std::cout << "\nAfter pop_front, Front: " << d.front();
}

void demonstrateList() {
    std::cout << "\n\n==== LIST DEMONSTRATION ====\n";
    std::list<int> lst = {10, 20, 30};
    lst.push_front(5);
    lst.push_back(40);

    std::cout << "List Elements: ";
    for (int v : lst) std::cout << v << " ";

    lst.reverse();
    std::cout << "\nReversed List: ";
    for (int v : lst) std::cout << v << " ";
}

void demonstratePriorityQueue() {
    std::cout << "\n\n==== PRIORITY QUEUE DEMONSTRATION ====\n";
    std::priority_queue<int> pq;
    pq.push(10); pq.push(30); pq.push(20);

    std::cout << "Top Element: " << pq.top();
    pq.pop();
    std::cout << "\nAfter pop, Top Element: " << pq.top();
}

int main() {
    demonstrateVector();
    demonstrateQueue();
    demonstrateStack();
    demonstrateDeque();
    demonstrateList();
    demonstratePriorityQueue();
    return 0;
}
