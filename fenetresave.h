#ifndef FENETRESAVE_H
#define FENETRESAVE_H

#include "qt.h"
#include "mainwindow.h"

class FenetreSave : public QFileDialog{
    Q_OBJECT
public:
    FenetreSave();
/*
public slots:
    void saveProjet();

private:
    QLabel* text;
    QPushButton* oui;
    QPushButton* non;

    QHBoxLayout* layout1;
    QHBoxLayout* layout2;
    QVBoxLayout* layout;

    QFileDialog* dialog;

    QWidget* fenetreSave;
*/
};


#endif // FENETRESAVE_H

