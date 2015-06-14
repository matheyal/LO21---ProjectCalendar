#ifndef TREEVIEW
#define TREEVIEW

#include "qt.h"
#include "projetmanager.h"

class TreeView : public QTreeWidget{
    Q_OBJECT
private:
    vector<QTreeWidgetItem*> items;
    QTreeWidgetItem* projetToTreeView(Projet* projet);
    QTreeWidgetItem* tacheToTreeView(Tache* tache);
public:
    TreeView(QTreeWidget* parent = 0);
    ~TreeView();

public slots:
    void updateTreeView();
};

#endif // TREEVIEW

