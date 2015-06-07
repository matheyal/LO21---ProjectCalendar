#include "projetmanager.h"
#include "export.h"
#include <typeinfo>

void ExportXML::save(const QString& f){
    //file=f;
    ProjetManager& PM = ProjetManager::getInstance();
    QFile newfile(f);
    if (!newfile.open(QIODevice::WriteOnly | QIODevice::Text))
        throw CalendarException(QString("erreur sauvegarde tâches : ouverture fichier xml"));
    QXmlStreamWriter stream(&newfile);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    //Écriture de tous les projets dans une balise <projets>
    stream.writeStartElement("projets");
<<<<<<< HEAD
    for(vector<Projet*>::iterator it1 = PM.getProjets().begin(); it1 != PM.getProjets().end(); ++it1){
=======
    const vector<Projet*>* projets = PM.getProjets();
    for(vector<Projet*>::const_iterator it1 = projets->begin(); it1 != projets->end(); ++it1){
>>>>>>> c933bdbd8de200ae63109b99db883cdc97ed0283
        //chaque projet est dans une balise <projet>
        stream.writeStartElement("projet");
        stream.writeTextElement("identificateur",(*it1)->getId());
        stream.writeTextElement("titre",(*it1)->getTitre());
        stream.writeTextElement("description",(*it1)->getDesc());
        stream.writeTextElement("disponibilite",(*it1)->getDispo().toString());
        stream.writeTextElement("echeance",(*it1)->getEcheance().toString());
        //Liste des taches du projet dans une balise <taches>
        stream.writeStartElement("taches");
<<<<<<< HEAD
        for (vector<Tache*>::iterator it2 = (*it1)->getTaches().begin() ; it2 != (*it1)->getTaches().end() ; ++it2){
=======
        const vector<Tache*>* taches = (*it1)->getTaches();
        for (vector<Tache*>::const_iterator it2 = taches->begin() ; it2 != taches->end() ; ++it2){
>>>>>>> c933bdbd8de200ae63109b99db883cdc97ed0283
            //Chaque tache dans une balise <tache>
            stream.writeStartElement("tache");
            //Met l'attribut preemptive à true si tache préemptable, false sinon
            if (typeid(*it2) == typeid(TachePreemptable))
                stream.writeAttribute("preemptive", "true");
            else
                stream.writeAttribute("preemptive", "false");
            //Met l'attribut composite à true si tache composite, false sinon
            if (typeid(*it2) == typeid(TachePreemptable))
                stream.writeAttribute("composite", "true");
            else
                stream.writeAttribute("composite", "false");
            stream.writeTextElement("identificateur",(*it2)->getId());
            stream.writeTextElement("titre",(*it2)->getTitre());
            stream.writeTextElement("disponibilite",(*it2)->getDate().toString());
            stream.writeTextElement("echeance",(*it2)->getEcheance().toString());
            //Durée uniquement si tache unitaire
            if (typeid(*it2) ==  typeid(TacheUnitaire)){
                QString str;
                str.setNum((*it2)->getDuree().getDureeEnMinutes());
                stream.writeTextElement("duree",str);
            }
            stream.writeEndElement();
        }
        stream.writeEndElement();
        stream.writeEndElement();
<<<<<<< HEAD
    }
    stream.writeEndElement();
    //Liste des précédences de Taches dans la balise <precedences>
    stream.writeStartElement("precedences");
    for(vector<Projet*>::iterator it1 = PM.getProjets().begin(); it1 != PM.getProjets().end(); ++it1){
        for (vector<Tache*>::iterator it2 = (*it1)->getTaches().begin() ; it2 != (*it1)->getTaches().end() ; ++it2){

        }
    }
    stream.writeEndElement();

=======
    }
    stream.writeEndElement();
    /*
    //Liste des précédences de Taches dans la balise <precedences>
    stream.writeStartElement("precedences");
    for(vector<Projet*>::iterator it1 = PM.getProjets().begin(); it1 != PM.getProjets().end(); ++it1){
        for (vector<Tache*>::iterator it2 = (*it1)->getTaches().begin() ; it2 != (*it1)->getTaches().end() ; ++it2){

        }
    }
    stream.writeEndElement();
    */
>>>>>>> c933bdbd8de200ae63109b99db883cdc97ed0283
    stream.writeEndDocument();
    newfile.close();
}
