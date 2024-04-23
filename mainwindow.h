#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>

#include "player.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_addPlayer_cancel_clicked();

    void on_pushButton_2_clicked();


    void on_playersProfiles_button_clicked();

    void on_profiles_returnToMenu_clicked();

    void on_tableWidget_2_cellClicked(int row, int column);

    bool isPlayerExist(QString);

    bool isPlayerNameCorrect(QString);

    void readFromFile();

private:
    Ui::MainWindow *ui;

    Player* players[100];

    int playersCount = 0;
};
#endif // MAINWINDOW_H
