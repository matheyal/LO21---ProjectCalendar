
#include "export.h"

void ExportXML::save(const QString& f){
    //file=f;
    ProjetManager& PM = ProjetManager::getInstance();
    QFile newfile(f);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw CalendarException(QString("erreur sauvegarde tâches : ouverture fichier xml"));
    QXmlStreamWriter stream(&newfile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("projets");
    //S'arranger pour que nb et taches (de TacheManager à l'origine) soient reliés à des attributs de Projet
    for(vector<Projet*>::iterator it1 = PM.getProjets().begin(); it1 != PM.getProjets().end(); ++it1){
        stream.writeStartElement("projet");
        stream.writeTextElement("identificateur",(*it1)->getId());
        stream.writeTextElement("titre",(*it1)->getTitre());
        stream.writeTextElement("description",(*it1)->getDesc());
        stream.writeTextElement("disponibilite",(*it1)->getDispo().toString());
        stream.writeTextElement("echeance",(*it1)->getEcheance().toString());
        for (vector<Tache*>::iterator it2 = (*it1)->getTaches().begin() ; it2 != (*it1)->getTaches().end() ; ++it2){
            stream.writeStartElement("tache");
            //pour préemptive s'arranger pour trouver si la Tache est du type tachepreemptable
            //stream.writeAttribute("preemptive", ((*it2)->isPreemptive())?"true":"false");
            stream.writeTextElement("identificateur",(*it2)->getId());
            stream.writeTextElement("titre",(*it2)->getTitre());
            stream.writeTextElement("disponibilite",(*it2)->getDate().toString());
            stream.writeTextElement("echeance",(*it2)->getEcheance().toString());
            //Durée uniquement si tache unitaire
            /*
            QString str;
            str.setNum(taches[i]->getDuree().getDureeEnMinutes());
            stream.writeTextElement("duree",str);
            */
            stream.writeEndElement();
        }
    }
    stream.writeEndElement();
    stream.writeEndDocument();
    newfile.close();
}
