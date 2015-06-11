#ifndef FENETREPRECEDENCE_H
#define FENETREPRECEDENCE_H

#include<QtWidgets>
#include"projetmanager.h"

class FenetrePrecedence : public QMainWindow
{
public:
    FenetrePrecedence(QMainWindow* parent=0);
private:
    QWidget *fenetrePrecedence;

    QComboBox* tache;
    QComboBox* precedente;

    QPushButton* ajouter;
    QPushButton* quitter;

    QHBoxLayout* layoutHorizontal;
    QFormLayout* layoutFormulaire;
    QVBoxLayout* layout;
};

#endif // FENETREPRECEDENCE_H

