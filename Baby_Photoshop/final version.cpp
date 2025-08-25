/*
Through a variety of image processing techniques, this C++ application offers features similar to those of a simple photo editing tool.
It has tools for importing, adjusting, and storing images.
The following operations are supported: flipping (horizontally and vertically), brightness adjustment,
grayscale conversion, image inversion, rotation (90, 180, 270 degrees), and black-and-white conversion.
Through a console-based menu system, users can interact with the program by selecting from a variety of options to interactively alter images.
The program also ensures error handling during input operations and offers feedback about the loading and saving of image processes.
 ---------------
Name: هنا وجدي ناجي
ID: 20230459
Email: hanawagdy038@gmail.com
Filters: 2, 5
 ----------------
Name: فاطمة نزيه حنفي
ID: 20230284
Email: fatmanazeih37@gmail.com
Filters: 1, 4
 ---------------
Name: محمد بشر محمد
ID: 20230717
Email: Beshrsofi2005@gmail.com
Filters: 3, 6
*/


#include <iostream>
#include<string>
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
    string choice1,image_name_before,choice2,image_name_after;
    bool status1 = true,status2= true;
    Image image;
    cout <<"***********HELLO TO THE BABY PHOTOSHOP***********\n";
    while(status1) {
        cout << "Please enter the image name and directory to edit it: ";
        //check if user enter correct image name
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
            // show a message to inform the user about what filter is available
            cout<<"1-Load a new image\n2-Invert the image\n3-Rotate the image\n4-Change the brightness\n5-Gray Filter\n6-Flip the image\n7-black & white Filter\n8-Save the image\n9-Exit\n";
            cout << "Please choose number(1-9) to apply a filter\n";
            cin >> choice1;

            if(choice1=="1"){ //  a choice to update the old image with a new image to edit.
                cout <<"Do you want to save image before load?\n1-yes\n2-no\n";
                while (true){
                    cin >> choice2;
                    if(choice2 == "1"){ // the user choose yes
                        cout << "Now please enter the image name and the directory and the format to save it: ";
                        while (true){
                            try {
                                cin >> image_name_after;
                                if(image.saveImage(image_name_after)){
                                    // save the image after the edit and show a message to inform the user that the image  have been saved successfully
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
                    else if(choice2 == "2"){
                        status2= false;
                        break;
                    }
                    else{
                        cout << "invalid input\n";
                    }
                }
            }
            else if(choice1=="2"){ // user choose to invert the colors of the image
                image_invert(image); // call the function
            }
            else if(choice1=="3"){ // user choose to rotate the image
                while (true){
                    cout <<"How do you want to rotate image?\n1-Rotate 90 degrees\n2-Rotate 180 degrees\n3-Rotate 270 degrees\n";
                    cout << " choose a number (1-3)" << endl;
                    cin >> choice2;
                    if(choice2 == "1"){ // if the user choose 1 (90 degree)

                        image_rotate_90(image); // call the function that rotate the image 90 degree
                        break;
                    }
                    else if(choice2 == "2"){ // if the user choose 2 (180 degree)
                        image_rotate_180(image); // call the function that rotate the image 180 degree
                        break;
                    }
                    else if (choice2 == "3"){ // if the user chose 3 (270 degree)
                        image_rotate_270(image); // call the function that rotate the image 270 degree
                        break;
                    }
                    else{ // if user entered invalid choice
                        cout << "invalid input\n";
                    }
                }
            }
            else if(choice1=="4"){
                while (true){ // user chose 4 to Change the brightness
                    cout << "1-decrease the brightness\n2-increase the brightness\n";
                    cout << "choose number (1 or 2)"<< endl;
                    cin >> choice2;
                    if(choice2 == "1"){ // user entered 1 (make the image darker)
                        image_darkness(image); // call the function to apply the dark filter
                        break;
                    }
                    else if(choice2 == "2"){ // user entered 2 (make the image brighter)
                        image_brightness(image); // call the function to apply the bright filter
                        break;
                    }
                    else{ // user enter invalid choice
                        cout << "invalid input\n"; // show an error message
                    }
                }
            }
            else if(choice1=="5"){ // user chose 5 to apply the gray Filter
                image_gray(image); // call the function to apply the gray filter
            }
            else if(choice1=="6"){ // user chose 6 to flip the image
                while (true){
                    cout <<"1-flip Vertically\n2-flip horizontally\n";
                    cin >> choice2;
                    if(choice2 == "1"){ // user chose 1 to flip vertically
                        image_flipped_vertical(image); // call the function to flip vertically
                        break;
                    }
                    else if(choice2 == "2"){ // user chose 2 to flip horizontally
                        image_flipped_Horizontal(image); // call the function to flip horizontally
                        break;
                    }
                    else{
                        cout << "invalid input\n";
                    }
                }
            }
            else if(choice1=="7"){ // user chose 7 to apply the black & white Filter
                black_and_white(image); // call the function to apply the black & white Filter
            }
            else if(choice1=="8"){ // user chose 7 to save the image
                cout << "Enter the image name and the directory and the format to SAVE it: ";
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
            else if(choice1=="9"){ // user chose 9 to Exit the program
                cout <<"Thanks for using our baby photoshop\ngoodbye";
                status1= false; // status1= false so the loop will not continue
                break;
            }
            else{
                cout <<"Invalid input\n";
            }
        }
    }
}



//function to invert image
void image_invert(Image& image){
    for(int i = 0;i<image.width;i++){
        for(int j = 0;j<image.height;j++){
            image(i,j,0) = 255 - image(i,j,0); // update the value of the pixel
            image(i,j,1) = 255 - image(i,j,1);
            image(i,j,2) = 255 - image(i,j,2);
        }
    }
}
//function to rotate image 90 degrees
void image_rotate_90(Image& image_before){
    Image image_after(image_before.height,image_before.width); // declare a new image with the same dimensions after the rotation

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
    image_before=image_after;
}
//function to rotate image 180 degrees
void image_rotate_180(Image& image_before){
    Image image_after (image_before.width,image_before.height);
    for(int i = 0;i<image_before.width;i++){
        for(int j = 0;j<image_before.height;j++){
            image_after(i,j,0)=image_before(image_before.width-1-i,image_before.height-1-j,0);
            image_after(i,j,1)=image_before(image_before.width-1-i,image_before.height-1-j,1);
            image_after(i,j,2)=image_before(image_before.width-1-i,image_before.height-1-j,2);
        }
    }
    image_before=image_after;
}
//function to rotate image 270 degrees
void image_rotate_270(Image& image_before){
    Image image_after(image_before.height,image_before.width);
    for(int i = 0;i<image_before.width;i++) {
        for (int j = image_before.height - 1; j >= 0; j--) {
            image_after(j, i, 0) = image_before(image_before.width-1-i, j, 0);
            image_after(j, i, 1) = image_before(image_before.width-1-i, j, 1);
            image_after(j, i, 2) = image_before(image_before.width-1-i, j, 2);
        }
    }
    image_before=image_after;
}
// Function to decrease the brightness of an image by halving the pixel values
void image_darkness(Image& image){
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) { // For each pixel, iterate over its channels (e.g., Red, Green, Blue)
                double newValue = image(i, j, k) * 0.5; // Reduce the pixel value by multiplying it by 0.5 to decrease
                if (newValue > 255) {// Ensure the new value does not exceed 255 (maximum pixel value)
                    newValue = 255;
                }
                image(i, j, k) = newValue;// Update the pixel value with the new, darker value
            }
        }
    }
}
// Function to increase the brightness of an image by multiplying pixel values by 1.5
void image_brightness(Image& image){
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < image.channels; k++) {// For each pixel, iterate over its channels (e.g., Red, Green, Blue)
                double newValue = image(i, j, k) * 1.5;// Increase the pixel value by multiplying it by 1.5 to increase
                if (newValue > 255) {// Ensure the new value does not exceed 255 (maximum pixel value)
                    newValue = 255;
                }
                image(i, j, k) = newValue;// Update the pixel value with the new, brighter value
            }
        }
    }
}
// Function to convert an image to grayscale by taking the average of its RGB channels
void image_gray(Image& image){
    // Iterate over each pixel in the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            unsigned int avg = 0;
            for (int k = 0; k < image.channels; k++) {// Calculate the average pixel value by summing up all channels
                avg += image(i, j, k);
            }
            avg = avg / 3; // Compute the average by dividing the sum by the number of channels
            for (int k = 0; k < image.channels; k++) {// Set all channels of the pixel to the computed average value, effectively turning it grayscale
                image(i, j, k) = avg;
            }
        }
    }
}
void image_flipped_vertical(Image& image){
    Image new_image(image.width, image.height); // make a new image with the same dimensions of the original image
    for (int i = 0; i< image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                new_image(i, image.height - 1 - j, k) = image(i, j, k);
                // swap the first pixel in the first column with the last pixel in the same column
                // and so on until we reach the last column in the original image
            }
        }
    }
    image = new_image;
}
void image_flipped_Horizontal(Image& image){
    Image new_image(image.width, image.height);  // make a new image with the same dimensions of the original image

    for(int i=0;i <image.width ; ++i){
        for(int j=0; j <image.height; ++j){
            for(int k=0; k <3; ++k){
                new_image(image.width - 1 - i, j, k)=image(i, j, k);
                // swap the first pixel in the first row with the last pixel in the same column
                // and so on until we reach the last row in the original image

            }
        }
    }
    image = new_image;
}
void black_and_white(Image&image){
    for(int i=0; i<image.width; ++i){
        for(int j=0; j<image.height; ++j){
            unsigned int avg=0;
            for(int k=0; k<3; ++k){
                avg +=image(i, j, k); // add the value of each color in the pixel to the variable
            }
            avg /=3; // get the average
            if(avg >127.5){ // if the average is bigger than 127.5 make it white
                image(i, j,0)=255;
                image(i, j,1)=255;
                image(i, j,2)=255;
            }
            else{ // if the average is smaller than 127.5 make the pixel black
                image(i,j,0)=0;
                image(i,j,1)=0;
                image(i,j,2)=0;
            }
        }
    }
}
