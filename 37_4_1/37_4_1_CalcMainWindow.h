#ifndef INC_37_4_37_4_1_CALCMAINWINDOW_H
#define INC_37_4_37_4_1_CALCMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class CalcMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit CalcMainWindow (QWidget *parent = nullptr);
    ~CalcMainWindow () noexcept override;

private:
    Ui::MainWindow *ui;

private slots:
    void addition ();
    void subtraction ();
    void multiplication ();
    void division ();
};

#endif //INC_37_4_37_4_1_CALCMAINWINDOW_H
