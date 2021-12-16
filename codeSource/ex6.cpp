#include <iostream>
#include <stdexcept>

using namespace std;

class Test{
    public:
    static int tableau[] ;
    public :
    static int division(int indice, int diviseur){
        if (diviseur==0)
        {
            throw invalid_argument("Erreur, division par 0!") ; 
        }
        
        return tableau[indice]/diviseur;
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5} ;

int main()
{
    int x, y;
    cout << "Entrez l’indice de l’entier à diviser: " << endl;
    cin >> x ;
    cout << "Entrez le diviseur: " << endl;
    cin >> y ;
    
    try
    {
        int temp = Test::division(x,y); 
        cout << "Le résultat de la division est: "<< endl;
        cout << temp << endl;
    }
    catch(invalid_argument e)
    {
        cerr << e.what() << '\n';
    }
    
    return 0;
}