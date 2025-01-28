#include <array>
#include <string>

using namespace std;

enum class  Day { ERROR,   LUNDI,   MARDI,   MERCREDI,   JEUDI,   VENDREDI,   SAMEDI,   DIMANCHE};
const array DAY {"ERROR", "LUNDI", "MARDI", "MERCREDI", "JEUDI", "VENDREDI", "SAMEDI", "DIMANCHE"};

Day stringToDay(const string& s) {
    for (int i = 1; i < DAY.size(); ++i) {
        if(DAY[i] == s)
            return Day(i);
    }
    return Day::ERROR;
}

string dayToString(const Day& d) {
    if (d >= Day::LUNDI && d <= Day::DIMANCHE)
        return DAY[(size_t)d];
    return DAY[(int)Day::ERROR];
}

