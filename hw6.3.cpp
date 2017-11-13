#include <iostream>
#include <cctype>
#include <string> 
#include <fstream>

using namespace std;

void bubblesort(string arr[], int index);

int main()
{
    //string cd = "37. The Dying Poet- L. Gottschalk";
    string cd, array[100];
    ifstream inStream;
    
    inStream.open("songs.txt");
    int x = 0;
    while(getline(inStream, cd))
    {
        //delete the lead numbers, any periods, and any spaces so that the first word of the title is the first word of the line
        for(int i = 0; i < cd.length(); i++)
        {
            if(isdigit(cd[i]) || isspace(cd[i]) || ispunct(cd[i]))
            {
                cd.erase(i, 1);
                i--;
            }
            else if(isalpha(cd[i]))
            {   
                break;
            }
        }

        //replace any multiple spaces with a single space
        for(int j = 0; j < cd.length() - 1; j++)
        {
            if(isspace(cd[j]) && isspace(cd[j + 1]))
            {
                cd.erase(j + 1, 1);
            }
        }
    
        //replace all dash characters on any line before the end of the line by a space except the last one
        int dashCount = 0;
        for(int l = 0; l < cd.length(); l++)
        {
            if(cd.at(l) == '-')
            {
                dashCount++;
            }
        }
        int newDashCount = 0;
        for(int k = 0; k < cd.length(); k++)
        {
            if(newDashCount < dashCount - 1)
            {
                if(cd.at(k) == '-')
                {
                    cd.erase(k, 1);
                    cd.insert(k, " ");
                    newDashCount++;
                }
            }
        }
    
        //the last word in the title may have the - character with no space between it and the - character. Put the space in
        for(int b = cd.length() - 1; b >= 0; b--)
        {
            if(cd.at(b) == '-' && cd.at(b - 1) != ' ')
            {
                cd.insert(b, " ");
                break;
            }
        }
    
        //move initial words like 'A', 'An' and 'The' to just before the - character 
        string aAnOrThe;
        if(cd.substr(0, 3) == "The")
        {
            aAnOrThe = "The";
            cd.erase(0, 4);
        }
        else if(cd.substr(0, 2) == "An")
        {
            aAnOrThe = "An";
            cd.erase(0, 3);
        }
        else if(cd.substr(0, 1) == "A")
        {
            aAnOrThe = "A";
            cd.erase(0, 2);
        }
        int dashIndex = -1;
        for(int a = 0; a < cd.length(); a++)
        {
            if(cd.at(a) == '-')
            {
                dashIndex = a;
                break;
            }
        }
        cd = cd.substr(0, dashIndex) + aAnOrThe + cd.substr(dashIndex, cd.length() - dashIndex);
                     
        //move the composers' names to the beginning of the line, followed by the - character, followed by the compostition title
        int composerIndex = -1;
        dashIndex = -1;
        for(int m = cd.length() - 1; m >= 0; m--)
        {
            if(cd.at(m) == '-')
            {
                dashIndex = m;
                if(cd.at(m + 1) == ' ')
                {
                    composerIndex = m + 2;
                }
                else
                {
                    composerIndex = m + 1;
                }
                break;
            }
        }
        string temp = cd.substr(composerIndex, cd.length() - composerIndex);
        cd.erase(dashIndex, cd.length() - dashIndex);
        cd = temp + " - " + cd;
    
        //move any first initial or first and second names of the composer to after the composer's last name. If is "no author listed" should not be rearranged
        string name = temp;
        if(name != "no author listed")
        {
            int lastNameIndex = -1;
            for(int p = name.length() -1; p >= 0; p--)
            {
                if(isspace(cd[p]))
                {
                    lastNameIndex = p + 1;
                    break;
                }
            }
            string lastName = name.substr(lastNameIndex, name.length() - lastNameIndex);
            name.erase(lastNameIndex, name.length() - lastNameIndex);
            for(int q = 0; q < cd.length(); q++)
            {
                if(cd.at(q) == '-')
                {
                    dashIndex = q;
                    break;
                }
            }
            cd.erase(0, dashIndex);
            cd = lastName + ", " + name + cd;
        }
    
        //alphabetize by composer
        array[x] = cd;
        x++;
    }
    bubblesort(array, x);
    
    for(int d = 0; d < x; d++)
    {
        cout<<array[d]<<endl;
    }
    inStream.close();
    return 0;
}

void bubblesort(string arr[], int index)
{
    for(int i = index - 1; i>0; i--)
    {
        for(int j = 0; j<i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                string temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}