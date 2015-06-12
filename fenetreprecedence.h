#ifndef FENETREPRECEDENCE_H
#define FENETREPRECEDENCE_H

#include<QtWidgets>
#include"projetmanager.h"

class FenetrePrecedence : public QMainWindow
{
    Q_OBJECT

public:
    FenetrePrecedence(QMainWindow* parent=0);

private slots :
    void ajouterPrecedence();
    void load();


private:
    QWidget *fenetrePrecedence;

    QComboBox* projets;
    QComboBox* taches;
    QComboBox* precedente;

    QPushButton* ajouter;
    QPushButton* quitter;

    QHBoxLayout* layoutHorizontal;
    QFormLayout* layoutFormulaire;
    QVBoxLayout* layout;
};

#endif // FENETREPRECEDENCE_H

