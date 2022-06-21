#include <QValidator>
#include <string>
#include "37_4_1_CalcMainWindow.h"
#include "ui_37_4_1_MainWindow.h"

using CMW = CalcMainWindow;

CMW::CalcMainWindow (QWidget *parent) : QMainWindow(parent) {
    ui = new Ui::MainWindow;
    ui->setupUi(this);
    ui->lineEdit_1->setValidator(new QIntValidator(this));
    ui->lineEdit_2->setValidator(new QIntValidator(this));

    QObject::connect(ui->pushButton_plus, &QPushButton::clicked, this, &CMW::addition);
    QObject::connect(ui->pushButton_minus, &QPushButton::clicked, this, &CMW::subtraction);
    QObject::connect(ui->pushButton_mult, &QPushButton::clicked, this, &CMW::multiplication);
    QObject::connect(ui->pushButton_division, &QPushButton::clicked, this, &CMW::division);
}

CMW::~CalcMainWindow () noexcept {
    delete ui;
}

void CMW::addition () {
    auto var1 = ui->lineEdit_1->text().toInt();
    auto var2 = ui->lineEdit_2->text().toInt();
    auto result = var1 + var2;
    QString text;
    text.setNum(result);
    ui->lineEdit_result->setText(text);
    ui->lineEdit_result->update();
}

void CMW::subtraction () {
    auto var1 = ui->lineEdit_1->text().toInt();
    auto var2 = ui->lineEdit_2->text().toInt();
    auto result = var1 - var2;
    QString text;
    text.setNum(result);
    ui->lineEdit_result->setText(text);
    ui->lineEdit_result->update();
}

void CMW::multiplication () {
    auto var1 = ui->lineEdit_1->text().toInt();
    auto var2 = ui->lineEdit_2->text().toInt();
    auto result = var1 * var2;
    QString text;
    text.setNum(result);
    ui->lineEdit_result->setText(text);
    ui->lineEdit_result->update();
}

void CMW::division () {
    auto var1 = ui->lineEdit_1->text().toInt();
    auto var2 = ui->lineEdit_2->text().toInt();
    if (var2 == 0) {
        ui->lineEdit_result->setText("ERROR");
        ui->lineEdit_result->update();
        return;
    }
    auto result = var1 / var2;
    QString text;
    text.setNum(result);
    ui->lineEdit_result->setText(text);
    ui->lineEdit_result->update();
}

