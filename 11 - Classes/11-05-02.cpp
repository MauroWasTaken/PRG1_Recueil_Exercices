#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

class Voiture{
    static double prix_essence;
    double capacite_max, capacite;
    const double consommation_moy;
    friend void afficherVoiture(const Voiture& voiture);
public:
    Voiture(double capacite, double consommation_moy):capacite_max(int(capacite)),capacite(capacite),consommation_moy(consommation_moy){}
    double effectuerTrajet(double distance){
        double litres_essence = distance * consommation_moy / 100.0;
        capacite = capacite - litres_essence;
        while (capacite < 0) {
            capacite += capacite_max;
        }
        return litres_essence * prix_essence;
    }
    static double getPrixEssence(){
        return prix_essence;
    }
    static void setPrixEssence(double prix){
        prix_essence = prix;
    }
};



double Voiture::prix_essence = 1.70;

void afficherPrixEssence(double prix_essence){
    cout << "Prix de l'essence : " << prix_essence  << " CHF"<< endl;
}
void afficherVoiture(const Voiture& voiture){
    cout << "Capacite du reservoir [l]      : " << voiture.capacite_max << endl;
    cout << "Consommation moyenne [l/100km] : " << voiture.consommation_moy << endl;
    cout << "Nb litres restants             : " << voiture.capacite << endl;
}
void afficherCoutTrajet(double prix){
    cout << "Cout du trajet : " << prix  << " CHF"<< endl;

}

int main() {

    afficherPrixEssence(Voiture::getPrixEssence());

    Voiture::setPrixEssence(1.95);
    afficherPrixEssence(Voiture::getPrixEssence());

    Voiture v(52, 6.7);

    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(1000));
    afficherVoiture(v);
    afficherCoutTrajet(v.effectuerTrajet(200));
    afficherVoiture(v);

    return EXIT_SUCCESS;
}