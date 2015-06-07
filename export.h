#ifndef EXPORT_H
#define EXPORT_H

#include "calendar.h"
#include "qt.h"

class ExportStrategy {
public:
    virtual void save(const QString& f) = 0;
};

class ExportXML : public ExportStrategy {
public:
    void save(const QString& f);
};

#endif // EXPORT_H
