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
int main(){
    Image image;
    image.loadNewImage("C:\\Users\\HP\\Desktop\\CS112-Winter2023-2024-Assignemnt3-SampleImages\\CS112-Winter2023-2024-Assignemnt3-SampleImages\\building.jpg");
    Image image2(image.width-38,image.height-38);
    for(int i = 19;i<image.width-19;i++){
        for(int j = 19;j<image.height-19;j++){
            for(int k = 0;k<3;k++){
                long long avg = 0;
                for(int l = i-19;l<i+2;l++){
                    for(int m = j-19;m<j+2;m++){
                        avg += image(l,m,k);
                    }
                }
                image2(i-19,j-19,k) = avg/441;
            }
        }
    }
    image2.saveImage("blur image.jpg");
}
