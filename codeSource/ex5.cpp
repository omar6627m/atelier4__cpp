#include <iostream>
#include <set>
#include <vector>
#include <list>

using namespace std;

bool doesExistInSet(set <int> setToTest,int target){
    // la methode count() d'un set retourner le nombre des fois 
    // un valeur est presente dans un set.
    // si la valeur est est 1, alors 'target' existe dans 'setToTest' 
    // si la valeur est 0 alors il n;existe pas.
    int temp = setToTest.count(target);
    if (temp==1)
    {
        return true;
    }
    
    return false;
}

bool anotherDoesExistInSet
    (set <int>::iterator begin,set <int>::iterator end,int target)
{
    // on utilise l'iterateurs du debut et du fin  pour traverser le set.
    // on retourne true une fois on trouve 'target'.
    // sinon on retourne false.
    for(set <int>::iterator setIterator = begin; setIterator!=end;setIterator++){
        if(*setIterator == target){
            return true;
        }
    }
    return false;
}

template <typename Iterable,typename Target,typename Iterator,typename Begin,typename End> 
bool isInField(Iterable field,Iterator iterator,Target target,Begin begin,End end){
     for(
         iterator = begin;
         iterator != end;
         iterator++
         ){
        if(*iterator == target){
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    set <int> mySet;
    set <int>::iterator setIterator;
    int target;

    // remplissage de set par des entiers a partir de 1 jusqu'a 100.
    for(int i = 1;i <= 100; i++){
        mySet.insert(i);
    }

    // demander d'un valeur de l'utilisateur:
    cout << "entrer une valeur pour la chercher dans le set\n";
    cin >> target;
    if(doesExistInSet(mySet,target)){
        cout << "l'entier " << target << " existe dans le set.\n";
    }else{
        cout << "l'entier " << target << " n'existe pas dans le set.\n";
    }

    cout << "=========utilisation d'une autre methode============\n";
     if(anotherDoesExistInSet(mySet.begin(),mySet.end(),target)){
        cout << "l'entier " << target << " existe dans le set.\n";
    }else{
        cout << "l'entier " << target << " n'existe pas dans le set.\n";
    }
    cout << "=========utilisation d'une template methode============\n";
     if(isInField(mySet,setIterator,target,mySet.begin(),mySet.end())){
        cout << "l'entier " << target << " existe dans le set.\n";
    }else{
        cout << "l'entier " << target << " n'existe pas dans le set.\n";
    }
    
    cout << "=========utilisation d'une template methode avec un vecteur de string============\n";
    vector <string> myVector = {"omar","aharrar"} ;
    vector <string>::iterator vectorIterator;
    if(isInField(myVector,vectorIterator,"omar",myVector.begin(),myVector.end())){
    cout << "la valeur " << "omar" << " existe dans le vecteur.\n";
    }else{
        cout << "la valeur " << "omar" << " n'existe pas dans le vecteur.\n";
    }

    cout << "=========utilisation d'une template methode avec un liste d'entiers============\n";
    list <int> myList;
    list <int>::iterator listIterator;
    // remplissage de liste par des entiers a partir de 1 jusqu'a 100.
    for(int i = 1;i <= 100; i++){
        myList.push_back(i);
    }
    if(isInField(myList,listIterator,target,myList.begin(),myList.end())){
    cout << "l'entier " << target << " existe dans la liste.\n";
    }else{
        cout << "l'entier " << target << " n'existe pas dans la liste.\n";
    }

    cout << "=========utilisation d'une template methode avec un tableau de floats============\n";
    float classicTable[100];
    float* classicTableIterator = classicTable;
    for(int i = 1;i <= 100;i++){
        classicTable[i-1] = i;
    }
    if(isInField(classicTable,classicTableIterator,target,&classicTable[0],&classicTable[100])){
    cout << "la valeur " << target << " existe dans la table des floats.\n";
    }else{
        cout << "la valeur " << target << " n'existe pas dans la table des floats.\n";
    }
    
    return 0;
}
