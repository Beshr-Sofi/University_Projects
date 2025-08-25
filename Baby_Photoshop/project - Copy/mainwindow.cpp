#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "image_class.h"
#include <QMovie>
#include <QFileDialog>
#include <QFileInfo>
#include <QPixmap>
#include <string>
#include <iostream>
#include <QPushButton>
#include <cmath>
#include<algorithm>
#include <random>
#include <vector>
#include <QTextEdit>
#include <QString>
#include <QDebug>
#include <QLineEdit>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, &MainWindow::stringReturned, this, &MainWindow::storeString);
    QSize newSize(55, 55);
    ui->groupBox->setStyleSheet("background-color:#30306E;border-radius: 30px;border:3px solid #E0AF72;");
    QMovie *invert_movie = new QMovie("wired-lineal-54-photo.gif");
    invert_movie->setScaledSize(newSize);
    ui->invertlabel->setMovie(invert_movie);
    invert_movie->start();
    QMovie *Arrow = new QMovie("Animation - 1713303399474.gif");
    Arrow->setScaledSize(newSize);
    ui->label_3->setMovie(Arrow);
    Arrow->start();
    QMovie *gray_scale = new QMovie("wired-flat-1383-sphere.gif");
    gray_scale->setScaledSize(newSize);
    ui->label_23->setMovie(gray_scale);
    gray_scale->start();
    QMovie *black_white = new QMovie("wired-flat-1384-page-view-array.gif");
    black_white->setScaledSize(newSize);
    ui->label_22->setMovie(black_white);
    black_white->start();
    QMovie *sun_light = new QMovie("sun.gif");
    sun_light->setScaledSize(newSize);
    ui->label_21->setMovie(sun_light);
    sun_light->start();
    QMovie *infrared = new QMovie("icons8-fire.gif");
    infrared->setScaledSize(newSize);
    ui->label_20->setMovie(infrared);
    infrared->start();
    QMovie *oil_paint = new QMovie("drops.gif");
    oil_paint->setScaledSize(newSize);
    ui->label_19->setMovie(oil_paint);
    oil_paint->start();
    QMovie *purple = new QMovie("Purple Diamond.gif");
    purple->setScaledSize(newSize);
    ui->label_24->setMovie(purple);
    purple->start();
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    QMovie *brightness = new QMovie("icons8-light-bulb.gif");
    brightness->setScaledSize(newSize);
    ui->label_12->setMovie(brightness);
    brightness->start();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    QMovie *darkness = new QMovie("night-mode.gif");
    darkness->setScaledSize(newSize);
    ui->label_13->setMovie(darkness);
    darkness->start();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    QMovie *merge = new QMovie("merge.gif");
    merge->setScaledSize(newSize);
    ui->label_11->setMovie(merge);
    merge->start();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    QMovie *flip = new QMovie("Animation - 1713200871208.gif");
    flip->setScaledSize(newSize);
    ui->label_16->setMovie(flip);
    flip->start();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    QMovie *rotate = new QMovie("icons8-sync.gif");
    rotate->setScaledSize(newSize);
    ui->label_17->setMovie(rotate);
    rotate->start();
    QMovie *edges = new QMovie("wired-lineal-1419-polyline.gif");
    edges->setScaledSize(newSize);
    ui->label_18->setMovie(edges);
    edges->start();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    QMovie *frame = new QMovie("painting.gif");
    frame->setScaledSize(newSize);
    ui->label_9->setMovie(frame);
    frame->start();
    QMovie *blur = new QMovie("wired-flat-243-glasses-eye-blink.gif");
    blur->setScaledSize(newSize);
    ui->label_15->setMovie(blur);
    blur->start();
    QMovie *noise = new QMovie("speaker.gif");
    noise->setScaledSize(newSize);
    ui->label_10->setMovie(noise);
    noise->start();
    QMovie *television = new QMovie("news.gif");
    television->setScaledSize(newSize);
    ui->label_8->setMovie(television);
    television->start();
    QMovie *movie = new QMovie("wired-flat-62-film.gif");
    movie->setScaledSize(newSize);
    ui->label_7->setMovie(movie);
    movie->start();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    QMovie *skew = new QMovie("slope.gif");
    skew->setScaledSize(newSize);
    ui->label_6->setMovie(skew);
    skew->start();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    QMovie *crop = new QMovie("icons8-crop.gif");
    crop->setScaledSize(newSize);
    ui->label_5->setMovie(crop);
    crop->start();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();
    QMovie *resize = new QMovie("resize.gif");
    resize->setScaledSize(newSize);
    ui->label_4->setMovie(resize);
    resize->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_11_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    QStringList supportedFormats = {"Image Files (*.png *.jpg *.jpeg *.bmp)"};
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", supportedFormats.join(";;"));
    ui->label_2->clear();
    emit stringReturned(filePath);
}
void MainWindow::storeString(const QString &str)
{
    path1 = str;
    path = path1.toStdString();
    copy_path=path;
    QPixmap image1(path1);
    int w = ui->label->width();
    int h = ui->label->height();
    ui->label->setAlignment(Qt::AlignCenter);

    ui->label->setPixmap(image1.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_21_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    for(int i = 0;i<image_before.width;i++){
        for(int j = 0;j<image_before.height;j++){
            image_before(i,j,0) = abs(255 - image_before(i,j,0)); // update the value of the pixel
            image_before(i,j,1) = abs(255 - image_before(i,j,1));
            image_before(i,j,2) = abs(255 - image_before(i,j,2));
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}



void MainWindow::on_pushButton_20_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    for (int i = 0; i < image_before.width; i++) {
        for (int j = 0; j < image_before.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < image_before.channels; k++) {
                avg += image_before(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < image_before.channels; k++) {
                image_before(i, j, k) = avg;
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_19_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    for(int i=0; i<image_before.width; ++i){
        for(int j=0; j<image_before.height; ++j){
            unsigned int avg=0;
            for(int k=0; k<3; ++k){
                avg +=image_before(i, j, k);
            }
            avg /=3;
            if(avg >127.5){
                image_before(i, j,0)=255;
                image_before(i, j,1)=255;
                image_before(i, j,2)=255;
            }
            else{
                image_before(i,j,0)=0;
                image_before(i,j,1)=0;
                image_before(i,j,2)=0;
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_18_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    int channels = image_before.channels;

    for (int i = 0; i < image_before.width; i++) {
        for (int j = 0; j < image_before.height; j++) {
            int red = image_before.getPixel(i, j, 0);
            int green = image_before.getPixel(i, j, 1);
            int blue = image_before.getPixel(i, j, 2);
            // Adjust pixel values
            red += 50;
            green += 50;
            blue -= 50;
            if (blue < 0) blue = 0;
            // Check upper bounds
            if (red > 255) red = 255;
            if (green > 255) green = 255;
            if (blue > 255) blue = 255;
            image_before.setPixel(i, j, 0, red);
            image_before.setPixel(i, j, 1, green);
            image_before.setPixel(i, j, 2, blue);
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_17_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    for(int i=0;i<image_before.width;i++){
        for(int j =0;j<image_before.height;j++){
            image_before(i,j,0)=255;
            for(int k =1;k<3;k++){
                image_before(i,j,k)=(255-image_before(i,j,k));
                if(image_before(i,j,k)<0){
                    image_before(i,j,k)=0;
                }
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    for (int i = 2; i < width - 2; i++) { // Adjusted loop boundaries
        for (int j = 2; j < height - 2; j++) { // Adjusted loop boundaries
            // Array to store the RGB values of surrounding pixels
            array<int, 26> reds;
            array<int, 26> greens;
            array<int, 26> blues;

            int index = 0;
            for (int x = i - 2; x <= i + 2; x++) {
                for (int y = j - 2; y <= j + 2; y++) {
                    reds[index] = image_before.getPixel(x, y, 0);
                    greens[index] = image_before.getPixel(x, y, 1);
                    blues[index] = image_before.getPixel(x, y, 2);
                    index++;
                }
            }

            // Sort the color values
            sort(reds.begin(), reds.end());
            sort(greens.begin(), greens.end());
            sort(blues.begin(), blues.end());

            // Find the most frequent color (median value)
            int repeated_r = reds[13]; // Index 13 is the median of 26 elements
            int repeated_g = greens[13];
            int repeated_b = blues[13];

            // Set the pixel being processed to the most frequent color
            image_before.setPixel(i, j, 0, repeated_r);
            image_before.setPixel(i, j, 1, repeated_g);
            image_before.setPixel(i, j, 2, repeated_b);
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_27_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    int red,green,blue;
    for (int i = 0; i < image_before.width; ++i) {
        for (int j = 0; j < image_before.height; ++j) {
            red = image_before(i, j, 0) ;
            green = image_before(i, j, 1) ;
            blue = image_before(i, j, 2) ;
            image_before.getPixel(i, j,0)=red;
            image_before.getPixel(i, j,1)=green*0.7;
            image_before.getPixel(i, j,2)=blue;

        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    light = 0;
    ui->lighteffectslider->setVisible(true);
    ui->lighteffectbutton->setVisible(true);
    ui->lighteffectslider->setRange(1,10);
    int value =ui->lighteffectslider->value();
    light = (value/10.0)+1;
}


void MainWindow::on_lighteffectbutton_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    for (int i = 0; i < image_before.width; i++) {
        for (int j = 0; j < image_before.height; j++) {
            for (int k = 0; k < image_before.channels; k++) {
                double newValue = image_before(i, j, k) * light;
                if (newValue > 255) {
                    newValue = 255;
                }
                image_before(i, j, k) = newValue;
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));

}


void MainWindow::on_pushButton_10_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    dark = 0;
    ui->darkeffectslider->setVisible(true);
    ui->darkeffectbutton->setVisible(true);
    ui->darkeffectslider->setRange(5,10);
    int value =ui->darkeffectslider->value();
    dark = (value/10.0);
}


void MainWindow::on_darkeffectbutton_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    for (int i = 0; i < image_before.width; i++) {
        for (int j = 0; j < image_before.height; j++) {
            for (int k = 0; k < image_before.channels; k++) {
                double newValue = image_before(i, j, k) * dark;
                if (newValue > 255) {
                    newValue = 255;
                }
                image_before(i, j, k) = newValue;
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_8_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    ui->mergenotsize->setVisible(true);
    ui->mergesize->setVisible(true);
}


void MainWindow::on_mergesize_clicked()
{
    QStringList supportedFormats = {"Image Files (*.png *.jpg *.jpeg *.bmp)"};
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image to merge"), "", supportedFormats.join(";;"));
    string path_merge = filePath.toStdString();
    Image image_before,image_merge;
    image_before.loadNewImage(path);
    image_merge.loadNewImage(path_merge);
    int oldw = image_merge.width;
    int oldh = image_merge.height;

    // Create a new image with the specified dimensions
    Image resized(image_before.width, image_before.height);

    // Calculate the scale factors
    float scaleX = static_cast<float>(oldw) / image_before.width;
    float scaleY = static_cast<float>(oldh) / image_before.height;

    for (int y = 0; y < image_before.height; y++) {
        for (int x = 0; x < image_before.width; x++) {
            // Calculate the corresponding coordinates in the original image
            int oldX = round(x * scaleX);
            int oldY = round(y * scaleY);

            // Set the pixel value in the resized image
            for (int c = 0; c < image_merge.channels; c++) {
                resized.setPixel(x, y, c, image_merge.getPixel(oldX, oldY, c));
            }
        }
    }

    // Replace the original image with the resized image
    image_merge=resized;
    for (int x = 0; x < image_before.width; x++) {
        for (int y = 0; y < image_before.height; y++) {
            for (int z = 0; z < image_before.channels; z++) {
                image_before.setPixel(x, y, z, (image_before.getPixel(x, y, z) + image_merge.getPixel(x, y, z)) / 2);
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_mergenotsize_clicked()
{
    QStringList supportedFormats = {"Image Files (*.png *.jpg *.jpeg *.bmp)"};
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image to merge"), "", supportedFormats.join(";;"));
    string path_merge = filePath.toStdString();
    Image image_before,image_merge;
    image_before.loadNewImage(path);
    image_merge.loadNewImage(path_merge);
    for (int x = 0; x < image_before.width; x++) {
        for (int y = 0; y < image_before.height; y++) {
            for (int z = 0; z < image_before.channels; z++) {
                image_before.setPixel(x, y, z, (image_before.getPixel(x, y, z) + image_merge.getPixel(x, y, z)) / 2);
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    ui->fliphorizontal->setVisible(true);
    ui->flipvertical->setVisible(true);
}


void MainWindow::on_fliphorizontal_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    Image new_image(image_before.width, image_before.height);
    for(int i=0;i <image_before.width ; ++i){
        for(int j=0; j <image_before.height; ++j){
            for(int k=0; k <3; ++k){
                new_image(image_before.width - 1 - i, j, k)=image_before(i, j, k);
            }
        }
    }
    path = "lol.jpg";
    new_image.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_flipvertical_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    Image new_image(image_before.width, image_before.height);
    for (int i = 0; i< image_before.width; ++i) {
        for (int j = 0; j < image_before.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                new_image(i, image_before.height - 1 - j, k) = image_before(i, j, k);
            }
        }
    }
    path = "lol.jpg";
    new_image.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    ui->Rotate270->setVisible(true);
    ui->Rotate90->setVisible(true);
    ui->Rotate180->setVisible(true);
}


void MainWindow::on_Rotate270_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    Image image_after(image_before.height,image_before.width);
    for(int i = 0;i<image_before.width;i++) {
        for (int j = image_before.height - 1; j >= 0; j--) {
            image_after(j, i, 0) = image_before(image_before.width-1-i, j, 0);
            image_after(j, i, 1) = image_before(image_before.width-1-i, j, 1);
            image_after(j, i, 2) = image_before(image_before.width-1-i, j, 2);
        }
    }
    path = "lol.jpg";
    image_after.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_Rotate180_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    Image image_after (image_before.width,image_before.height);
    for(int i = 0;i<image_before.width;i++){
        for(int j = 0;j<image_before.height;j++){
            image_after(i,j,0)=image_before(image_before.width-1-i,image_before.height-1-j,0);
            image_after(i,j,1)=image_before(image_before.width-1-i,image_before.height-1-j,1);
            image_after(i,j,2)=image_before(image_before.width-1-i,image_before.height-1-j,2);
        }
    }
    path = "lol.jpg";
    image_after.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_Rotate90_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    Image image_after(image_before.height,image_before.width);
    int r = 0;
    for(int i = 0;i<image_before.width;i++){
        for(int j = image_before.height-1;j>=0;j--){
            image_after(r,i,0)=image_before(i,j,0);
            image_after(r,i,1)=image_before(i,j,1);
            image_after(r,i,2)=image_before(i,j,2);
            r++;
        }
        r=0;
    }
    path = "lol.jpg";
    image_after.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;

    double edge_magnitude[width][height];


    int sobel_x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}; // Sobel X gradient
    int sobel_y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}}; // Sobel Y gradient

    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            int gx = 0, gy = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    gx += sobel_x[x + 1][y + 1] * image_before.getPixel(i + x, j + y, 0);
                    gy += sobel_y[x + 1][y + 1] * image_before.getPixel(i + x, j + y, 0);
                }
            }
            // Calculate edge magnitude
            edge_magnitude[i][j] = sqrt(gx * gx + gy * gy)*0.5;
        }
    }

    // Calculate the threshold (average of edge magnitudes)
    double threshold = 0;
    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            threshold += edge_magnitude[i][j];
        }
    }
    threshold /= ((width - 2) * (height - 2)); // Average

    // Thresholding
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (edge_magnitude[i][j] > threshold) {
                image_before.setPixel(i, j, 0, 0); // Set pixel to white
                image_before.setPixel(i, j, 1, 0);
                image_before.setPixel(i, j, 2, 0);
            } else {
                image_before.setPixel(i, j, 0, 225); // Set pixel to black
                image_before.setPixel(i, j, 1, 225);
                image_before.setPixel(i, j, 2, 225);
            }
        }
    }

    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    ui->simpleframe->setVisible(true);
    ui->fancyframe->setVisible(true);
}


void MainWindow::on_simpleframe_clicked()
{
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    ui->redframe->setVisible(true);
    ui->greenframe->setVisible(true);
    ui->blueframe->setVisible(true);

}


void MainWindow::on_blueframe_clicked()
{
    int red=68,blue=173,green=126,frame_width;
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    frame_width = max(width,height) * 0.03;
    for(int i = 0;i<frame_width;i++){
        for(int j = 0;j<image_before.height;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(image_before.width-1-i,j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(image_before.width-1-i,j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(image_before.width-1-i,j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width;i<image_before.width-frame_width;i++){
        for(int j = 0;j<frame_width;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(i,image_before.height-1-j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(i,image_before.height-1-j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(i,image_before.height-1-j,k)=blue;
                }
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_redframe_clicked()
{
    int red=181,blue=42,green=42,frame_width;
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    frame_width = max(width,height) * 0.03;
    for(int i = 0;i<frame_width;i++){
        for(int j = 0;j<image_before.height;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(image_before.width-1-i,j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(image_before.width-1-i,j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(image_before.width-1-i,j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width;i<image_before.width-frame_width;i++){
        for(int j = 0;j<frame_width;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(i,image_before.height-1-j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(i,image_before.height-1-j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(i,image_before.height-1-j,k)=blue;
                }
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_greenframe_clicked()
{
    int red=24,blue=68,green=163,frame_width;
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    frame_width = max(width,height) * 0.03;
    for(int i = 0;i<frame_width;i++){
        for(int j = 0;j<image_before.height;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(image_before.width-1-i,j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(image_before.width-1-i,j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(image_before.width-1-i,j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width;i<image_before.width-frame_width;i++){
        for(int j = 0;j<frame_width;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(i,image_before.height-1-j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(i,image_before.height-1-j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(i,image_before.height-1-j,k)=blue;
                }
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_fancyframe_clicked()
{
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    ui->redframe_2->setVisible(true);
    ui->greenframe_2->setVisible(true);
    ui->blueframe_2->setVisible(true);
}


void MainWindow::on_blueframe_2_clicked()
{
    int red=68,blue=173,green=126,frame_width;
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    frame_width = max(width,height) * 0.03;
    for(int i = 0;i<frame_width;i++){
        for(int j = 0;j<image_before.height;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(image_before.width-1-i,j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(image_before.width-1-i,j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(image_before.width-1-i,j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width;i<image_before.width-frame_width;i++){
        for(int j = 0;j<frame_width;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(i,image_before.height-1-j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(i,image_before.height-1-j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(i,image_before.height-1-j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width/2 ;i<frame_width/2 + frame_width/5;i++){
        for(int j=0;j<image_before.height;j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i-frame_width/5,j,k)=255;
                image_before(image_before.width+frame_width/5-1-i,j,k) = 255;
            }
        }
    }
    for(int i =0;i<image_before.width;i++){
        for(int j=frame_width/2;j<frame_width/2 + frame_width/5;j++){
            for(int k=0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(i,image_before.height-1-j,k) = 255;
                image_before(i,j-frame_width/5,k)=255;
                image_before(i,image_before.height+frame_width/5-1-j,k) = 255;
            }
        }
    }
    for(int i = frame_width + frame_width/3 ;i<frame_width + frame_width/3+frame_width/3;i++){
        for(int j=frame_width + frame_width/3;j<image_before.height-(frame_width + frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
            }
        }
    }
    for(int i =frame_width + frame_width/3+frame_width/3;i<image_before.width-(frame_width + frame_width/3);i++){
        for(int j=frame_width + frame_width/3;j<frame_width + frame_width/3+frame_width/3;j++){
            for(int k=0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(i,image_before.height-1-j,k) = 255;
            }
        }
    }
    for(int i = frame_width + frame_width/3+frame_width/3;i<(3*frame_width)-(frame_width/2);i++){
        for(int j=(3*frame_width)-(frame_width/2) ;j<(3*frame_width)-(frame_width/2)+(frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i,image_before.height-1-j,k)=255;
                image_before(image_before.width-1-i,image_before.height-1-j,k) = 255;
            }
        }
    }
    for(int i = (3*frame_width)-(frame_width/2);i<(3*frame_width)-(frame_width/2)+(frame_width/3);i++){
        for(int j=frame_width + frame_width/3+frame_width/3 ;j<(3*frame_width)-(frame_width/2)+(frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i,image_before.height-1-j,k)=255;
                image_before(image_before.width-1-i,image_before.height-1-j,k) = 255;
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_redframe_2_clicked()
{
    int red=181,blue=42,green=42,frame_width;
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    frame_width = max(width,height) * 0.03;
    for(int i = 0;i<frame_width;i++){
        for(int j = 0;j<image_before.height;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(image_before.width-1-i,j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(image_before.width-1-i,j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(image_before.width-1-i,j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width;i<image_before.width-frame_width;i++){
        for(int j = 0;j<frame_width;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(i,image_before.height-1-j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(i,image_before.height-1-j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(i,image_before.height-1-j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width/2 ;i<frame_width/2 + frame_width/5;i++){
        for(int j=0;j<image_before.height;j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i-frame_width/5,j,k)=255;
                image_before(image_before.width+frame_width/5-1-i,j,k) = 255;
            }
        }
    }
    for(int i =0;i<image_before.width;i++){
        for(int j=frame_width/2;j<frame_width/2 + frame_width/5;j++){
            for(int k=0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(i,image_before.height-1-j,k) = 255;
                image_before(i,j-frame_width/5,k)=255;
                image_before(i,image_before.height+frame_width/5-1-j,k) = 255;
            }
        }
    }
    for(int i = frame_width + frame_width/3 ;i<frame_width + frame_width/3+frame_width/3;i++){
        for(int j=frame_width + frame_width/3;j<image_before.height-(frame_width + frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
            }
        }
    }
    for(int i =frame_width + frame_width/3+frame_width/3;i<image_before.width-(frame_width + frame_width/3);i++){
        for(int j=frame_width + frame_width/3;j<frame_width + frame_width/3+frame_width/3;j++){
            for(int k=0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(i,image_before.height-1-j,k) = 255;
            }
        }
    }
    for(int i = frame_width + frame_width/3+frame_width/3;i<(3*frame_width)-(frame_width/2);i++){
        for(int j=(3*frame_width)-(frame_width/2) ;j<(3*frame_width)-(frame_width/2)+(frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i,image_before.height-1-j,k)=255;
                image_before(image_before.width-1-i,image_before.height-1-j,k) = 255;
            }
        }
    }
    for(int i = (3*frame_width)-(frame_width/2);i<(3*frame_width)-(frame_width/2)+(frame_width/3);i++){
        for(int j=frame_width + frame_width/3+frame_width/3 ;j<(3*frame_width)-(frame_width/2)+(frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i,image_before.height-1-j,k)=255;
                image_before(image_before.width-1-i,image_before.height-1-j,k) = 255;
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_greenframe_2_clicked()
{
    int red=24,blue=68,green=163,frame_width;
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    frame_width = max(width,height) * 0.03;
    for(int i = 0;i<frame_width;i++){
        for(int j = 0;j<image_before.height;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(image_before.width-1-i,j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(image_before.width-1-i,j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(image_before.width-1-i,j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width;i<image_before.width-frame_width;i++){
        for(int j = 0;j<frame_width;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image_before(i,j,k)=red;
                    image_before(i,image_before.height-1-j,k)=red;
                }
                else if(k==1){
                    image_before(i,j,k)=green;
                    image_before(i,image_before.height-1-j,k)=green;
                }
                else if(k==2){
                    image_before(i,j,k)=blue;
                    image_before(i,image_before.height-1-j,k)=blue;
                }
            }
        }
    }
    for(int i = frame_width/2 ;i<frame_width/2 + frame_width/5;i++){
        for(int j=0;j<image_before.height;j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i-frame_width/5,j,k)=255;
                image_before(image_before.width+frame_width/5-1-i,j,k) = 255;
            }
        }
    }
    for(int i =0;i<image_before.width;i++){
        for(int j=frame_width/2;j<frame_width/2 + frame_width/5;j++){
            for(int k=0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(i,image_before.height-1-j,k) = 255;
                image_before(i,j-frame_width/5,k)=255;
                image_before(i,image_before.height+frame_width/5-1-j,k) = 255;
            }
        }
    }
    for(int i = frame_width + frame_width/3 ;i<frame_width + frame_width/3+frame_width/3;i++){
        for(int j=frame_width + frame_width/3;j<image_before.height-(frame_width + frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
            }
        }
    }
    for(int i =frame_width + frame_width/3+frame_width/3;i<image_before.width-(frame_width + frame_width/3);i++){
        for(int j=frame_width + frame_width/3;j<frame_width + frame_width/3+frame_width/3;j++){
            for(int k=0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(i,image_before.height-1-j,k) = 255;
            }
        }
    }
    for(int i = frame_width + frame_width/3+frame_width/3;i<(3*frame_width)-(frame_width/2);i++){
        for(int j=(3*frame_width)-(frame_width/2) ;j<(3*frame_width)-(frame_width/2)+(frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i,image_before.height-1-j,k)=255;
                image_before(image_before.width-1-i,image_before.height-1-j,k) = 255;
            }
        }
    }
    for(int i = (3*frame_width)-(frame_width/2);i<(3*frame_width)-(frame_width/2)+(frame_width/3);i++){
        for(int j=frame_width + frame_width/3+frame_width/3 ;j<(3*frame_width)-(frame_width/2)+(frame_width/3);j++){
            for(int k =0;k<3;k++){
                image_before(i,j,k)=255;
                image_before(image_before.width-1-i,j,k) = 255;
                image_before(i,image_before.height-1-j,k)=255;
                image_before(image_before.width-1-i,image_before.height-1-j,k) = 255;
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    Image image_blure(image_before.width-30,image_before.height-30);
    for(int i = 15 ;i<image_before.width-15;i++){
        for(int j=15;j<image_before.height-15;j++){
            for(int k = 0;k<3;k++){
                int avg = 0;
                for(int l = -15;l<15;l++){
                    avg += image_before(i+l,j,k);
                }
                for(int l = -15;l<15;l++){
                    avg += image_before(i,j+l,k);
                }
                image_blure(i-15,j-15,k)=avg/60;
            }
        }
    }
    path = "lol.jpg";
    image_blure.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<int> distribution(-0.5 * 255, 0.5 * 255);
    for (int i = 0; i < image_before.width; ++i) {
        for (int j = 0; j < image_before.height; ++j) {
            // Generate random noise for each channel
            int noise_red = distribution(rng);
            int noise_green = distribution(rng);
            int noise_blue = distribution(rng);
            // Add noise to the pixel values
            image_before(i, j , 0) = min(255, max(0, image_before(i, j , 0) + noise_red)); // Ensure pixel value stays within [0, 255]
            image_before(i, j , 1) = min(255, max(0, image_before(i, j, 1) + noise_green));
            image_before(i, j , 2) = min(255, max(0, image_before(i, j , 2) + noise_blue));
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<int> distribution(-0.5 * 255, 0.5 * 255);
    for (int i = 0; i < image_before.width; ++i) {
        for (int j = 0; j < image_before.height; j += 50) { // Repeat every 50 lines (30 + 20)
            for (int k = 0; k < 20; ++k) { // Repeat 20 times
                if (j + k >= image_before.height) // Check if we have reached the end of the image
                    break;
                // Generate random noise for each channel
                int noise_red = distribution(rng);
                int noise_green = distribution(rng);
                int noise_blue = distribution(rng);
                // Add noise to the pixel values
                image_before(i, j + k, 0) = min(255, max(0, image_before(i, j + k, 0) + noise_red)); // Ensure pixel value stays within [0, 255]
                image_before(i, j + k, 1) = min(255, max(0, image_before(i, j + k, 1) + noise_green));
                image_before(i, j + k, 2) = min(255, max(0, image_before(i, j + k, 2) + noise_blue));
            }
        }
    }
    random_device rd2;
    default_random_engine rng2(rd2());
    uniform_int_distribution<int> (-40, 40);
    for (int i = 0; i < image_before.width; ++i) {
        for (int j = 0; j < image_before.height; ++j) {
            // Generate random distortion for each channel
            int distortion_red = distribution(rng);
            int distortion_green = distribution(rng);
            int distortion_blue = distribution(rng);
            // Apply distortion to the pixel values
            image_before(i, j, 0) = min(255, max(0, image_before(i, j, 0) + distortion_red)); // Red channel
            image_before(i, j, 1) = min(255, max(0, image_before(i, j, 1) + distortion_green)); // Green channel
            image_before(i, j, 2) = min(255, max(0, image_before(i, j, 2) + distortion_blue)); // Blue channel
        }
    }
    // Loop through each row of pixels in the image
    for (int y = 0; y < image_before.height; ++y) {
        // Darken every other row of pixels
        if (y % 2 == 0) {
            for (int x = 0; x < image_before.width; ++x) {
                // Darken each pixel on the even row
                for (int c = 0; c < image_before.channels; ++c) {
                    image_before(x, y, c) = max(0, image_before(x, y, c) - 40); // Decrease pixel value
                }
            }
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;

    // Image processing logic
    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            // array 1d to store the value of each percent of RGB for the 9 pixels
            array<int, 9> reds = {};
            array<int, 9> greens = {};
            array<int, 9> blues = {};

            // Collect the colors of the surrounding pixels
            int k = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    reds[k] = image_before.getPixel(i + x, j + y, 0);
                    greens[k] = image_before.getPixel(i + x, j + y, 1);
                    blues[k] = image_before.getPixel(i + x, j + y, 2);
                    k++;
                }
            }

            // arranges the elements in the array in ascending order by default
            sort(reds.begin(), reds.end());
            sort(greens.begin(), greens.end());
            sort(blues.begin(), blues.end());

            int repeated_r = (reds[1]+reds[4])/2; // Median value
            int repeated_g = (greens[1]+greens[4])/2; // Median value
            int repeated_b = (blues[1]+ greens[4])/2; // Median value

            // Increase the color saturation
            repeated_r = min(255, (int)(repeated_r ));
            repeated_g = min(255, (int)(repeated_g ));
            repeated_b = min(255, (int)(repeated_b ));

            // Set the color of the center pixel to the most frequent color
            image_before.setPixel(i, j, 0, repeated_r);
            image_before.setPixel(i, j, 1, repeated_g);
            image_before.setPixel(i, j, 2, repeated_b);
        }
    }
    path = "lol.jpg";
    image_before.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();

    ui->skewbutton->setVisible(true);
    ui->skewslider->setVisible(true);
    ui->skewslider->setRange(10,89);
}


void MainWindow::on_skewbutton_clicked()
{
    int degree =ui->skewslider->value();
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    // Calculate the new dimensions after skewing
    double skew_radians = degree * M_PI / 180.0;
    int new_width = width + height * tan(skew_radians);
    int new_height = height;

    // Create a new image with the skewed dimensions
    Image skewed_image(new_width, new_height);

    // Perform the skew operation
    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            int source_x = x - y * tan(skew_radians);
            if (source_x < 0 || source_x >= width) {
                // Skip copying if the source pixel is outside the original image
                continue;
            }
            for (int c = 0; c < 3; ++c) {  // Assuming an RGB image
                unsigned char pixel_value = image_before.getPixel(source_x, y, c);
                skewed_image.setPixel(x, y, c, pixel_value);
            }
        }
    }
    path = "lol.jpg";
    skewed_image.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->label_14->hide();
    ui->label_26->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->pushButton_23->hide();

    ui->crop1->setVisible(true);
    ui->crop2->setVisible(true);
    ui->crop3->setVisible(true);
    ui->crop4->setVisible(true);
}


void MainWindow::on_crop4_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    height = (int)(2.0/3.0 * width);
    width = min(width, image_before.width);

    // Calculate the starting point for the crop
    int startX = (image_before.width - width) / 2;
    int startY = (image_before.height - height) / 2;

    Image cropped_image(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < 3; ++c) {
                unsigned char pixel_value = image_before.getPixel(startX + x, startY + y, c);
                cropped_image.setPixel(x, y, c, pixel_value);
            }
        }
    }
    path = "lol.jpg";
    cropped_image.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_crop3_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    width = (int)(3.0/4.0 * height);
    width = min(width, image_before.width);

    // Calculate the starting point for the crop
    int startX = (image_before.width - width) / 2;
    int startY = (image_before.height - height) / 2;

    Image cropped_image(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < 3; ++c) {
                unsigned char pixel_value = image_before.getPixel(startX + x, startY + y, c);
                cropped_image.setPixel(x, y, c, pixel_value);
            }
        }
    }
    path = "lol.jpg";
    cropped_image.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_crop2_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    height = (int)(9.0/16.0 * width);
    width = min(width, image_before.width);

    // Calculate the starting point for the crop
    int startX = (image_before.width - width) / 2;
    int startY = (image_before.height - height) / 2;

    Image cropped_image(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < 3; ++c) {
                unsigned char pixel_value = image_before.getPixel(startX + x, startY + y, c);
                cropped_image.setPixel(x, y, c, pixel_value);
            }
        }
    }
    path = "lol.jpg";
    cropped_image.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_crop1_clicked()
{
    Image image_before;
    image_before.loadNewImage(path);
    int width = image_before.width;
    int height = image_before.height;
    width = height;
    width = min(width, image_before.width);

    // Calculate the starting point for the crop
    int startX = (image_before.width - width) / 2;
    int startY = (image_before.height - height) / 2;

    Image cropped_image(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            for (int c = 0; c < 3; ++c) {
                unsigned char pixel_value = image_before.getPixel(startX + x, startY + y, c);
                cropped_image.setPixel(x, y, c, pixel_value);
            }
        }
    }
    path = "lol.jpg";
    cropped_image.saveImage(path);
    path1 = QString::fromStdString(path);
    QPixmap image2(path1);
    int w = ui->label_2->width();
    int h = ui->label_2->height();
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
}


void MainWindow::on_pushButton_clicked()
{
    ui->lighteffectslider->hide();
    ui->lighteffectbutton->hide();
    ui->darkeffectslider->hide();
    ui->darkeffectbutton->hide();
    ui->mergesize->hide();
    ui->mergenotsize->hide();
    ui->fliphorizontal->hide();
    ui->flipvertical->hide();
    ui->Rotate180->hide();
    ui->Rotate90->hide();
    ui->Rotate270->hide();
    ui->fancyframe->hide();
    ui->simpleframe->hide();
    ui->redframe->hide();
    ui->greenframe->hide();
    ui->blueframe->hide();
    ui->redframe_2->hide();
    ui->greenframe_2->hide();
    ui->blueframe_2->hide();
    ui->skewbutton->hide();
    ui->skewslider->hide();
    ui->crop1->hide();
    ui->crop2->hide();
    ui->crop3->hide();
    ui->crop4->hide();
    ui->pushButton_23->hide();

    ui->label_14->setVisible(true);
    ui->label_26->setVisible(true);
    ui->textEdit->setVisible(true);
    ui->textEdit_3->setVisible(true);
    ui->pushButton_23->setVisible(true);
}


void MainWindow::on_pushButton_23_clicked()
{
    QString text1 = ui->textEdit->toPlainText();
    QString text2 = ui->textEdit_3->toPlainText();

    bool conversionOk1;
    int numericValue1 = text1.toInt(&conversionOk1);
    bool conversionOk2;
    int numericValue2 = text2.toInt(&conversionOk2);
    if(conversionOk1 && conversionOk2){
        Image image_before;
        image_before.loadNewImage(path);
        int oldw = image_before.width;
        int oldh = image_before.height;
        // Create a new image with the specified dimensions
        Image resized(numericValue2, numericValue2);

        // Calculate the scale factors
        float scaleX = (float)oldw / numericValue1;
        float scaleY = (float)oldh / numericValue2;

        for (int y = 0; y < numericValue2; y++) {
            for (int x = 0; x < numericValue1; x++) {
                // Calculate the corresponding coordinates in the original image
                int oldX = round(x * scaleX);
                int oldY = round(y * scaleY);

                // Set the pixel value in the resized image
                for (int c = 0; c < image_before.channels; c++) {
                    resized.setPixel(x, y, c, image_before.getPixel(oldX, oldY, c));
                }
            }
        }

        path = "lol.jpg";
        resized.saveImage(path);
        path1 = QString::fromStdString(path);
        QPixmap image2(path1);
        int w = ui->label_2->width();
        int h = ui->label_2->height();
        ui->label_2->setAlignment(Qt::AlignCenter);
        ui->label_2->setPixmap(image2.scaled(w,h,Qt::KeepAspectRatio));
    }
    else{
        qDebug() << "Invalid integer value";
    }
}


void MainWindow::on_pushButton_22_clicked()
{

    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), QDir::homePath(), tr("Images (*.png *.jpg *.jpeg)"));
    saved = filePath.toStdString();
    Image saved_image;
    saved_image.loadNewImage("lol.jpg");
    saved_image.saveImage(saved);
}


void MainWindow::on_pushButton_24_clicked()
{
    ui->label_2->clear();
    path = copy_path;
}

