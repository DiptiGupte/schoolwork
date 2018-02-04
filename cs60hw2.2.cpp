#include <iostream>
#include <cstdlib> 
#include <cmath>

using namespace std;

class ZipCode
{
public:
    ZipCode(int zipCode);
    ZipCode(string barCode);
    void returnZipInt();
    void returnZipStr();
private:
    int z; 
    string str;
    
};

int main()
{
    string userInput;
    cout<<"Enter your zip code as a barcode as 0's and 1's: ";
    cin>>userInput;
    ZipCode zip(userInput);
    cout << "The barcode of " << userInput << " as an integer is ";
    zip.returnZipInt();
    cout<<endl;
    
    int userInput2;
    cout<<"Enter your zip code as a barcode as integer: ";
    cin>>userInput2;
    ZipCode zip2(userInput2);
    cout << "The barcode of " << userInput2 << " in 0's and 1's is ";
    zip2.returnZipStr();
    cout<<endl;
    
    return 0; 
}

ZipCode::ZipCode(int zipCode)
{
    z = zipCode;
}

ZipCode::ZipCode(string barCode)
{
    str = barCode;
}

void ZipCode::returnZipInt()
{
    int group1 = (((str[1] - 48) * 7) + ((str[2] - 48) * 4) + ((str[3] - 48) * 2) + ((str[4] - 48) * 1) + ((str[5] - 48) * 0));
    if(group1 == 11)
    {
      group1 = 0;
    }
    int group2 = (((str[6] - 48) * 7) + ((str[7] - 48) * 4) + ((str[8] - 48) * 2) + ((str[9] - 48) * 1) + ((str[10] - 48) * 0));
    if(group2 == 11)
    {
        group2 = 0;
    }
    int group3 = (((str[11] - 48) * 7) + ((str[12] - 48) * 4) + ((str[13] - 48) * 2) + ((str[14] - 48) * 1) + ((str[15] - 48) * 0));
    if(group3 == 11)
    {
        group3 = 0;
    }
    int group4 = (((str[16] - 48) * 7) + ((str[17] - 48) * 4) + ((str[18] - 48) * 2) + ((str[19] - 48) * 1) + ((str[20] - 48) * 0));
    if(group4 == 11)
    {
        group4 = 0;
    }
    int group5 = (((str[21] - 48) * 7) + ((str[22] - 48) * 4) + ((str[23] - 48) * 2) + ((str[24] - 48) * 1) + ((str[25] - 48) * 0));
    if(group5 == 11)
    {
        group5 = 0;
    }
    cout<< group1 << group2 << group3 << group4 << group5 << endl;
}

void ZipCode::returnZipStr()
{
    cout<<"1";
    int temp[5];
    for(int i = 4; i >= 0; i--)
    {
        temp[i] = z % 10;
        z = z / 10;
    }
    for(int j = 0; j < 5; j++)
    {
        if(temp[j] == 1)
        {
            cout<<"00011";
        }
        else if(temp[j] == 2)
        {
            cout<<"00101";
        }
        else if(temp[j] == 3)
        {
            cout<<"00110";
        }
        else if(temp[j] == 4)
        {
            cout<<"01001";
        }
        else if(temp[j] == 5)
        {
            cout<<"01010";
        }
        else if(temp[j] == 6)
        {
            cout<<"01100";
        }
        else if(temp[j] == 7)
        {
            cout<<"10001";
        }
        else if(temp[j] == 8)
        {
            cout<<"10010";
        }
        else if(temp[j] == 9)
        {
            cout<<"10100";
        }
        else if(temp[j] == 0)
        {
            cout<<"11000";
        }
    }
    cout<<"1"<<endl;
}