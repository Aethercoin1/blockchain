#include "ATHtechsetup.h"
#include "ATHtechitem.h"
#include "ui_ATHtechsetup.h"
#include "net.h"
#include "skinize.h"
#include "util.h"

#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QListWidget>
#include <QMessageBox>
#include <QtNetwork>
#include <QWidget>

ATHtechsetup::ATHtechsetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ATHtechsetup)
{
    ui->setupUi(this);
    ui->getInfoButton->setVisible(false);
    ui->removeButton->setVisible(false);

    ui->saveButton->setVisible(false);

    this->setWindowTitle("ATHtech");

    connect(ui->addNewButton,SIGNAL(clicked()),this,SLOT(addATHtechServer()));
    connect(ui->getInfoButton,SIGNAL(clicked()),this,SLOT(getinfoATHtechServer()));
    connect(ui->removeButton,SIGNAL(clicked()),this,SLOT(removeATHtechServer()));
    connect(ui->serversListWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(showButtons()));
    connect(ui->saveButton,SIGNAL(clicked()),this,SLOT(close()));

    reloadATHtechServers();
}

ATHtechsetup::~ATHtechsetup()
{
    delete ui;
}

void ATHtechsetup::addATHtechServer()
{
    QString serverToAdd = ui->addServerText->text();

    if(serverToAdd == "")
        return;

    serverToAdd = serverToAdd.remove(' ').remove('\n').remove('\r').remove('\t');

    LOCK(cs_vAddedAnonServers);
    std::vector<std::string>::iterator it = vAddedAnonServers.begin();
    for(; it != vAddedAnonServers.end(); it++)
        if (serverToAdd.toStdString() == *it)
            break;

    WriteConfigFile("addanonserver", serverToAdd.toStdString());
    if (it == vAddedAnonServers.end())
        vAddedAnonServers.push_back(serverToAdd.toStdString());

    ui->addServerText->clear();

    reloadATHtechServers();
}

void ATHtechsetup::reloadATHtechServers()
{
    ui->serversListWidget->clear();

    const std::vector<std::string>& confAnonServers = mapMultiArgs["-addanonserver"];

    BOOST_FOREACH(std::string confAnonServer, confAnonServers) {
        ui->serversListWidget->addItem(QString::fromStdString(confAnonServer));
    }

    BOOST_FOREACH(std::string vAddedAnonServer, vAddedAnonServers) {
        ui->serversListWidget->addItem(QString::fromStdString(vAddedAnonServer));
    }
}

void ATHtechsetup::showATHtechIntro()
{
    setWindowIcon(QIcon(":icons/aethercoin"));
    setStyleSheet(Skinize());

    ui->saveButton->setVisible(true);

    exec();
}

void ATHtechsetup::removeATHtechServer()
{
    QString serverToRemove = ui->serversListWidget->currentItem()->text();

    if(serverToRemove == "")
        return;

    QMessageBox::StandardButton btnRetVal = QMessageBox::question(this, tr("Remove ATHtech server"),
        tr("You are about to remove the following ATHtech server: ") + "<br><br>" + serverToRemove + "<br><br>" + tr("Are you sure?"),
        QMessageBox::Yes | QMessageBox::Cancel, QMessageBox::Cancel);

    if(btnRetVal == QMessageBox::Cancel)
        return;

    LOCK(cs_vAddedAnonServers);
    std::vector<std::string>::iterator it = vAddedAnonServers.begin();

    RemoveConfigFile("addanonserver", serverToRemove.toStdString());
    for(; it != vAddedAnonServers.end(); it++)
        if (serverToRemove == QString::fromStdString(*it))
            break;

    if (it != vAddedAnonServers.end())
    {
      vAddedAnonServers.erase(it);
      QMessageBox::critical(this, windowTitle(),
          tr("Removed."),
          QMessageBox::Ok, QMessageBox::Ok);
    }

    showButtons(false);
    reloadATHtechServers();
}

void ATHtechsetup::showButtons(bool show)
{
    ui->getInfoButton->setVisible(show);
    ui->removeButton->setVisible(show);
}

void ATHtechsetup::getinfoATHtechServer()
{
    QString serverToCheck = ui->serversListWidget->currentItem()->text();

    if(serverToCheck == "")
        return;

    QStringList server = serverToCheck.split(':');

    if(server.length() != 2)
        return;

    try {
        ATHtech *ATHtechobj = new ATHtech();
        UniValue data = ATHtechobj->GetServerInfo(serverToCheck.toStdString());

        QMessageBox::information(this, windowTitle(),
            tr("ATHtech server") + "<br><br>" +  tr("Address: ") + serverToCheck + "<br>" + tr("Min amount: ") + QString::number(data["min_amount"].get_real()) + " <br>" + tr("Max amount: ") + QString::number(data["max_amount"].get_real()) + "<br>" + tr("Tx fee: ") + QString::number(data["transaction_fee"].get_real()) + "%",
            QMessageBox::Ok, QMessageBox::Ok);
    }
    catch(const std::runtime_error &e)
    {
        QMessageBox::warning(this, tr("ATHtech server"),
                             "<qt>Could not get info:<br/><br/>" +
                             tr(e.what())+"</qt>");
    }
}
