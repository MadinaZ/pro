//
//  main.cpp
//  hw6-1
//
//  Created by Madina Sadirmekova on 10/13/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Stack.h"
#include "Stack.h"
#include<cassert>

int main() {
    
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    Stack<int> t_int;
    
    cout<<"Stack test: (int) \n";
    cout<<"Testing Stack::size \n";
    cout<<"EXPECTED: 0 \n";
    cout<<"ACTUAL: "<<t_int.size()<<endl;
    
    cout<<"\n\n";
    
    cout<<"Testing Stack::peek & Stack:: push \n";
    cout<<"EXPECTED: 2\n";
    t_int.push(2);
    cout<<"ACTUAL: "<<t_int.peek()<<endl;
    cout<<"EXPECTED: 42\n";
    t_int.push(42);
    cout<<"ACTUAL: "<<t_int.peek()<<endl;
    cout<<"EXPECTED: 999\n";
    t_int.push(999);
    cout<<"ACTUAL: "<<t_int.peek()<<endl;
    
    
    cout<<"\n\n"<<"Testing Stack::pop \n";
    cout<<"BEFORE pop: 999 \n";
    t_int.pop();
    cout<<"AFTER pop: "<<t_int.peek()<<endl;
    cout<<"BEFORE pop: 42 \n";
    t_int.pop();
    cout<<"AFTER pop: "<<t_int.peek()<<endl;
    cout<<"BEFORE pop: 2 \n";
    t_int.pop();
    cout<<"AFTER pop: "<<t_int.peek()<<endl;
    
    t_int.push(2);
    t_int.push(429);
    
    cout<<"\n\n"<<"Testing copy constructor \n";
    Stack<int> c_int = t_int;
    for(int i = 0; i < t_int.size(); i++)
    {
        assert(t_int.peek() == c_int.peek());
        t_int.pop();
        c_int.pop();
    }
    cout<<"Pass \n";
    
    t_int.push(2);
    t_int.push(429);
    
    cout<<"\n\n"<<"Testing assignment operator \n";
    Stack<int> a_int = t_int;
    for(int i = 0; i < t_int.size(); i++)
    {
        assert(t_int.peek() == a_int.peek());
        t_int.pop();
        a_int.pop();
    }
    cout<<"Pass \n";
    cout<<"\n\n";

    cout<<"Const object test \n";
    const Stack<int> co_int;
    assert(co_int.size() == 0);
    assert(co_int.peek() == co_int.peek());
    cout<<"Pass \n";
    
    cout<<"\n\n"<<"Testing Stack::clear & empty \n";
    t_int.clear();
    assert(t_int.empty() == true);
    cout<<"Pass\n";
    cout<<"\n\n";

    //test double
    Stack<double> t_double;
    
    cout<<"Stack test: (double) \n";
    cout<<"Testing Stack::size \n";
    cout<<"EXPECTED: 0 \n";
    cout<<"ACTUAL: "<<t_double.size()<<endl;
    
    cout<<"\n\n";
    
    cout<<"Testing Stack::peek & Stack:: push \n";
    cout<<"EXPECTED: 2.2\n";
    t_double.push(2.2);
    cout<<"ACTUAL: "<<t_double.peek()<<endl;
    cout<<"EXPECTED: 42.2\n";
    t_double.push(42.2);
    cout<<"ACTUAL: "<<t_double.peek()<<endl;
    cout<<"EXPECTED: 999.2\n";
    t_double.push(999.2);
    cout<<"ACTUAL: "<<t_double.peek()<<endl;
    
    
    cout<<"\n\n"<<"Testing Stack::pop \n";
    cout<<"BEFORE pop: 999.2 \n";
    t_double.pop();
    cout<<"AFTER pop: "<<t_double.peek()<<endl;
    cout<<"BEFORE pop: 42.2 \n";
    t_double.pop();
    cout<<"AFTER pop: "<<t_double.peek()<<endl;
    cout<<"BEFORE pop: 2.2 \n";
    t_double.pop();
    cout<<"AFTER pop: "<<t_double.peek()<<endl;
    
    t_double.push(3.14);
    t_double.push(429.2);
    
    cout<<"\n\n"<<"Testing copy constructor \n";
    Stack<double> c_double = t_double;
    for(int i = 0; i < t_double.size(); i++)
    {
        assert(t_double.peek() == c_double.peek());
        t_double.pop();
        c_double.pop();
    }
    cout<<"Pass \n";
    
    t_double.push(3.14);
    t_double.push(429.2);
    
    cout<<"\n\n"<<"Testing assignment operator \n";
    Stack<double> a_double = t_double;
    for(int i = 0; i < t_double.size(); i++)
    {
        assert(t_double.peek() == a_double.peek());
        t_double.pop();
        a_double.pop();
    }
    cout<<"Pass \n";
    cout<<"\n\n";

    cout<<"Const object test \n";
    const Stack<double> co_double;
    assert(co_double.size() == 0);
    assert(co_double.peek() == co_double.peek());
    cout<<"Pass \n";
    
    cout<<"\n\n"<<"Testing Stack::clear & empty \n";
    t_double.clear();
    assert(t_double.empty() == true);
    cout<<"Pass\n";
    cout<<"\n\n";

    //test char
    Stack<char> t_char;

    cout<<"Stack test: (char) \n";
    cout<<"Testing Stack::size \n";
    cout<<"EXPECTED: 0 \n";
    cout<<"ACTUAL: "<<t_char.size()<<endl;
    
    cout<<"\n\n";
    
    cout<<"Testing Stack::peek & Stack:: push \n";
    cout<<"EXPECTED: a\n";
    t_char.push('a');
    cout<<"ACTUAL: "<<t_char.peek()<<endl;
    cout<<"EXPECTED: +\n";
    t_char.push('+');
    cout<<"ACTUAL: "<<t_char.peek()<<endl;
    cout<<"EXPECTED: B\n";
    t_char.push('B');
    cout<<"ACTUAL: "<<t_char.peek()<<endl;
    
    
    cout<<"\n\n"<<"Testing Stack::pop \n";
    cout<<"BEFORE pop: B \n";
    t_char.pop();
    cout<<"AFTER pop: "<<t_char.peek()<<endl;
    cout<<"BEFORE pop: + \n";
    t_char.pop();
    cout<<"AFTER pop: "<<t_char.peek()<<endl;
    cout<<"BEFORE pop: a \n";
    t_char.pop();
    cout<<"AFTER pop: "<<t_char.peek()<<endl;
    
    t_char.push('X');
    t_char.push('Y');
    
    cout<<"\n\n"<<"Testing copy constructor \n";
    Stack<char> c_char = t_char;
    for(int i = 0; i < t_char.size(); i++)
    {
        assert(t_char.peek() == c_char.peek());
        t_char.pop();
        c_char.pop();
    }
    cout<<"Pass \n";
    
    t_char.push('X');
    t_char.push('Y');
    
    cout<<"\n\n"<<"Testing assignment operator \n";
    Stack<char> a_char = t_char;
    for(int i = 0; i < t_int.size(); i++)
    {
        assert(t_char.peek() == a_char.peek());
        t_char.pop();
        a_char.pop();
    }
    cout<<"Pass \n";
    cout<<"\n\n";

    cout<<"Const object test \n";
    const Stack<char> co_char;
    assert(co_char.size() == 0);
    assert(co_char.peek() == co_char.peek());
    cout<<"Pass \n";
    
    cout<<"\n\n"<<"Testing Stack::clear & empty \n";
    t_char.clear();
    assert(t_char.empty() == true);
    cout<<"Pass\n";
    cout<<"\n\n";
    
    //test string
    Stack<string> t_string;

    cout<<"Stack test: (string) \n";
    cout<<"Testing Stack::size \n";
    cout<<"EXPECTED: 0 \n";
    cout<<"ACTUAL: "<<t_string.size()<<endl;
    
    cout<<"\n\n";
    
    cout<<"Testing Stack::peek & Stack:: push \n";
    cout<<"EXPECTED: a\n";
    t_string.push("one");
    cout<<"ACTUAL: "<<t_string.peek()<<endl;
    cout<<"EXPECTED: +\n";
    t_string.push("two");
    cout<<"ACTUAL: "<<t_string.peek()<<endl;
    cout<<"EXPECTED: B\n";
    t_string.push("three");
    cout<<"ACTUAL: "<<t_string.peek()<<endl;
    
    
    cout<<"\n\n"<<"Testing Stack::pop \n";
    cout<<"BEFORE pop: three \n";
    t_string.pop();
    cout<<"AFTER pop: "<<t_string.peek()<<endl;
    cout<<"BEFORE pop: two \n";
    t_string.pop();
    cout<<"AFTER pop: "<<t_string.peek()<<endl;
    
    t_string.push("Hello");
    t_string.push("World");
    
    cout<<"\n\n"<<"Testing copy constructor \n";
    Stack<string> c_string = t_string;
    for(int i = 0; i < t_string.size(); i++)
    {
        assert(t_string.peek() == c_string.peek());
        t_string.pop();
        c_string.pop();
    }
    cout<<"Pass \n";
    
    t_string.push("Hello");
    t_string.push("World");
    
    cout<<"\n\n"<<"Testing assignment operator \n";
    Stack<string> a_string = t_string;
    for(int i = 0; i < t_string.size(); i++)
    {
        assert(t_string.peek() == a_string.peek());
        t_string.pop();
        a_string.pop();
    }
    cout<<"Pass \n";
    
    cout<<"\n\n";
    cout<<"Const object test \n";
    const Stack<string> co_string;
    assert(co_string.size() == 0);
    assert(co_string.peek() == co_string.peek());
    cout<<"Pass \n";
    
    cout<<"\n\n"<<"Testing Stack::clear & empty \n";
    t_string.clear();
    assert(t_string.empty() == true);
    cout<<"Pass\n";
    cout<<"\n\n";
    
    
    return 0;
}
