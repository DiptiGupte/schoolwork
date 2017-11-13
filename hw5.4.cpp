#include <iostream>

using namespace std;


int main()
{
    int arr[50], nums[50], count[50], i = 0, userInput;
    cout<<"Enter an integer (00 when complete): ";
    cin>>userInput;
    while(userInput != 00)
    {
        arr[i] = userInput;
        i++;
        cout<<"Enter an integer (00 when complete): ";
        cin>>userInput;
    }
    cout<<i<<endl;
    //sorting
    int temp, index;
    for(int j = 0; j < i; j++)
    {
        //max = arr[j];
        for(int k = 0; k < i; k++)
        {
            if(arr[k] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
        
    }
    
    //creating two column list
    for(int m = 0; m < i; m++)
    {
        nums[m] = 0;
        count[m] = 0;
    }
    nums[0] = arr[0];
    count[0]++;
    int index2 = 0;
    for(int x = 1; x < i; x++)
    {
        if(arr[x] == arr[x - 1])
        {
            while(arr[x] != nums[index2])
            {
                index2++;
            }
            count[index2]++;
        }
        else
        {
            while(count[index2] != 0)
            {
                index2++;
            }
            nums[index2] = arr[x];
            count[index2]++;
        }
        index2 = 0;
    }
    
    int size = i;
    for(int y = 0; y < i; y++)
    {
        if(nums[y] == 0)
        {
            size--;
        }
    }
    cout<<"N \t"<<"Count"<<endl;
    for(int a = 0; a < size; a++)
    {
        cout<<nums[a]<<"\t"<<count[a]<<endl;
    }
    
    return 0;
}