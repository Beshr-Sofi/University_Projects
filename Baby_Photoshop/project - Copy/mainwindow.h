#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void stringReturned(const QString &str);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_11_clicked();
    void storeString(const QString &str);

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_9_clicked();

    void on_lighteffectbutton_clicked();

    void on_pushButton_10_clicked();

    void on_darkeffectbutton_clicked();

    void on_pushButton_8_clicked();

    void on_mergesize_clicked();

    void on_mergenotsize_clicked();

    void on_pushButton_13_clicked();

    void on_fliphorizontal_clicked();

    void on_flipvertical_clicked();

    void on_pushButton_14_clicked();

    void on_Rotate270_clicked();

    void on_Rotate180_clicked();

    void on_Rotate90_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_6_clicked();

    void on_simpleframe_clicked();

    void on_blueframe_clicked();

    void on_redframe_clicked();

    void on_greenframe_clicked();

    void on_fancyframe_clicked();

    void on_blueframe_2_clicked();

    void on_redframe_2_clicked();

    void on_greenframe_2_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_skewbutton_clicked();

    void on_pushButton_2_clicked();

    void on_crop4_clicked();

    void on_crop3_clicked();

    void on_crop2_clicked();

    void on_crop1_clicked();

    void on_pushButton_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_24_clicked();

private:
    double dark;
    QString path1;
    QString saved_path;
    std::string saved;
    std::string copy_path;
    std::string path;
    double light;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
