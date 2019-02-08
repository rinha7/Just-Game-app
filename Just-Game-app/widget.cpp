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
    ui->tabWidget->addTab(new GameForm(nullptr,st,"desc","notes"),st);

}

void Widget::on_recentGame1_clicked()
{
    ui->tabWidget->addTab(new GameForm(nullptr,ui->recentGame1->text(),"desc","notes"),ui->recentGame1->text());
}
void Widget::on_recentGame2_clicked()
{
    ui->tabWidget->addTab(new GameForm(nullptr,ui->recentGame2->text(),"desc","notes"),ui->recentGame2->text());

}
void Widget::on_recentGame3_clicked()
{
    ui->tabWidget->addTab(new GameForm(nullptr,ui->recentGame3->text(),"desc","notes"),ui->recentGame3->text());

}
void Widget::on_recentGame4_clicked()
{
    ui->tabWidget->addTab(new GameForm(nullptr,ui->recentGame4->text(),"desc","notes"),ui->recentGame4->text());

}
void Widget::on_recentGame5_clicked()
{
    ui->tabWidget->addTab(new GameForm(nullptr,ui->recentGame5->text(),"desc","notes"),ui->recentGame5->text());
    ;
}
void Widget::on_recentGame6_clicked()
{
    ui->tabWidget->addTab(new GameForm(nullptr,ui->recentGame6->text(),"desc","notes"),ui->recentGame6->text());

}

void Widget::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

