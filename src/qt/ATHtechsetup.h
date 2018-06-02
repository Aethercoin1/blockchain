#ifndef ATHTECHSETUP_H
#define ATHTECHSETUP_H

#include "wallet/ATHtech.h"

#include <QDialog>
#include <QVBoxLayout>

namespace Ui {
class ATHtechsetup;
}

class ATHtechsetup : public QDialog
{
    Q_OBJECT

public:
    explicit ATHtechsetup(QWidget *parent = 0);
    ~ATHtechsetup();

private:
    Ui::ATHtechsetup *ui;

public Q_SLOTS:
    void reloadATHtechServers();
    void addATHtechServer();
    void removeATHtechServer();
    void getinfoATHtechServer();
    void showButtons(bool show=true);
    void showATHtechIntro();

};

#endif // ATHTECHSETUP_H
