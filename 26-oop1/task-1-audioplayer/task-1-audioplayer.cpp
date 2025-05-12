#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>

class Track {
    std::string name;
    std::tm creationDate;
    int duration;

  public:

    void setName(std::string name) {
        Track::name = name;
    }

    void setCreationDate(int year, int month, int day) {
        creationDate.tm_year = year - 1900;
        creationDate.tm_mon = month - 1;
        creationDate.tm_mday = day;
    }

    void setDuration(int duration) {
        Track::duration = duration;
    }

    std::string getName() {
        return name;
    }

    std::tm& getCreationDate() {
        return creationDate;
    }

    int getDuration() {
        return duration;
    }
};

class Audioplayer {
    std::vector<Track> tracks{};
    bool musicIsPlaying = false;
    bool musicIsPaused = false;
    int currentTrackIndex = -1;

  public:

    void addTrack(Track track) {
        tracks.push_back(track);
    }

    void play() {
        if (musicIsPaused) {
            musicIsPaused = false;
            musicIsPlaying = true;
            std::cout << "Resuming: " << tracks[currentTrackIndex].getName() << "\nDuration: " << tracks[currentTrackIndex].getDuration() << " seconds;\n" << "Creation date: " << std::put_time(&tracks[currentTrackIndex].getCreationDate(), "%Y/%m/%d") << ";\n"; 
        } else if (!musicIsPlaying) {
            std::string name;
            std::cout << "Input track name: ";
            std::getline(std::cin, name);
            for (int i = 0; i < tracks.size(); ++i) {
                if (tracks[i].getName() == name) {
                    currentTrackIndex = i;
                    musicIsPlaying = true;
                    std::cout << "Playing: " << tracks[i].getName() << "\nDuration: " << tracks[i].getDuration() << " seconds;\n" << "Creation date: " << std::put_time(&tracks[i].getCreationDate(), "%Y/%m/%d") << ";\n";
                    return;
                }
            }
            std::cout << "Track not found.\n";
        } else {
            std::cout << "The music is already playing!\n";
        }   
    }

    void pause() {
        if (musicIsPlaying && !musicIsPaused) {
            musicIsPaused = true;
            musicIsPlaying = false;
            std::cout << "Track is paused!\n"; 
        } else {
            std::cout << "The music is not playing!\n";
        }
    }

    void next() {
        if (tracks.empty()) {
            std::cout << "No tracks available!\n";
            return;
        }

        if (musicIsPlaying) {
            int nextIndex;
            do {
                nextIndex = std::rand() % tracks.size();
            } while (nextIndex == currentTrackIndex);
            currentTrackIndex = nextIndex;
            std::cout << "Playing next track: " << tracks[currentTrackIndex].getName() << "\nDuration: " << tracks[currentTrackIndex].getDuration() << " seconds;\n" << "Creation date: " << std::put_time(&tracks[currentTrackIndex].getCreationDate(), "%Y/%m/%d") << ";\n";  
        } else {
            std::cout << "The music is not playing!\n";
        }
    }

    void stop() {
        if (musicIsPlaying) {
            std::cout << "Stopped playing!\n";
            musicIsPlaying = false;
            musicIsPaused = false;
            currentTrackIndex = -1;
        } else if (!musicIsPlaying) {
            std::cout << "Music is not playing!\n";
        }
    }

    void command(){
        std::string command;
        while (true) {
            std::cout << "Enter command (play, pause, next, stop, exit): ";
            std::getline(std::cin, command);
            if (command == "play") {
                play();
            } else if (command == "pause") {
                pause();
            } else if (command == "next") {
                next();
            } else if (command == "stop") {
                stop();
            } else if (command == "exit") {
                break;
            } else {
                std::cout << "Command is not found!\n";
            }
        }
    }
};

int main() {
    std::srand(std::time(nullptr));
    Audioplayer player;
    
    Track track1;
    track1.setName("Track 1");
    track1.setCreationDate(2004, 12, 25);
    track1.setDuration(254);
    player.addTrack(track1);
    
    Track track2;
    track2.setName("Track 2");
    track2.setCreationDate(2010, 4, 1);
    track2.setDuration(183);
    player.addTrack(track2);

    Track track3;
    track3.setName("Track 3");
    track3.setCreationDate(2020, 8, 15);
    track3.setDuration(232);
    player.addTrack(track3);

    player.command();
    
}