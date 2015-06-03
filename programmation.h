#ifndef PROGRAMMATION
#define PROGRAMMATION

#include "timing.h"
#include "evenement.h"

using namespace TIME;

class Programmation {
private:
    Date date;
    Horaire heure;
    Evenement* event;
public:
    Programmation(const Date& d, const Horaire& h, Evenement* e):date(d),heure(h),event(e){}
    Date getDate() const {return date;}
    Horaire getHoraire() const {return heure;}
    Evenement* getEvenement() {return event;}

};

#endif // PROGRAMMATION

