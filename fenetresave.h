#ifndef FENETRESAVE_H
#define FENETRESAVE_H

#include "qt.h"
#include "mainwindow.h"

class FenetreSave : public QFileDialog{
    Q_OBJECT
public:
    FenetreSave(QFileDialog *parent=0) : QFileDialog(parent){
        QString fileName = getOpenFileName(parent, tr("Open project"), "", tr("XML Files(*.xml)"));
        ProjetManager::getInstance().load(new ImportXML, fileName);
    }
};


#endif // FENETRESAVE_H

