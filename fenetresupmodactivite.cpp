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
    dispoActivite = new QDateEdit;
    dispoActivite->setDisabled(true);
    echeanceActivite = new QDateEdit;
    echeanceActivite->setDisabled(true);
    dureeActivite = new QSpinBox;
    dureeActivite->setMinimum(0);
    dureeActivite->setMaximum(12);
    dureeActivite->setDisabled(true);
    lieuActivite = new QLineEdit;
    lieuActivite->setDisabled(true);
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
    QObject::connect(dispoActivite, SIGNAL(dateChanged(const QDate)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(echeanceActivite, SIGNAL(dateChanged(const QDate&)), this, SLOT(checkDate(const QDate&)));

}

void FenetreSupModActivite::load(){
        ActiviteManager& am= ActiviteManager::getInstance();
        if(am.trouverActivite(idActivite->currentText())){
            mod->setEnabled(true);
            ann->setEnabled(true);
            supp->setEnabled(true);
            titreActivite->setEnabled(true);
            dispoActivite->setEnabled(true);
            echeanceActivite->setEnabled(true);
            dureeActivite->setEnabled(true);
            lieuActivite->setEnabled(true);
            titreActivite->setText(am.trouverActivite(idActivite->currentText())->getTitre());
            dispoActivite->setDate(am.trouverActivite(idActivite->currentText())->getDate());
            echeanceActivite->setDate(am.trouverActivite(idActivite->currentText())->getEcheance());
            dureeActivite->setValue(am.trouverActivite(idActivite->currentText())->getDuree().getDureeEnHeures());
            lieuActivite->setText(am.trouverActivite(idActivite->currentText())->getLieu());
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
        }
}

    void FenetreSupModActivite::modifier(){
        ActiviteManager& am= ActiviteManager::getInstance();
        am.trouverActivite(idActivite->currentText())->setTitre(titreActivite->text());
        am.trouverActivite(idActivite->currentText())->setDateDisponibilite(dispoActivite->date());
        am.trouverActivite(idActivite->currentText())->setEcheance(echeanceActivite->date());
    }

    void FenetreSupModActivite::checkDate(const QDate& d){
        if(d==dispoActivite->date() && d<QDate::currentDate())
            dispoActivite->setDate(QDate::currentDate());
        if(d==dispoActivite->date() && echeanceActivite->date()<dispoActivite->date())
            echeanceActivite->setDate(dispoActivite->date());
        else if (d==echeanceActivite->date() && echeanceActivite->date()<dispoActivite->date())
                dispoActivite->setDate(echeanceActivite->date());
    }

    void FenetreSupModActivite::supprimer(){
        ActiviteManager& am= ActiviteManager::getInstance();
        am.supprimerActivite(idActivite->currentText());
    }

