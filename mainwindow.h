#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btn0_clicked();
    void on_btn1_clicked();
    void on_btn2_clicked();
    void on_btn3_clicked();
    void on_btn4_clicked();
    void on_btn5_clicked();
    void on_btn6_clicked();
    void on_btn7_clicked();
    void on_btn8_clicked();


    void on_actionNew_Game_triggered();



private:
    Ui::MainWindow *ui;
    void reset();
    void update();
    bool turn;
    QString a;
    void writeToArray(int);
    void switchTurn();
    void checkMatch(int,int,int);
    void checkWin();

private:
    QString board[9];
};
#endif // MAINWINDOW_H
