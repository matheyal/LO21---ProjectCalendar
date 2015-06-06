/*#include "export.h"

void ExportXML::save(const QString& f){
    //file=f;
    QFile newfile(f);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw CalendarException(QString("erreur sauvegarde tâches : ouverture fichier xml"));
    QXmlStreamWriter stream(&newfile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("taches");
    //S'arranger pour que nb et taches (de TacheManager à l'origine) soit reliés à des attributs de Projet
    for(unsigned int i=0; i<nb; i++){
        stream.writeStartElement("tache");
        stream.writeAttribute("preemptive", (taches[i]->isPreemptive())?"true":"false");
        stream.writeTextElement("identificateur",taches[i]->getId());
        stream.writeTextElement("titre",taches[i]->getTitre());
        stream.writeTextElement("disponibilite",taches[i]->getDateDisponibilite().toString(Qt::ISODate));
        stream.writeTextElement("echeance",taches[i]->getDateEcheance().toString(Qt::ISODate));
        QString str;
        str.setNum(taches[i]->getDuree().getDureeEnMinutes());
        stream.writeTextElement("duree",str);
        stream.writeEndElement();
    }
    stream.writeEndElement();
    stream.writeEndDocument();
    newfile.close();
}*/
