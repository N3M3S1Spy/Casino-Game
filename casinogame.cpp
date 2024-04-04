#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <thread>
#include <chrono>

int randomNumberGen(int startNum, int endNum) {
    std::mt19937 rng(std::random_device{}());

    std::uniform_int_distribution<int> distribution(startNum, endNum);

    int randomNumber = distribution(rng);

    
    return randomNumber;
}

void sleepProgram(int secount) {
    std::this_thread::sleep_for(std::chrono::seconds(secount));
}



class Casino {
    public:
        int money;
        bool alreadyPlayed;
        Casino() {
            alreadyPlayed = false;
            money = 0;
        }
};

Casino PlayerStats;

int gameFunction() {        
    if (PlayerStats.alreadyPlayed == false) {
        std::cout << "Dealer: Willkommen, sie starten mit 1000 Doller\n";
        sleepProgram(1);
        PlayerStats.money = 1000;
        PlayerStats.alreadyPlayed = true;
        std::cout << "System: Ihr Guthaben beträgt jetzt: " << PlayerStats.money << std::endl;
        sleepProgram(1);
    }

    std::cout << "Dealer: Bitte Wählen sie eine Zahl zwischen 1 bis 10\n";
    std::cout << "Du: ";
    int gewählteZahl;
    std::cin >> gewählteZahl;
    sleepProgram(1);
    std::cout << "Es wird gewürfelt\n";
    sleepProgram(3);
    if (gewählteZahl == randomNumberGen(1, 10)) {
        std::cout << "Dealer: \\\\\\\\\\JACKPOT///////// Ihr Gewinn ist das doppelte ihres einsatzes";
    } else {
        std::cout << "Dealer: Schade probieren sie es doch noch ein mal";
    }
    sleepProgram(1);
    std::cout << "Dealer: Möchten sie weiter spielen?\n";
    sleepProgram(1);
    std::cout << "Wähle ja oder nein: ";
    std::string wahl;
    std::cin >> wahl;
    sleepProgram(1);
    if (wahl == "ja") {
        std::cout << "Dealer: Es freut mich weiter mit ihnen spielen zu dürfen\n";
        gameFunction();
    } else {
        std::cout << "Dealer: Schade das sie uns schon verlassen wollen\n";
    }

    return 0;
}

int main() {
    std::cout << "Javis: Willkommen im Casino Mr.X\n";
    sleepProgram(1);
    std::cout << "Javis: Möchten sie etwas zu trinken haben?\n";
    sleepProgram(1);
    std::cout << "Wähle ja oder nein: ";
    std::string antwort;
    
    std::cin >> antwort;

    if (antwort == "ja") {
        sleepProgram(1);
        std::cout << "Javis: Kommt sofort, bitte setzen sie sich schon mal an einen Tisch ihrer wahl\n";
    } else if (antwort == "nein") {
        sleepProgram(1);

        std::cout << "Javis: Ich verstehe, bitte setzen sie sich doch an einen Tisch\n";
    } else {
        sleepProgram(1);
        std::cout << "Javis: Ich habe verstanden, bitte setzen sie sich doch an einen Tisch\n";
    }
    sleepProgram(1);
    std::cout << "Du setzt dich an einen Tisch, den du nach kurzen umschauen ausgewählt hast\n";
    sleepProgram(1);

    gameFunction();


    return 0;
}
