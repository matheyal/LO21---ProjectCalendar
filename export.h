
#ifndef EXPORT_H
#define EXPORT_H

#include "projetmanager.h"
#include "calendar.h"
#include "qt.h"

class ExportStrategy {
friend class ProjetManager;
friend class Projet;
public:
    virtual void save(const QString& f) = 0;
};

class ExportXML : public ExportStrategy {
public:
    void save(const QString& f);
};

#endif // EXPORT_H
