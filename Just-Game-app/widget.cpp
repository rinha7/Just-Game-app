#include "widget.h"
#include "ui_widget.h"
#include "gameform.h"
#include "ui_gameform.h"

#include <QString>
#include <QListWidgetItem>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->addItem("The Game No.1");
    ui->listWidget->addItem("The Game No.2");
    ui->listWidget->addItem("The Game No.3");
    ui->tabWidget->removeTab(1);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QListWidgetItem *s = ui->listWidget->currentItem();
    QString st = s->text();

    //set gamepage
    //if there are opened page, tab cursor will move to there
    // else, add tab
    bool gameopen = false;
    for(int i=0;i<ui->tabWidget->count();i++){
        if(ui->tabWidget->tabText(i) == st){
            gameopen = true;
            ui->tabWidget->setCurrentIndex(i);
            break;
        }
    }
    if (gameopen == 0) ui->tabWidget->addTab(new GameForm(nullptr,st,"description","notes"),st);
}

void Widget::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

