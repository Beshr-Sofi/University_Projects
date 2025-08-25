//filter #1
#include <iostream>
#include <cmath>
#include "Image_Class.h"

using namespace std;
//filter #1
void grayscale(Image& image) {
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
// filter #7
void Darken_and_Lighten_Image(Image& image){
    Image image("luffy.jpg");
    int choice;
    cout << " Do you want to make the image darker(1) or lighter(2) : ";
    cin >> choice;
    if (choice == 1){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    double newValue = image(i, j, k) * 0.5;
                    if (newValue < 0) {
                         newValue = 0;
                    }
                    if (newValue > 255) {
                        newValue = 255;
                    }
                    image(i, j, k) = newValue;
                }
            }
        }
        image.saveImage("edited.jpg");
    }
    else if (choice == 2){
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < image.channels; k++) {
                    double newValue = image(i, j, k) * 1.5;
                    if (newValue < 0) {
                        newValue = 0;
                    }
                    if (newValue > 255) {
                        newValue = 255;
                    }
                    image(i, j, k) = newValue;
                }
            }
        }
        image.saveImage("edited.jpg");
    }else {
        cout << " Invalid choice ";
    }
    return 0;
}
// filter #4
void merge(Image& image1, const Image& image2) {
    // Check if the dimensions of the images match
    if (image1.width != image2.width || image1.height != image2.height) {
        cerr << "Error: Images dimensions don't match." << endl;
        return;
    }

    // Merge the images
    for (int x = 0; x < image1.width; x++) {
        for (int y = 0; y < image1.height; y++) {
            for (int z = 0; z < image1.channels; z++) {
                int pixel1 = image1.getPixel( x, y, z);
                int pixel2 = image2.getPixel( x, y, z);
                int blendedPixel = (pixel1 + pixel2) / 2;
                if (blendedPixel < 0) {
                    blendedPixel = 0;
                }
                if (blendedPixel > 255) {
                    blendedPixel = 255;
                }
                image1.setPixel(x, y, z, blendedPixel);
            }
        }
    }
}

void resize2(Image& image, int newWidth, int newHeight) {

    int oldWidth = image.width;
    int oldHeight = image.height;

    // Create a new image with the specified dimensions
    Image resized(newWidth, newHeight);

    // Calculate the scale factors
    float scaleX = static_cast<float>(oldWidth) / newWidth;
    float scaleY = static_cast<float>(oldHeight) / newHeight;

    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            // Calculate the corresponding coordinates in the original image
            int oldX = round(x * scaleX);
            int oldY = round(y * scaleY);

            // Set the pixel value in the resized image
            for (int c = 0; c < image.channels; c++) {
                resized.setPixel(x, y, c, image.getPixel(oldX, oldY, c));
            }
        }
    }
}
// filter #10
void Detect_Image_Edges(Image& image) {

    int width = image.width;
    int height = image.height;


    int **edge_magnitude = new int*[height];
    for (int i = 0; i < height; i++) {
        edge_magnitude[i] = new int[width];
    }

    int sobel_x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int sobel_y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            int gx = 0, gy = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    gx += sobel_x[x + 1][y + 1] * image.getPixel(i + x, j + y, 0);
                    gy += sobel_y[x + 1][y + 1] * image.getPixel(i + x, j + y, 0);
                }
            }
            edge_magnitude[j][i] = sqrt(gx * gx + gy * gy)*0.5;
        }
    }

    double threshold = 0;
    for (int i = 1; i < width - 1; i++) {
        for (int j = 1; j < height - 1; j++) {
            threshold += edge_magnitude[j][i];
        }
    }
    threshold /= ((width - 2) * (height - 2));

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (edge_magnitude[j][i] > threshold) {
                image.setPixel(i, j, 0, 0);
                image.setPixel(i, j, 1, 0);
                image.setPixel(i, j, 2, 0);
            } else {
                image.setPixel(i, j, 0, 255);
                image.setPixel(i, j, 1, 255);
                image.setPixel(i, j, 2, 255);
            }
        }
    }

    for (int i = 0; i < height; i++) {
        delete[] edge_magnitude[i];
    }
    delete[] edge_magnitude;

}
//filter #13
void good_natural_sunlight(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            int red = image.getPixel(i, j, 0);
            int green = image.getPixel(i, j, 1);
            int blue = image.getPixel(i, j, 2);
            
            // Adjust pixel values
            red += 50;
            green += 50;
            blue -= 50;
            
            // Check lower bounds
            if (red < 0) red = 0;
            if (green < 0) green = 0;
            if (blue < 0) blue = 0;
            
            // Check upper bounds
            if (red > 255) red = 255;
            if (green > 255) green = 255;
            if (blue > 255) blue = 255;
            
            // Set modified pixel values
            image.setPixel(i, j, 0, red);
            image.setPixel(i, j, 1, green);
            image.setPixel(i, j, 2, blue);
        }
    }
}
//filter #14

void oil_paint(Image& image) {
    int width = image.width;
    int height = image.height;

    // Image processing logic
    for (int i = 2; i < width - 2; i++) { // Adjusted loop boundaries
        for (int j = 2; j < height - 2; j++) { // Adjusted loop boundaries
            // Array to store the RGB values of surrounding pixels
            array<int, 26> reds;
            array<int, 26> greens;
            array<int, 26> blues;

            int index = 0;
            for (int x = i - 2; x <= i + 2; x++) {
                for (int y = j - 2; y <= j + 2; y++) {
                    reds[index] = image.getPixel(x, y, 0);
                    greens[index] = image.getPixel(x, y, 1);
                    blues[index] = image.getPixel(x, y, 2);
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
            image.setPixel(i, j, 0, repeated_r);
            image.setPixel(i, j, 1, repeated_g);
            image.setPixel(i, j, 2, repeated_b);
        }
    }

    // Optional error handling for saving the image
    if (!image.saveImage("edited.jpg")) {
        cerr << "Error saving image!" << endl;
        return 1;
    }

}

//filter bonus movie filter
void movie_filter(Image& image) {
    int width = image.width;
    int height = image.height;

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
                    reds[k] = image.getPixel(i + x, j + y, 0);
                    greens[k] = image.getPixel(i + x, j + y, 1);
                    blues[k] = image.getPixel(i + x, j + y, 2);
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
            image.setPixel(i, j, 0, repeated_r);
            image.setPixel(i, j, 1, repeated_g);
            image.setPixel(i, j, 2, repeated_b);
        }
    }

    // Optional error handling for saving the image
    if (!image.saveImage("edited.jpg")) {
        cerr << "Error saving image!" << endl;
        return 1;
    }

}
