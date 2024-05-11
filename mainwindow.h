#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>
#include <vector>
#include <QMovie>
#include <QPalette>
#include <QGraphicsDropShadowEffect>

#include "player/player.h"
#include "heroes/hero.h"
#include "heroes/Lina/lina.h"

#include "heroes/Lina/linadetails.h"
#include "heroes/Phoenix/phoenixdetails.h"

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
    void rewriteFile();

    void on_profilesTable_cellClicked(int row, int column);

    void on_deleteProfile_button_clicked();



    void on_createProfile_button_clicked();

    void on_playersProfiles_addButton_clicked();

    void on_playersProfiles_addCancel_clicked();

    void on_editProfile_button_clicked();

    void on_playersProfiles_editButton_clicked();

    void on_playersProfiles_editCancel_clicked();

    void on_pushButton_5_clicked();

    void on_endGame_button_clicked();

    void on_pushButton_3_clicked();

    void on_LinaDetails_button_clicked();

    void on_PhoenixChoose_button_clicked();

    void on_PhoenixDetails_button_clicked();

private:
    Ui::MainWindow *ui;

    //Player* players[100];
    std::vector<Player*> players;


    int selectedProfile;
    int playersCount = 0;

    QString* selectedProfilesForGame = new QString[2];
    int currentChoosing = 0;

    std::vector<Hero> heroes;
    int currentHeroChoosing = 0;

    LinaDetails linaDetails;
    PhoenixDetails phoenixDetails;
};
#endif // MAINWINDOW_H
