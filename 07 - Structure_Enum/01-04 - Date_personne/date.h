//
// Created by maurx on 05/11/2024.
//

#ifndef DATE_H
#define
enum Liste_Mois {JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET,
                    AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE};
struct Date {
    int jour;
    int mois;
    int annee;
};
void afficher_date(Date date);
#endif //DATE_H
