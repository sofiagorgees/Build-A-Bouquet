//
// Created by Sofia Gorgees on 2/20/25.
//
#include <ctime>
#include "Bouquet.h"
#include <fstream>
#include <sstream>


Bouquet::Bouquet() : numFlowers(0), container("Vase") {}
int Bouquet::getNumFlowers() const{
    return numFlowers;
}
string Bouquet::getContainer() const{
    return container;
}

vector<Tulip>& Bouquet::getFlowerList() {
    return flowers;
}

void Bouquet::setContainer(string c) {
    container = c;
}

void Bouquet::addToBouquet(Tulip& t) {
    flowers.push_back(t);
    numFlowers++;
}
void Bouquet::removeFromBouquet(int num) {
    flowers.erase(flowers.end()-num, flowers.end());
    numFlowers -= num;
}

Tulip Bouquet::pickFromGarden() {
    // vectors that hold the colors and petal shapes
    vector<string> colors = {"red", "orange", "pink", "yellow", "purple", "white"};
    vector<string> shapes = {"cup", "star", "pointed"};

    // picks a random element from the color and shape vector, picks a random height between
    // 10 and 18 in and sets cut to false
    string randomColor = colors[rand() % colors.size()];
    string randomShape = shapes[rand() % shapes.size()];

    // makes sure the height is between 10 and 18 inches
    int randomHeight = rand() % 9 + 10;
    int petalNum = rand() % 10 + 3;

    // return picked tulip
    Tulip t = Tulip(petalNum, randomColor, randomShape, randomHeight, false);
    flowers.push_back(t);
    numFlowers++;
    return t;
}

Tulip Bouquet::chooseFromStore() {
    vector<Tulip> storeFlowers;
    ifstream file("../inventory.csv");

    if (!file) {
        cout << "Error: Could not open inventory.csv" << endl;
        return Tulip();
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string petalCountStr, color, shape, heightStr, isCutStr;

        getline(ss, petalCountStr, ',');
        getline(ss, color, ',');
        getline(ss, shape, ',');
        getline(ss, heightStr, ',');
        getline(ss, isCutStr, ',');

        int petalCount = stoi(petalCountStr);
        int height = stoi(heightStr);
        bool isCut = (isCutStr == "1");

        storeFlowers.push_back(Tulip(petalCount, color, shape, height, isCut));
    }
    file.close();

    // display inventory
    for (int i = 0; i < storeFlowers.size(); i++) {
        cout << i + 1 << ". Color: " << storeFlowers[i].getColor()
             << " | Shape: " << storeFlowers[i].getShape()
             << " | Height: " << storeFlowers[i].getHeight() << " inches"
             << " | Is the stem cut? " << (storeFlowers[i].isCut() ? "Yes" : "No")
             << endl;
    }

    int choice;
    cout << "Which tulip would you like? Enter a number: ";
    while (!(cin >> choice)) {
        cout << "Please enter a valid flower choice: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (choice < 1 || choice > storeFlowers.size()) {
        cout << "Invalid choice. Picking a random tulip instead." << endl;
        int ranFlowerChoice = rand() % storeFlowers.size();
        flowers.push_back(storeFlowers[ranFlowerChoice]);
        return storeFlowers[rand() % storeFlowers.size()];
    }
    flowers.push_back(storeFlowers[choice-1]);
    numFlowers++;
    return storeFlowers[choice - 1];
}