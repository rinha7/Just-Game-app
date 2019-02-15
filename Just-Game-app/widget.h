// widget.h is for MainWindow Page widget

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QtNetwork/QNetworkReply>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    QString nn= "";

    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
    void on_tabWidget_tabCloseRequested(int index);
    void on_loginbtn_clicked();
    void on_registerbtn_clicked();

    void onLoadnamesFinish(QNetworkReply *rep);
    void onLoadgameinfoFinish(QNetworkReply *rep);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
