#include "levellogwindow.h"
#include "ui_levellogwindow.h"
#include "consts.h"

#include <QFileDialog>
#include <QStandardPaths>

LevelLogWindow::LevelLogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelLogWindow)
{
    ui->setupUi(this);
    connect(ui->saveToFileButton, &QPushButton::clicked, this, &LevelLogWindow::saveClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &LevelLogWindow::clearClicked);
}

LevelLogWindow::~LevelLogWindow()
{
    delete ui;
}

void LevelLogWindow::saveClicked()
{
    //Setup dialog box
    QFileDialog dialog(this);
    dialog.setWindowTitle(APP_NAME);
    dialog.setDirectory(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
    dialog.setNameFilter("Text Files (*.txt)");
    dialog.setDefaultSuffix("txt");
    dialog.selectFile("universe1.txt");
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if(dialog.exec()) {
        QString saveName = dialog.selectedFiles().at(0);
        if(saveName.isEmpty()) {
            return;
        }
    }
}

void LevelLogWindow::clearClicked()
{

}
