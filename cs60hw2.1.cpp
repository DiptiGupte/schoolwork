#include <iostream>
#include <vector> 
#include <cstdlib>

using namespace std;

/* program plan:
 * declare variable of vector type to store an array of elements
 * read the number of suiters is to be inserted in vector from the user
 * initialise the values into vector variable using push_back function
 * erase every 3rd suiter in a vector using erase function and countinue counting from the next suiter
 * display the last suiter after all suiters are eliminated
 */

int wantedPos(vector<int> theVector);

int main()
{
    vector<int> v;
    
    int numOfSuiters;
    cout<<"Enter number of suiters: ";
    cin>>numOfSuiters;
    int i = numOfSuiters;
    int suiter = 1;
    
    while(i > 0)
    {
        v.push_back(suiter);
        suiter++;
        i--;
    }
    int pos = wantedPos(v);
    
    cout<<"For that many suiters, you should be number "<< pos << " in line."<<endl;
    
    return 0;
}

int wantedPos(vector<int> theVector)
{
    while(theVector.size() > 1)
    {
        for(int j = 2; j < theVector.size(); j = (j + 2) % theVector.size())
        {
            for(int k = 0; k < theVector.size(); k++)
            {
                cout<<theVector[k]<<" ";
            }
            cout<<endl;
            theVector.erase(theVector.begin() + j);

            if(theVector.size() == 1)
            {
                break;
            }
        }
    }
    int winner = theVector[0];
    cout<<winner<<endl;
    return winner;
}

