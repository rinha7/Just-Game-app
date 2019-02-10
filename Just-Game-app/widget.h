// widget.h is for MainWindow Page widget

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);


    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
