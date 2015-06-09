/*#include "import.h"

void ImportXML::load(const QString& f){
    //qDebug()<<"debut load\n";
    //this->~TacheManager();
    //file=f;
    ProjetManager& PM = ProjetManager::getInstance();
    QFile fin(f);
    // If we can't open it, let's show an error message.
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw CalendarException("Erreur ouverture fichier tâches");
    }
    // QXmlStreamReader takes any QIODevice.
    QXmlStreamReader xml(&fin);
    //qDebug()<<"debut fichier\n";
    // We'll parse the XML until we reach end of it.
    while(!xml.atEnd() && !xml.hasError()) {
        // Read next element.
        QXmlStreamReader::TokenType token = xml.readNext();
        // If token is just StartDocument, we'll go to next.
        if(token == QXmlStreamReader::StartDocument) continue;
        // If token is StartElement, we'll see if we can read it.
        if(token == QXmlStreamReader::StartElement) {
            // If it's named projectcalendar, we'll go to the next.
            if(xml.name() == "projectcalendar") continue;
            // If it's named projets, we dig into to find all the projects.
            if(xml.name() == "projets") {
                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "projets")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        if(xml.name() == "projet"){
                            //qDebug()<<"new projet\n";
                            QString id_projet;
                            QString titre_projet;
                            QString description_projet;
                            QDate disponibilite_projet;
                            QDate echeance_projet;
                            vector<Tache*> taches_projet;

                            xml.readNext();
                            //We're going to loop over the things because the order might change.
                            //We'll continue the loop until we hit an EndElement named projet.
                            while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "projet")) {
                                if(xml.tokenType() == QXmlStreamReader::StartElement) {
                                    // We've found identificteur.
                                    if(xml.name() == "identificateur") {
                                        xml.readNext(); id_projet=xml.text().toString();
                                    }

                                    // We've found titre.
                                    if(xml.name() == "titre") {
                                        xml.readNext(); titre_projet=xml.text().toString();
                                        //qDebug()<<"titre="<<titre<<"\n";
                                    }
                                    // We've found disponibilite
                                    if(xml.name() == "disponibilite") {
                                        xml.readNext();
                                        disponibilite_projet=QDate::fromString(xml.text().toString(),Qt::TextDate);
                                        //qDebug()<<"disp="<<disponibilite.toString()<<"\n";
                                    }
                                    // We've found echeance
                                    if(xml.name() == "echeance") {
                                        xml.readNext();
                                        echeance_projet=QDate::fromString(xml.text().toString(),Qt::TextDate);
                                        //qDebug()<<"echeance="<<echeance.toString()<<"\n";
                                    }
                                    // We've found taches, we dig into to find all the taches
                                    if(xml.name() == "taches"){
                                        Projet* projet = PM.ajouterProjet(id_projet, titre_projet,description_projet,disponibilite_projet,echeance_projet);
                                        // We loop on all the taches of the <taches> element
                                        while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "taches")){
                                            if(xml.tokenType() == QXmlStreamReader::StartElement) {
                                                if(xml.name() == "tache"){
                                                    //! il faudra prendre en compte si la tache est programmée ou non
                                                    QString id_tache;
                                                    QString titre_tache;
                                                    QDate disponibilite_tache;
                                                    QDate echeance_tache;
                                                    Duree duree_tache;
                                                    bool preemptive;
                                                    bool composite;
                                                    bool unitaire;

                                                    QXmlStreamAttributes attributes = xml.attributes();
                                                    if(attributes.hasAttribute("preemptive")) {
                                                        QString val =attributes.value("preemptive").toString();
                                                        preemptive=(val == "true" ? true : false);
                                                    }
                                                    if(attributes.hasAttribute("composite")) {
                                                        QString val =attributes.value("composite").toString();
                                                        composite=(val == "true" ? true : false);
                                                    }
                                                    if(attributes.hasAttribute("unitaire")) {
                                                        QString val =attributes.value("unitaire").toString();
                                                        unitaire=(val == "true" ? true : false);
                                                    }
                                                    xml.readNext();
                                                    // We loop on all the elements of the <tache> element
                                                    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "tache")){
                                                        if(xml.tokenType() == QXmlStreamReader::StartElement) {
                                                            // We've found identificteur.
                                                            if(xml.name() == "identificateur") {
                                                                xml.readNext(); id_tache=xml.text().toString();
                                                                //qDebug()<<"id="<<identificateur<<"\n";
                                                            }

                                                            // We've found titre.
                                                            if(xml.name() == "titre") {
                                                                xml.readNext(); titre_tache=xml.text().toString();
                                                                //qDebug()<<"titre="<<titre<<"\n";
                                                            }
                                                            // We've found disponibilite
                                                            if(xml.name() == "disponibilite") {
                                                                xml.readNext();
                                                                disponibilite_tache=QDate::fromString(xml.text().toString(),Qt::TextDate);
                                                                //qDebug()<<"disp="<<disponibilite.toString()<<"\n";
                                                            }
                                                            // We've found echeance
                                                            if(xml.name() == "echeance") {
                                                                xml.readNext();
                                                                echeance_tache=QDate::fromString(xml.text().toString(),Qt::TextDate);
                                                                //qDebug()<<"echeance="<<echeance.toString()<<"\n";
                                                            }
                                                            // We've found duree
                                                            if(xml.name() == "duree") {
                                                                xml.readNext();
                                                                duree_tache.setDuree(xml.text().toString().toInt());
                                                                //qDebug()<<"duree="<<duree.getDureeEnMinutes()<<"\n";
                                                            }
                                                        }
                                                        xml.readNext();
                                                    } // Fin while tache
                                                    if (composite){
                                                        projet->ajouterTacheComposite(id_tache,titre_tache,disponibilite_tache,echeance_tache);
                                                    }
                                                    if (preemptive){
                                                        projet->ajouterTachePreemptable(id_tache,titre_tache,disponibilite_tache,echeance_tache,duree_tache);
                                                    }
                                                    if (unitaire){
                                                        projet->ajouterTacheUnitaire(id_tache,titre_tache,disponibilite_tache,echeance_tache,duree_tache);
                                                    }
                                                } // Fin if tache
                                            }
                                            xml.readNext();
                                        } // Fin while taches
                                    } // Fin if taches
                                }
                                xml.readNext();
                            } // Fin while projet
                        } // Fin if projet
                    }
                    xml.readNext();
                } // Fin while projets
            } // Fin if projets
            if(xml.name() == "precedences") {
                while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "precedences")) {
                    if(xml.tokenType() == QXmlStreamReader::StartElement) {
                        if(xml.name() == "precedence") {
                            QString id_projet;
                            QString id_tache;
                            QXmlStreamAttributes attributes = xml.attributes();
                            if(attributes.hasAttribute("id_projet")) {
                                id_projet =attributes.value("id_projet").toString();
                            }
                            if(attributes.hasAttribute("id_tache")) {
                                id_projet =attributes.value("id_tache").toString();
                            }
                            Tache* tache = PM.trouverProjet(id_projet)->trouverTache(id_tache);
                            xml.readNext();
                            while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "precedence")) {
                                if (xml.name() == "id_precedence"){
                                    xml.readNext();
                                    Tache* preced = PM.trouverProjet(id_projet)->trouverTache(xml.name().toString());
                                    tache->addPrecedence(preced);
                                }
                                xml.readNext();
                            } //Fin while precedence
                        }// Fin if precedence
                    }
                    xml.readNext();
                } // Fin while precedences
            } // Fin if precedences
            if(xml.name() == "composites"){

            } // Fin if composites
        }
    } // Fin lecture document
    // Error handling.
    if(xml.hasError()) {
        throw CalendarException("Erreur lecteur fichier taches, parser xml");
    }
    // Removes any device() or data from the reader * and resets its internal state to the initial state.
    xml.clear();
    //qDebug()<<"fin load\n";
}

*/
