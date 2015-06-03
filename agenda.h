#ifndef AGENDA
#define AGENDA

using namespace std;
#include <vector>
#include "timing.h"
#include "programmation.h"
#include "evenement.h"

using namespace TIME;

class Agenda {
private:
   vector<Programmation*> progs;
   void addItem(Programmation* t);
   Programmation* trouverProgrammation(const Evenement& e) const;

public:
   Agenda();
   ~Agenda();
   Agenda(const Agenda& a);
   Agenda& operator=(const Agenda& a);
   void ajouterProg(const Evenement& e, const Date& d, const Horaire& h);
   void supprimerProg(const Evenement& e);
   void afficherProg();

};

#endif // AGENDA

