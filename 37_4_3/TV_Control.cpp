#include <string>
#include "TV_Control.h"
#include "ui_TV_Control_Interface.h"

#define CONNECT_NUMERIC_BUTTON(val) QObject::connect(ui->pushButton_##val, &QPushButton::clicked, this, [=](){TV_Control::setChannel(val);})

TV_Control::TV_Control (QWidget *parent) : QWidget(parent), ui(new Ui::TV_Control_Interface) {
    ui->setupUi(this);
    this->refreshDisplay();

    QObject::connect(ui->pushButton_volUp, &QPushButton::clicked, this, &TV_Control::upVolume);
    QObject::connect(ui->pushButton_volDown, &QPushButton::clicked, this, &TV_Control::downVolume);
    QObject::connect(ui->pushButton_chUp, &QPushButton::clicked, this, &TV_Control::upChannel);
    QObject::connect(ui->pushButton_chDown, &QPushButton::clicked, this, &TV_Control::downChannel);
    CONNECT_NUMERIC_BUTTON(0);
    CONNECT_NUMERIC_BUTTON(1);
    CONNECT_NUMERIC_BUTTON(2);
    CONNECT_NUMERIC_BUTTON(3);
    CONNECT_NUMERIC_BUTTON(4);
    CONNECT_NUMERIC_BUTTON(5);
    CONNECT_NUMERIC_BUTTON(6);
    CONNECT_NUMERIC_BUTTON(7);
    CONNECT_NUMERIC_BUTTON(8);
    CONNECT_NUMERIC_BUTTON(9);
}

TV_Control::~TV_Control () {
    delete ui;
}

void TV_Control::refreshDisplay () {
    std::string text = "Channel: " + std::to_string(channel) + "\nVolume: " + std::to_string(volume);
    ui->display->setText(text.c_str());
    ui->display->update();
}

void TV_Control::setChannel (int _chanel) {
    channel = _chanel;
    refreshDisplay();
}

void TV_Control::upVolume () {
    if (volume <= volumeMax - volumeStep) {
        volume += volumeStep;
    }
    else {
        volume = volumeMax;
    }
    refreshDisplay();
}

void TV_Control::downVolume () {
    if (volume >= volumeMin + volumeStep) {
        volume -= volumeStep;
    }
    else {
        volume = volumeMin;
    }
    refreshDisplay();
}

void TV_Control::upChannel () {
    if (channel < channelMax) {
        channel += 1;
    }
    refreshDisplay();
}

void TV_Control::downChannel () {
    if (channel > channelMin) {
        channel -= 1;
    }
    refreshDisplay();
}


