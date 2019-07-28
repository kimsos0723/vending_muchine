#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb10_clicked();

    void on_pb50_clicked();

    void on_pb100_clicked();

    void on_pb_coffee_clicked();

    void on_pb_gt_clicked();

    void on_pb_mocha_clicked();

    void on_pb_change_clicked();

private:
    unsigned int money;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
