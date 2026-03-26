#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CurrentPlayer = "X";
    StateGame = true;
    Owins = 0;
    Xwins = 0;

    connect(ui->btn_0_0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->btn_0_1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->btn_0_2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->btn_1_0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->btn_1_1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->btn_1_2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->btn_2_0, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->btn_2_1, SIGNAL(clicked()), this, SLOT(onButtonClicked()));
    connect(ui->btn_2_2, SIGNAL(clicked()), this, SLOT(onButtonClicked()));

    connect(ui->btnExit, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onButtonClicked(){
    QPushButton *button = qobject_cast<QPushButton *>(sender());

    if(!button){return;}

    QString name = button->objectName();

    int row = name.at(4).digitValue();
    int col = name.at(6).digitValue();

    if(!StateGame || !FieldState[row][col].isEmpty()){
        return;
    } else {
        button->setText(CurrentPlayer);
        FieldState[row][col] = CurrentPlayer;
    }

    if(CurrentPlayer == "X"){
        CurrentPlayer = "O";
    } else {
        CurrentPlayer = "X";
    }

    checkWinner();
}


void MainWindow::checkWinner(){
    if(FieldState[0][0] != "" && FieldState[0][0] == FieldState[0][1] && FieldState[0][1] == FieldState[0][2]){
        StateGame = false;
        if(FieldState[0][0] == "X"){
            Xwins++;
            ui->labelXWins->setText("X : " + QString::number(Xwins));
        } else {
            Owins++;
            ui->labelXWins->setText("X : " + QString::number(Owins));
        }

        QMessageBox::information(this, "🎉 Победа!", "Игрок " + FieldState[0][0] + " выиграл!");
    }

    if(FieldState[1][0] != "" && FieldState[1][0] == FieldState[1][1] && FieldState[1][1] == FieldState[1][2]){
        StateGame = false;
        if(FieldState[1][0] == "X"){
            Xwins++;
            ui->labelXWins->setText("X : " + QString::number(Xwins));
        } else {
            Owins++;
            ui->labelOWins->setText("O : " + QString::number(Owins));
        }

        QMessageBox::information(this, "🎉 Победа!", "Игрок " + FieldState[1][0] + " выиграл!");
    }

    if(FieldState[2][0] != "" && FieldState[2][0] == FieldState[2][1] && FieldState[2][1] == FieldState[2][2]){
        StateGame = false;
        if(FieldState[2][0] == "X"){
            Xwins++;
            ui->labelXWins->setText("X : " + QString::number(Xwins));
        } else {
            Owins++;
            ui->labelOWins->setText("O : " + QString::number(Owins));
        }

        QMessageBox::information(this, "🎉 Победа!", "Игрок " + FieldState[2][0] + " выиграл!");
    }

    // Столбец 0
    if (FieldState[0][0] != "" &&
        FieldState[0][0] == FieldState[1][0] &&
        FieldState[1][0] == FieldState[2][0]) {
        StateGame = false;
        if(FieldState[0][0] == "X"){
            Xwins++;
            ui->labelXWins->setText("X : " + QString::number(Xwins));
        } else {
            Owins++;
            ui->labelOWins->setText("O : " + QString::number(Owins));
        }

        QMessageBox::information(this, "🎉 Победа!", "Игрок " + FieldState[0][0] + " выиграл!");
    }

    // Столбец 1
    if (FieldState[0][1] != "" &&
        FieldState[0][1] == FieldState[1][1] &&
        FieldState[1][1] == FieldState[2][1]) {
        StateGame = false;
        if(FieldState[0][1] == "X"){
            Xwins++;
            ui->labelXWins->setText("X : " + QString::number(Xwins));
        } else {
            Owins++;
            ui->labelOWins->setText("O : " + QString::number(Owins));
        }

        QMessageBox::information(this, "🎉 Победа!", "Игрок " + FieldState[0][1] + " выиграл!");
    }

    // Столбец 2
    if (FieldState[0][2] != "" &&
        FieldState[0][2] == FieldState[1][2] &&
        FieldState[1][2] == FieldState[2][2]) {
        StateGame = false;
        if(FieldState[0][2] == "X"){
            Xwins++;
            ui->labelXWins->setText("X : " + QString::number(Xwins));
        } else {
            Owins++;
            ui->labelOWins->setText("O : " + QString::number(Owins));
        }

        QMessageBox::information(this, "🎉 Победа!", "Игрок " + FieldState[0][2] + " выиграл!");
    }

    if (FieldState[0][0] != "" &&
        FieldState[0][0] == FieldState[1][1] &&
        FieldState[1][1] == FieldState[2][2]) {
        StateGame = false;
        if(FieldState[0][0] == "X"){
            Xwins++;
            ui->labelXWins->setText("X : " + QString::number(Xwins));
        } else {
            Owins++;
            ui->labelOWins->setText("O : " + QString::number(Owins));
        }

        QMessageBox::information(this, "🎉 Победа!", "Игрок " + FieldState[0][0] + " выиграл!");
    }

    if (FieldState[2][0] != "" &&
        FieldState[2][0] == FieldState[1][1] &&
        FieldState[1][1] == FieldState[0][2]) {
        StateGame = false;
        if(FieldState[2][0] == "X"){
            Xwins++;
            ui->labelXWins->setText("X :" + QString::number(Xwins));
        } else {
            Owins++;
            ui->labelOWins->setText("O :" + QString::number(Owins));
        }

        QMessageBox::information(this, "🎉 Победа!", "Игрок " + FieldState[2][0] + " выиграл!");
    }

    if(StateGame){
        bool isDraw = true;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(FieldState[i][j] == ""){
                    isDraw = false;
                    break;
                }
            }
        }

        if(isDraw){
            StateGame = false;
            QMessageBox::information(this, "Ничья!", "Ничья! Попробуйте ещё раз!");
        }
    }
}


void MainWindow::resetGame(){

}

void MainWindow::on_btnReset_clicked()
{
    StateGame = true;
    CurrentPlayer = "X";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            FieldState[i][j] = "";
            QString button = "btn_" + QString::number(i) + "_" + QString::number(j);
            QPushButton *btn = findChild<QPushButton*>(button);
            if(btn){
                btn->setText("");
            }

        }
    }
}


void MainWindow::on_btnReset_2_clicked()
{
    ui->labelXWins->setText("X :" + QString::number(0));
    ui->labelOWins->setText("O :" + QString::number(0));
}


void MainWindow::onExitClicked() {
    close();
}

void MainWindow::animateButton(QPushButton *button, const QString &text) {
    // 1. Создаём эффект прозрачности
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(button);
    button->setGraphicsEffect(effect);

    // 2. Устанавливаем начальную прозрачность (0% - невидимый)
    effect->setOpacity(0);

    // 3. Устанавливаем текст (пока невидимый)
    button->setText(text);

    // 4. Создаём анимацию
    QPropertyAnimation *animation = new QPropertyAnimation(effect, "opacity");
    animation->setDuration(300);  // 300 мс = 0.3 секунды
    animation->setStartValue(0);  // От 0%
    animation->setEndValue(1);    // До 100%

    // 5. Запускаем анимацию
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}
