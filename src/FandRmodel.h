

#ifndef FANDRMODEL_H
#define FANDRMODEL_H

#include <QAbstractTableModel>
#include <Nodes/characteristic.h>
#include "srecfile.h"

class FandRModel : public QAbstractTableModel
{
    public:           //public：表示类的成员可以被外部访问；


        FandRModel(SrecFile *srec, QObject *parent = 0);
        ~FandRModel();

        int rowCount(const QModelIndex &parent) const;
        int columnCount(const QModelIndex &parent) const;
        QVariant data(const QModelIndex &index, int role) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const;
        Qt::ItemFlags flags(const QModelIndex &index) const;

    private:          //private：表示类的成员不可以被外部访问。
        QMap<QString, Data*> listDataPrio;
        QMap<QString, Data*> listDataFnR0;
        QMap<QString, Data*> listDataFnR1;
        QMap<QString, Data*> listDataFnR2;
        QMap<QString, Data*> listDataFnR3;
        QMap<QString, Data*> listDataFnR4;
        SrecFile *srec;
        int nColumn;
        int nRow;

};

#endif // FANDRMODEL_H
