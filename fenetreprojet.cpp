#include "fenetreprojet.h"

FenetreProjet::FenetreProjet(QWidget *parent)
{
    fenetreProjet = new QWidget;


    titreProjet = new QLineEdit;
    descriptionProjet = new QTextEdit;
    dateActuelle = new QDateTime;
    dispoProjet = new QDateTimeEdit(dateActuelle->currentDateTime());
    echeanceProjet = new QDateTimeEdit(dateActuelle->currentDateTime());
    enregistrerProjet = new QPushButton("Enregister");
    quitter = new QPushButton("quitter");

    layout21Form = new QFormLayout;

    layout21Form->addRow("Titre", titreProjet);
    layout21Form->addRow("Descritpion", descriptionProjet);
    layout21Form->addRow("Date de disponnibilite", dispoProjet);
    layout21Form->addRow("Date d'echeance", echeanceProjet);

    horizontal=new QHBoxLayout;
    horizontal->addWidget(enregistrerProjet);
    horizontal->addWidget(quitter);

    layoutNouveauProjet = new QVBoxLayout;
    layoutNouveauProjet->addLayout(layout21Form);
    layoutNouveauProjet->addLayout(horizontal);

    QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(enregistrerProjet, SIGNAL(clicked()), this, SLOT(saveProjet()));

    groupeNouveauProjet = new QGroupBox("Rentrer un nouveau projet dans la base de donnee", this);
    groupeNouveauProjet->setLayout(layoutNouveauProjet);

    layout = new QHBoxLayout;
    layout->addWidget(groupeNouveauProjet);

    fenetreProjet->setLayout(layout);

    setCentralWidget(fenetreProjet);
}

void FenetreProjet::saveProjet()
{
    ProjetManager& pm = ProjetManager::getInstance();
    //pm.ajouterProjet("1", titreProjet->text(), descriptionProjet->toPlainText(),  )

}
