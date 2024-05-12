#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->startMenu);
    ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer);
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer);

    ui->tableWidget_2->verticalHeader()->hide();
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->profilesTable->verticalHeader()->hide();
    ui->profilesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->profilesTable->setSelectionMode(QAbstractItemView::SingleSelection);

    readFromFile();


    // гифки

    QMovie *lina = new QMovie("../../Resources/images/Heroes/Lina/Lina.gif");
    ui->LinaGif->setScaledContents(true);
    ui->LinaGif->setMovie(lina);
    lina->start();

    QMovie *phoenix = new QMovie("../../Resources/images/Heroes/Phoenix/Phoenix.gif");
    ui->PhoenixGif->setScaledContents(true);
    ui->PhoenixGif->setMovie(phoenix);
    phoenix->start();

    QMovie *venomancer = new QMovie("../../Resources/images/Heroes/Venomancer/Venomancer.gif");
    ui->VenomancerGif->setScaledContents(true);
    ui->VenomancerGif->setMovie(venomancer);
    venomancer->start();

    QMovie *drowRanger = new QMovie("../../Resources/images/Heroes/DrowRanger/DrowRanger.gif");
    ui->DrowRangerGif->setScaledContents(true);
    ui->DrowRangerGif->setMovie(drowRanger);
    drowRanger->start();

    QMovie *dragonKnight = new QMovie("../../Resources/images/Heroes/DragonKnight/DragonKnight.gif");
    ui->DragonKnightGif->setScaledContents(true);
    ui->DragonKnightGif->setMovie(dragonKnight);
    dragonKnight->start();


    movie = new QMovie("../../Resources/images/wallpaper.gif");
    processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();

    processLabel->setGeometry(0, 0, this->width(), this->height());
    processLabel->setScaledContents(true);

    this->setCentralWidget(ui->stackedWidget); // чтобы stackedWidget был наверху

    ui->LinaChoosed->hide();
    ui->PhoenixChoosed->hide();
    ui->VenomancerChoosed->hide();
    ui->DRChoosed->hide();
    ui->DKChoosed->hide();

    QGraphicsDropShadowEffect *effect1 = new QGraphicsDropShadowEffect;
    effect1->setBlurRadius(50);
    effect1->setXOffset(5);
    effect1->setYOffset(5);
    effect1->setColor(QColor(0, 0, 0, 255));

    QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect;
    effect2->setBlurRadius(50);
    effect2->setXOffset(5);
    effect2->setYOffset(5);
    effect2->setColor(QColor(0, 0, 0, 255));

    QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect;
    effect3->setBlurRadius(50);
    effect3->setXOffset(5);
    effect3->setYOffset(5);
    effect3->setColor(QColor(0, 0, 0, 255));

    QGraphicsDropShadowEffect *effect4 = new QGraphicsDropShadowEffect;
    effect4->setBlurRadius(50);
    effect4->setXOffset(5);
    effect4->setYOffset(5);
    effect4->setColor(QColor(0, 0, 0, 255));

    QGraphicsDropShadowEffect *effect5 = new QGraphicsDropShadowEffect;
    effect5->setBlurRadius(50);
    effect5->setXOffset(5);
    effect5->setYOffset(5);
    effect5->setColor(QColor(0, 0, 0, 255));

    ui->LinaChoosed->setGraphicsEffect(effect1);
    ui->PhoenixChoosed->setGraphicsEffect(effect2);
    ui->VenomancerChoosed->setGraphicsEffect(effect3);
    ui->DRChoosed->setGraphicsEffect(effect4);
    ui->DKChoosed->setGraphicsEffect(effect5);

    ui->player2_heroGif->setScaledContents(true);
    ui->player2Gif->setScaledContents(true);
    ui->player1_heroGif->setScaledContents(true);
    ui->player1Gif->setScaledContents(true);

    //connect(animationGroup1, &QSequentialAnimationGroup::finished, this, &MainWindow::onAnimationFinished1);

    /*if(animationGroup2 != nullptr) {
        connect(animationGroup2, &QSequentialAnimationGroup::finished, this, &MainWindow::onAnimationFinished2);
    }*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

// СТОРОННИЕ ФУНКЦИИ

void MainWindow::readFromFile() { // чтение информации с файла db.txt
    QFile file("../../db/PlayersDataBase.txt");

    if (!file.open(QIODevice::ReadOnly)) {
        return;
    } else {

    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.isEmpty()) {
            return;
        }

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

        players.push_back(new Player(name, gamePlayed.toInt(), winGames.toInt()));

        ui->tableWidget_2->insertRow(playersCount);
        ui->profilesTable->insertRow(playersCount);

        QTableWidgetItem *col1Item1 = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(playersCount,0,col1Item1);

        QTableWidgetItem *col1Item2 = new QTableWidgetItem(name);
        ui->profilesTable->setItem(playersCount,0,col1Item2);

        QTableWidgetItem *col2Item1 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->tableWidget_2->setItem(playersCount,1,col2Item1);

        QTableWidgetItem *col2Item2 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->profilesTable->setItem(playersCount,1,col2Item2);

        QTableWidgetItem *col3Item1 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->tableWidget_2->setItem(playersCount,2,col3Item1);

        QTableWidgetItem *col3Item2 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->profilesTable->setItem(playersCount,2,col3Item2);

        playersCount++;
    }
}

bool MainWindow::isPlayerExist(QString name) { // проверка на то, есть ли игрок в базе данных
    for (int i = 0; i < playersCount; i++) {
        if (players[i]->getName() == name) {
            return true;
        }
    }

    return false;
}

bool MainWindow::isPlayerNameCorrect(QString name) { // проверка на коррекность никнейма
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

void MainWindow::rewriteFile() { // перезапись файла
    QFile file("../../db/PlayersDataBase.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);

    for (int i = 0; i < playersCount; i++) {
        out << players[i]->getName() << ";" << players[i]->getGamePlayed() << ";" << players[i]->getWinGames() << ";\n";
    }
}

// ГЛАВНОЕ МЕНЮ

void MainWindow::on_pushButton_11_clicked() // начать игру
{
    ui->stackedWidget->setCurrentWidget(ui->playersScreen);
}

void MainWindow::on_playersProfiles_button_clicked() // посмотреть профиля игроков
{
    ui->stackedWidget->setCurrentWidget(ui->playersProfiles);
}

void MainWindow::on_pushButton_12_clicked() // выйти из игры
{
    QApplication::quit();
}

// ВКЛАДКА ВЫБОРА ПЕРСОНАЖА

void MainWindow::on_pushButton_clicked() // выход в главное меню
{
    ui->stackedWidget->setCurrentWidget(ui->startMenu);

    ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer);
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_4_clicked() // переход на вкладку добавления игрока
{
    ui->lineEdit->clear();
    ui->profileStackedWidget->setCurrentWidget(ui->addPLayer);
    ui->playerChoosin_label->hide();

}

    // ВКЛАДКА ВЫБОРА ПЕРСОНАЖА -> ВКЛАДКА ДОБАВЛЕНИЯ ИГРОКА
void MainWindow::on_addPlayer_cancel_clicked() // отмена +  переход на вкладку выбора профиля
{
    ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer);
    ui->lineEdit->clear();
    ui->label_3->show();

}


void MainWindow::on_pushButton_2_clicked() //добавление игрока + переход на вкладку выбора игрока
{
    QString name = ui->lineEdit->text();

    if (isPlayerExist(name)) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Профиль с таким же именем уже существует!\nВыберите другое имя");
        return;
    }

    if(isPlayerNameCorrect(name)) {

        ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer); // переход на вкладку с выбором персонажа
        ui->playerChoosin_label->show();

        ui->tableWidget_2->insertRow(playersCount);
        ui->profilesTable->insertRow(playersCount);

        players.push_back(new Player(name, 0, 0));


        QTableWidgetItem *col1Item1 = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(playersCount,0,col1Item1);

        QTableWidgetItem *col1Item2 = new QTableWidgetItem(name);
        ui->profilesTable->setItem(playersCount,0,col1Item2);

        QTableWidgetItem *col2Item1 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->tableWidget_2->setItem(playersCount,1,col2Item1);

        QTableWidgetItem *col2Item2 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->profilesTable->setItem(playersCount,1,col2Item2);

        QTableWidgetItem *col3Item1 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->tableWidget_2->setItem(playersCount,2,col3Item1);

        QTableWidgetItem *col3Item2 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->profilesTable->setItem(playersCount,2,col3Item2);



        QFile file("../../db/PlayersDataBase.txt");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);
        out << players[playersCount]->getName() << ";" << players[playersCount]->getGamePlayed() << ";" << players[playersCount]->getWinGames() << ";\n";

        playersCount++;
    }

}
    // КОНЕЦ ФУНКЦИЙ ДЛЯ 'ВКЛАДКА ДОБАВЛЕНИЯ ИГРОКА'

void MainWindow::on_profiles_returnToMenu_clicked() // выход в главное меню
{
    ui->stackedWidget->setCurrentWidget(ui->startMenu);

    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer);
    ui->playersProfiles_addLineEdit->clear();
}

void MainWindow::on_tableWidget_2_cellClicked(int row, int column) // активация кнопок при нажатии на строку таблицы
{
    QTableWidgetItem* item = ui->tableWidget_2->item(row, column);

    if (item != nullptr && !(item->flags() & Qt::ItemIsEnabled))
        return;

    ui->pushButton_5->setEnabled(true);
    ui->label_3->setText("Выбранный профиль: "+players[row]->getName());
}

// ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ

void MainWindow::on_profilesTable_cellClicked(int row, int column) // активация кнопкок при нажатии на строку таблицы
{
    ui->editProfile_button->setEnabled(true);
    ui->deleteProfile_button->setEnabled(true);
    ui->stats_button->setEnabled(true);

    selectedProfile = row;
}


void MainWindow::on_deleteProfile_button_clicked() // удаление профиля
{
    int selectedRow = ui->profilesTable->currentRow();

    players.erase(players.begin() + selectedRow);

    ui->profilesTable->removeRow(selectedRow);
    ui->tableWidget_2->removeRow(selectedRow);

    playersCount--;
    rewriteFile();

    if (playersCount == 0) {
        ui->editProfile_button->setEnabled(false);
        ui->deleteProfile_button->setEnabled(false);
        ui->stats_button->setEnabled(false);
    }
}

void MainWindow::on_createProfile_button_clicked() // переход на вкладку ДОБАВЛЕНИЕ ПРОФИЛЯ
{
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_createPlayer);
}

    // ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ -> ВКЛАДКА ДОБАВЛЕНИЯ ПРОФИЛЯ

void MainWindow::on_playersProfiles_addButton_clicked() // добавление профиля + переход на вкладку ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ
{
    QString name = ui->playersProfiles_addLineEdit->text();

    if (isPlayerExist(name)) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Профиль с таким же именем уже существует!\nВыберите другое имя");
        return;
    }

    if(isPlayerNameCorrect(name)) {

        ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer); // переход на вкладку ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ
        ui->playerChoosin_label->show();

        ui->tableWidget_2->insertRow(playersCount);
        ui->profilesTable->insertRow(playersCount);

        players.push_back(new Player(name, 0, 0));


        QTableWidgetItem *col1Item1 = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(playersCount,0,col1Item1);

        QTableWidgetItem *col1Item2 = new QTableWidgetItem(name);
        ui->profilesTable->setItem(playersCount,0,col1Item2);

        QTableWidgetItem *col2Item1 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->tableWidget_2->setItem(playersCount,1,col2Item1);

        QTableWidgetItem *col2Item2 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->profilesTable->setItem(playersCount,1,col2Item2);

        QTableWidgetItem *col3Item1 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->tableWidget_2->setItem(playersCount,2,col3Item1);

        QTableWidgetItem *col3Item2 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->profilesTable->setItem(playersCount,2,col3Item2);



        QFile file("../../db/PlayersDataBase.txt");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);
        out << players[playersCount]->getName() << ";" << players[playersCount]->getGamePlayed() << ";" << players[playersCount]->getWinGames() << ";\n";

        playersCount++;
    }
}

void MainWindow::on_playersProfiles_addCancel_clicked() // отмена
{
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer); // переход на вкалдку ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ
    ui->playersProfiles_addLineEdit->clear();
}

    // конец функций для ВКЛАДКА ДОБАВЛЕНИЯ ПРОФИЛЯ


void MainWindow::on_editProfile_button_clicked() // переход на вкладку ИЗМЕНЕНИЕ ПРОФИЛЯ
{
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_editPlayer);
    ui->playersProfiles_editLineEdit->setText(players[selectedProfile]->getName()); // выписывание имя профиля для дальнейшего изменения
}

    // ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ -> ИЗМЕНЕНИЯ ПРОФИЛЯ

void MainWindow::on_playersProfiles_editButton_clicked()
{

    QString name = ui->playersProfiles_editLineEdit->text();

    if (isPlayerExist(name)) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Профиль с таким же именем уже существует!\nВыберите другое имя");
        return;
    }

    if(isPlayerNameCorrect(name)) {

        ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer); // переход на вкладку ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ
        ui->playerChoosin_label->show();

        players[selectedProfile]->setName(name);

        QTableWidgetItem *col1Item1 = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(selectedProfile,0,col1Item1);

        QTableWidgetItem *col1Item2 = new QTableWidgetItem(name);
        ui->profilesTable->setItem(selectedProfile,0,col1Item2);

        QTableWidgetItem *col2Item1 = new QTableWidgetItem(QString::number(players[selectedProfile]->getGamePlayed()));
        ui->tableWidget_2->setItem(selectedProfile,1,col2Item1);

        QTableWidgetItem *col2Item2 = new QTableWidgetItem(QString::number(players[selectedProfile]->getGamePlayed()));
        ui->profilesTable->setItem(selectedProfile,1,col2Item2);

        QTableWidgetItem *col3Item1 = new QTableWidgetItem(players[selectedProfile]->winRate());
        ui->tableWidget_2->setItem(selectedProfile,2,col3Item1);

        QTableWidgetItem *col3Item2 = new QTableWidgetItem(players[selectedProfile]->winRate());
        ui->profilesTable->setItem(selectedProfile,2,col3Item2);

        rewriteFile();
    }
}


void MainWindow::on_playersProfiles_editCancel_clicked()
{
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer);
}

    // конец функций для ВКЛАДКА ИЗМЕНЕНИЯ ПРОФИЛЯ

void MainWindow::on_pushButton_5_clicked()
{
    int selectedRow = ui->tableWidget_2->currentRow();

    selectedProfilesForGame[currentChoosing] = players[selectedRow]->getName();
    currentChoosing++;

    ui->playerChoosin_label->setText("Игрок #2 выбирает профиль игрока");

    for (int column = 0; column < 3; ++column)
    {
        QTableWidgetItem* item = ui->tableWidget_2->item(selectedRow, column);

        if (item != nullptr)
        {
            item->setFlags(item->flags() & ~Qt::ItemIsEnabled);

            item->setForeground(Qt::gray);
        }
    }

    ui->label_3->setText("Выбранный профиль:");
    ui->pushButton_5->setEnabled(false);

    if (currentChoosing == 2) {
        ui->stackedWidget->setCurrentWidget(ui->selectHeroes);
        currentChoosing = 0;

        int rowCount = ui->tableWidget_2->rowCount();
        int columnCount = ui->tableWidget_2->columnCount();

        for (int row = 0; row < rowCount; ++row)
        {
            for (int column = 0; column < columnCount; ++column)
            {
                QTableWidgetItem* item = ui->tableWidget_2->item(row, column);

                if (item != nullptr)
                {
                    item->setFlags(item->flags() | Qt::ItemIsEnabled);
                    item->setForeground(Qt::black);
                }
            }
        }
        ui->player1_label->setText(selectedProfilesForGame[0]);
        ui->player2_label->setText(selectedProfilesForGame[1]);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[0]+"' выбирает персонажа");


    }



}


void MainWindow::on_endGame_button_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите завершить игру? Игра не будет засчитана.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->stackedWidget->setCurrentWidget(ui->startMenu);
    }

    ui->LinaChoosed->hide();
    ui->PhoenixChoosed->hide();
    ui->VenomancerChoosed->hide();
    ui->DRChoosed->hide();
    ui->DKChoosed->hide();

    ui->pushButton_3->setEnabled(true);
    ui->PhoenixChoose_button->setEnabled(true);
    ui->VenomancerChoose_button->setEnabled(true);
    ui->DRChoose_button->setEnabled(true);
    ui->DKChoose_button->setEnabled(true);

    heroes.clear();
    currentHeroChoosing = 0;
}



void MainWindow::on_pushButton_3_clicked()
{
    ui->LinaChoosed->show();
    ui->pushButton_3->setEnabled(false);


    heroes.push_back(Lina());
    currentHeroChoosing++;

    QMovie *lina = new QMovie("../../Resources/images/Heroes/Lina/Lina.gif");


    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Lina");
        ui->player2_heroGif->setMovie(lina);
        ui->player2Gif->setMovie(lina);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Lina");
        ui->player1_heroGif->setMovie(lina);
        ui->player1Gif->setMovie(lina);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    lina->start();
}


void MainWindow::on_LinaDetails_button_clicked()
{
    linaDetails.exec();
}


void MainWindow::on_PhoenixChoose_button_clicked()
{
    ui->PhoenixChoosed->show();
    ui->PhoenixChoose_button->setEnabled(false);

    QMovie *phoenix = new QMovie("../../Resources/images/Heroes/Phoenix/Phoenix.gif");



    heroes.push_back(Phoenix());
    currentHeroChoosing++;

    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Phoenix");
        ui->player2_heroGif->setMovie(phoenix);
        ui->player2Gif->setMovie(phoenix);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Phoenix");
        ui->player1_heroGif->setMovie(phoenix);
        ui->player1Gif->setMovie(phoenix);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    phoenix->start();
}


void MainWindow::on_PhoenixDetails_button_clicked()
{
    phoenixDetails.exec();
}


void MainWindow::on_VenomancerChoose_button_clicked()
{
    ui->VenomancerChoosed->show();
    ui->VenomancerChoose_button->setEnabled(false);

    QMovie *venomancer = new QMovie("../../Resources/images/Heroes/Venomancer/Venomancer.gif");

    heroes.push_back(Venomancer());
    currentHeroChoosing++;

    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Venomancer");
        ui->player2_heroGif->setMovie(venomancer);
        ui->player2Gif->setMovie(venomancer);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Venomancer");
        ui->player1_heroGif->setMovie(venomancer);
        ui->player1Gif->setMovie(venomancer);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    venomancer->start();
}


void MainWindow::on_VenomancerDetails_button_clicked()
{
    venomancerDetails.exec();
}


void MainWindow::on_DRDetails_button_clicked()
{
    drowRangerDetails.exec();
}


void MainWindow::on_DRChoose_button_clicked()
{
    ui->DRChoosed->show();
    ui->DRChoose_button->setEnabled(false);

    QMovie *drowRanger = new QMovie("../../Resources/images/Heroes/DrowRanger/DrowRanger.gif");

    heroes.push_back(DrowRanger());
    currentHeroChoosing++;

    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Drow Ranger");
        ui->player2_heroGif->setMovie(drowRanger);
        ui->player2Gif->setMovie(drowRanger);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Drow Ranger");
        ui->player1_heroGif->setMovie(drowRanger);
        ui->player1Gif->setMovie(drowRanger);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    drowRanger->start();
}


void MainWindow::on_DKChoose_button_clicked()
{
    ui->DKChoosed->show();
    ui->DKChoose_button->setEnabled(false);

    QMovie *dragonKnight = new QMovie("../../Resources/images/Heroes/DragonKnight/DragonKnight.gif");

    heroes.push_back(DragonKnight());
    currentHeroChoosing++;

    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Dragon Knight");
        ui->player2_heroGif->setMovie(dragonKnight);
        ui->player2Gif->setMovie(dragonKnight);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Dragon Knight");
        ui->player1_heroGif->setMovie(dragonKnight);
        ui->player1Gif->setMovie(dragonKnight);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    dragonKnight->start();
}


void MainWindow::on_DKDetails_button_clicked()
{
    dragonKnightDetails.exec();
}


void MainWindow::on_pushButton_7_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите завершить игру? Игра не будет засчитана.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->stackedWidget->setCurrentWidget(ui->startMenu);
    }

    ui->LinaChoosed->hide();
    ui->PhoenixChoosed->hide();
    ui->VenomancerChoosed->hide();
    ui->DRChoosed->hide();
    ui->DKChoosed->hide();

    ui->pushButton_3->setEnabled(true);
    ui->PhoenixChoose_button->setEnabled(true);
    ui->VenomancerChoose_button->setEnabled(true);
    ui->DRChoose_button->setEnabled(true);
    ui->DKChoose_button->setEnabled(true);

    heroes.clear();
    currentHeroChoosing = 0;
}


void MainWindow::on_pushButton_8_clicked()
{
    if (heroes[0].getName() == "Lina") {
        linaDetails.exec();
    } else if (heroes[0].getName() == "Phoenix") {
        phoenixDetails.exec();
    } else if (heroes[0].getName() == "Venomancer") {
        venomancerDetails.exec();
    } else if (heroes[0].getName() == "Drow Ranger") {
        drowRangerDetails.exec();
    } else {
        dragonKnightDetails.exec();
    }
}




void MainWindow::on_startGame_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stageAnnouncement);
    isStageAnnouncement = true;
    ui->nextStage->setText("Cтадия "+QString::number(stageCount)+": ФАРМ");
    ui->player1Name->setText(selectedProfilesForGame[0]);
    ui->player2Name->setText(selectedProfilesForGame[1]);
}

void MainWindow::keyPressEvent(QKeyEvent *event) // добавьте этот метод
{
    if (isStageAnnouncement) {
        if (event->text() == "w" || event->text() == "W" || event->text() == "ц" || event->text() == "Ц") {
            isPlayer1Ready = true;
            ui->player1Ready->setText("ГОТОВ");
            ui->player1Ready->setStyleSheet("QLabel { color : green; }");
        }

        if (event->text() == "o" || event->text() == "O" || event->text() == "щ" || event->text() == "Щ") {
            isPlayer2Ready = true;
            ui->player2Ready->setText("ГОТОВ");
            ui->player2Ready->setStyleSheet("QLabel { color : green; }");
        }

        if (isPlayer1Ready && isPlayer2Ready) {
            ui->stackedWidget->setCurrentWidget(ui->farmStage);
            isStageAnnouncement = false;
            processLabel->clear();

            ui->farm_player1->setText(selectedProfilesForGame[0]);
            ui->farm_player2->setText(selectedProfilesForGame[1]);



            ui->gold->setText("Золото за попадание: " + QString::number(goldFarm));

            count = 3;
            timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &MainWindow::countdown);
            timer->start(1000);
        }
    } else if (isFarmStage) {
        if ((event->text() == "w" || event->text() == "W" || event->text() == "ц" || event->text() == "Ц") && !isFinished1) {
            stop_rect1();
            isFinished1 = true;
            finishedBoth++;
        }

        if ((event->text() == "o" || event->text() == "O" || event->text() == "щ" || event->text() == "Щ") && !isFinished2) {
            stop_rect2();
            isFinished2 = true;
            finishedBoth++;
        }

        if (finishedBoth == 2) {
            finishedBoth = 0;
            count = 3; // начальное значение обратного отсчёта
            timer = new QTimer(this);
            // Подключение сигнала timeout к слоту
            connect(timer, &QTimer::timeout, this, &MainWindow::countdown);

            // Запуск таймера с интервалом в 1 секунду
            timer->start(1000);
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (isFarmStage) {

        painter.drawRect(10, 210, 500, 300);
        painter.drawRect(770, 210, 500, 300);

        painter.setBrush(Qt::black);

        painter.drawRect(10, 310, 500, 100);
        painter.drawRect(770, 310, 500, 100);

        // Установка жёлтого цвета для прямоугольника
        painter.setBrush(Qt::yellow);

        painter.drawRect(yellowRectPos1.x(), yellowRectPos1.y(), yellowRectSize, 100);
        painter.drawRect(yellowRectPos2.x(), yellowRectPos2.y(), yellowRectSize, 100);
    }
}

void MainWindow::countdown()
{
    if (farmStages == 3) {
        farmStageFinished = true;
        ui->labelTimer->clear();
        ui->farmStarting->setText("ФАРМ ОКОНЧЕН!");
        ui->farmGoldPlayer1->setText(selectedProfilesForGame[0]+" заработал "+QString::number(player1Received)+" золота");
        ui->farmGoldPlayer2->setText(selectedProfilesForGame[1]+" заработал "+QString::number(player2Received)+" золота");
        goldFarm += 50;
        speed = 1.0;
        timer->start(2000);
        if (yellowRectSize != 30) {
            yellowRectSize -= 5;
        }
        return;
    }
    if (count != 0) {
        ui->labelTimer->setText(QString::number(count));
    } else {
        ui->labelTimer->setText("GO!");
    }
    count--;
    if (count < 0) {
        timer->stop();
        isFarmStage = true;
        farmStages++;
        ui->player1Status->clear();
        ui->player2Status->clear();
        startAnimation1();
        startAnimation2();
        speed +=0.5;
    }
}

void MainWindow::stop_rect1()
{
    if (animationGroup1->state() == QAbstractAnimation::Running) {
        animationGroup1->stop();
        QPoint currentPos = rect1->pos();
        if (currentPos.x() > yellowRectPos1.x()-20 && currentPos.x() < yellowRectPos1.x()+yellowRectSize) {
            ui->player1Status->setText("ОТЛИЧНО!");
            heroes[0].addGold(goldFarm);
            player1Received += goldFarm;
        } else {
            ui->player1Status->setText("ПРОМАХ");
        }

        /*// Создание таймера для обратного отсчёта
        */
    }
}

void MainWindow::stop_rect2()
{
    if (animationGroup2->state() == QAbstractAnimation::Running) {
        animationGroup2->stop();
        QPoint currentPos = rect2->pos();
        if (currentPos.x() > yellowRectPos2.x()-20 && currentPos.x() < yellowRectPos2.x()+yellowRectSize) {
            ui->player2Status->setText("ОТЛИЧНО!");
            heroes[1].addGold(goldFarm);
            player2Received += goldFarm;
        } else {
            ui->player2Status->setText("ПРОМАХ");
        }

        /* // Создание таймера для обратного отсчёта
        count = 3; // начальное значение обратного отсчёта
        timer = new QTimer(this);
        // Подключение сигнала timeout к слоту
        connect(timer, &QTimer::timeout, this, &MainWindow::countdown);

        // Запуск таймера с интервалом в 1 секунду
        timer->start(1000);*/
    }
}

void MainWindow::startAnimation1()
{

    isFinished1 = false;

    if (rect1 != nullptr) {
        delete rect1;
    }

    rect1 = new AnimatedRect(this);
    rect1->move(10, 110);
    rect1->show();


    // Создание анимации для движения вперед
    QPropertyAnimation *animation1 = new QPropertyAnimation(rect1, "pos");
    animation1->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation1->setStartValue(QPoint(10, 310)); // начальная позиция
    animation1->setEndValue(QPoint(480, 310)); // конечная позиция

    // Создание анимации для движения назад
    QPropertyAnimation *animation2 = new QPropertyAnimation(rect1, "pos");
    animation2->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation2->setStartValue(QPoint(480, 310)); // начальная позиция
    animation2->setEndValue(QPoint(10, 310)); // конечная позиция

    QPropertyAnimation *animation3 = new QPropertyAnimation(rect1, "pos");
    animation3->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation3->setStartValue(QPoint(10, 310)); // начальная позиция
    animation3->setEndValue(QPoint(480, 310)); // конечная позиция

    // Создание группы анимаций
    animationGroup1 = new QSequentialAnimationGroup;
    animationGroup1->addAnimation(animation1);
    animationGroup1->addAnimation(animation2);
    animationGroup1->addAnimation(animation3);

    connect(animationGroup1, &QSequentialAnimationGroup::finished, this, &MainWindow::onAnimationFinished1);
    // Запуск анимации
    animationGroup1->start(QAbstractAnimation::DeleteWhenStopped);

    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    // Генерация случайной позиции для прямоугольника
    int randomX = rand() % (430 - 10 + 1) + 10; // случайное число в диапазоне от 10 до 480
    yellowRectPos1 = QPoint(randomX, 310);


    // Перерисовка окна
    update();

}

void MainWindow::startAnimation2()
{

    isFinished2 = false;

    if (rect2 != nullptr) {
        delete rect2;
    }

    rect2 = new AnimatedRect(this);
    rect2->move(10, 110);
    rect2->show();

    // Создание анимации для движения вперед
    QPropertyAnimation *animation1 = new QPropertyAnimation(rect2, "pos");
    animation1->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation1->setStartValue(QPoint(770, 310)); // начальная позиция
    animation1->setEndValue(QPoint(1240, 310)); // конечная позиция

    // Создание анимации для движения назад
    QPropertyAnimation *animation2 = new QPropertyAnimation(rect2, "pos");
    animation2->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation2->setStartValue(QPoint(1240, 310)); // начальная позиция
    animation2->setEndValue(QPoint(770, 310)); // конечная позиция

    QPropertyAnimation *animation3 = new QPropertyAnimation(rect2, "pos");
    animation3->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation3->setStartValue(QPoint(770, 310)); // начальная позиция
    animation3->setEndValue(QPoint(1240, 310)); // конечная позиция

    // Создание группы анимаций
    animationGroup2 = new QSequentialAnimationGroup;
    animationGroup2->addAnimation(animation1);
    animationGroup2->addAnimation(animation2);
    animationGroup2->addAnimation(animation3);

    connect(animationGroup2, &QSequentialAnimationGroup::finished, this, &MainWindow::onAnimationFinished2);
    // Запуск анимации
    animationGroup2->start(QAbstractAnimation::DeleteWhenStopped);

    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    // Генерация случайной позиции для прямоугольника
    int randomX = rand() % (430 - 10 + 1) + 770; // случайное число в диапазоне от 10 до 480
    yellowRectPos2 = QPoint(randomX, 310);


    // Перерисовка окна
    update();
}

void MainWindow::onAnimationFinished1() {
        isFinished1=true;
        ui->player1Status->setText("ПРОМАХ");

        count = 3; // начальное значение обратного отсчёта
        timer = new QTimer(this);
        // Подключение сигнала timeout к слоту
        finishedBoth = 0;
        connect(timer, &QTimer::timeout, this, &MainWindow::countdown);

        // Запуск таймера с интервалом в 1 секунду
        timer->start(1000);
}


void MainWindow::onAnimationFinished2() {
    if (isFinished1) {
        isFinished2=true;
        ui->player2Status->setText("ПРОМАХ");

        count = 3; // начальное значение обратного отсчёта
        timer = new QTimer(this);
        // Подключение сигнала timeout к слоту
        finishedBoth = 0;
        connect(timer, &QTimer::timeout, this, &MainWindow::countdown);

        // Запуск таймера с интервалом в 1 секунду
        timer->start(1000);
    }
}

