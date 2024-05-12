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
#include <QKeyEvent>

#include "player/player.h"
#include "heroes/hero.h"

#include "heroes/Lina/lina.h"
#include "heroes/Phoenix/phoenix.h"
#include "heroes/Venomancer/venomancer.h"
#include "heroes/DrowRanger/drowranger.h"
#include "heroes/DragonKnight/dragonknight.h"

#include "heroes/Lina/linadetails.h"
#include "heroes/Phoenix/phoenixdetails.h"
#include "heroes/Venomancer/venomancerdetails.h"
#include "heroes/DrowRanger/drowrangerdialog.h"
#include "heroes/DragonKnight/dragonknightdetails.h"


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

    void on_VenomancerChoose_button_clicked();

    void on_VenomancerDetails_button_clicked();

    void on_DRDetails_button_clicked();

    void on_DRChoose_button_clicked();

    void on_DKChoose_button_clicked();

    void on_DKDetails_button_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_startGame_clicked();

protected:
    void keyPressEvent(QKeyEvent *event) override;

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
    VenomancerDetails venomancerDetails;
    DrowRangerDialog drowRangerDetails;
    DragonKnightDetails dragonKnightDetails;

    bool isStageAnnouncement = false;
    bool isPlayer1Ready = false;
    bool isPlayer2Ready = false;

    int stageCount = 1;

};
#endif // MAINWINDOW_H
