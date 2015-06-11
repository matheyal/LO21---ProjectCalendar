#ifndef FENETRELOAD_H
#define FENETRELOAD_H

#include "qt.h"
#include "mainwindow.h"

class FenetreLoad : public QMainWindow{
    Q_OBJECT
public:
    FenetreLoad(QMainWindow* parent);
public slots:
    void loadProjet();

private:
    QLabel* text;
    QPushButton* oui;
    QPushButton* non;

    QHBoxLayout* layout1;
    QHBoxLayout* layout2;
    QVBoxLayout* layout;

    QWidget* fenetreLoad;
};

#endif // FENETRELOAD_H

