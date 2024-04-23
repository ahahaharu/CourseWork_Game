#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget_2->verticalHeader()->hide();
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);

    readFromFile();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_12_clicked() // выйти из игры
{
    QApplication::quit();
}


void MainWindow::on_pushButton_11_clicked() // начать игру
{
    ui->stackedWidget->setCurrentWidget(ui->playersScreen);
}


void MainWindow::on_pushButton_clicked() // выход в главное меню
{
    ui->stackedWidget->setCurrentWidget(ui->startMenu);
}


void MainWindow::on_pushButton_4_clicked() // переход на вкладку добавления игрока
{
    ui->lineEdit->clear();
    ui->profileStackedWidget->setCurrentWidget(ui->addPLayer);
    ui->playerChoosin_label->hide();

}

void MainWindow::readFromFile() {
    QFile file("../../db/PlayersDataBase.txt");

    if (!file.open(QIODevice::ReadOnly)) {
        return;
    } else {

    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QString name = "";
        QString gamePlayed = "";
        QString winGames = "";

        int i = 0;

        while (line[i] != ';') {
            name += line[i];
            i++;
        }

        i++;

        while (line[i] != ';') {
            gamePlayed += line[i];
            i++;
        }

        i++;

        while (line[i] != ';') {
            winGames += line[i];
            i++;
        }

        i++;

        players[playersCount] = new Player(name, gamePlayed.toInt(), winGames.toInt());

        ui->tableWidget_2->insertRow(playersCount);

        QTableWidgetItem *col1Item = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(playersCount,0,col1Item);

        QTableWidgetItem *col2Item = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->tableWidget_2->setItem(playersCount,1,col2Item);

        QTableWidgetItem *col3Item = new QTableWidgetItem(players[playersCount]->winRate());
        ui->tableWidget_2->setItem(playersCount,2,col3Item);

        playersCount++;
    }
}


void MainWindow::on_addPlayer_cancel_clicked() // переход на вкладку выбора игрока (отмена)
{
    ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer);

}

bool MainWindow::isPlayerExist(QString name) {
    for (int i = 0; i < playersCount; i++) {
        if (players[i]->getName() == name) {
            return true;
        }
    }

    return false;
}
bool MainWindow::isPlayerNameCorrect(QString name) {
    bool isSpace = true;

    for (int i = 0; i < name.length(); i++) {
        if (name[i] != ' ') {
            isSpace = false;
        }
    }

    if (isSpace || name.isEmpty()) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Имя не может быть пустым или содержать только пробелы");
        return false;
    }

    if (name[0] == ' ') {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Имя не может начинаться с пробела");
        return false;
    }

    QRegularExpression regex("^[\\p{L}0-9 ]+$");
    if(!regex.match(name).hasMatch()) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Имя должно содержать только буквы, цифры и пробелы");
        return false;
    }

    return true;
}

void MainWindow::on_pushButton_2_clicked() // переход на вкладку выбора игрока + добавление игрока
{


    QString name = ui->lineEdit->text();

    if (isPlayerExist(name)) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Профиль с таким же именем уже существует!\nВыберите другое имя");
        return;
    }

    if(isPlayerNameCorrect(name)) {

        ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer);
        ui->playerChoosin_label->show();

        ui->tableWidget_2->insertRow(playersCount);

        players[playersCount] = new Player(name, 0, 0);


        QTableWidgetItem *col1Item = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(playersCount,0,col1Item);

        QTableWidgetItem *col2Item = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->tableWidget_2->setItem(playersCount,1,col2Item);

        QTableWidgetItem *col3Item = new QTableWidgetItem(players[playersCount]->winRate());
        ui->tableWidget_2->setItem(playersCount,2,col3Item);



        QFile file("../../db/PlayersDataBase.txt");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);
        out << players[playersCount]->getName() << ";" << players[playersCount]->getGamePlayed() << ";" << players[playersCount]->getWinGames() << ";\n";

        playersCount++;
    }

}




void MainWindow::on_playersProfiles_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->playersProfiles);
}

void MainWindow::on_profiles_returnToMenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->startMenu);
}

void MainWindow::on_tableWidget_2_cellClicked(int row, int column)
{
    ui->pushButton_5->setEnabled(true);
}

