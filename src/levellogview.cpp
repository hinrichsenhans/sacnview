#include "levellogview.h"
#include "ui_levellogview.h"

LevelLogView::LevelLogView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelLogView)
{
    ui->setupUi(this);
}

LevelLogView::~LevelLogView()
{
    delete ui;
}
