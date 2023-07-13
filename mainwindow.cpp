#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ostream>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset(){
    turn = true;
    for (int i=0;i<9;i++) {
        board[i] = "";
    }


}
void MainWindow::update(){
    ui->btn0->setText(QString(board[0]));
    ui->btn1->setText(QString(board[1]));
    ui->btn2->setText(QString(board[2]));
    ui->btn3->setText(QString(board[3]));
    ui->btn4->setText(QString(board[4]));
    ui->btn5->setText(QString(board[5]));
    ui->btn6->setText(QString(board[6]));
    ui->btn7->setText(QString(board[7]));
    ui->btn8->setText(QString(board[8]));
}


void MainWindow::checkMatch(int move1,int move2,int move3){
    if (board[move1] == board[move2] &&
        board[move2] == board[move3]) {

        if (board[move1] == "X"){
         std::cout << "Player 1 wins!" << std::endl;
        }
        if (board[move1] == "O") {
         std::cout << "Player 2 wins!"  << std::endl;
        }
    }

}

void MainWindow::checkWin(){
    checkMatch(0,1,2);
    checkMatch(3,4,5);
    checkMatch(6,7,8);
    checkMatch(0,4,8);
    checkMatch(2,4,6);
    checkMatch(0,3,6);
    checkMatch(1,4,7);
    checkMatch(2,5,8);
}

void MainWindow::on_btn0_clicked(){writeToArray(0);}
void MainWindow::on_btn1_clicked(){writeToArray(1);}
void MainWindow::on_btn2_clicked(){writeToArray(2);}
void MainWindow::on_btn3_clicked(){writeToArray(3);}
void MainWindow::on_btn4_clicked(){writeToArray(4);}
void MainWindow::on_btn5_clicked(){writeToArray(5);}
void MainWindow::on_btn6_clicked(){writeToArray(6);}
void MainWindow::on_btn7_clicked(){writeToArray(7);}
void MainWindow::on_btn8_clicked(){writeToArray(8);}




void MainWindow::writeToArray(int btnPos) {
    if (turn) {
        a = "X";
        turn = false;
    } else {
        a = "O";
        turn = true;
    }
    board[btnPos] = a;

    update();
    checkWin();

}










void MainWindow::on_actionNew_Game_triggered()
{
    reset();
    update();

}






