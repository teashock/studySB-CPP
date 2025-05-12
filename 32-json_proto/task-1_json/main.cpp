#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <nlohmann/json.hpp>

struct Actor {
    std::string character_name;
    std::string actor_name;
};

struct Movie {
    std::string title;
    std::string release_date;
    std::string country;
    std::vector<std::string> production_companies;
    std::string director;
    std::vector<std::string> writer;
    std::vector<std::string> producer;
    std::vector<Actor> main_characters;
};

int main() {
    Movie movie;

    movie.title = "Interstellar";
    movie.release_date = "2014-11-07";
    movie.country = "USA";
    movie.production_companies = {"Warner Bros.", "Paramount Pictures", "Legendary Entertainment"};
    movie.director = "Christopher Nolan";
    movie.writer = {"Jonathan Nolan", "Christopher Nolan"};
    movie.producer = {"Emma Thomas", "Christopher Nolan", "Lynda Obst"};
    movie.main_characters.push_back({"Cooper", "Matthew McConaughey"});
    movie.main_characters.push_back({"Brand", "Anne Hathaway"});
    movie.main_characters.push_back({"Murph", "Jessica Chastain"});
    movie.main_characters.push_back({"Professor Brand", "Michael Caine"});
    movie.main_characters.push_back({"TARS(voice)", "Bill Irwin"});

    nlohmann::json movieinfo = {
        {"title", movie.title},
        {"release date", movie.release_date},
        {"county", movie.country},
        {"production companies", movie.production_companies},
        {"director", movie.director},
        {"writer", movie.writer},
        {"producer", movie.producer}
    };

    nlohmann::json actors_info = nlohmann::json::array();
    for (auto it = movie.main_characters.begin(); it != movie.main_characters.end(); ++it) {
        nlohmann::json actor_info = {
            {"character name", it->character_name},
            {"actor name", it->actor_name}
        };
        actors_info.push_back(actor_info);
    }

    movieinfo["main characters"] = actors_info;

    std::ofstream file("movie.json");
    if (file.is_open()) {
        file << movieinfo.dump(4);
        file.close();
        std::cout << "Successfully created movie file!" << std::endl;
    } else {
        std::cout << "Failed to create movie file!" << std::endl;
    }
    return 0;
}