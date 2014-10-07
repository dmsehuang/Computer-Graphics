#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

/* hhj- inheritent from QDialog */
class Dialog : public QDialog
{
    Q_OBJECT

    // hhj - if no parent QWidget is passed to the Dialog, then it's null
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
