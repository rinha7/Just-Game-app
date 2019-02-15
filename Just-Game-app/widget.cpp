#include "widget.h"
#include "ui_widget.h"
#include "gameform.h"
#include "ui_gameform.h"
#include "logindialog.h"
#include "registerdialog.h"

#include <QString>
#include <QListWidgetItem>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Just-Game");

    //create network access manager
    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    connect(mgr, SIGNAL(finished(QNetworkReply*)), this, SLOT(onLoadnamesFinish(QNetworkReply*)));
    connect(mgr, SIGNAL(finished(QNetworkReply*)), mgr, SLOT(deleteLater()));
    mgr->get(QNetworkRequest(QUrl("http://localhost:3000/games/names")));

    ui->tabWidget->removeTab(1);    //remove index(1) tab
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString currentGamename = item->text();

    //set gamepage
    //if there are opened page, tab cursor will move to there
    bool gameopen = false;
    for(int i=0;i<ui->tabWidget->count();i++){
        if(ui->tabWidget->tabText(i) == currentGamename){
            gameopen = true;
            ui->tabWidget->setCurrentIndex(i);
            break;
        }
    }

    //if there aren't gamepage, add the gamepage tab
    if (gameopen == 0) {
        //request from nodejs server and call finishmethod to addtab
        QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
        connect(mgr, SIGNAL(finished(QNetworkReply*)), this, SLOT(onLoadgameinfoFinish(QNetworkReply*)));
        connect(mgr, SIGNAL(finished(QNetworkReply*)), mgr, SLOT(deleteLater()));
        mgr->get(QNetworkRequest(QUrl("http://localhost:3000/games/info/"+currentGamename)));
    }
}

void Widget::on_tabWidget_tabCloseRequested(int index)
{
    if(index==0) ;
    else ui->tabWidget->removeTab(index);
}

void Widget::on_loginbtn_clicked()
{
    loginDialog *diag = new loginDialog();
    diag->show();
}

void Widget::on_registerbtn_clicked()
{
    registerDialog *diag = new registerDialog();
    diag->show();
}

void Widget::onLoadnamesFinish(QNetworkReply *rep){
    QByteArray bts = rep->readAll();
    QString str(bts);
    QJsonDocument json_doc = QJsonDocument::fromJson(bts);
    QJsonArray a = json_doc.array();
    foreach(QJsonValue var, json_doc.array()){
        QString gamename = var.toObject().value("name").toString();
        ui->listWidget->addItem(gamename);
    }
}

void Widget::onLoadgameinfoFinish(QNetworkReply *rep){
    //add tab from game/info page
    QByteArray bts = rep->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(bts);
    QJsonObject obj = json_doc.array().at(0).toObject();

    QString _name = obj["name"].toString();
    QString _desc = obj["description"].toString();

    ui->tabWidget->setCurrentIndex(ui->tabWidget->addTab(new GameForm(nullptr, _name ,_desc ,"notes"),_name));
}
