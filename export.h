#ifndef EXPORT_H
#define EXPORT_H

#include "projetmanager.h"
#include "qt.h"

class ExportStrategy {
public:
    virtual save(ExportStrategy* strategy, const QString& f) = 0;
};

#endif // EXPORT_H

