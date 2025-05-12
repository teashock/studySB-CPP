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

void createJsonFile(const std::string& filename) {
    nlohmann::json movies;

    movies["Interstellar"] = {
        {"release date", "2014-11-07"},
        {"country", "USA"},
        {"production companies", {"Warner Bros.", "Paramount Pictures", "Legendary Entertainment"}},
        {"director", "Christopher Nolan"},
        {"writer", {"Jonathan Nolan", "Christopher Nolan"}},
        {"producer", {"Emma Thomas", "Christopher Nolan", "Lynda Obst"}},
        {"main characters", {
            {{"character name", "Cooper"}, {"actor name", "Matthew McConaughey"}},
            {{"character name", "Brand"}, {"actor name", "Anne Hathaway"}},
            {{"character name", "Murph"}, {"actor name", "Jessica Chastain"}},
            {{"character name", "Professor Brand"}, {"actor name", "Michael Caine"}},
            {{"character name", "TARS(voice)"}, {"actor name", "Bill Irwin"}}
        }}
    };

    movies["The Lord of the Rings: The Return of the King"] = {
        {"release date", "2003-12-17"},
        {"country", "New Zealand/USA"},
        {"production companies", {"New Line Cinema", "WingNut Films"}},
        {"director", "Peter Jackson"},
        {"writer", {"Fran Walsh", "Philippa Boyens", "Peter Jackson"}},
        {"producer", {"Peter Jackson", "Fran Walsh", "Barrie M. Osborne"}},
        {"main characters", {
            {{"character name", "Frodo Baggins"}, {"actor name", "Elijah Wood"}},
            {{"character name", "Samwise Gamgee"}, {"actor name", "Sean Astin"}},
            {{"character name", "Gandalf"}, {"actor name", "Ian McKellen"}},
            {{"character name", "Aragorn"}, {"actor name", "Viggo Mortensen"}},
            {{"character name", "Legolas"}, {"actor name", "Orlando Bloom"}}
        }}
    };

    movies["The Shawshank Redemption"] = {
        {"release date", "1994-09-23"},
        {"country", "USA"},
        {"production companies", {"Castle Rock Entertainment"}},
        {"director", "Frank Darabont"},
        {"writer", {"Stephen King", "Frank Darabont"}},
        {"producer", {"Frank Darabont", "Niki Marvin"}},
        {"main characters", {
            {{"character name", "Andy Dufresne"}, {"actor name", "Tim Robbins"}},
            {{"character name", "Ellis 'Red' Redding"}, {"actor name", "Morgan Freeman"}},
            {{"character name", "Warden Norton"}, {"actor name", "Bob Gunton"}},
            {{"character name", "Captain Hadley"}, {"actor name", "Clancy Brown"}},
            {{"character name", "Brooks Hatlen"}, {"actor name", "James Whitmore"}}
        }}
    };

    movies["Inception"] = {
        {"release date", "2010-07-16"},
        {"country", "USA"},
        {"production companies", {"Warner Bros.", "Legendary Pictures"}},
        {"director", "Christopher Nolan"},
        {"writer", {"Christopher Nolan"}},
        {"producer", {"Emma Thomas", "Christopher Nolan"}},
        {"main characters", {
            {{"character name", "Dom Cobb"}, {"actor name", "Leonardo DiCaprio"}},
            {{"character name", "Arthur"}, {"actor name", "Joseph Gordon-Levitt"}},
            {{"character name", "Ariadne"}, {"actor name", "Elliot Page"}},
            {{"character name", "Mal"}, {"actor name", "Marion Cotillard"}},
            {{"character name", "Eames"}, {"actor name", "Tom Hardy"}}
        }}
    };

    movies["Avengers: Endgame"] = {
        {"release date", "2019-04-26"},
        {"country", "USA"},
        {"production companies", {"Marvel Studios", "Walt Disney Studios"}},
        {"director", {"Anthony Russo", "Joe Russo"}},
        {"writer", {"Christopher Markus", "Stephen McFeely"}},
        {"producer", {"Kevin Feige"}},
        {"main characters", {
            {{"character name", "Tony Stark/Iron Man"}, {"actor name", "Robert Downey Jr."}},
            {{"character name", "Steve Rogers/Captain America"}, {"actor name", "Chris Evans"}},
            {{"character name", "Natasha Romanoff/Black Widow"}, {"actor name", "Scarlett Johansson"}},
            {{"character name", "Thor"}, {"actor name", "Chris Hemsworth"}},
            {{"character name", "Bruce Banner/Hulk"}, {"actor name", "Mark Ruffalo"}}
        }}
    };

    std::ofstream file(filename);
    if (file.is_open()) {
        file << movies.dump(4);
        file.close();
        std::cout << "Successfully created movies json file!" << std::endl;
    } else {
        std::cout << "Failed to create movies json file!" << std::endl;
    }
}

void printMovieInfo(const nlohmann::json& movie) {
    std::cout << "Release Date: " << movie["release date"] << std::endl;
    std::cout << "Country: " << movie["country"] << std::endl;
    std::cout << "Production Companies: ";
    for (auto& company : movie["production companies"]) {
        std::cout << company << " ";
    }
    std::cout << std::endl;
    std::cout << "Director: " << movie["director"] << std::endl;
    std::cout << "Writers: ";
    for (auto& writer : movie["writer"]) {
        std::cout << writer << " ";
    }
    std::cout << std::endl;
    std::cout << "Producers: ";
    for (auto& producer : movie["producer"]) {
        std::cout << producer << " ";
    }
    std::cout << std::endl;
    std::cout << "Main Characters: " << std::endl;
    for (auto actor : movie["main characters"]) {
        std::cout << "  - Character: " << actor["character name"] << ", Actor: " << actor["actor name"] << std::endl;
    }
    std::cout << std::endl;
}


int main() {
    const std::string file = "movies.json";
    createJsonFile(file);

    std::ifstream file_in(file);
    nlohmann::json movies_data;
    if(!file_in.is_open()) {
        std::cout << "Failed to open file!" << std::endl;
    }
    file_in >> movies_data;
    file_in.close();

    std::string actor_name;
    std::cout << "Enter actor name: ";
    std::getline(std::cin, actor_name);

    bool found_actor = false;

    for (auto [title, movie] : movies_data.items()) {
        for (auto actor : movie["main characters"]) {
            if (actor["actor name"] == actor_name) {
                std::cout << "Found actor in movie: " << title << std::endl;
                printMovieInfo(movie);
                found_actor = true;
            }
        }
    }

    if (!found_actor) {
        std::cout << "No movies found for actor: " << actor_name << std::endl;
    }

    return 0;
}