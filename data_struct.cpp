#include <vector>

#include <iostream>

#include <string>

#include <cassert>

using namespace std;

// 1. Stack Implementation (LIFO)
template <typename T>
class Stack 
{
    private:
        vector<T> data;

    public:

        //for push_back I can just do .push_back for T
        void push(const T& value) 
        {
            data.push_back(value);
        }

        //pop_back
        T pop() 
        {
            if (data.empty()) 
            {
                cout << "Error: Stack underflow.\n";
                return T{};
            }

            T top_element = data.back();

            data.pop_back();

            return top_element;
        }

};

//2) Queue Implementation (FIFO)
template <typename T>

class Queue 
{
    private:
        vector<T> data;

    public:
        void push(const T& value) {
            data.push_back(value);
        }

        T pop() 
        {
            if (data.empty()) 
            {
                cout << "Error: Queue underflow.\n";
                return T{};
            }
            T front_element = data.front();

            data.erase(data.begin()); //shifting elements left

            return front_element;
        }

};

//quack
template <typename T>

class Quack 
{
    private:
        vector<T> data;

    public:
        void push_front(const T& value) 
        {
            data.insert(data.begin(), value); //this one allows shifting right
        }

        void push_back(const T& value) 
        {
            data.push_back(value); //normal pushback
        }

        T pop_front() 
        {
            if (data.empty()) 
            {
                cout << "Error: Quack underflow (front).\n";
                return T{};
            }
            T front_element = data.front();

            data.erase(data.begin());

            return front_element;
        }

        T pop_back() 
        {
            if (data.empty()) 
            {
                cout << "Error: Quack underflow (back).\n";
                return T{};
            }

            T back_element = data.back();
            data.pop_back();
            return back_element;
        }


};


int main() 
{
    //test 1 fifo
    cout << "int stack test \n";

    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    //Popped expected 30
    assert(intStack.pop() == 30);
    //Popped expected 20
    assert(intStack.pop() == 20);

    // test 2 queue fifo
    cout << "testing fifo queue\n";

    Queue<int> intQueue;
    intQueue.push(100);
    intQueue.push(200);
    intQueue.push(300);

    //pop expected 100
    assert(intQueue.pop() == 100);
    //pop expected 200
    assert(intQueue.pop() == 200);

    //last test 3 for "quack"
    cout << "testing quack!\n";

    Quack<string> stringQuack;
    stringQuack.push_back("Apple");
    stringQuack.push_front("Banana");
    stringQuack.push_back("Cherry");

    //current state from front to back should be banana apple cherry 

    assert(stringQuack.pop_front() == "Banana");

    assert(stringQuack.pop_back() == "Cherry");

    assert(stringQuack.pop_front() == "Apple");

    cout << "if you see this it works!";


}

