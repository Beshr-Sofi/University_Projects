#include <iostream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<string>
#include <algorithm>
#include <array>
#include<random>
#include <ctime>
#include "Image_Class.h"
using namespace std;
void image_invert(Image& image);
void image_rotate_90(Image& image_before);
void image_rotate_180(Image& image_before);
void image_rotate_270(Image& image_before);
void image_darkness(Image& image);
void image_brightness(Image& image);
void image_gray(Image& image);
void image_flipped_vertical(Image& image);
void image_flipped_Horizontal(Image& image);
void black_and_white(Image&image);

int main(){
    string choice1,image_name_before,choice2,choice3,choice4,image_name_after;
    bool status1 = true,status2= true;
    Image image;
    cout <<"***********HELLO TO THE BABY PHOTOSHOP***********\n";
    while(status1) {
        cout << "Please enter the image name and directory to upload it: ";
        while (true){
            try {
                cin >> image_name_before;
                if(image.loadNewImage(image_name_before)){
                    cout << "Image uploaded successfully!\n";
                    status2= true;
                    break;
                }
            }
            catch (...){
                cerr <<"\nTry again: ";
                continue;
            }
        }
        while (status2){
            cout << "Please enter what you want to do:\n";
            cout<<"1-Load new image\n2-Invert image\n3-Rotate image\n4-Change brightness\n5-Make the image gray\n6-Flip image\n7-Make the image black & white\n8-Save image\n9-Exit\n";
            cin >> choice1;
            if(choice1=="1"){
                cout <<"Do you want to save image before load?\n1-yes\n2-no\n";
                while (true){
                    cin >> choice3;
                    if(choice3=="1"){
                        cout << "Now please enter the image name and the directory and the format to save it: ";
                        while (true){
                            try {
                                cin >> image_name_after;
                                if(image.saveImage(image_name_after)){
                                    cout << "Image saved successfully!\n";
                                    break;
                                }
                            }
                            catch (...){
                                cerr <<"\nTry again: ";
                                continue;
                            }
                        }
                        status2 = false;
                        break;
                    }
                    else if(choice3=="2"){
                        status2= false;
                        break;
                    }
                    else{
                        cout << "invalid input\n";
                    }
                }
            }
            else if(choice1=="2"){
                image_invert(image);
            }
            else if(choice1=="3"){
                while (true){
                    cout <<"How do you want to rotate image?\n1-Rotate 90 degrees\n2-Rotate 180 degrees\n3-Rotate 270 degrees\n";
                    cin >> choice4;
                    if(choice4 =="1"){
                        image_rotate_90(image);
                        break;
                    }
                    else if(choice4=="2"){
                        image_rotate_180(image);
                        break;
                    }
                    else if (choice4 =="3"){
                        image_rotate_270(image);
                        break;
                    }
                    else{
                        cout << "invalid input\n";
                    }
                }
            }
            else if(choice1=="4"){
                while (true){
                    cout << "How do you want to make image?\n1-dark\n2-light\n";
                    cin >> choice3;
                    if(choice3=="1"){
                        image_darkness(image);
                        break;
                    }
                    else if(choice3=="2"){
                        image_brightness(image);
                        break;
                    }
                    else{
                        cout << "invalid input\n";
                    }
                }
            }
            else if(choice1=="5"){
                image_gray(image);
            }
            else if(choice1=="6"){
                while (true){
                    cout <<"How do you want to flip?\n1-Vertical\n2-horizontal\n";
                    cin >> choice3;
                    if(choice3=="1"){
                        image_flipped_vertical(image);
                        break;
                    }
                    else if(choice3=="2"){
                        image_flipped_Horizontal(image);
                        break;
                    }
                    else{
                        cout << "invalid input\n";
                    }
                }
            }
            else if(choice1=="7"){
                black_and_white(image);
            }
            else if(choice1=="8"){
                cout << "Now please enter the image name and the directory and the format to save it: ";
                while (true){
                    try {
                        cin >> image_name_after;
                        if(image.saveImage(image_name_after)){
                            cout << "Image saved successfully!\n";
                            break;
                        }
                    }
                    catch (...){
                        cerr <<"\nTry again: ";
                        continue;
                    }
                }
            }
            else if(choice1=="9"){
                cout <<"Thanks for using our baby photoshop\ngoodbye";
                status1= false;
                break;
            }
            else{
                cout <<"Invalid input\n";
            }
        }
    }
}






void image_invert(Image& image){
    for(int i = 0;i<image.width;i++){
        for(int j = 0;j<image.height;j++){
            image(i,j,0) = 255 - image(i,j,0);
            image(i,j,1) = 255 - image(i,j,1);
            image(i,j,2) = 255 - image(i,j,2);
        }
    }
}
void image_rotate_90(Image& image_before){
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
    int width = image_before.width;
    image_before.width = image_before.height;
    image_before.height = width;
    for(int i = 0;i<image_after.width;i++){
        for(int j = 0;j<image_after.height;j++){
            image_before(i,j,0)=image_after(i,j,0);
            image_before(i,j,1)=image_after(i,j,1);
            image_before(i,j,2)=image_after(i,j,2);
        }
    }
}
void image_rotate_180(Image& image_before){
    Image image_after (image_before.width,image_before.height);
    for(int i = 0;i<image_before.width;i++){
        for(int j = 0;j<image_before.height;j++){
            image_after(i,j,0)=image_before(image_before.width-1-i,image_before.height-1-j,0);
            image_after(i,j,1)=image_before(image_before.width-1-i,image_before.height-1-j,1);
            image_after(i,j,2)=image_before(image_before.width-1-i,image_before.height-1-j,2);
        }
    }
    for(int i = 0;i<image_after.width;i++){
        for(int j = 0;j<image_after.height;j++){
            image_before(i,j,0)=image_after(i,j,0);
            image_before(i,j,1)=image_after(i,j,1);
            image_before(i,j,2)=image_after(i,j,2);
        }
    }
}
void image_rotate_270(Image& image_before){
    Image image_after(image_before.height,image_before.width);
    for(int i = 0;i<image_before.width;i++) {
        for (int j = image_before.height - 1; j >= 0; j--) {
            image_after(j, i, 0) = image_before(image_before.width-1-i, j, 0);
            image_after(j, i, 1) = image_before(image_before.width-1-i, j, 1);
            image_after(j, i, 2) = image_before(image_before.width-1-i, j, 2);
        }
    }
    int r = image_before.width;
    image_before.width = image_before.height;
    image_before.height = r;
    for(int i = 0;i<image_after.width;i++){
        for(int j = 0;j<image_after.height;j++){
            image_before(i,j,0)=image_after(i,j,0);
            image_before(i,j,1)=image_after(i,j,1);
            image_before(i,j,2)=image_after(i,j,2);
        }
    }
}
void image_darkness(Image& image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                double newValue = image(i, j, k) * 0.5;
                if (newValue > 255) {
                    newValue = 255;
                }
                image(i, j, k) = newValue;
            }
        }
    }
}
void image_brightness(Image& image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {
                double newValue = image(i, j, k) * 1.5;
                if (newValue > 255) {
                    newValue = 255;
                }
                image(i, j, k) = newValue;
            }
        }
    }
}
void image_gray(Image& image){
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < image.channels; k++) {
                avg += image(i, j, k);
            }
            avg = avg / 3;
            for (int k = 0; k < image.channels; k++) {
                image(i, j, k) = avg;
            }
        }
    }
}
void image_flipped_vertical(Image& image){
    Image new_image(image.width, image.height);
    for (int i = 0; i< image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                new_image(i, image.height - 1 - j, k) = image(i, j, k);
            }
        }
    }
    for(int i = 0;i<new_image.width;i++){
        for(int j = 0;j<new_image.height;j++){
            image(i,j,0)=new_image(i,j,0);
            image(i,j,1)=new_image(i,j,1);
            image(i,j,2)=new_image(i,j,2);
        }
    }
}
void image_flipped_Horizontal(Image& image){
    Image new_image(image.width, image.height);
    for(int i=0;i <image.width ; ++i){
        for(int j=0; j <image.height; ++j){
            for(int k=0; k <3; ++k){
                new_image(image.width - 1 - i, j, k)=image(i, j, k);
            }
        }
    }
    for(int i = 0;i<new_image.width;i++){
        for(int j = 0;j<new_image.height;j++){
            image(i,j,0)=new_image(i,j,0);
            image(i,j,1)=new_image(i,j,1);
            image(i,j,2)=new_image(i,j,2);
        }
    }
}
void black_and_white(Image&image){
    for(int i=0; i<image.width; ++i){
        for(int j=0; j<image.height; ++j){
            unsigned int avg=0;
            for(int k=0; k<3; ++k){
                avg +=image(i, j, k);
            }
            avg /=3;
            if(avg >127.5){
                image(i, j,0)=255;
                image(i, j,1)=255;
                image(i, j,2)=255;
            }
            else{
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
        }
    }
}