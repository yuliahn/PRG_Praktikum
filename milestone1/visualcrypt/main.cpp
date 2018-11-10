#ifdef QT_NO_DEBUG_OUTPUT
#undef QT_NO_DEBUG_OUTPUT
#endif

#include "visualcrypt.cpp"

int main(int argc, char *argv[]){

    string save_dir = "C:\\Users\\Yulia\\Documents\\Informatik\\WS18-19\\PRG_Praktikum\\milestone1\\sources\\";
    string targetDir = save_dir;
    string fileName;

    if (string(argv[1]) == "encode"){

        string source = string(argv[2]); // set the source name to import the image to encrypt
        NBild image; // create a new instance of NBild
        image.importData(source); // import the contents
        cout << '\n' << "Image to encrypt:" << endl;
        image.print();

        //CBild result(1,2);
        CBild result(image.getRows(), image.getCols()); // generate a random key1 using sizes of the imported image
        fileName = "result.txt";
        result.exportData(targetDir.append(fileName)); // save the random key1 (encrypted image)
        targetDir = save_dir;
        cout << '\n' << "Encrypted image:" << endl;
        result.print();

        CBild key(encode(image.getMatrix(), result.getMatrix())); // generate a new key2 (key) by encoding image with key1 (result)
        cout << '\n' << "Generated key:" << endl;
        key.print();
        fileName = "key.txt";
        result.exportData(targetDir.append(fileName));
        targetDir = save_dir;

    } else if(string(argv[1]) == "decode"){

        string source_result = string(argv[2]);
        string source_key = string(argv[3]);
        CBild result;
        result.importData(source_result); //import result
        cout << '\n' << "Encrypted image:" << endl;
        result.print();

        CBild key;
        key.importData(source_key); //import key
        cout << '\n' << "Generated key:" << endl;
        key.print();

        NBild image(decode(result.getMatrix(), key.getMatrix()));
        cout << '\n' << "Decrypted image:" << endl;
        image.print();

    } else if (string(argv[1]) == "overlay"){ //bug when one of the images is one dimensional

        string source_image_1 = string(argv[2]);
        string source_image_2 = string(argv[3]);
        NBild image_1;
        image_1.importData(source_image_1);
        cout << '\n' << "Image 1:" << endl;
        image_1.print();

        NBild image_2;
        image_2.importData(source_image_2);
        cout << '\n' << "Image_2:" << endl;
        image_2.print();

        NBild result(overlay(image_1.getMatrix(), image_2.getMatrix()));
        cout << '\n' << "Overlay image:" << endl;
        result.print();
        fileName = "overlay.txt";
        result.exportData(targetDir.append(fileName));
        targetDir = save_dir;

    } else if (string(argv[1]) == "2f") {

        cout << "\nAufgabe 2f:" << endl;
        NBild fimage_1(genMatrix(10,10));
        cout << "First random 10x10 image:" << endl;
        fimage_1.print();
        NBild fimage_2(genMatrix(10,10));
        cout << "Second random 10x10 image:" << endl;
        fimage_2.print();
        CBild key_1(fimage_1.getRows(),fimage_1.getCols());

        CBild result_1(encode(fimage_1.getMatrix(),key_1.getMatrix()));
        fileName = "A2f.image1.txt";
        result_1.exportData(targetDir.append(fileName));
        targetDir = save_dir;

        CBild result_2(encode(fimage_2.getMatrix(),key_1.getMatrix()));
        fileName = "A2f.image2.txt";
        result_2.exportData(targetDir.append(fileName));
        targetDir = save_dir;

        NBild foverlay(overlay(result_1.getMatrix(),result_2.getMatrix()));
        fileName = "A2f.overlay.txt";
        foverlay.exportData(targetDir.append(fileName));
        targetDir = save_dir;
        cout << "Overlay of two images encrypted with the same key:" << endl;
        foverlay.print();

    } else {
        cout << "Wrong parameter" << endl;
    }

    return 0;
}
