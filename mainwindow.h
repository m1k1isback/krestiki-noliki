#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QMainWindow>
#include <QPushButton>

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

private:
    Ui::MainWindow *ui;
    QString CurrentPlayer;
    QString FieldState [3][3];
    bool StateGame;
    int Owins;
    int Xwins;

private slots:
    void onButtonClicked();
    void checkWinner();
    void resetGame();
    void on_btnReset_clicked();
    void on_btnReset_2_clicked();
    void onExitClicked();

    void animateButton(QPushButton *button, const QString &text);
};
#endif // MAINWINDOW_H
