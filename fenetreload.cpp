#include "fenetreload.h"
#include "agenda.h"

FenetreLoad::FenetreLoad(){
    QString filename = getOpenFileName(this, tr("Load project"), "..", tr("XML Files (*.xml)"));
    ProjetManager::getInstance().load(new ImportXML, filename);
}
