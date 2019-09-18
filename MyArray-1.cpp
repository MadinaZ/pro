#include "Array.h"

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    Array a;
    int check = 0;
    int count = 0;
    string ch,chi;
    int value = 0;
    int index = 0;
    while(chi != "Q" || chi != "q")
    {
        cout<<"Input an index and a value [Q to quit]: ";
        cin>>chi;
        if(chi == "Q" || chi == "q")
            break;
        cin>>ch;
        value = stoi(ch);
        if(isalpha(chi[0]))
            index = 0;
        else
            index = stoi(chi);
        
        a[index] = value;
    }
    
    for(int i = 0; i < 100; i++)
    {
        if(a[i] != 0)
            count++;
    }
    cout<<"You stored this many values: "<<count<<endl;
    
    cout<<"The index-value pairs are:"<<endl;
    for(int i = 0; i < 100; i++)
    {
        if(a[i] != 0)
            cout<<i<<" -> "<<a[i]<<endl;
        if(check == 1)
            cout<<i<<" -> "<<a[i]<<endl;
    }
    
    
    while(chi != "Q" || chi != "q")
    {
        cout<<"Input an index for me to look up [Q to quit]: ";
        cin>>chi;
        if(chi == "Q" || chi == "q")
            break;
        index = stoi(chi);
        if(a[index] != 0 && (index >=0 && index < 100))
            cout<<"Found it -- the value stored at "<<index<<" is "<<a[index]<<endl;
        else
            cout<<"I didn't find it \n";
    }
}

