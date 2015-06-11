#ifndef FENETREACTIVITE
#define FENETREACTIVITE

#include <QMainWindow>
#include <QtWidgets>

class FenetreActivite : public QMainWindow
{
    Q_OBJECT
public:
    FenetreActivite(QMainWindow *parent=0);

private slots:
    void saveActivite();
    void cancel();
    void checkDate(const QDate& d);

private:
    QLineEdit *idActivite;
    QLineEdit *titreActivite;

    QTextEdit* descriptionActivite;

    QDateEdit *dispoActivite;
    QDateEdit *echeanceActivite;
    QSpinBox *dureeActivite;
    QLineEdit *lieuActivite;

    QPushButton *enregistrerActivite;
    QPushButton* annuler;

    QGroupBox* groupeNouvelleActivite;

    QHBoxLayout*horizontal;
    QFormLayout *layout21Form;
    QVBoxLayout* layoutNouvelleActivite;
    QHBoxLayout* layout;

    QWidget *fenetreActivite;
};

#endif // FENETREACTIVITE

