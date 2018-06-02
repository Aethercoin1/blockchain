#include "ATHtechinit.h"
#include "ui_ATHtechinit.h"
#include "net.h"
#include "util.h"
#include "skinize.h"

#include <string>
#include <iostream>

#include <QStringList>
#include <QUrl>

ATHTechInit::ATHTechInit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ATHTechInit)
{
    ui->setupUi(this);
}

ATHTechInit::~ATHTechInit()
{
    delete ui;
}

void ATHTechInit::ShowATHtechIntro(bool exitAfter)
{
    ATHTechInit ATHtechinit;
    ATHtechinit.setWindowIcon(QIcon(":icons/aethercoin"));
    ATHtechinit.setStyleSheet(Skinize());

    if(!ATHtechinit.exec())
    {
        if(exitAfter)
            exit(0);
        else
            return;
    }

    QString ServersToAdd = ATHtechinit.GetServers();
    QStringList ss = ServersToAdd.split('\n');

    for (int i = 0; i < ss.size(); ++i){
        QString Server = ss.at(i);
        QString strippedServer = Server.remove(' ');
        if(strippedServer != "")
        {
            WriteConfigFile("addanonserver",strippedServer.toStdString());
        }
    }
}

QString ATHTechInit::GetServers()
{
    return ui->plainTextEdit->toPlainText();
}
