#include <iostream>
#include<string>
#include "Image_Class.h"
using namespace std;
void Blur(Image &image){
    Image image2(image.width-30,image.height-30);
    for(int i = 15 ;i<image.width-15;i++){
        for(int j=15;j<image.height-15;j++){
            for(int k = 0;k<3;k++){
                int avg = 0;
                for(int l = -15;l<15;l++){
                    avg += image(i+l,j,k);
                }
                for(int l = -15;l<15;l++){
                    avg += image(i,j+l,k);
                }
                image2(i-15,j-15,k)=avg/60;
            }
        }
    }
    image = image2;
}
void Simple_Frame(Image &image,int red=0,int green=0,int blue=255){
    for(int i = 0;i<30;i++){
        for(int j = 0;j<image.height;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image(i,j,k)=red;
                    image(image.width-1-i,j,k)=red;
                }
                else if(k==1){
                    image(i,j,k)=green;
                    image(image.width-1-i,j,k)=green;
                }
                else if(k==2){
                    image(i,j,k)=blue;
                    image(image.width-1-i,j,k)=blue;
                }
            }
        }
    }
    for(int i = 30;i<image.width-30;i++){
        for(int j = 0;j<30;j++){
            for(int k = 0;k<3;k++){
                if(k==0){
                    image(i,j,k)=red;
                    image(i,image.height-1-j,k)=red;
                }
                else if(k==1){
                    image(i,j,k)=green;
                    image(i,image.height-1-j,k)=green;
                }
                else if(k==2){
                    image(i,j,k)=blue;
                    image(i,image.height-1-j,k)=blue;
                }
            }
        }
    }
}
void fancy_frame(Image &image){
    Simple_Frame(image,0,0,255);
    for(int i = 15 ;i<18;i++){
        for(int j=0;j<image.height;j++){
            for(int k =0;k<3;k++){
                image(i,j,k)=255;
                image(image.width-1-i,j,k) = 255;
                image(i-5,j,k)=255;
                image(image.width+4-i,j,k) = 255;
            }
        }
    }
    for(int i =0;i<image.width;i++){
        for(int j=15;j<18;j++){
            for(int k=0;k<3;k++){
                image(i,j,k)=255;
                image(i,image.height-1-j,k) = 255;
                image(i,j-5,k)=255;
                image(i,image.height+4-j,k) = 255;
            }
        }
    }
    for(int i = 35 ;i<40;i++){
        for(int j=35;j<image.height-35;j++){
            for(int k =0;k<3;k++){
                image(i,j,k)=255;
                image(image.width-1-i,j,k) = 255;
            }
        }
    }
    for(int i =35;i<image.width-35;i++){
        for(int j=35;j<40;j++){
            for(int k=0;k<3;k++){
                image(i,j,k)=255;
                image(i,image.height-1-j,k) = 255;
            }
        }
    }
    for(int i = 38;i<70;i++){
        for(int j=70 ;j<75;j++){
            for(int k =0;k<3;k++){
                image(i,j,k)=255;
                image(image.width-1-i,j,k) = 255;
                image(i,image.height-1-j,k)=255;
                image(image.width-1-i,image.height-1-j,k) = 255;
            }
        }
    }
    for(int i = 70;i<75;i++){
        for(int j=38 ;j<75;j++){
            for(int k =0;k<3;k++){
                image(i,j,k)=255;
                image(image.width-1-i,j,k) = 255;
                image(i,image.height-1-j,k)=255;
                image(image.width-1-i,image.height-1-j,k) = 255;
            }
        }
    }
}
void infrared(Image &image){
    for(int i=0;i<image.width;i++){
        for(int j =0;j<image.height;j++){
            image(i,j,0)=255;
            for(int k =1;k<3;k++){
                image(i,j,k)=(255-image(i,j,k));
                if(image(i,j,k)<0){
                    image(i,j,k)=0;
                }
            }
        }
    }
}
