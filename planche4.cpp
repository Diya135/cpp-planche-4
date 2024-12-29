#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Exercie 1:
template <typename T>
void echanger(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

template <typename T>
void trier(T arr[],int n){
    for (int i=0;i<n-1;i++){
       int minIndex=i;
        for (int j=i+1;j<n;j++){
            if (arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        echanger(arr[i],arr[minIndex]);
    }
}

int main(){
   int tableau[10]={5,2,9,1,5,6,3,8,7,4};
    trier(tableau,10);
    
    cout<<"Tableau trié: ";
    for (int i=0; i < 10; i++){
        cout<<tableau[i]<<" ";
    }
    cout<<endl;

    return 0;
}
//Exercie 2:
void afficherP(int &x,int seuil=0){
    if (x >= 0) cout<<x<<"\t";
}

void afficherN(int &x,int seuil=0){
    if (x < 0) cout<<x<<"\t";
}

void greaterThan(int &x,int seuil){
    if (x >= seuil) cout<<x<<"\t";
}

void appliquerFiltre(vector<int> &vec,void (*filtre)(int &,int)){
   int seuil=0;
    if (filtre==greaterThan){
        cout<<"Donner seuil: ";
        cin>>seuil;
    }
    for (int &e : vec){
        filtre(e, seuil);
    }
}

int main(){
    vector<int> tab{-2, 3, -33, 7, 99, 6, 2, -39};
    cout<<"************************\n";
    cout<<"* 1. Afficher positif   *\n";
    cout<<"* 2. Afficher Negatif   *\n";
    cout<<"* 3. Superieur A       *\n";
    cout<<"************************\n";
    cout<<"Entrez votre choix? \n";
    
   int choix;
    cin>>choix;
    
    switch (choix){
        case 1: appliquerFiltre(tab, afficherP); break;
        case 2: appliquerFiltre(tab, afficherN); break;
        case 3: appliquerFiltre(tab, greaterThan); break;
        default: break;
    }
    
    return 0;
}
//Exercie 3 :
int main(){
    vector<int> tab{-2, 3, -33, 7, 99, 6, 2, -39};

    cout<<"************************\n";
    cout<<"* 1. Afficher positif   *\n";
    cout<<"* 2. Afficher Negatif   *\n";
    cout<<"* 3. Superieur A       *\n";
    cout<<"************************\n";
    cout<<"Entrez votre choix? \n";
    
   int choix;
    cin>>choix;

    switch (choix){
        case 1: 
            for_each(tab.begin(), tab.end(), [](int x){ if (x >= 0) cout<<x<<"\t"; });
            break;
        case 2: 
            for_each(tab.begin(), tab.end(), [](int x){ if (x < 0) cout<<x<<"\t"; });
            break;
        case 3:{
           int seuil;
            cout<<"Donner seuil: ";
            cin>>seuil;
            for_each(tab.begin(), tab.end(), [seuil](int x){ if (x >= seuil) cout<<x<<"\t"; });
            break;
        }
        default: break;
    }
    
    return 0;
}
//Exercie 4 :
struct Produit{
 string type;
    double prixHT;
    bool solde;
};

double calculerPrix(const Produit &produit){
    double taux=(produit.type == "luxe") ? 0.25 : 0.19;
    double prixTTC=produit.prixHT * (1 + taux);
    if (produit.solde){
        prixTTC *= 0.8;
    }
    return prixTTC;
}

int main(){
    Produit produit1{"standard", 100.0, false};
    Produit produit2{"luxe", 200.0, true};

    cout<<"Prix final produit 1: "<<calculerPrix(produit1)<<"€"<<endl;
    cout<<"Prix final produit 2: "<<calculerPrix(produit2)<<"€"<<endl;

    return 0;
}