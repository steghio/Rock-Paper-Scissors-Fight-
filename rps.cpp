#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <map>

using namespace std;

int main() {

  //possible moves    
  const int ROCK = 0;
  const int PAPER = 1;
  const int SCISSORS = 2;
  
  //winning pairs: winning move, losing move
  std::map<int, int> winPairs;
  winPairs.insert(std::make_pair(ROCK, SCISSORS));
  winPairs.insert(std::make_pair(PAPER, ROCK));
  winPairs.insert(std::make_pair(SCISSORS, PAPER));

  cout << "Rock! Paper! Scissors! Fight!" << endl;
  
  cout << "Insert victory limit, must be at least 1 and an odd number: " << endl;

  //only need to win or lose round / 2 + 1 times
  int round, wins, losses;
  
  //round input and validation
  std::string limit;
  
  while(true){
      std::getline(std::cin, limit);
      
      //whole string must be digits only
      if(!(limit.find_first_not_of("0123456789") == std::string::npos)){
          cout << "Round limit must be at least 1 and an odd number, got: '" << limit << "', please retry: " << endl;
          cin.clear();
          continue;
      }
      
      round = stoi(limit);
      
      if(round % 2 == 0){
          cout << "Round limit must be at least 1 and an odd number, got: '" << round << "', please retry: " << endl;
          cin.clear();
          continue;
      }
      
      break;
  }

  //calculate game ending number of wins and losses
  wins = ((int) (round / 2)) + 1;
  losses = wins;

  //user move input
  std::string move;
  
  //user and ai moves
  int user, ai;
  
  //fairly random generator, better than srand(time(NULL))
  std::random_device r;
  std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
  std::mt19937 eng(seed);
  //only 3 possible moves
  std::uniform_int_distribution<> dist{0,2};
  
  while(round > 0){
      
      //validate user move input
      while(true){
          cout << "Place your move: [R]ock, [P]aper, [S]scissors" << endl;
          std::getline(std::cin, move);
      
          //converts input string to lower case
          std::transform(move.begin(), move.end(), move.begin(), ::tolower);
          
          if(move != "r" 
            && move != "p" 
            && move != "s"){
              cout << "Invalid move entered, please retry. Valid moves are: [R]ock, [P]aper, [S]scissors, got: " << move << endl;
              continue;
          }
          
          break;
      }
    
      //convert user input in game move
      if(move == "r"){
          user = ROCK;
      } else if(move == "p"){
          user = PAPER;
      } else if(move == "s"){
          user = SCISSORS;
      } else {
          cout << "FATAL ERROR, move: " << move << endl;
          return -1;
      }
      
      //random ai move
      ai = dist(eng);
      
      switch(ai){
          case ROCK:
              cout << "AI played: Rock" << endl;
              break;
          case PAPER:
              cout << "AI played: Paper" << endl;
              break;
          case SCISSORS:
              cout << "AI played: Scissors" << endl;
              break;
          default:
              cout << "FATAL ERROR, AI: " << ai << endl;
              return -1;
      }
      
      //check round result
      if(ai == user){
          cout << "Round DRAW" << endl;
          continue;
      }
      
      //has user chosen the winning move for the round?
      if(winPairs.find(user) -> second == ai){
          cout << "Round WON" << endl;
          wins--;
      } else {
          cout << "Round LOST" << endl;
          losses--;
      }
      
      //when either is true, game ends no matter how many rounds are left
      if(wins == 0){
          cout << "WON" << endl;
          return 0;
      }
      if(losses == 0){
          cout << "LOST" << endl;
          return 0;
      }
      
      round--;
  }

  return 0;
}
        
