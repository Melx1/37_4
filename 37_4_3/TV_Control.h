#ifndef INC_37_4_3_TV_CONTROL_H
#define INC_37_4_3_TV_CONTROL_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class TV_Control_Interface; }
QT_END_NAMESPACE

class TV_Control : public QWidget {
Q_OBJECT

public:
    explicit TV_Control(QWidget *parent = nullptr);

    ~TV_Control() override;

private slots:
    void setChannel (int _chanel);
    void upVolume ();
    void downVolume ();
    void upChannel ();
    void downChannel ();

private:
    Ui::TV_Control_Interface *ui;

    int channel = 0;
    const int channelMin = 0;
    const int channelMax = 9;
    int volume = 0;
    const int volumeMin = 0;
    const int volumeMax = 100;
    const int volumeStep = 10;
    void refreshDisplay ();

};


#endif //INC_37_4_3_TV_CONTROL_H
