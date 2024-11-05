//
// Created by maurx on 05/11/2024.
//

#ifndef PERSONNE_H
#define PERSONNE_H
#include "date.h"

struct Personne{
    const char* nom;
    const char* addresse;
    Date anniversaire ;
};
void afficher_personne(Personne personne);
#endif //PERSONNE_H
