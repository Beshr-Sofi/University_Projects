#ifndef FB_TEST_H
#define FB_TEST_H

#include <QMainWindow>

class FB_test : public QMainWindow
{
    Q_OBJECT

public:
    FB_test(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~FB_test();

private:
    Ui::FB_testClass ui;

public slots:
    QString on_pushButton_clicked();

};

#endif
