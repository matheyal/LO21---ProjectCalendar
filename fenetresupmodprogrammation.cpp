#include "fenetresupmodprogrammation.h"

FenetreSupModProg::FenetreSupModProg(QMainWindow *parent):QMainWindow(parent){
    Agenda& A = Agenda::getInstance();
    fenetreSupModProg = new QWidget;

    idEvenement = new QComboBox;
    idEvenement->addItem("");
    listeTitresEvenements.push_back("");
    for(vector<Programmation*>::const_iterator it = A.getProgramamtions()->begin() ; it != A.getProgramamtions()->end(); ++it){
        idEvenement->addItem((*it)->getEvenement()->getId());
        listeTitresEvenements.push_back((*it)->getEvenement()->getTitre());
    }
    titreEvenement = new QLineEdit;
    titreEvenement->setReadOnly(true);

    dispoEvenement = new QDateTimeEdit;
    dispoEvenement->setReadOnly(true);
    echeanceEvenement = new QDateTimeEdit;
    echeanceEvenement->setReadOnly(true);
    dateHeureProg = new QDateTimeEdit;

    modifierProg = new QPushButton("Modifier");
    supprimerProg = new QPushButton("Supprimer");
    reinitProg = new QPushButton("Réinitialiser");

    layoutForm = new QFormLayout;
    layoutForm->addRow("ID",idEvenement);
    layoutForm->addRow("Titre", titreEvenement);
    layoutForm->addRow("Disponibilité", dispoEvenement);
    layoutForm->addRow("Echeance", echeanceEvenement);
    layoutForm->addRow("Date et heure", dateHeureProg);

    layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(modifierProg);
    layoutButtons->addWidget(supprimerProg);
    layoutButtons->addWidget(reinitProg);

    Vlayout1 = new QVBoxLayout;
    Vlayout1->addLayout(layoutForm);
    Vlayout1->addLayout(layoutButtons);

    groupeSupModProg = new QGroupBox("Modifier ou supprimer la programmation d'événement du calendrier", this);
    groupeSupModProg->setLayout(Vlayout1);

    layout = new QVBoxLayout;
    layout->addWidget(groupeSupModProg);

    fenetreSupModProg->setLayout(layout);
    setCentralWidget(fenetreSupModProg);

    QObject::connect(idEvenement, SIGNAL(currentIndexChanged(int)), this, SLOT(updateTitreEvenement(int)));
    QObject::connect(reinitProg, SIGNAL(clicked()), this, SLOT(close()));


}

void FenetreSupModProg::updateTitreEvenement(int i){
    QString titre = listeTitresEvenements[i];
    titreEvenement->setText(titre);
}

void FenetreSupModProg::supprimerProgrammation(){

}

void FenetreSupModProg::modifierProgrammtion(){

}
