#include "fenetreload.h"
#include "agenda.h"

FenetreLoad::FenetreLoad(){
    QString filename = getOpenFileName(this, tr("Load project"), "..", tr("XML Files (*.xml)"));
    ProjetManager::getInstance().load(new ImportXML, filename);
    Evenement* ev = ProjetManager::getInstance().trouverProjet("1")->trouverTache("2");
    Agenda::getInstance().ajouterProg(ev,QDate(2015,6,12), Horaire(10,30));
    /*
    fenetreLoad = new QWidget;

    text = new QLabel("Souhaitez vous charger un calendrier ?");
    oui = new QPushButton("Oui");
    non = new QPushButton("Non");

    layout1 = new QHBoxLayout;
    layout1->addWidget(text);;
    layout2 = new QHBoxLayout;
    layout2->addWidget(oui);
    layout2->addWidget(non);

    layout = new QVBoxLayout;
    layout->addLayout(layout1);
    layout->addLayout(layout2);

    fenetreLoad->setLayout(layout);
    setCentralWidget(fenetreLoad);

    QObject::connect(oui, SIGNAL(clicked()), this, SLOT(loadProjet()));
    QObject::connect(non, SIGNAL(clicked()), this, SLOT(close()));
    */
}
