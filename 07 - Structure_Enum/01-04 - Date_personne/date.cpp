//
// Created by maurx on 05/11/2024.
//

#include "date.h"
#include <iostream>

void afficher_date(Date date) {
    const char seperator = '.';
    std::cout << date.jour << seperator << date.mois << seperator << date.annee;
}

bool est_bissextile(Date date) {
    return date.annee % 400 || (date.annee % 100 && date.annee % 4 == 0);
}
int nb_jours(Date date) {
    switch (date.mois) {
        case FEVRIER: return est_bissextile(date) ? 29 : 28;
        case JANVIER:
        case MARS:
        case MAI:
        case JUILLET:
        case AOUT:
        case OCTOBRE:
        case DECEMBRE: return 31;
        default: return 30;
    }
}