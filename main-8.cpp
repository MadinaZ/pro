#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void linearSearch(int a[],int SIZE, int target)
{
    int i = 0;
    int count = 0;
    for(i = 0; i < SIZE;i++)
    {
        if(a[i] == target)
        {
            cout << target <<setw(15)<< i << endl;
            count = i;
            i = SIZE;
        }
    }
    
    if (a[count] != target)
        cout<<target<<setw(20)<<" Not found\n";
    
}

int binarySearch(int arr[],int SIZE, int target[],int SIZE2)
{
    int comp= 0;
    int first = 0,
    last = SIZE-1,
    mid= (first+last)/2;
    bool found = false;
    
    while(!found && mid != first && mid!= last)
    {
        if(arr[mid] == target[SIZE2]){
            found = true;
            comp++;
        }
        else if (target[SIZE2]>arr[mid]){
            comp++;
            first = mid;
            mid = (first+last)/2;
        }
        else if (target [SIZE2]< arr[mid]){
            comp++;
            last = mid;
            mid = (first+last)/2;
        }
    }
    if (found)
        return comp;
    else
        return -1;
}


int main()
{
    const int size = 1000;
    int arr1[size];
    const int size2 = 5;
    int arr2[size2];
    
    int i = 0;
    srand(time(0));
    for(i = 0; i < size;i++)
    {
        arr1[i] = rand()%2000;
    }
    
    for(i = 0; i < size2;i++)
    {
        arr2[i] = rand()%2000;
        //cin>>arr1[i];
    }
    
    int min;
    for(int i = 0; i < size;i++)
    {
        for(int j = i + 1; j <= size;j++)
        {
            min = i;
            if(arr1[j] < arr1[i])
                swap(arr1[j],arr1[i]);
        }
        //cout<<arr1[min]<<" ";
    }
    cout<<"Value "<<setw(17)<<"Comparisons"<<endl;
    for(i = 0; i < size2;i++)
    {
        linearSearch(arr1,size,arr2[i]);
    }
    cout<<"-----------------------"<<endl;
    
    cout<<"Value "<<setw(17)<<"Comparisons"<<endl;
    
    for(i = 0; i < size2;i++)
    {
        int d = binarySearch(arr1,size,arr2,i);
        if(d == -1)
            cout<<arr2[i]<<setw(20)<<"Not found\n";
        else
            cout<<arr2[i]<<setw(20)<<d<<endl;
    }
    cout<<endl;
    
    
    return 0;
}


