//
// Created by maurx on 05/11/2024.
//

#include "personne.h"
#include "date.h"
#include <iostream>
#include <iomanip>

void afficher_personne(Personne personne) {
    std::cout << std::setw(13) << std::left << "Nom"            << ": " << personne.nom << std::endl
              << std::setw(13) << std::left << "Addresse"       << ": " << personne.addresse << std::endl
              << std::setw(13) << std::left << "Anniversaire"   << ": "; afficher_date(personne.anniversaire);

}