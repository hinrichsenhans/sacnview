#ifndef LEVELLOGWINDOW_H
#define LEVELLOGWINDOW_H

#include <QDialog>

namespace Ui {
class LevelLogWindow;
}

class LevelLogWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LevelLogWindow(QWidget *parent = 0);
    ~LevelLogWindow();

public slots:
    void saveClicked();
    void clearClicked();

private:
    void setUpModel();
    Ui::LevelLogWindow *ui;
};

#endif // LEVELLOGWINDOW_H
