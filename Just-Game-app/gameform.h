//gameform.h is form that displaying game's name, description, update log in new tab

#ifndef GAMEFORM_H
#define GAMEFORM_H

#include <QWidget>


namespace Ui{
class GameForm;
}

class GameForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameForm(QWidget *parent = nullptr);
    explicit GameForm(QWidget *parent = nullptr,QString gname=nullptr, QString gdesc=nullptr, QString gnotes=nullptr);
    ~GameForm();

private:
    Ui::GameForm *ui;
};


#endif // GAMEFORM_H
