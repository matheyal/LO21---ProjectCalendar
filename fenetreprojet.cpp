#include "fenetreprojet.h"
#include "projetmanager.h"

FenetreProjet::FenetreProjet(QWidget *parent)
{
    fenetreProjet = new QWidget;

    idProjet = new QLineEdit;
    titreProjet = new QLineEdit;
    descriptionProjet = new QTextEdit;
    dispoProjet = new QDateEdit(QDate::currentDate());
    echeanceProjet = new QDateEdit(QDate::currentDate());
    enregistrerProjet = new QPushButton("Enregister");
    annuler = new QPushButton("annuler");

    layout21Form = new QFormLayout;
    layout21Form->addRow("Id", idProjet);
    layout21Form->addRow("Titre", titreProjet);
    layout21Form->addRow("Descritpion", descriptionProjet);
    layout21Form->addRow("Date de disponnibilite", dispoProjet);
    layout21Form->addRow("Date d'echeance", echeanceProjet);

    horizontal=new QHBoxLayout;
    horizontal->addWidget(enregistrerProjet);
    horizontal->addWidget(annuler);

    layoutNouveauProjet = new QVBoxLayout;
    layoutNouveauProjet->addLayout(layout21Form);
    layoutNouveauProjet->addLayout(horizontal);

    QObject::connect(enregistrerProjet, SIGNAL(clicked()), this, SLOT(saveProjet()));
    QObject::connect(enregistrerProjet, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(annuler, SIGNAL(clicked()), this, SLOT(cancel()));
    QObject::connect(dispoProjet, SIGNAL(dateChanged(const QDate)), this, SLOT(checkDate(const QDate&)));
    QObject::connect(echeanceProjet, SIGNAL(dateChanged(const QDate&)), this, SLOT(checkDate(const QDate&)));

    groupeNouveauProjet = new QGroupBox("Rentrer un nouveau projet dans la base de donnee", this);
    groupeNouveauProjet->setLayout(layoutNouveauProjet);

    layout = new QHBoxLayout;
    layout->addWidget(groupeNouveauProjet);

    fenetreProjet->setLayout(layout);

    setCentralWidget(fenetreProjet);
}


void FenetreProjet::saveProjet()
{
<<<<<<< HEAD
    ProjetManager& pm= ProjetManager::getInstance();
    if(pm.trouverProjet(idProjet->text()))
        QMessageBox::warning(this, "erreur","sauvegarde impossible, id deja utilise");
    else if (dispoProjet->date()<QDate::currentDate())
        QMessageBox::warning(this, "erreur","sauvegarde impossible, date de disponibilité antérieur à la date du jour");
    else pm.ajouterProjet(idProjet->text(), titreProjet->text(), descriptionProjet->toPlainText(), dispoProjet->date(), echeanceProjet->date());
}

void FenetreProjet::cancel(){
    idProjet->clear();
    titreProjet->clear();
    descriptionProjet->clear();
    dispoProjet->setDate(QDate::currentDate());
    echeanceProjet->setDate(QDate::currentDate());
}
=======
    ProjetManager& pm = ProjetManager::getInstance();
    //pm.ajouterProjet("1", titreProjet->text(), descriptionProjet->toPlainText(),  )
>>>>>>> 4d895204d940735f38141d3c6a6842c58dd139f7

void FenetreProjet::checkDate(const QDate& d){
    if(d==dispoProjet->date() && echeanceProjet->date()<dispoProjet->date())
        echeanceProjet->setDate(dispoProjet->date());
    else if (d==echeanceProjet->date() && echeanceProjet->date()<dispoProjet->date())
            dispoProjet->setDate(echeanceProjet->date());
}
