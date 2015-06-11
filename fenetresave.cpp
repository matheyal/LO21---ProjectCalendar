#include "fenetresave.h"

FenetreSave::FenetreSave(){
    QString filename = getSaveFileName(this, tr("Save project"), "..", tr("XML Files (*.xml)"));
    ProjetManager::getInstance().save(new ExportXML, filename);

    /*fenetreSave = new QWidget;

    text = new QLabel("Souhaitez vous sauvegarder votre calendrier ?");
    oui = new QPushButton("Oui");
    non = new QPushButton("Non");
    dialog = new QFileDialog;

    layout1 = new QHBoxLayout;
    layout1->addWidget(text);;
    layout2 = new QHBoxLayout;
    layout2->addWidget(oui);
    layout2->addWidget(non);

    layout = new QVBoxLayout;
    layout->addLayout(layout1);
    layout->addLayout(layout2);

    fenetreSave->setLayout(layout);
    setCentralWidget(fenetreSave);

    QObject::connect(oui, SIGNAL(clicked()), this, SLOT(saveProjet()));
    QObject::connect(this, SIGNAL(), qApp, SLOT(quit()));
    QObject::connect(non, SIGNAL(clicked()), qApp, SLOT(quit()));
    */
}

/*
void FenetreSave::saveProjet(){
    QString filename = dialog->getSaveFileName(this, tr("Save project"), ".", tr("XML Files (*.xml)"));
    ProjetManager::getInstance().save(new ExportXML, filename);
    this->close();
}
*/
