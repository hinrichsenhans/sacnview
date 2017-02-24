#ifndef LEVELLOGVIEW_H
#define LEVELLOGVIEW_H

#include <QWidget>

namespace Ui {
class LevelLogView;
}

class LevelLogView : public QWidget
{
    Q_OBJECT

public:
    explicit LevelLogView(QWidget *parent = 0);
    ~LevelLogView();

private:
    Ui::LevelLogView *ui;
};

#endif // LEVELLOGVIEW_H
