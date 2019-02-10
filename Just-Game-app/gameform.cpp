#include "gameform.h"
#include "ui_gameform.h"

GameForm::GameForm(QWidget *parent) :
    QWidget (parent),
    ui(new Ui::GameForm)
{
    ui->setupUi(this);
}
GameForm::GameForm(QWidget *parent, QString gname, QString gdesc, QString gnotes) :
    QWidget (parent),
    ui(new Ui::GameForm){
    ui->setupUi(this);

    ui->gamename->setText(gname);
    ui->gamedescription->setText(gdesc);
    ui->gamelog->setText(gnotes);
}
GameForm::~GameForm()
{
    delete ui;
}
