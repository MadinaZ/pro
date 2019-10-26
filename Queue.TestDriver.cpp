//
//  main.cpp
//  Assignment-7-part-1
//
//  Created by Madina Sadirmekova on 10/19/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;
#include "Queue.h"
#include "Queue.h"
#include<cassert>

int main() {
    
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";

    Queue<int> t_int;

    cout<<"Queue test: (int) \n";
    cout<<"Testing Queue::size \n";
    cout<<"EXPECTED: 0 \n";
    cout<<"ACTUAL: "<<t_int.size()<<endl;
    cout<<"Pass \n";

    cout<<"\n\n";


    cout<<"Testing Queue::peek & Queue:: push \n";
    cout<<"EXPECTED: 2\n";
    t_int.push(2);
    cout<<"ACTUAL: "<<t_int.front()<<endl;
    t_int.push(42);
    t_int.push(999);
    cout<<"Pass \n";


    cout<<"\n\n"<<"Testing Queue::pop \n";
    cout<<"BEFORE pop: 2 \n";
    t_int.pop();
    cout<<"AFTER pop: "<<t_int.front()<<endl;
    cout<<"BEFORE pop: 42 \n";
    t_int.pop();
    cout<<"AFTER pop: "<<t_int.front()<<endl;
    cout<<"Pass \n";

    t_int.push(2);
    t_int.push(429);
    t_int.push(999);
    cout<<"\n\n";

    cout<<"Testing Queue::back \n";
    cout<<"EXPECTED: 999 \n";
    cout<<"ACTUAL: "<<t_int.back()<<endl;
    cout<<"Pass \n";

    cout<<"\n\n"<<"Testing copy constructor \n";
    Queue<int> c_int = t_int;
    for(int i = 0; i < t_int.size(); i++)
    {
        assert(t_int.front() == c_int.front());
        assert(t_int.back() == t_int.back());
        t_int.pop();
        c_int.pop();
    }
    cout<<"Pass \n";

    t_int.push(2);
    t_int.push(429);
    t_int.push(999);

    cout<<"\n\n"<<"Testing assignment operator \n";
    Queue<int> a_int = t_int;
    for(int i = 0; i < t_int.size(); i++)
    {
        assert(t_int.front() == a_int.front());
        assert(t_int.back() == a_int.back());

        t_int.pop();
        a_int.pop();
    }
    cout<<"Pass \n";
    cout<<"\n\n";

    cout<<"Const object test \n";
    const Queue<int> co_int;
    assert(co_int.size() == 0);
    assert(co_int.front() == co_int.front());
    assert(co_int.back() == co_int.back());

    cout<<"Pass \n";

    cout<<"\n\n"<<"Testing Queue::clear & empty \n";
    t_int.clear();
    assert(t_int.empty() == true);
    cout<<"Pass\n";
    cout<<"\n\n";

//test double
    Queue<double> t_double;
    
    cout<<"Queue test: (double) \n";
    cout<<"Testing Queue::size \n";
    cout<<"EXPECTED: 0 \n";
    cout<<"ACTUAL: "<<t_double.size()<<endl;
    cout<<"Pass \n";

    cout<<"\n\n";
    
    cout<<"Testing Queue::peek & Queue:: push \n";
    cout<<"EXPECTED: 2.2\n";
    t_double.push(2.2);
    t_double.push(42.2);
    t_double.push(999.2);
    cout<<"ACTUAL: "<<t_double.front()<<endl;
    cout<<"Pass \n";
    
    cout<<"\n\n"<<"Testing Queue::pop \n";
    cout<<"BEFORE pop: 2.2 \n";
    t_double.pop();
    cout<<"AFTER pop: "<<t_double.front()<<endl;
    cout<<"BEFORE pop: 42.2\n";
    t_double.pop();
    cout<<"AFTER pop: "<<t_double.front()<<endl;
    cout<<"Pass\n";

    t_double.push(2.2);
    t_double.push(-429.2);
    t_double.push(999.2);
    cout<<"\n\n";

    cout<<"Testing Queue::back \n";
    cout<<"EXPECTED: 999.2 \n";
    cout<<"ACTUAL: "<<t_double.back()<<endl;
    cout<<"Pass \n";

    cout<<"\n\n"<<"Testing copy constructor \n";
    Queue<double> c_double = t_double;
    for(double i = 0; i < t_double.size(); i++)
    {
        assert(t_double.front() == c_double.front());
        assert(t_double.back() == t_double.back());
        t_double.pop();
        c_double.pop();
    }
    cout<<"Pass \n";

    t_double.push(2.2);
    t_double.push(-429.2);
    t_double.push(999.2);

    cout<<"\n\n"<<"Testing assignment operator \n";
    Queue<double> a_double = t_double;
    for(double i = 0; i < t_double.size(); i++)
    {
        assert(t_double.front() == a_double.front());
        assert(t_double.back() == a_double.back());

        t_double.pop();
        a_double.pop();
    }
    cout<<"Pass \n";
    cout<<"\n\n";

    cout<<"Const object test \n";
    const Queue<double> co_double;
    assert(co_double.size() == 0);
    assert(co_double.front() == co_double.front());
    assert(co_double.back() == co_double.back());

    cout<<"Pass \n";

    cout<<"\n\n"<<"Testing Queue::clear & empty \n";
    t_double.clear();
    assert(t_double.empty() == true);
    cout<<"Pass\n";
    cout<<"\n\n";

    //test char
    Queue<char> t_char;
    
    cout<<"Queue test: (char) \n";
    cout<<"Testing Queue::size \n";
    cout<<"EXPECTED: 0 \n";
    cout<<"ACTUAL: "<<t_char.size()<<endl;
    cout<<"Pass \n";

    cout<<"\n\n";
    
    cout<<"Testing Queue::peek & Queue:: push \n";
    cout<<"EXPECTED: A\n";
    t_char.push('A');
    cout<<"ACTUAL: "<<t_char.front()<<endl;
    t_char.push('B');
    t_char.push('C');
    cout<<"Pass \n";

    
    cout<<"\n\n"<<"Testing Queue::pop \n";
    cout<<"BEFORE pop: A \n";
    t_char.pop();
    cout<<"AFTER pop: "<<t_char.front()<<endl;
    cout<<"BEFORE pop: B \n";
    t_char.pop();
    cout<<"AFTER pop: "<<t_char.front()<<endl;
    cout<<"Pass \n";

    t_char.push('A');
    t_char.push('B');
    t_char.push('C');
    cout<<"\n\n";

    cout<<"Testing Queue::back \n";
    cout<<"EXPECTED: C \n";
    cout<<"ACTUAL: "<<t_char.back()<<endl;

    cout<<"\n\n"<<"Testing copy constructor \n";
    Queue<char> c_char = t_char;
    for(char i = 0; i < t_char.size(); i++)
    {
        assert(t_char.front() == c_char.front());
        assert(t_char.back() == t_char.back());
        t_char.pop();
        c_char.pop();
    }
    cout<<"Pass \n";

    t_char.push('A');
    t_char.push('B');
    t_char.push('C');

    cout<<"\n\n"<<"Testing assignment operator \n";
    Queue<char> a_char = t_char;
    for(char i = 0; i < t_char.size(); i++)
    {
        assert(t_char.front() == a_char.front());
        assert(t_char.back() == a_char.back());

        t_char.pop();
        a_char.pop();
    }
    cout<<"Pass \n";
    cout<<"\n\n";

    cout<<"Const object test \n";
    const Queue<char> co_char;
    assert(co_char.size() == 0);
    assert(co_char.front() == co_char.front());
    assert(co_char.back() == co_char.back());

    cout<<"Pass \n";

    cout<<"\n\n"<<"Testing Queue::clear & empty \n";
    t_char.clear();
    assert(t_char.empty() == true);
    cout<<"Pass\n";
    cout<<"\n\n";

//test string
    
    Queue<string> t_string;
    
    cout<<"Queue test: (string) \n";
    cout<<"Testing Queue::size \n";
    cout<<"EXPECTED: 0 \n";
    cout<<"ACTUAL: "<<t_string.size()<<endl;
    cout<<"Pass \n";

    cout<<"\n\n";
    
    cout<<"Testing Queue::peek & Queue:: push \n";
    cout<<"EXPECTED: Hello\n";
    t_string.push("Hello");
    cout<<"ACTUAL: "<<t_string.front()<<endl;
    t_string.push("World");
    t_string.push("!!!");
    cout<<"Pass \n";

    
    cout<<"\n\n"<<"Testing Queue::pop \n";
    cout<<"BEFORE pop: Hello \n";
    t_string.pop();
    cout<<"AFTER pop: "<<t_string.front()<<endl;
    cout<<"BEFORE pop: World \n";
    t_string.pop();
    cout<<"AFTER pop: "<<t_string.front()<<endl;
    cout<<"Pass \n";

    t_string.push("Hello");
    t_string.push("World");
    t_string.push("!!!");
    cout<<"\n\n";

    cout<<"Testing Queue::back \n";
    cout<<"EXPECTED: !!! \n";
    cout<<"ACTUAL: "<<t_string.back()<<endl;
    

    cout<<"\n\n"<<"Testing copy constructor \n";
    Queue<string> c_string = t_string;
    while(!t_string.empty())
    {
        assert(t_string.front() == c_string.front());
        assert(t_string.back() == t_string.back());
        t_string.pop();
        c_string.pop();
    }
    cout<<"Pass \n";

    t_string.push("Hello");
    t_string.push("World");
    t_string.push("!");

    cout<<"\n\n"<<"Testing assignment operator \n";
    Queue<string> a_string = t_string;
    while(!t_string.empty())
    {
        assert(t_string.front() == a_string.front());
        assert(t_string.back() == a_string.back());

        t_string.pop();
        a_string.pop();
    }
    cout<<"Pass \n";
    cout<<"\n\n";

    cout<<"Const object test \n";
    const Queue<string> co_string;
    assert(co_string.size() == 0);
    assert(co_string.front() == co_string.front());
    assert(co_string.back() == co_string.back());

    cout<<"Pass \n";

    cout<<"\n\n"<<"Testing Queue::clear & empty \n";
    t_string.clear();
    assert(t_string.empty() == true);
    cout<<"Pass\n";
    cout<<"\n\n";
    return 0;
}
