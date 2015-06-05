#ifndef IMPORT_H
#define IMPORT_H

#include "projetmanager.h"
#include "calendar.h"
#include "qt.h"

class ImportStrategy {
public:
    virtual void load (const QString& f) = 0;
};

class ImportXML : public ImportStrategy{
public:
    void load(const QString &f);
};

#endif // IMPORT_H

