#ifndef STATYSTYKI_H
#define STATYSTYKI_H

#include <QDialog>

namespace Ui {
class Statystyki;
}

class Statystyki : public QDialog
{
    Q_OBJECT

public:
    explicit Statystyki(QWidget *parent = nullptr);
    ~Statystyki();

private:
    Ui::Statystyki *ui;
};

#endif // STATYSTYKI_H
