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

int main(){
    string choice1,image_name_before,choice2,choice3,choice4,image_name_after;
    bool status1 = true;
    Image image;
    cout <<"***********HELLO TO THE BABY PHOTOSHOP***********\n";
    while(true) {
        cout << "What do you want to do?\n1-Upload image and edit it\n2-Exit\n";
        cin >> choice1;
        if (choice1 == "1") {
            cout <<"Please enter image name and directory: ";
            while (true){
                try {
                    cin >> image_name_before;
                    if(image.loadNewImage(image_name_before)){
                        cout << "Image uploaded successfully!\n";
                        break;
                    }
                }
                catch (...){
                    cerr <<"\nTry again: ";
                    continue;
                }
            }
            while (status1){
                cout << "Please enter the filter you want to apply:\n1-Invert image\n2-Rotate image\n";
                cin >> choice2;
                if(choice2 == "1"){
                    image_invert(image);
                    while (true){
                        cout <<"Do you want to continue?\n1-yes\n2-no\n";
                        cin >> choice3;
                        if(choice3 =="1"){
                            break;
                        }
                        else if(choice3=="2"){
                            status1 = false;
                            break;
                        }
                        else{
                            cout <<"Invalid input\n";
                        }
                    }
                }

                if(choice2 == "2"){
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
                    while (true){
                        cout <<"Do you want to continue?\n1-yes\n2-no\n";
                        cin >> choice3;
                        if(choice3 =="1"){
                            break;
                        }
                        else if(choice3=="2"){
                            status1 = false;
                            break;
                        }
                        else{
                            cout <<"Invalid input\n";
                        }
                    }
                }
            }
            cout << "Thank you for using filters\nNow please enter the image name and the directory and the format to save it: ";
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
        else if(choice1=="2"){
            cout <<"Thanks for using our baby photoshop\ngoodbye";
            break;
        }
        else {
            cout <<"Invalid input\n";
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