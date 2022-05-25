#include "Game.h"
#include "Material.h"
#include "Diver.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

const string a = "proj2_data.txt"; 

  /* Name: Game() Default Constructor
  // Desc - Builds a new game by: 
  // 1. Loads all materials and their recipes into m_materials
  // 2. Asks user for their diver's name (store in m_myDiver as m_myName)
  // 3. Copies all materials from m_materials into the diver's material array
  // Preconditions - None
  // Postconditions - m_materials is populated
  */ 

  // Constructor
  Game::Game(){
    Diver m_myDiver; 
    Material m_materials[PROJ2_SIZE];
  } 

  // Name: LoadMaterials
  // Desc - Loads each material into m_materials from file
  // Preconditions - Requires file with valid material data
  // Postconditions - m_material is populated with material structs
  void Game::LoadMaterials(){
    
    ifstream inData;
    inData.open("proj2_data.txt");
    if(inData.fail())
    {
        cout << "Error opening file." << endl;
    }
    int index;
    string menu;
    double price;
    for(index=0; index < 50; index++)
    {
        getline(inData, m_materials[index].m_name, ',');
        getline(inData, m_materials[index].m_type, ',');
        getline(inData, m_materials[index].m_material1, ',');
        getline(inData, m_materials[index].m_material2, ',');
        getline(inData, m_materials[index].temp_depth, '\n');
    }
    inData.close();

      for (int j = 0; j < 50; j++){
        cout << m_materials[j].m_name << " ";
        cout << m_materials[j].m_type << " ";
        cout << m_materials[j].m_material1 << " ";
        cout << m_materials[j].m_material2 << " ";
        cout << (m_materials[j].temp_depth) << " ";
        cout << endl;
      }
  }

  // Name: StartGame()
  // Desc - Manages the game itself including win conditions continually
  //         calling the main menu 
  // Preconditions - Player is placed in game
  // Postconditions - Continually checks to see if player has entered 5
  void Game::StartGame(){
    string playerName; 
    //LoadMaterials();
    cout << "What is the name of your Diver? " << endl;
    cin >> playerName; 
    m_myDiver.SetName(playerName); 
    cout << m_myDiver.GetName(); 
    //GameTitle();
    SearchMaterials();
    m_myDiver.DisplayMaterials();
  }

  // Name: DisplayMyMaterials()
  // Desc - Displays the diver's materials
  // Preconditions - Player's diver has materials
  // Postconditions - Displays a numbered list of materials
  void Game::DisplayMaterials(){
    m_myDiver.DisplayMaterials();
  }

    // Name: MainMenu()
  // Desc - Displays and manages menu. Also checks win condition (diver reaches 1000 meters).
  // Preconditions - Player has an Diver
  // Postconditions - Returns number including exit
  int Game::MainMenu(){
    string input;
    while(m_myDiver.CalcDepth() <= 1000 ){
      cout << 'j';
    }
  return 0;
  }

    // Name: SearchMaterials()
  // Desc - Attempts to search for raw materials (must be type "raw")
  // Preconditions - Raw materials loaded
  // Postconditions - Increases quantity in Diver's posession of materials
  string astr; 
  void Game::SearchMaterials(){
  int randomNumber;
  randomNumber = (rand() % 16) + 0 ;
  Material tempMaterial = m_myDiver.GetMaterial(randomNumber);
  astr = m_myDiver.ShowMaterial(randomNumber);
  cout << "You have gained " << astr << endl; 
  cout << randomNumber << endl;

  }

    // Name: CombineMaterials()
  // Desc - Attempts to combine known materials. If combined, quantity of material decreased
  // Preconditions - Diver is populated with materials
  // Postconditions - Increments quantity of item "made", decreases quantity of source items
  void Game::CombineMaterials(){

  }

  // Name: RequestMaterial()
  // Desc - Requests material to use to merge
  // Preconditions - Diver has materials to try and merge
  // Postconditions - Returns integer of item selected by user
  void Game::RequestMaterial(int &choice){

  }

  // Name: SearchRecipes()
  // Desc - Searches recipes for two strings (name of item)
  // Preconditions - m_materials is populated
  // Postconditions - Returns int index of matching recipe
  int Game::SearchRecipes(string, string){

  }

   // Name: CalcScore()
  // Desc - Displays current score for Diver
  // Preconditions - Diver is populated with materials
  // Postconditions - Displays total
  void Game::CalcScore(){

  }
  // Name: GameTitle()
  // Desc - Title for Game (Do not edit)
  // Preconditions - None
  // Postconditions - None
  void GameTitle(){
    cout << "*****************************************************************" << endl;
    cout << " SSSS  U   U  BBBB   N    N   AAA   U   U  TTTTT  II  CCCC   AAA " << endl;
    cout << " S     U   U  B   B  NN   N  A   A  U   U    T    II  C     A   A" << endl;
    cout << " S     U   U  B   B  N N  N  A   A  U   U    T    II  C     A   A" << endl;
    cout << " SSSS  U   U  BBBB   N  N N  AAAAA  U   U    T    II  C     AAAAA" << endl;
    cout << "    S  U   U  B   B  N  N N  A   A  U   U    T    II  C     A   A" << endl;
    cout << "    S  U   U  B   B  N   NN  A   A  U   U    T    II  C     A   A" << endl;
    cout << " SSSS  UUUUU  BBBB   N    N  A   A  UUUUU    T    II  CCCC  A   A" << endl;
    cout << "*****************************************************************" << endl;
  }
  