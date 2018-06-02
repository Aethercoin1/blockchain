#ifndef ATHTECHITEM_H
#define ATHTECHITEM_H

#include <QWidget>

namespace Ui {
class ATHtechitem;
}

class ATHtechitem : public QWidget
{
    Q_OBJECT

public:
    explicit ATHtechitem(QWidget *parent = 0);
    ~ATHtechitem();
    void setHost(QString hostStr);
    void setName(QString nameStr);

private:
    Ui::ATHtechitem *ui;
    QString host;
    QString name;
};

#endif // ATHTECHITEM_H
