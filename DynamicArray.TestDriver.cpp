#include<iostream>
#include<string>
#include <cassert>
#include "DynamicArray.h"
#include "DynamicArray.h"

using namespace std;

int main()
{
    cout<<"Programmer: Madina Sadirmekova \n";
    cout<<"Programmer's ID: 1736270 \n";
    cout<<"file: "<<__FILE__<<"\n\n";
    
    DynamicArray<int> a;
    DynamicArray<double> b;
    DynamicArray<char> c;
    DynamicArray<string> d;
    
    a.capacity(100);
    cout<<"Testing DynamicArray::capacity \n";
    cout<<"EXPECTED: 100\n";
    cout<<"ACTUAL: "<<a.capacity()<<endl;
    assert(100 == a.capacity());
    cout<<"Pass \n";
    
    cout<<"Testing DynamicArray<T>::DynamicArray(int cap) \n";
    for(int i = 0; i < a.capacity(); i++)
        assert(a[i] == 0);
    cout<<"Pass \n";
    
    //test for int values
    cout<<"Testing the Array::operator[ ]setter \n";
    a[105] = 34;
    a[5] = 666;
    cout<<"EXPECTED: 34 for a[105]"<<endl;
    cout<<"ACTUAL: "<<a[105]<<endl;
    assert(34 == a[105]);
    cout<<"EXPECTED: 666 for a[5]"<<endl;
    cout<<"ACTUAL: "<<a[5]<<endl;
    assert(666 == a[5]);
    cout<<"Pass \n";
    cout<<"EXPECTED: the new capacity for a is 200*2 \n";
    a.capacity(200 * 2);
    cout<<"ACTUAL: "<<a.capacity()<<endl;
    assert(400 == a.capacity());
    
    cout<<"Testing the Array::operator[ ]getter \n";
    const DynamicArray<int> za = a;
    for(int i = 0; i < a.capacity(); i++)
        assert(a[i] == za[i]);
    cout<<"Pass \n";
    
    cout<<"Const object test \n";
    const DynamicArray<int> coa;
    assert(coa.capacity());
    assert(coa[0] == coa[0]);
    assert(coa[-1] == coa[-1]);
    cout<<"Pass \n";
    
    cout<<"Object copy test \n";
    DynamicArray<int> xa = a;
    assert(xa.capacity() == a.capacity());
    for(int i = 0; i < a.capacity(); i++)
        assert(a[i] == xa[i]);
    a[0]++;
    assert(a[0] != xa[0]);
    cout<<"Pass \n";
    
    cout<<"Object assignment test \n";
    DynamicArray<int> ya = a;
    assert(ya.capacity() == a.capacity());
    for(int i = 0; i < a.capacity(); i++)
        assert(ya[i] == a[i]);
    cout<<"Pass \n";
    cout<<"NOW CAPACITY: "<<a.capacity()<<endl;

//test for doubles
    b[35] = 2.2;
    b[56] = -48.2;
    b[-1000] = 666.6;

    cout<<"EXPECTED: 2.2 for b[35]"<<endl;
    cout<<"ACTUAL: "<<b[35]<<endl;
    assert(2.2 == b[35]);
    cout<<"EXPECTED: -48.2 for b[56]"<<endl;
    cout<<"ACTUAL: "<<b[56]<<endl;
    assert(-48.2 == b[56]);
    cout<<"EXPECTED: 666.6 for b[-1000]"<<endl;
    cout<<"ACTUAL: "<<b[-1000]<<endl;
    assert(666.6 == b[-1000]);
    cout<<"Pass \n";
    
    cout<<"Testing the Array::operator[ ]getter \n";
    const DynamicArray<double> xb = b;
    for(int i = 0; i < b.capacity(); i++)
        assert(b[i] == xb[i]);
    cout<<"Pass \n";
    
    cout<<"Const object test \n";
    const DynamicArray<double> cob;
    assert(cob.capacity());
    assert(cob[0] == cob[0]);
    assert(cob[-1] == cob[-1]);
    cout<<"Pass \n";
    
    cout<<"Object copy test \n";
    DynamicArray<double> yb = b;
    assert(yb.capacity() == b.capacity());
    for(int i = 0; i < b.capacity(); i++)
        assert(b[i] == yb[i]);
    b[0]++;
    assert(b[0] != yb[0]);
    cout<<"Pass \n";
    
    cout<<"Object assignment test \n";
    DynamicArray<double> zb = b;
    assert(zb.capacity() == b.capacity());
    for(int i = 0; i < b.capacity(); i++)
        assert(zb[i] == b[i]);
    cout<<"Pass \n";
    
    cout<<"NOW CAPACITY: "<<b.capacity()<<endl;

    //test for char-------------
    c[42] = 'C';
    c[500] = '*';

    cout<<"EXPECTED: C for c[42]"<<endl;
    cout<<"ACTUAL: "<<c[42]<<endl;
    assert('C' == c[42]);
    cout<<"EXPECTED: * for c[500]"<<endl;
    cout<<"ACTUAL: "<<c[500]<<endl;
    assert('*' == c[500]);
    
    cout<<"Testing the Array::operator[ ]getter \n";
    const DynamicArray<char> xc = c;
    for(int i = 0; i < c.capacity(); i++)
        assert(c[i] == xc[i]);
    cout<<"Pass \n";
    
    cout<<"Const object test \n";
    const DynamicArray<char> coc;
    assert(coc.capacity());
    assert(coc[0] == coc[0]);
    assert(coc[-1] == coc[-1]);
    cout<<"Pass \n";
    
    cout<<"Object copy test \n";
    DynamicArray<char> yc = c;
    assert(yc.capacity() == c.capacity());
    for(int i = 0; i < c.capacity(); i++)
        assert(yc[i] == c[i]);
    c[0]++;
    assert(c[0] != yc[0]);
    cout<<"Pass \n";
    
    cout<<"Object assignment test \n";
    DynamicArray<char> zc = c;
    assert(zc.capacity() == c.capacity());
    for(int i = 0; i < c.capacity(); i++)
        assert(zc[i] == c[i]);
    cout<<"Pass \n";
    
    cout<<"NOW CAPACITY: "<<c.capacity()<<endl;


    //test for string
    d[125] = "one hundred";
    d[90] = "ninety";
    
    cout<<"EXPECTED: one hundred for d[125]"<<endl;
    cout<<"ACTUAL: "<<d[125]<<endl;
    assert("one hundred" == d[125]);
    cout<<"EXPECTED: ninety for d[90]"<<endl;
    cout<<"ACTUAL: "<<d[90]<<endl;
    assert("ninety" == d[90]);

    cout<<"Testing the Array::operator[ ]getter \n";
    const DynamicArray<string> xd = d;
    for(int i = 0; i < d.capacity(); i++)
        assert(d[i] == xd[i]);
    cout<<"Pass \n";
    
    cout<<"Const object test \n";
    const DynamicArray<string> cod;
    assert(cod.capacity());
    assert(cod[0] == cod[0]);
    assert(cod[-1] == cod[-1]);
    cout<<"Pass \n";
    
    cout<<"Object copy test \n";
    DynamicArray<string> yd = d;
    assert(yd.capacity() == d.capacity());
    for(int i = 0; i < d.capacity(); i++)
        assert(yd[i] == d[i]);
    d[0] = "abc";
    assert(d[0] != yd[0]);
    cout<<"Pass \n";
    
    cout<<"Object assignment test \n";
    DynamicArray<string> zd = d;
    assert(zd.capacity() == d.capacity());
    for(int i = 0; i < d.capacity(); i++)
        assert(zd[i] == d[i]);
    cout<<"Pass \n";
    
    cout<<"NOW CAPACITY: "<<d.capacity()<<endl;

    return 0;
}
