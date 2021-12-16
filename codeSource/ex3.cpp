#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    // creation d'un instance de classe List:
    list <int> myList;
    list <int>::iterator itr;
    int temp;

    for (int i = 0; i < 5; i++)
    {
        cout << "entre le valeur " << i << " de la list:\n";
        cin >> temp;
        myList.push_back(temp);
    }
    
    myList.sort(); //triage de la liste

    // affichage de la liste: 
    cout << "la liste des entiers entre triee:\n";
    for(itr=myList.begin();itr!=myList.end();itr++){
        cout << *itr << endl;
    }
    
    return 0;
}
