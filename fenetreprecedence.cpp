#include"fenetreprecedence.h"

FenetrePrecedence::FenetrePrecedence(QMainWindow* parent)
{
    fenetrePrecedence = new QWidget;

    tache = new QComboBox;
    precedente = new QComboBox;
    ProjetManager& pm=ProjetManager::getInstance();
    for(vector<Projet*>::const_iterator it = (*pm.getProjets()).begin(); it != (*pm.getProjets()).end(); ++it){
        tache->addItem((*it)->getId());
        precedente->addItem((*it)->getId());
    }

    ajouter = new QPushButton("Ajouter");
    ajouter->setDisabled(false);
    quitter = new QPushButton("quitter");
    quitter->setDisabled(false);

    layoutFormulaire = new QFormLayout;
    layoutFormulaire->addRow("Tache : ", tache);
    layoutFormulaire->addRow("Contrainte de precedence : ", precedente);

    layoutHorizontal = new QHBoxLayout;
    layoutHorizontal->addWidget(ajouter);
    layoutHorizontal->addWidget(quitter);

    layout = new QVBoxLayout;
    layout->addLayout(layoutFormulaire);
    layout->addLayout(layoutHorizontal);

    fenetrePrecedence->setLayout(layout);

    setCentralWidget(fenetrePrecedence);
}
