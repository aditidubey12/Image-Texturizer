#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Header{
    char idLength;
    char colorMapType;
    char dataTypeCode;
    short colorMapOrigin;
    short colorMapLength;
    char colorMapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};
struct Pixel{
    unsigned char red;
    unsigned char blue;
    unsigned char green;
};

int main() {
    Header header;
    Pixel pixel;
    Pixel otherPixel;
    Pixel imagePixel;
    Pixel layerPixel;
    Pixel carPixel;
    Pixel finalPixel;
    Pixel circles;
    Pixel multiply;
    Pixel pattern;
    Pixel load;
    Pixel thirdPixel;
    Pixel textPixel;
    Pixel diffPixel;
    Pixel overlay;
    Pixel sixth;
    Pixel seventh;
    Pixel redC;
    Pixel blueC;
    Pixel greenC;
    Pixel red2;
    Pixel blue2;
    Pixel green2;
    Pixel ninth;
    Pixel textPixel2;
    vector<Pixel> tempScreen;
    vector<Pixel> screen;
    vector<Pixel> pixels;
    vector<Pixel> tempPixel;
    vector<Pixel> result;
    vector<Pixel> layer;
    vector<Pixel> car;
    vector<Pixel> subtract;
    vector<Pixel> tempCircle;
    vector<Pixel> fourth;
    vector<Pixel> tempPattern;
    vector<Pixel> fourthFinal;
    vector<Pixel> tempText;
    vector<Pixel> fifth;
    vector<Pixel> green;
    vector<Pixel> red;
    vector<Pixel> redTga;
    vector<Pixel> blueTga;
    vector<Pixel> greenTga;
    vector<Pixel> layerRed;
    vector<Pixel> layerBlue;
    vector<Pixel> layerGreen;
    vector<Pixel> reverse;
    vector<Pixel> tempText2;
    vector<Pixel> last;
    ifstream file("input/layer1.tga", ios_base::binary);
    if (file.is_open()) {
        //read the header data
        file.read(&header.idLength, sizeof(header.idLength));
        file.read(&header.colorMapType, sizeof(header.colorMapType));
        file.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        file.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        file.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        file.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        file.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        file.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        file.read((char *) &header.width, sizeof(header.width));
        file.read((char *) &header.height, sizeof(header.height));
        file.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        file.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            file.read((char *) &pixel.blue, sizeof(pixel.blue));
            file.read((char *) &pixel.green, sizeof(pixel.green));
            file.read((char *) &pixel.red, sizeof(pixel.red));
            pixels.push_back(pixel);
        }
        file.close();
    }
    ifstream someFile("input/pattern1.tga", ios_base::binary);
    if (someFile.is_open()) {
        someFile.read(&header.idLength, sizeof(header.idLength));
        someFile.read(&header.colorMapType, sizeof(header.colorMapType));
        someFile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        someFile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        someFile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        someFile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        someFile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        someFile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        someFile.read((char *) &header.width, sizeof(header.width));
        someFile.read((char *) &header.height, sizeof(header.height));
        someFile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        someFile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            someFile.read((char *) &otherPixel.blue, sizeof(otherPixel.blue));
            someFile.read((char *) &otherPixel.green, sizeof(otherPixel.green));
            someFile.read((char *) &otherPixel.red, sizeof(otherPixel.red));
            tempPixel.push_back(otherPixel);
        }
        someFile.close();
    }
    for (unsigned int i = 0; i < pixels.size(); i++) {
        float tempVal = (pixels[i].red / 255.0 * tempPixel[i].red / 255.0) * 255.0 + 0.5f;
        if (tempVal > 255) {
            imagePixel.red = 255;
        }
        if (tempVal < 0) {
            imagePixel.red = 0;
        } else {
            imagePixel.red = tempVal;
        }
        float temp = (pixels[i].blue / 255.0 * tempPixel[i].blue / 255.0) * 255.0 + 0.5f;
        if (temp > 255) {
            imagePixel.blue = 255;
        }
        if (temp < 0) {
            imagePixel.blue = 0;
        } else {
            imagePixel.blue = temp;
        }
        float tempGreen = (pixels[i].green / 255.0 * tempPixel[i].green / 255.0) * 255.0 + 0.5f;
        if (tempGreen > 255) {
            imagePixel.green = 255;
        }
        if (tempGreen < 0) {
            imagePixel.green = 0;
        } else {
            imagePixel.green = tempGreen;
        }
        result.push_back(imagePixel);
    }
    ofstream newFile("output/part1.tga", ios_base::binary);
    if (newFile.is_open()) {
        newFile.write(&header.idLength, sizeof(header.idLength));
        newFile.write(&header.colorMapType, sizeof(header.colorMapType));
        newFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        newFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        newFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        newFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        newFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        newFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        newFile.write((char *) &header.width, sizeof(header.width));
        newFile.write((char *) &header.height, sizeof(header.height));
        newFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        newFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            newFile.write((char *) &result[i].blue, sizeof(result[i].blue));
            newFile.write((char *) &result[i].green, sizeof(result[i].green));
            newFile.write((char *) &result[i].red, sizeof(result[i].red));
        }
        newFile.close();
    }

    ifstream layerFile("input/layer2.tga", ios_base::binary);
    if (layerFile.is_open()) {
        //read the header data
        layerFile.read(&header.idLength, sizeof(header.idLength));
        layerFile.read(&header.colorMapType, sizeof(header.colorMapType));
        layerFile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        layerFile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        layerFile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        layerFile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        layerFile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        layerFile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        layerFile.read((char *) &header.width, sizeof(header.width));
        layerFile.read((char *) &header.height, sizeof(header.height));
        layerFile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        layerFile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            layerFile.read((char *) &layerPixel.blue, sizeof(layerPixel.blue));
            layerFile.read((char *) &layerPixel.green, sizeof(layerPixel.green));
            layerFile.read((char *) &layerPixel.red, sizeof(layerPixel.red));
            layer.push_back(layerPixel);
        }
        layerFile.close();
    }
    ifstream carfile("input/car.tga", ios_base::binary);
    if (carfile.is_open()) {
        //read the header data
        carfile.read(&header.idLength, sizeof(header.idLength));
        carfile.read(&header.colorMapType, sizeof(header.colorMapType));
        carfile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        carfile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        carfile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        carfile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        carfile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        carfile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        carfile.read((char *) &header.width, sizeof(header.width));
        carfile.read((char *) &header.height, sizeof(header.height));
        carfile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        carfile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            carfile.read((char *) &carPixel.blue, sizeof(carPixel.blue));
            carfile.read((char *) &carPixel.green, sizeof(carPixel.green));
            carfile.read((char *) &carPixel.red, sizeof(carPixel.red));
            car.push_back(carPixel);
        }
        carfile.close();
    }
    for (unsigned int i = 0; i < layer.size(); i++) {
        float tempVal = (car[i].red / 255.0 - layer[i].red / 255.0) * 255.0 + 0.5f;
        if (tempVal > 255) {
            finalPixel.red = 255;
        }
        if (tempVal < 0) {
            finalPixel.red = 0;
        } else {
            finalPixel.red = tempVal;
        }
        float temp = (car[i].blue / 255.0 - layer[i].blue / 255.0) * 255.0 + 0.5f;
        if (temp > 255) {
            finalPixel.blue = 255;
        }
        if (temp < 0) {
            finalPixel.blue = 0;
        } else {
            finalPixel.blue = temp;
        }
        float tempGreen = (car[i].green / 255.0 - layer[i].green / 255.0) * 255.0 + 0.5f;
        if (tempGreen > 255) {
            finalPixel.green = 255;
        }
        if (tempGreen < 0) {
            finalPixel.green = 0;
        } else {
            finalPixel.green = tempGreen;
        }
        subtract.push_back(finalPixel);
    }
    ofstream subFile("output/part2.tga", ios_base::binary);
    if (subFile.is_open()) {
        subFile.write(&header.idLength, sizeof(header.idLength));
        subFile.write(&header.colorMapType, sizeof(header.colorMapType));
        subFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        subFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        subFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        subFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        subFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        subFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        subFile.write((char *) &header.width, sizeof(header.width));
        subFile.write((char *) &header.height, sizeof(header.height));
        subFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        subFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            subFile.write((char *) &subtract[i].blue, sizeof(subtract[i].blue));
            subFile.write((char *) &subtract[i].green, sizeof(subtract[i].green));
            subFile.write((char *) &subtract[i].red, sizeof(subtract[i].red));
        }
        subFile.close();
    }
    ifstream circlefile("input/circles.tga", ios_base::binary);
    if (circlefile.is_open()) {
        //read the header data
        circlefile.read(&header.idLength, sizeof(header.idLength));
        circlefile.read(&header.colorMapType, sizeof(header.colorMapType));
        circlefile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        circlefile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        circlefile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        circlefile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        circlefile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        circlefile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        circlefile.read((char *) &header.width, sizeof(header.width));
        circlefile.read((char *) &header.height, sizeof(header.height));
        circlefile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        circlefile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            circlefile.read((char *) &circles.blue, sizeof(circles.blue));
            circlefile.read((char *) &circles.green, sizeof(circles.green));
            circlefile.read((char *) &circles.red, sizeof(circles.red));
            tempCircle.push_back(circles);
        }
        circlefile.close();
    }
    for (unsigned int i = 0; i < layer.size(); i++) {
        float tempVal = (layer[i].red / 255.0 * tempCircle[i].red / 255.0) * 255.0 + 0.5f;
        if (tempVal > 255) {
            multiply.red = 255;
        }
        if (tempVal < 0) {
            multiply.red = 0;
        } else {
            multiply.red = tempVal;
        }
        float temp = (layer[i].blue / 255.0 * tempCircle[i].blue / 255.0) * 255.0 + 0.5f;
        if (temp > 255) {
            multiply.blue = 255;
        }
        if (temp < 0) {
            multiply.blue = 0;
        } else {
            multiply.blue = temp;
        }
        float tempGreen = (layer[i].green / 255.0 * tempCircle[i].green / 255.0) * 255.0 + 0.5f;
        if (tempGreen > 255) {
            multiply.green = 255;
        }
        if (tempGreen < 0) {
            multiply.green = 0;
        } else {
            multiply.green = tempGreen;
        }
        fourth.push_back(multiply);
    }
    ifstream patternfile("input/pattern2.tga", ios_base::binary);
    if (patternfile.is_open()) {
        //read the header data
        patternfile.read(&header.idLength, sizeof(header.idLength));
        patternfile.read(&header.colorMapType, sizeof(header.colorMapType));
        patternfile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        patternfile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        patternfile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        patternfile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        patternfile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        patternfile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        patternfile.read((char *) &header.width, sizeof(header.width));
        patternfile.read((char *) &header.height, sizeof(header.height));
        patternfile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        patternfile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            patternfile.read((char *) &pattern.blue, sizeof(pattern.blue));
            patternfile.read((char *) &pattern.green, sizeof(pattern.green));
            patternfile.read((char *) &pattern.red, sizeof(pattern.red));
            tempPattern.push_back(pattern);
        }
        patternfile.close();
    }
    for (unsigned int i = 0; i < layer.size(); i++) {
        float tempVal = (fourth[i].red / 255.0 - tempPattern[i].red / 255.0) * 255.0 + 0.5f;
        if (tempVal > 255) {
            load.red = 255;
        }
        if (tempVal < 0) {
            load.red = 0;
        } else {
            load.red = tempVal;
        }
        float temp = (fourth[i].blue / 255.0 - tempPattern[i].blue / 255.0) * 255.0 + 0.5f;
        if (temp > 255) {
            load.blue = 255;
        }
        if (temp < 0) {
            load.blue = 0;
        } else {
            load.blue = temp;
        }
        float tempGreen = (fourth[i].green / 255.0 - tempPattern[i].green / 255.0) * 255.0 + 0.5f;
        if (tempGreen > 255) {
            load.green = 255;
        }
        if (tempGreen < 0) {
            load.green = 0;
        } else {
            load.green = tempGreen;
        }
        fourthFinal.push_back(load);
    }
    ofstream bothFile("output/part4.tga", ios_base::binary);
    if (bothFile.is_open()) {
        bothFile.write(&header.idLength, sizeof(header.idLength));
        bothFile.write(&header.colorMapType, sizeof(header.colorMapType));
        bothFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        bothFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        bothFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        bothFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        bothFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        bothFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        bothFile.write((char *) &header.width, sizeof(header.width));
        bothFile.write((char *) &header.height, sizeof(header.height));
        bothFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        bothFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            bothFile.write((char *) &fourthFinal[i].blue, sizeof(fourthFinal[i].blue));
            bothFile.write((char *) &fourthFinal[i].green, sizeof(fourthFinal[i].green));
            bothFile.write((char *) &fourthFinal[i].red, sizeof(fourthFinal[i].red));
        }
        subFile.close();
    }
    for (unsigned int i = 0; i < pixels.size(); i++) {
        float tempVal = (pixels[i].red / 255.0 * tempPattern[i].red / 255.0) * 255.0 + 0.5f;
        if (tempVal > 255) {
            thirdPixel.red = 255;
        }
        if (tempVal < 0) {
            thirdPixel.red = 0;
        } else {
            thirdPixel.red = tempVal;
        }
        float temp = (pixels[i].blue / 255.0 * tempPattern[i].blue / 255.0) * 255.0 + 0.5f;
        if (temp > 255) {
            thirdPixel.blue = 255;
        }
        if (temp < 0) {
            thirdPixel.blue = 0;
        } else {
            thirdPixel.blue = temp;
        }
        float tempGreen = (pixels[i].green / 255.0 * tempPattern[i].green / 255.0) * 255.0 + 0.5f;
        if (tempGreen > 255) {
            thirdPixel.green = 255;
        }
        if (tempGreen < 0) {
            thirdPixel.green = 0;
        } else {
            thirdPixel.green = tempGreen;
        }
        screen.push_back(thirdPixel);
    }
    ifstream textfile("input/text.tga", ios_base::binary);
    if (textfile.is_open()) {
        //read the header data
        textfile.read(&header.idLength, sizeof(header.idLength));
        textfile.read(&header.colorMapType, sizeof(header.colorMapType));
        textfile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        textfile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        textfile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        textfile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        textfile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        textfile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        textfile.read((char *) &header.width, sizeof(header.width));
        textfile.read((char *) &header.height, sizeof(header.height));
        textfile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        textfile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            textfile.read((char *) &textPixel.blue, sizeof(textPixel.blue));
            textfile.read((char *) &textPixel.green, sizeof(textPixel.green));
            textfile.read((char *) &textPixel.red, sizeof(textPixel.red));
            tempText.push_back(textPixel);
        }
        textfile.close();
    }
    for (unsigned int i = 0; i < pixels.size(); i++) {
        float tempVal =
                (1 - (1 - (float) screen[i].red / 255.0) * (1 - (float) tempText[i].red / 255.0)) * 255.0 + 0.5f;
        if (tempVal > 255) {
            diffPixel.red = 255;
        }
        if (tempVal < 0) {
            diffPixel.red = 0;
        } else {
            diffPixel.red = tempVal;
        }
        float temp = (1 - (1 - (float) screen[i].blue / 255.0) * (1 - (float) tempText[i].blue / 255.0)) * 255.0 + 0.5f;
        if (temp > 255) {
            diffPixel.blue = 255;
        }
        if (temp < 0) {
            diffPixel.blue = 0;
        } else {
            diffPixel.blue = temp;
        }
        float tempGreen =
                (1 - (1 - (float) screen[i].green / 255.0) * (1 - (float) tempText[i].green / 255.0)) * 255.0 + 0.5f;
        if (tempGreen > 255) {
            diffPixel.green = 255;
        }
        if (tempGreen < 0) {
            diffPixel.green = 0;
        } else {
            diffPixel.green = tempGreen;
        }
        tempScreen.push_back(diffPixel);
    }
    ofstream diffFile("output/part3.tga", ios_base::binary);
    if (diffFile.is_open()) {
        diffFile.write(&header.idLength, sizeof(header.idLength));
        diffFile.write(&header.colorMapType, sizeof(header.colorMapType));
        diffFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        diffFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        diffFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        diffFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        diffFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        diffFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        diffFile.write((char *) &header.width, sizeof(header.width));
        diffFile.write((char *) &header.height, sizeof(header.height));
        diffFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        diffFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            diffFile.write((char *) &tempScreen[i].blue, sizeof(tempScreen[i].blue));
            diffFile.write((char *) &tempScreen[i].green, sizeof(tempScreen[i].green));
            diffFile.write((char *) &tempScreen[i].red, sizeof(tempScreen[i].red));
        }
        diffFile.close();
    }
    //overlay function
    for (unsigned int i = 0; i < pixels.size(); i++) {
        if ((float)tempPixel[i].red/255.0f <= 0.5) {
            float red = (float)pixels[i].red/255.0f;
            float red2 = (float)tempPixel[i].red/255.0f;
            float tempVal = 2*red*red2;
            tempVal = tempVal * 255.0f + 0.5f;
            if (tempVal > 255) {
                overlay.red = 255;
            }
            else if (tempVal < 0) {
                overlay.red = 0;
            }
            else {
                overlay.red = tempVal;
            }
        }
        else if ((float)tempPixel[i].red/255.0f > 0.5) {
            float red = (float)pixels[i].red/255.0f;
            float red2 = (float)tempPixel[i].red/255.0f;
            float tempVal = 1-(2*(float)(1-red)*(float)(1-red2));
            tempVal = tempVal * 255.0f + 0.5f;
            if (tempVal > 255) {
                overlay.red = 255;
            }
            else if (tempVal < 0) {
                overlay.red = 0;
            }
            else {
                overlay.red = tempVal;
            }
        }
        if ((float)tempPixel[i].blue/255.0f <= 0.5) {
            float blue = (float)pixels[i].blue/255.0f;
            float blue2 = (float)tempPixel[i].blue/255.0f;
            float temp = 2*blue*blue2;
            temp = temp * 255.0f + 0.5f;
            if (temp > 255) {
                overlay.blue = 255;
            }
            else if (temp < 0) {
                overlay.blue = 0;
            }
            else {
                overlay.blue = temp;
            }
        }
        else if ((float)tempPixel[i].blue/255.0f > 0.5) {
            float blue = (float)pixels[i].blue/255.0f;
            float blue2 = (float)tempPixel[i].blue/255.0f;
            float temp = 1-(2*(float)(1-blue)*(float)(1-blue2));
            temp = temp * 255.0f + 0.5f;
            if (temp > 255) {
                overlay.blue = 255;
            }
            else if (temp < 0) {
                overlay.blue = 0;
            }
            else {
                overlay.blue = temp;
            }
        }
            if ((float)tempPixel[i].green/255.0f <= 0.5) {
                float green = (float)pixels[i].green/255.0f;
                float green2 = (float)tempPixel[i].green/255.0f;
                float tempGreen = 2*green*green2;
                tempGreen = tempGreen * 255.0f + 0.5f;
                if (tempGreen > 255) {
                    overlay.green = 255;
                }
                else if (tempGreen < 0) {
                    overlay.green = 0;
                } else {
                    overlay.green = tempGreen;
                }
            }
            else if ((float)tempPixel[i].green/255.0f > 0.5) {
                float green = (float)pixels[i].green/255.0f;
                float green2 = (float)tempPixel[i].green/255.0f;
                float tempGreen = 1-(2*(float)(1-green)*(float)(1-green2));
                tempGreen = tempGreen * 255.0f + 0.5f;
                if (tempGreen > 255) {
                    overlay.green = 255;
                }
                else if (tempGreen < 0) {
                    overlay.green = 0;
                } else {
                    overlay.green = tempGreen;
                }
            }
             fifth.push_back(overlay);
         }
    ofstream fifthFile("output/part5.tga", ios_base::binary);
    if (fifthFile.is_open()) {
        fifthFile.write(&header.idLength, sizeof(header.idLength));
        fifthFile.write(&header.colorMapType, sizeof(header.colorMapType));
        fifthFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        fifthFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        fifthFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        fifthFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        fifthFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        fifthFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        fifthFile.write((char *) &header.width, sizeof(header.width));
        fifthFile.write((char *) &header.height, sizeof(header.height));
        fifthFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        fifthFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            fifthFile.write((char *) &fifth[i].blue, sizeof(fifth[i].blue));
            fifthFile.write((char *) &fifth[i].green, sizeof(fifth[i].green));
            fifthFile.write((char *) &fifth[i].red, sizeof(fifth[i].red));
        }
        fifthFile.close();
    }
    for (unsigned int i = 0; i < car.size(); i++) {
        sixth.red = car[i].red;
        sixth.blue = car[i].blue;
        float temp = car[i].green + 200;
        if (temp > 255) {
            sixth.green = 255;
        }
        else {
            sixth.green = temp;
        }
        green.push_back(sixth);
     }
        ofstream sixthFile("output/part6.tga", ios_base::binary);
        if (sixthFile.is_open()) {
            sixthFile.write(&header.idLength, sizeof(header.idLength));
            sixthFile.write(&header.colorMapType, sizeof(header.colorMapType));
            sixthFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
            sixthFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
            sixthFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
            sixthFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
            sixthFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
            sixthFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
            sixthFile.write((char *) &header.width, sizeof(header.width));
            sixthFile.write((char *) &header.height, sizeof(header.height));
            sixthFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
            sixthFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
            for (int i = 0; i < header.width * header.height; i++) {
                sixthFile.write((char *) &green[i].blue, sizeof(green[i].blue));
                sixthFile.write((char *) &green[i].green, sizeof(green[i].green));
                sixthFile.write((char *) &green[i].red, sizeof(green[i].red));
            }
            sixthFile.close();
        }
    for (unsigned int i = 0; i < car.size(); i++) {
        float temp = car[i].red * 4;
        if (temp > 255) {
            seventh.red = 255;
        }
        else {
            seventh.red = temp;
        }
        seventh.blue = 0;
        seventh.green = car[i].green;
        red.push_back(seventh);
    }
    ofstream seventhFile("output/part7.tga", ios_base::binary);
    if (seventhFile.is_open()) {
        seventhFile.write(&header.idLength, sizeof(header.idLength));
        seventhFile.write(&header.colorMapType, sizeof(header.colorMapType));
        seventhFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        seventhFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        seventhFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        seventhFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        seventhFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        seventhFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        seventhFile.write((char *) &header.width, sizeof(header.width));
        seventhFile.write((char *) &header.height, sizeof(header.height));
        seventhFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        seventhFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            seventhFile.write((char *) &red[i].blue, sizeof(red[i].blue));
            seventhFile.write((char *) &red[i].green, sizeof(red[i].green));
            seventhFile.write((char *) &red[i].red, sizeof(red[i].red));
        }
        seventhFile.close();
    }
    for (unsigned int i = 0; i < car.size(); i++) {
        redC.red = car[i].red;
        redC.blue = car[i].red;
        redC.green = car[i].red;
        redTga.push_back(redC);
    }
    for (unsigned int i = 0; i < car.size(); i++) {
        blueC.red = car[i].blue;
        blueC.blue = car[i].blue;
        blueC.green = car[i].blue;
        blueTga.push_back(blueC);
    }
    for (unsigned int i = 0; i < car.size(); i++) {
        greenC.red = car[i].green;
        greenC.blue = car[i].green;
        greenC.green = car[i].green;
        greenTga.push_back(greenC);
    }
    ofstream eightFile1("output/part8_r.tga", ios_base::binary);
    if (eightFile1.is_open()) {
        eightFile1.write(&header.idLength, sizeof(header.idLength));
        eightFile1.write(&header.colorMapType, sizeof(header.colorMapType));
        eightFile1.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        eightFile1.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        eightFile1.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        eightFile1.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        eightFile1.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        eightFile1.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        eightFile1.write((char *) &header.width, sizeof(header.width));
        eightFile1.write((char *) &header.height, sizeof(header.height));
        eightFile1.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        eightFile1.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            eightFile1.write((char *) &redTga[i].blue, sizeof(redTga[i].blue));
            eightFile1.write((char *) &redTga[i].green, sizeof(redTga[i].green));
            eightFile1.write((char *) &redTga[i].red, sizeof(redTga[i].red));
        }
        eightFile1.close();
    }
    ofstream eightFile2("output/part8_b.tga", ios_base::binary);
    if (eightFile2.is_open()) {
        eightFile2.write(&header.idLength, sizeof(header.idLength));
        eightFile2.write(&header.colorMapType, sizeof(header.colorMapType));
        eightFile2.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        eightFile2.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        eightFile2.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        eightFile2.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        eightFile2.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        eightFile2.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        eightFile2.write((char *) &header.width, sizeof(header.width));
        eightFile2.write((char *) &header.height, sizeof(header.height));
        eightFile2.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        eightFile2.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            eightFile2.write((char *) &blueTga[i].blue, sizeof(blueTga[i].blue));
            eightFile2.write((char *) &blueTga[i].green, sizeof(blueTga[i].green));
            eightFile2.write((char *) &blueTga[i].red, sizeof(blueTga[i].red));
        }
        eightFile2.close();
    }
    ofstream eightFile3("output/part8_g.tga", ios_base::binary);
    if (eightFile3.is_open()) {
        eightFile3.write(&header.idLength, sizeof(header.idLength));
        eightFile3.write(&header.colorMapType, sizeof(header.colorMapType));
        eightFile3.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        eightFile3.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        eightFile3.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        eightFile3.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        eightFile3.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        eightFile3.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        eightFile3.write((char *) &header.width, sizeof(header.width));
        eightFile3.write((char *) &header.height, sizeof(header.height));
        eightFile3.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        eightFile3.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            eightFile3.write((char *) &greenTga[i].blue, sizeof(greenTga[i].blue));
            eightFile3.write((char *) &greenTga[i].green, sizeof(greenTga[i].green));
            eightFile3.write((char *) &greenTga[i].red, sizeof(greenTga[i].red));
        }
        eightFile3.close();
    }
    ifstream redfile("input/layer_red.tga", ios_base::binary);
    if (redfile.is_open()) {
        //read the header data
        redfile.read(&header.idLength, sizeof(header.idLength));
        redfile.read(&header.colorMapType, sizeof(header.colorMapType));
        redfile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        redfile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        redfile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        redfile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        redfile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        redfile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        redfile.read((char *) &header.width, sizeof(header.width));
        redfile.read((char *) &header.height, sizeof(header.height));
        redfile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        redfile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            redfile.read((char *) &red2.blue, sizeof(red2.blue));
            redfile.read((char *) &red2.green, sizeof(red2.green));
            redfile.read((char *) &red2.red, sizeof(red2.red));
            layerRed.push_back(red2);
        }
        redfile.close();
    }
    ifstream greenfile("input/layer_green.tga", ios_base::binary);
    if (greenfile.is_open()) {
        //read the header data
        greenfile.read(&header.idLength, sizeof(header.idLength));
        greenfile.read(&header.colorMapType, sizeof(header.colorMapType));
        greenfile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        greenfile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        greenfile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        greenfile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        greenfile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        greenfile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        greenfile.read((char *) &header.width, sizeof(header.width));
        greenfile.read((char *) &header.height, sizeof(header.height));
        greenfile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        greenfile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            greenfile.read((char *) &green2.blue, sizeof(green2.blue));
            greenfile.read((char *) &green2.green, sizeof(green2.green));
            greenfile.read((char *) &green2.red, sizeof(green2.red));
            layerGreen.push_back(green2);
        }
        greenfile.close();
    }
    ifstream bluefile("input/layer_blue.tga", ios_base::binary);
    if (bluefile.is_open()) {
        //read the header data
        bluefile.read(&header.idLength, sizeof(header.idLength));
        bluefile.read(&header.colorMapType, sizeof(header.colorMapType));
        bluefile.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        bluefile.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        bluefile.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        bluefile.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        bluefile.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        bluefile.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        bluefile.read((char *) &header.width, sizeof(header.width));
        bluefile.read((char *) &header.height, sizeof(header.height));
        bluefile.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        bluefile.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            bluefile.read((char *) &blue2.blue, sizeof(blue2.blue));
            bluefile.read((char *) &blue2.green, sizeof(blue2.green));
            bluefile.read((char *) &blue2.red, sizeof(blue2.red));
            layerBlue.push_back(blue2);
        }
        bluefile.close();
    }
    //vector is reverse and pixel name is ninth
    for (unsigned int i = 0; i < layerBlue.size(); i++) {
        ninth.red = layerRed[i].red;
        ninth.blue = layerBlue[i].blue;
        ninth.green = layerGreen[i].green;
        reverse.push_back(ninth);
    }
    ofstream ninthFile("output/part9.tga", ios_base::binary);
    if (ninthFile.is_open()) {
        ninthFile.write(&header.idLength, sizeof(header.idLength));
        ninthFile.write(&header.colorMapType, sizeof(header.colorMapType));
        ninthFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        ninthFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        ninthFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        ninthFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        ninthFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        ninthFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        ninthFile.write((char *) &header.width, sizeof(header.width));
        ninthFile.write((char *) &header.height, sizeof(header.height));
        ninthFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        ninthFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            ninthFile.write((char *) &reverse[i].blue, sizeof(reverse[i].blue));
            ninthFile.write((char *) &reverse[i].green, sizeof(reverse[i].green));
            ninthFile.write((char *) &reverse[i].red, sizeof(reverse[i].red));
        }
        ninthFile.close();
    }
    ifstream textfile2("input/text2.tga", ios_base::binary);
    if (textfile2.is_open()) {
        //read the header data
        textfile2.read(&header.idLength, sizeof(header.idLength));
        textfile2.read(&header.colorMapType, sizeof(header.colorMapType));
        textfile2.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        textfile2.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        textfile2.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        textfile2.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        textfile2.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        textfile2.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        textfile2.read((char *) &header.width, sizeof(header.width));
        textfile2.read((char *) &header.height, sizeof(header.height));
        textfile2.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        textfile2.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            textfile2.read((char *) &textPixel2.blue, sizeof(textPixel2.blue));
            textfile2.read((char *) &textPixel2.green, sizeof(textPixel2.green));
            textfile2.read((char *) &textPixel2.red, sizeof(textPixel2.red));
            tempText2.push_back(textPixel2);
        }
        textfile2.close();
    }
    //rotate image
    for(int i = tempText2.size()-1; i>=0; i--){
        last.push_back(tempText2[i]);
    }
    ofstream tenthFile("output/part10.tga", ios_base::binary);
    if (tenthFile.is_open()) {
        tenthFile.write(&header.idLength, sizeof(header.idLength));
        tenthFile.write(&header.colorMapType, sizeof(header.colorMapType));
        tenthFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        tenthFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        tenthFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        tenthFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        tenthFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        tenthFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        tenthFile.write((char *) &header.width, sizeof(header.width));
        tenthFile.write((char *) &header.height, sizeof(header.height));
        tenthFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        tenthFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        for (int i = 0; i < header.width * header.height; i++) {
            tenthFile.write((char *) &last[i].blue, sizeof(last[i].blue));
            tenthFile.write((char *) &last[i].green, sizeof(last[i].green));
            tenthFile.write((char *) &last[i].red, sizeof(last[i].red));
        }
        tenthFile.close();
    }

    //extra credit
    ifstream carfile2("input/car.tga", ios_base::binary);
    if (carfile2.is_open()) {
        //read the header data
        carfile2.read(&header.idLength, sizeof(header.idLength));
        carfile2.read(&header.colorMapType, sizeof(header.colorMapType));
        carfile2.read(&header.dataTypeCode, sizeof(header.dataTypeCode));
        carfile2.read((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        carfile2.read((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        carfile2.read(&header.colorMapDepth, sizeof(header.colorMapDepth));
        carfile2.read((char *) &header.xOrigin, sizeof(header.xOrigin));
        carfile2.read((char *) &header.yOrigin, sizeof(header.yOrigin));
        carfile2.read((char *) &header.width, sizeof(header.width));
        carfile2.read((char *) &header.height, sizeof(header.height));
        carfile2.read(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        carfile2.read(&header.imageDescriptor, sizeof(header.imageDescriptor));
        //read the actual data
        for (int i = 0; i < header.width * header.height; i++) {
            carfile2.read((char *) &carPixel.blue, sizeof(carPixel.blue));
            carfile2.read((char *) &carPixel.green, sizeof(carPixel.green));
            carfile2.read((char *) &carPixel.red, sizeof(carPixel.red));
            car.push_back(carPixel);
        }
        carfile2.close();
    }
    header.width*=2;
    header.height*=2;
    ofstream extracreditFile("output/extracredit.tga", ios_base::binary);
    if (extracreditFile.is_open()) {
        extracreditFile.write(&header.idLength, sizeof(header.idLength));
        extracreditFile.write(&header.colorMapType, sizeof(header.colorMapType));
        extracreditFile.write(&header.dataTypeCode, sizeof(header.dataTypeCode));
        extracreditFile.write((char *) &header.colorMapOrigin, sizeof(header.colorMapOrigin));
        extracreditFile.write((char *) &header.colorMapLength, sizeof(header.colorMapLength));
        extracreditFile.write(&header.colorMapDepth, sizeof(header.colorMapDepth));
        extracreditFile.write((char *) &header.xOrigin, sizeof(header.xOrigin));
        extracreditFile.write((char *) &header.yOrigin, sizeof(header.yOrigin));
        extracreditFile.write((char *) &header.width, sizeof(header.width));
        extracreditFile.write((char *) &header.height, sizeof(header.height));
        extracreditFile.write(&header.bitsPerPixel, sizeof(header.bitsPerPixel));
        extracreditFile.write(&header.imageDescriptor, sizeof(header.imageDescriptor));
        int size = header.height*header.width;
        int a = 0;
        int b = 0;
        int c = 0;
        int d = 0;
        int size2 = 0;
        while(size2 != size/2){
            for(int i = 0; i<512; i++){
                extracreditFile.write((char*) &tempText[a].blue, sizeof(tempText[a].blue));
                extracreditFile.write((char*) &tempText[a].green, sizeof(tempText[a].green));
                extracreditFile.write((char*) &tempText[a].red, sizeof(tempText[a].red));
                size2++;
                a++;
            }
            for(int i = 0; i<512; i++){
                extracreditFile.write((char*) &tempPixel[d].blue, sizeof(tempPixel[d].blue));
                extracreditFile.write((char*) &tempPixel[d].green, sizeof(tempPixel[d].green));
                extracreditFile.write((char*) &tempPixel[d].red, sizeof(tempPixel[d].red));
                size2++;
                d++;
            }
        }
        while(size2 != size){
            for(int i = 0; i<512; i++){
                extracreditFile.write((char*) &car[c].blue, sizeof(car[c].blue));
                extracreditFile.write((char*) &car[c].green, sizeof(car[c].green));
                extracreditFile.write((char*) &car[c].red, sizeof(car[c].red));
                size2++;
                c++;
            }
            for(int i = 0; i<512; i++){
                extracreditFile.write((char*) &tempCircle[b].blue, sizeof(tempCircle[b].blue));
                extracreditFile.write((char*) &tempCircle[b].green, sizeof(tempCircle[b].green));
                extracreditFile.write((char*) &tempCircle[b].red, sizeof(tempCircle[b].red));
                size2++;
                b++;
            }
        }
        extracreditFile.close();
    }



}






