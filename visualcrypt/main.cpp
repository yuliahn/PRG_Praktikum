#ifdef QT_NO_DEBUG_OUTPUT
#undef QT_NO_DEBUG_OUTPUT
#endif

#include "visualcrypt.cpp"

int main(int argc, char *argv[]){

    if (string(argv[1]) == "encode"){
        //string source = string(argv[2]);
        vector <vector <int> > bild = genMatrix(rand()%10+1, rand()%10+1);
        printMat(bild, "Randomly generated matrix");
        //vector <vector <int> > bild = import(source); // an import function needed
        vector < vector<int> > result = genKey(bild.size(),bild[0].size());
        vector < vector<int> > key = encode(bild, result);
        printMat(key, "Generated key");
        // save the newly generated key

    } else if(string(argv[1]) == "decode"){
        vector <vector <int> > bild = genMatrix(rand()%10+1, rand()%10+1);
        printMat(bild, "Encrypted image");
        vector < vector<int> > result = genKey(bild.size(),bild[0].size());
        vector < vector<int> > key = encode(bild, result);
        printMat(key, "Generated key");
        vector <vector <int>> newBild = decode(result, key);
        printMat(newBild, "Decrypted image");

    } else if (string(argv[1]) == "overlay"){ //bug when one of the images is one dimensional
        vector <vector <int> > img1 = genMatrix(rand()%10+1, rand()%10+1);
        printMat(img1, "Image 1");
        vector <vector <int> > img2 = genMatrix(rand()%10+1, rand()%10+1);
        printMat(img2, "Image 2");
        vector <vector <int> > result = overlay(img1, img2);
        printMat(result, "Overlay image");

    } else {
        cout << "Wrong parameter" << endl;
    }


    /*
    cout << "Please, enter a number of rows: ";
    int x;
    cin >> x;
    cout << "Please, enter a number of columns: ";
    int y;
    cin >> y;

    // Initialize a random 2x2 bild array:
    vector <vector <int> > bild = genMatrix(x,y);
    printMat(bild, "Image"); // Print the image


    vector < vector<int> > schluessel = genKey(bild.size(),bild[0].size());
    printMat(schluessel, "Key");

    // Encrypt image (bild) using key (schluessel):
    vector <vector <int>> folie = encode(bild, schluessel);
    printMat(folie, "Encrypted image");

    // Decrypt image (bild) using key (schluessel) and slide (folie):
    vector <vector <int>> newBild = decode(folie, schluessel);
    printMat(newBild, "Decrypted image");

    // Initialize random images 1,2 (bild1, bild2):
    vector <vector <int>> bild1 = genMatrix(3,2);
    vector <vector <int>> bild2 = genMatrix(2,2);
    printMat(bild1, "Bild 1 to overlay");
    printMat(bild2, "Bild 2 to overlay");

    // Overlay images:
    vector <vector <int>> overlayImage = overlay(bild1,bild2);
    printMat(overlayImage, "Overlay image");

    */
    /*
    vector <vector <int>> encodedImage1 = encode(bild1,schluessel);
    vector <vector <int>> encodedImage2 = encode(bild2,schluessel);
    vector <vector <int>> resultingOverlay = overlay(encodedImage1, encodedImage2);
    vector <vector <int>> resultingOverlayImage = decode(resultingOverlay, schluessel);

    printMat(resultingOverlayImage, "Resulting overlay image");
    */



    return 0;
}
