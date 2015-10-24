#ifndef ADDRESSWIDGET_H
#define ADDRESSWIDGET_H

#include "newaddresstab.h"
#include "tablemodel.h"
#include "productmodel.h"

#include <QItemSelection>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
class QSortFilterProxyModel;
class QItemSelectionModel;
QT_END_NAMESPACE

class AddressWidget : public QTabWidget
{
    Q_OBJECT

public:
    AddressWidget(QWidget *parent = 0);
    void readFromFile(const QString &fileName);
    void writeToFile(const QString &fileName);

public slots:
    void addEntry();
    void addEntry(QString name, QString address);
    void editEntry();
    void removeEntry();
		
		void addProduct();
    void addProduct(int i, int c, double w, int number1, int number2, int number3);
    void editProduct();
    void removeProduct();

signals:
    void selectionChanged (const QItemSelection &selected);

private:
    void setupTabs();

    TableModel *table;
    ProductModel *producttable;
		
    NewAddressTab *newAddressTab;

    QSortFilterProxyModel *table_proxy;
    QSortFilterProxyModel *product_proxy;
};
//! [0]

#endif // ADDRESSWIDGET_H
