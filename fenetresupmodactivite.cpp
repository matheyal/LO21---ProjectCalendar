#include "fenetresupmodactivite.h"
#include "activitemanager.h"

FenetreSupModActivite::FenetreSupModActivite(QMainWindow *parent) : QMainWindow(parent)
{
    fenetreActivite = new QWidget;

    idActivite = new QComboBox(this);
    idActivite->addItem("");
    ActiviteManager& am=ActiviteManager::getInstance();
    for(vector<Activite*>::const_iterator it = (*am.getActivites()).begin(); it != (*am.getActivites()).end(); ++it){
        idActivite->addItem((*it)->getId());
    }

    titreActivite = new QLineEdit;
    titreActivite->setDisabled(true);
    dispoActivite = new QDateTimeEdit;
    dispoActivite->setDisabled(true);
    echeanceActivite = new QDateTimeEdit;
    echeanceActivite->setDisabled(true);
    dureeActivite = new QTimeEdit;
    dureeActivite->setDisabled(true);
    lieuActivite = new QLineEdit;
    lieuActivite->setDisabled(true);
    personne = new QLineEdit;
    personne->setDisabled(true);
    supprimerParticipant = new QComboBox;
    supprimerParticipant->setDisabled(true);
    ajoutParticipant = new QLineEdit;
    ajoutParticipant->setDisabled(true);
    mod = new QPushButton("Modifier");
    mod->setDisabled(true);
    ann = new QPushButton("Réinitialiser");
    ann->setDisabled(true);
    supp = new QPushButton("supprimer");
    supp->setDisabled(true);

    layout21Form = new QFormLayout;
    layout21Form->addRow("Id", idActivite);
    layout21Form->addRow("Titre", titreActivite);
    layout21Form->addRow("Date de disponnibilite", dispoActivite);
    layout21Form->addRow("Date d'echeance", echeanceActivite);
    layout21Form->addRow("Duree", dureeActivite);
    layout21Form->addRow("Lieu", lieuActivite);
    layout21Form->addRow("Interlocuteur", personne);
    layout21Form->addRow("Ajouter un participant", ajoutParticipant);
    layout21Form->addRow("Supprimer un participant", supprimerParticipant);

    horizontal=new QHBoxLayout;
    horizontal->addWidget(supp);
    horizontal->addWidget(mod);
    horizontal->addWidget(ann);

    layoutNouvelleActivite = new QVBoxLayout;
    layoutNouvelleActivite->addLayout(layout21Form);
    layoutNouvelleActivite->addLayout(horizontal);

    groupeActivite = new QGroupBox("Supprimer ou modifier une activité", this);
    groupeActivite->setLayout(layoutNouvelleActivite);

    layout = new QHBoxLayout;
    layout->addWidget(groupeActivite);

    fenetreActivite->setLayout(layout);

    setCentralWidget(fenetreActivite);

    QObject::connect(idActivite, SIGNAL(currentIndexChanged(int)), this, SLOT(load()));
    QObject::connect(mod, SIGNAL(clicked()), this, SLOT(modifier()));
    QObject::connect(mod, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ann, SIGNAL(clicked()), this, SLOT(load()));
    QObject::connect(supp, SIGNAL(clicked()), this, SLOT(supprimer()));
    QObject::connect(supp, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(dispoActivite, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(checkDate(const QDateTime&)));
    QObject::connect(echeanceActivite, SIGNAL(dateTimeChanged(QDateTime)), this, SLOT(checkDate(const QDateTime&)));

}

void FenetreSupModActivite::load(){
        ActiviteManager& am= ActiviteManager::getInstance();
        if(am.trouverActivite(idActivite->currentText())){
            QTime time(am.trouverActivite(idActivite->currentText())->getDuree().getDureeEnHeures(), am.trouverActivite(idActivite->currentText())->getDuree().getDureeEnMinutes());
            ajoutParticipant->setDisabled(true);
            ajoutParticipant->clear();
            supprimerParticipant->setDisabled(true);
            supprimerParticipant->clear();
            supprimerParticipant->addItem("");
            personne->setDisabled(true);
            mod->setEnabled(true);
            ann->setEnabled(true);
            supp->setEnabled(true);
            titreActivite->setEnabled(true);
            dispoActivite->setEnabled(true);
            echeanceActivite->setEnabled(true);
            dureeActivite->setEnabled(true);
            lieuActivite->setEnabled(true);
            titreActivite->setText(am.trouverActivite(idActivite->currentText())->getTitre());
            dispoActivite->setDateTime(am.trouverActivite(idActivite->currentText())->getDate());
            echeanceActivite->setDateTime(am.trouverActivite(idActivite->currentText())->getEcheance());
            dureeActivite->setTime(time);
            lieuActivite->setText(am.trouverActivite(idActivite->currentText())->getLieu());
            if (typeid(*(am.trouverActivite(idActivite->currentText())))==typeid(Reunion)){
                ajoutParticipant->setEnabled(true);
                supprimerParticipant->setEnabled(true);
                for(vector<QString>::const_iterator it = (am.trouverActivite(idActivite->currentText())->getParticipants()).begin(); it != (am.trouverActivite(idActivite->currentText())->getParticipants()).end(); ++it){
                    supprimerParticipant->addItem(*it);
                }
                personne->setDisabled(true);
                personne->clear();
            }
            if (typeid(*(am.trouverActivite(idActivite->currentText())))==typeid(Rdv)){
                ajoutParticipant->setDisabled(true);
                ajoutParticipant->clear();
                supprimerParticipant->setDisabled(true);
                supprimerParticipant->clear();
                personne->setEnabled(true);
                personne->setText(am.trouverActivite(idActivite->currentText())->getInterlocuteur());
            }
        }else{
            titreActivite->clear();
            titreActivite->setDisabled(true);
            dispoActivite->clear();
            dispoActivite->setDisabled(true);
            echeanceActivite->clear();
            echeanceActivite->setDisabled(true);
            dureeActivite->clear();
            dureeActivite->setDisabled(true);
            lieuActivite->setDisabled(true);
            ajoutParticipant->clear();
            ajoutParticipant->setDisabled(true);
            supprimerParticipant->clear();
            supprimerParticipant->setDisabled(true);
        }
}

    void FenetreSupModActivite::modifier(){
        ActiviteManager& am= ActiviteManager::getInstance();
        Duree du(dureeActivite->time().hour(), dureeActivite->time().minute());
        am.trouverActivite(idActivite->currentText())->setTitre(titreActivite->text());
        am.trouverActivite(idActivite->currentText())->setDateDisponibilite(dispoActivite->dateTime());
        am.trouverActivite(idActivite->currentText())->setEcheance(echeanceActivite->dateTime());
        am.trouverActivite(idActivite->currentText())->setDuree(du);
        if (typeid(*(am.trouverActivite(idActivite->currentText())))==typeid(Reunion)){
            am.trouverActivite(idActivite->currentText())->ajouterParticipant(ajoutParticipant->text());
            am.trouverActivite(idActivite->currentText())->supprimerParticipant(supprimerParticipant->currentText());
        }
        if (typeid(*(am.trouverActivite(idActivite->currentText())))==typeid(Rdv)){
            am.trouverActivite(idActivite->currentText())->setInterlocuteur(personne->text());
        }

    }

    void FenetreSupModActivite::checkDate(const QDateTime& d){
        if(d==dispoActivite->dateTime() && d<QDateTime::currentDateTime())
            dispoActivite->setDateTime(QDateTime::currentDateTime());
        if(d==dispoActivite->dateTime() && echeanceActivite->dateTime()<dispoActivite->dateTime())
            echeanceActivite->setDateTime(dispoActivite->dateTime());
        else if (d==echeanceActivite->dateTime() && echeanceActivite->dateTime()<dispoActivite->dateTime())
                dispoActivite->setDateTime(echeanceActivite->dateTime());
    }

    void FenetreSupModActivite::supprimer(){
        ActiviteManager& am= ActiviteManager::getInstance();
        am.supprimerActivite(idActivite->currentText());
    }

