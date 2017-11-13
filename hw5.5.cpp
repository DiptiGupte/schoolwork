#include <iostream>

using namespace std;
const int SIZE = 20;
int main()
{
    char temp1[SIZE], temp2[SIZE], userInput;
    int num1[SIZE], num2[SIZE], size1, size2, sum[SIZE];;
    do
        {
        for(int n = 0; n < SIZE; n++)
        {
            temp1[n] = '0';
            temp2[n] = '0'; 
            num1[n] = 0;
            num2[n] = 0;
            sum[n] = 0;
        }
    
        cout << "Enter the size of the first integer: ";
        cin >> size1;
        cout << "Enter the size of the second integer: ";
        cin >> size2;
    
        cout <<"Enter the first integer:"<<endl;
        for(int i = 0; i < size1; i++)
        {
            cin>>temp1[i];
        }
        cout <<"Enter the second integer:"<<endl;
        for(int i = 0; i < size2; i++)
        {
            cin>>temp2[i];
        }

        int index1 = 0, index2 = 0;
        for(int j = size1 - 1; j >= 0; j--)
        {
            num1[index1] = temp1[j] - '0';
            index1++;
        }
        for(int j = size2 - 1; j >= 0; j--)
        {
            num2[index2] = temp2[j] - '0';
            index2++;
        }   
        
        int carry = 0, temp, length = 0;
        if(size1 > size2)
        {
            for(int n = size2; n < size1; n++)
            {
                num2[n] = 0;
            }
            for(int k = 0; k < size1; k++)
            {
                temp = num1[k] + num2[k] + carry;
                if(temp >= 10)
                {
                    sum[k] = temp % 10;
                    carry = temp / 10;
                }
                else
                {
                    sum[k] = temp;
                }
            }
            cout<<"sum = ";
            for(int m = size1 - 1; m >= 0; m--)
            {
                cout<<sum[m];
            }
            cout<<endl;
        }
        else
        {
            for(int n = size1; n < size2; n++)
            {
                num1[n] = 0;
            }
            for(int k = 0; k < size2; k++)
            {
                temp = num1[k] + num2[k] + carry;
                if(temp >= 10)
                {
                    sum[k] = temp % 10;
                    carry = temp / 10;
                }
                else
                {
                    sum[k] = temp;
                }
            }
            cout<<"sum = ";
            for(int m = size2 - 1; m >= 0; m--)
            {
                cout<<sum[m];
            }
            cout<<endl;
        }
        cout<<"Do you want to calculate again (y/n)? ";
        cin>>userInput;
    }
    while(userInput == 'y' || userInput =='N');
    return 0;
}