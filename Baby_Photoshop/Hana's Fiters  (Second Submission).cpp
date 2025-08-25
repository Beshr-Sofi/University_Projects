#include <iostream>
using namespace std;
#include "Image_Class.h"

//////////////////////////////////////////////////////////////// FILTER 2 ////////////////////////////////////////////////////////////////

void blackandwhite(Image&image){
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

            }else{
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
        }
    }
}

//////////////////////////////////////////////////////////////// FILTER 5 part 1 ////////////////////////////////////////////////////////////////

void flippedhorizontally(Image&image){
    Image newimage(image.width,image.height);

    for(int i=0;i <image.width ; ++i){
        for(int j=0; j <image.height; ++j){
            for(int k=0; k <3; ++k){
                newimage(image.width-1-i,j,k)=image(i,j,k);
            }
        }
    }
}

//////////////////////////////////////////////////////////////// FILTER 5 part 2 ////////////////////////////////////////////////////////////////

void flippedvertical(Image& image){
    Image newimage(image.width,image.height);
    for (int i = 0; i< image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                newimage(i, image.height-1-j, k) = image(i, j, k);
            }
        }
    }
}

//////////////////////////////////////////////////////////////// FILTER 8 ////////////////////////////////////////////////////////////////

void crop(Image& image)
{ int x, y, w, h;
    cout << "Enter the x-coordinate of the upper-left corner: ";
    cin >> x;
    cout << "Enter the y-coordinate of the upper-left corner: ";
    cin >> y;
    cout << "Enter the width: ";
    cin >> w;
    cout << "Enter the height: ";
    cin >> h;

    int wid = image.width;
    int hght = image.height;

    Image cropped(w, h);

    for (int i = y; i < y + h && i < hght; i++) {
        for (int j = x; j < x + w && j < wid; j++) {
            if (i >= 0 && j >= 0) {
                for (int c = 0; c < image.channels; c++) {
                    cropped.setPixel(j - x, i - y, c, image.getPixel(j, i, c));
                }
            }
        }
    }

    // Replace the original image with the cropped image
    image = cropped;
}

//////////////////////////////////////////////////////////////// FILTER 11 ////////////////////////////////////////////////////////////////
	
void resize(Image& image) {
    int neww, newh;
    cout << "Enter the new width: ";
    cin >> neww;
    cout << "Enter the new height: ";
    cin >> newh;
    int oldw = image.width;
    int oldh = image.height;
    // Create a new image with the specified dimensions
    Image resized(neww, newh);
    
    // Calculate the scale factors
    float scaleX = (float)oldw / neww;
    float scaleY = (float)oldh / newh;
    
    for (int y = 0; y < newh; y++) {
        for (int x = 0; x < neww; x++) {
            // Calculate the corresponding coordinates in the original image
            int oldX = round(x * scaleX);
            int oldY = round(y * scaleY);

            // Set the pixel value in the resized image
            for (int c = 0; c < image.channels; c++) {
                resized.setPixel(x, y, c, image.getPixel(oldX, oldY, c));
            }
        }
    }

    // Replace the original image with the resized image
    image = resized;
}

//////////////////////////////////////////////////////////////// FILTER 16 (bounce) ////////////////////////////////////////////////////////////////

void purplefilter(Image& image) {
    int red,green,blue;
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            red = image(i, j, 0) ;
            green = image(i, j, 1) ;
            blue = image(i, j, 2) ;
            image.getPixel(i, j,0)=red;
            image.getPixel(i, j,1)=green*0.7;
            image.getPixel(i, j,2)=blue;

        }
    }
}

//////////////////////////////////////////////////////////////// FILTER 18  ////////////////////////////////////////////////////////////////

void AddNoise(Image& image ) {
    random_device rd;
    double intensity = 0.7;
    default_random_engine rng(rd());
    uniform_int_distribution<int> distribution(-intensity * 255, intensity * 255);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; j += 150) { // Repeat every 150 lines (100 + 50)
            for (int k = 0; k < 60; ++k) { // Repeat 100 times
                if (j + k >= image.height) // Check if we have reached the end of the image
                    break;
                // Generate random noise for each channel
                int noise_red = distribution(rng);
                int noise_green = distribution(rng);
                int noise_blue = distribution(rng);
                // Add noise to the pixel values
                image(i, j + k, 0) = min(255, max(0, image(i, j + k, 0) + noise_red)); // Ensure pixel value stays within [0, 255]
                image(i, j + k, 1) = min(255, max(0, image(i, j + k, 1) + noise_green));
                image(i, j + k, 2) = min(255, max(0, image(i, j + k, 2) + noise_blue));
            }
        }
    }
}
//////////////////////////////////////////////////////////////// FILTER  (bounce) ////////////////////////////////////////////////////////////////

//use these 3 functions so it gives us the TV effect.//
#include <random>
#include <algorithm>

void addnoise(Image& image, double intens ) {
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<int> distribution(-intens * 255, intens * 255);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; j += 50) { // Repeat every 50 lines (30 + 20)
            for (int k = 0; k < 20; ++k) { // Repeat 20 times
                if (j + k >= image.height) // Check if we have reached the end of the image
                    break;
                // Generate random noise for each channel
                int noise_red = distribution(rng);
                int noise_green = distribution(rng);
                int noise_blue = distribution(rng);
                // Add noise to the pixel values
                image(i, j + k, 0) = min(255, max(0, image(i, j + k, 0) + noise_red)); // Ensure pixel value stays within [0, 255]
                image(i, j + k, 1) = min(255, max(0, image(i, j + k, 1) + noise_green));
                image(i, j + k, 2) = min(255, max(0, image(i, j + k, 2) + noise_blue));
            }
        }
    }
}

void distortion(Image& image, int distortion) {
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<int> distribution(-distortion, distortion);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            // Generate random distortion for each channel
            int distortion_red = distribution(rng);
            int distortion_green = distribution(rng);
            int distortion_blue = distribution(rng);
            // Apply distortion to the pixel values
            image(i, j, 0) = min(255, max(0, image(i, j, 0) + distortion_red)); // Red channel
            image(i, j, 1) = min(255, max(0, image(i, j, 1) + distortion_green)); // Green channel
            image(i, j, 2) = min(255, max(0, image(i, j, 2) + distortion_blue)); // Blue channel
        }
    }
}

void scanlines(Image& image, int slintens) {
    // Loop through each row of pixels in the image
    for (int y = 0; y < image.height; ++y) {
        // Darken every other row of pixels
        if (y % 2 == 0) {
            for (int x = 0; x < image.width; ++x) {
                // Darken each pixel on the even row
                for (int c = 0; c < image.channels; ++c) {
                    image(x, y, c) = max(0, image(x, y, c) - slintens); // Decrease pixel value
                }
            }
        }
    }
}

//////////////////////////////////////////////////////////////// FILTER  (bounce) ////////////////////////////////////////////////////////////////
void addnoise(Image& image, double intens ) {
    random_device rd;
    default_random_engine rng(rd());
    uniform_int_distribution<int> distribution(-intens * 255, intens * 255);
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
                // Generate random noise for each channel
                int noise_red = distribution(rng);
                int noise_green = distribution(rng);
                int noise_blue = distribution(rng);
                // Add noise to the pixel values
                image(i, j , 0) = min(255, max(0, image(i, j , 0) + noise_red)); // Ensure pixel value stays within [0, 255]
                image(i, j , 1) = min(255, max(0, image(i, j, 1) + noise_green));
                image(i, j , 2) = min(255, max(0, image(i, j , 2) + noise_blue));
            }
        }
    }
