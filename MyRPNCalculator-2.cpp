//
//  main.cpp
//  HW6-2-2
//
//  Created by Madina Sadirmekova on 10/10/19.
//  Copyright © 2019 Madina Sadirmekova. All rights reserved.
//

#include<string>
#include <iostream>
using namespace std;
#include"Stack.h"
#include<cctype>


int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    Stack<double> num;
    double first, second;
    string line;
    double value;
    char c[15];
    
    while(c[0] != 'q' && c[0] != 'Q')
    {
        Stack<double> copy = num;
        
        cout<<"Enter: ";
        while(copy.size() > 0)
        {
            cout<<copy.peek()<<" ";
            copy.pop();
        }
        
        cin>>c;
        
        if(isdigit(c[0]) || isdigit(c[1]))
        {
            value = atof(c);
            num.push(value);
        }
        else
        {
            switch(c[0])
            {
                    
                case '+':
                    if(num.size() >= 2)
                    {
                        first = num.peek();
                        num.pop();
                        second = num.peek();
                        num.pop();
                        num.push(first + second);
                        //                cout<<num.peek()<<endl;
                    }
                    break;
                case '-':
                    if(num.size() >= 2)
                    {
                        first = num.peek();
                        num.pop();
                        second = num.peek();
                        num.pop();
                        num.push(second - first);
                    }
                    break;
                case '*':
                    if(num.size() >= 2)
                    {
                        first = num.peek();
                        num.pop();
                        second = num.peek();
                        num.pop();
                        num.push(first * second);
                    }
                    break;
                case '/':
                    if(num.size() >= 2)
                    {
                        first = num.peek();
                        num.pop();
                        second = num.peek();
                        num.pop();
                        num.push(second / first);
                    }
                    break;
            }
        }
        
    }
    return 0;
}
