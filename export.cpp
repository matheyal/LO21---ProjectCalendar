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
    stream.writeStartElement("projectcalendar");
    stream.writeStartElement("projets");
    const vector<Projet*>* projets = PM.getProjets();
    for(vector<Projet*>::const_iterator it1 = projets->begin(); it1 != projets->end(); ++it1){
        //chaque projet est dans une balise <projet>
        stream.writeStartElement("projet");
        stream.writeTextElement("identificateur",(*it1)->getId());
        stream.writeTextElement("titre",(*it1)->getTitre());
        stream.writeTextElement("description",(*it1)->getDesc());
        stream.writeTextElement("disponibilite",(*it1)->getDispo().toString());
        stream.writeTextElement("echeance",(*it1)->getEcheance().toString());
        //Liste des taches du projet dans une balise <taches>
        stream.writeStartElement("taches");
        const vector<Tache*>* taches = (*it1)->getTaches();
        for (vector<Tache*>::const_iterator it2 = taches->begin() ; it2 != taches->end() ; ++it2){
            //Chaque tache dans une balise <tache>
            stream.writeStartElement("tache");
            //Met l'attribut preemptive à true si tache préemptable, false sinon
            if (typeid(**it2) == typeid(TachePreemptable))
                stream.writeAttribute("preemptive", "true");
            else
                stream.writeAttribute("preemptive", "false");
            //Met l'attribut composite à true si tache composite, false sinon
            if (typeid(**it2) == typeid(TacheComposite))
                stream.writeAttribute("composite", "true");
            else
                stream.writeAttribute("composite", "false");
            //Met l'attribut unitaire à true si tache unitaire, false sinon
            if (typeid(**it2) == typeid(TacheComposite))
                stream.writeAttribute("unitaire", "true");
            else
                stream.writeAttribute("unitaire", "false");

            stream.writeTextElement("identificateur",(*it2)->getId());
            stream.writeTextElement("titre",(*it2)->getTitre());
            stream.writeTextElement("disponibilite",(*it2)->getDate().toString());
            stream.writeTextElement("echeance",(*it2)->getEcheance().toString());
            //Durée uniquement si tache unitaire
            if (typeid(**it2) ==  typeid(TacheUnitaire)){
                QString str;
                str.setNum((*it2)->getDuree().getDureeEnMinutes());
                stream.writeTextElement("duree",str);
            }
            stream.writeEndElement();// Fin <tache>
        }
        stream.writeEndElement(); // Fin <taches>
        stream.writeEndElement(); // Fin <projet>
    }
    stream.writeEndElement(); // Fin <projets>

    //Liste des précédences de Taches dans la balise <precedences>
    stream.writeStartElement("precedences");
    for(vector<Projet*>::const_iterator it1 = projets->begin(); it1 != projets->end(); ++it1){ //Itération sur les projets
        const vector<Tache*>* taches = (*it1)->getTaches();
        for (vector<Tache*>::const_iterator it2 = taches->begin() ; it2 != taches->end() ; ++it2){ //Itération sur les taches du projet
            const vector<Tache*>* tachesPrecedentes = (*it2)->getTachesPrecedentes();
            if (!tachesPrecedentes->empty()){ //La tache a des contraintes de precedence
                stream.writeStartElement("precedence");
                stream.writeAttribute("id", (*it2)->getId());
                for (vector<Tache*>::const_iterator it3 = tachesPrecedentes->begin() ; it3 != tachesPrecedentes->end() ; ++it3) //Pour chaque tache, itération sur les taches précédentes
                    stream.writeTextElement("id_precedence", (*it3)->getId());
                stream.writeEndElement(); // Fin <precedence>
            }
        }
    }
    stream.writeEndElement(); // Fin <precedences>

    //Liste des composants pour les taches compositees
    stream.writeStartElement("composites");
    for(vector<Projet*>::const_iterator it1 = projets->begin(); it1 != projets->end(); ++it1){ //Itération sur les projets
        const vector<Tache*>* taches = (*it1)->getTaches();
        for (vector<Tache*>::const_iterator it2 = taches->begin() ; it2 != taches->end() ; ++it2){ //Itération sur les taches du projet
            if (typeid(**it2) == typeid(TacheComposite)){
                stream.writeStartElement("composite");
                stream.writeAttribute("id", (*it2)->getId());
                const vector<Tache*>* sousTaches = (*it2)->getSousTaches();
                for (vector<Tache*>::const_iterator it3 = sousTaches->begin() ; it3 != sousTaches->end() ; ++it3) //Pour chaque tache, itération sur les sous taches
                    stream.writeTextElement("id_composant", (*it3)->getId());
                stream.writeEndElement(); // Fin <composite>
            }
        }
    }
    stream.writeEndElement(); // Fin <composites>
    stream.writeEndElement(); // Fin <projectcalendar>
    stream.writeEndDocument();
    newfile.close();
}
