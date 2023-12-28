#include <iostream>

//int main() {
//    std::cout << "sada N Hello, World!" << std::endl;
//
//    return 0;
//}
// Base Game class
class Game {
public:
    // Constructor
    Game(std::string gameName);

    // Destructor
    virtual ~Game();

    // Accessor and Mutator Methods
    std::string getGameName() const;
    void setGameName(std::string name);

    // Virtual methods to be overridden by derived classes
    virtual void start() = 0;
    virtual void end() = 0;
    virtual void rules() const = 0;

    // Other common methods

protected:
    std::string gameName;
};

// Player class
class Player {
public:
    Player(std::string username, std::string gameName);
    std::string getUsername() const;
    std::string getGameName() const;
    int getScore() const;
    void updateScore(int points);

private:
    std::string username;
    std::string gameName;
    int score;
};

// SynonymGame class derived from Game
class SynonymGame : public Game {
public:
    SynonymGame();
    void start() override;
    void end() override;
    void rules() const override;

private:
    // Add specific data members and methods for the SynonymGame
};

// GuessMovieGame class derived from Game
class GuessMovieGame : public Game {
public:
    GuessMovieGame();
    void start() override;
    void end() override;
    void rules() const override;

private:
    // Add specific data members and methods for the GuessMovieGame
};

// YourGame class derived from Game
class YourGame : public Game {
public:
    YourGame();
    void start() override;
    void end() override;
    void rules() const override;

private:
    // Add specific data members and methods for YourGame
};

// Main function
int main() {
    // Implement the main menu and game loop here
    // Use polymorphism to create instances of different game types
    // Allow the player to choose a game, view rules, set difficulty, and play
    // After each game, display the player's score and return to the main menu
    printf("Hello World!\n");

    return 0;
}