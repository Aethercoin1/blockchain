#ifndef ATHTECHINIT_H
#define ATHTECHINIT_H

#include <QDialog>

namespace Ui {
class ATHTechInit;
}

class ATHTechInit : public QDialog
{
    Q_OBJECT

public:
    explicit ATHTechInit(QWidget *parent = 0);
    ~ATHTechInit();
    QString GetServers();
    void ShowATHtechIntro(bool exitAfter = true);

private:
    Ui::ATHTechInit *ui;
};

#endif // ATHTECHINIT_H
