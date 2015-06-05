#ifndef TACHEPREEMPTABLE
#define TACHEPREEMPTABLE

#include "timing.h"
#include "tacheunitaire.h"

class TachePreemptable : public TacheUnitaire {
private:

public:
    TachePreemptable(const QString& ident, const QString& t, const Date& d,const Date& ech,const Duree& du):TacheUnitaire(ident,t,d,ech, du){}
};

QTextStream& operator<<(QTextStream& fout, const TachePreemptable& t);
#endif // TACHEPREEMPTABLE

