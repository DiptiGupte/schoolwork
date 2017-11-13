#include <iostream>

using namespace std;

void deleteRepeats(char a[], int size);

int main()
{
    int index = 0;
    char arr[100], userInput;
    cout<<"Enter a lower case character (A when complete): ";
    cin>>userInput;
    while(userInput != 'A')
    {
        arr[index] = userInput;
        index++;
        cout<<"Enter a lower case character (A when complete): ";
        cin>>userInput;
    }
    deleteRepeats(arr, index);
    return 0;
}

void deleteRepeats(char a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(a[i] == a[j])
            {
                a[j] = 0;
            }
        }
    }
    int index = size;
    for(int m = 0; m < size; m++)
    {
        if(a[m] == 0)
        {
            for(int n = m; n < size - 1; n++)
            {
                a[n] = a[n+1];
            }
            index--;
        }
    }
    for(int k = 0; k < index; k++)
    {
        cout<<a[k]<<endl;
    }
}