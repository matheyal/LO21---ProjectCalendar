#ifndef PROGRAMMATION
#define PROGRAMMATION

#include "timing.h"
#include "evenement.h"

using namespace TIME;

class Programmation {
private:
    Date date;
    Horaire heure;
    const Evenement* event;
    Programmation(const Date& d, const Horaire& h, const Evenement& e):date(d),heure(h),event(&e){}
    ~Programmation();
    friend class Agenda;
public:
    Date getDate() const {return date;}
    Horaire getHoraire() const {return heure;}
    const Evenement& getEvenement() const {return *event;}

};

#endif // PROGRAMMATION

