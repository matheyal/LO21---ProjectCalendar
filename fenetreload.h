#ifndef FENETRELOAD_H
#define FENETRELOAD_H

#include "qt.h"
#include "mainwindow.h"

class FenetreLoad : public QFileDialog{
    Q_OBJECT
public:
    FenetreLoad(){
        QString filename = getSaveFileName(this, tr("Save project"), ".", tr("XML Files (*.xml)"));
        ProjetManager::getInstance().save(new ExportXML, filename);
    }
};

#endif // FENETRELOAD_H

