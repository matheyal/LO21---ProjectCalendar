#ifndef AGENDA
#define AGENDA

using namespace std;
#include <vector>
#include "timing.h"
#include "programmation.h"
#include "evenement.h"

using namespace TIME;

class Agenda {
public:
   vector<Programmation*> progs;

//public:
   void ajouterProg(const Date& d,const Horaire& h, Evenement* e);
   void supprimerProg(const Evenement& e);
   void afficherProg();

};

#endif // AGENDA

