#include "WordCloud.hpp"
using namespace std;
  WordCloud::WordCloud(){

  }
  // Name: WordCloud (Overloaded Constructor) - Passed filename for input
  // Desc: Used to pass an essay (in input file) and generates word list and frequency
  //       Dynamically allocates m_cloud
  // Preconditions: Input file has correctly formatted input
  // Postconditions: Returns list of items and their frequency (stored in LL)
  WordCloud::WordCloud(string fileName){
      m_fileName = fileName;
  }
  // Name: ~WordCloud (Destructor)
  // Desc: Deallocates m_cloud
  // Preconditions: m_cloud has been dynamically allocated
  // Postconditions: m_cloud is empty
  WordCloud::~WordCloud(){

  }
  // Name: LoadFile()
  // Desc: Loads a file (everything as a string although could be anything stringlike)
  //       Each input file is an unknown length
  // Preconditions: m_fileName is populated with good data
  // Postconditions: m_cloud is populated
  void WordCloud::LoadFile(){
      ifstream inData;
      inData.open(m_fileName);
      string word;
      if(inData.fail())
      cout << "Error opening file." << endl;
      else{
          while(!inData.eof()){
              getline(inData, word, ' ');
              RemovePunct(word);
              m_cloud->Insert(word);
      }
      
  }
  }
  // Name: RemovePunct (passed a string
  // Desc: When passed a string, removes all non letter punctation on the beginning
  //       or end of the string.
  //       These are all ok: "don't" "inner-circle" but "candy," is bad
  //       Is called during LoadFile
  // Preconditions: Strings to be evaluated
  // Postconditions: Punctuation is removed from string
  void WordCloud::RemovePunct(string& remove){
      if(ispunct(remove[0])){
          remove.erase(remove.begin());
      }
      if(ispunct(remove[remove.size()-1])){
          remove.erase((remove.size())-1);
      }
  }

  // Name: RemoveCommon
  // Desc: Iterates through m_cloud and removes all common words after they are read
  // Preconditions: m_cloud is populated and EXCLUDE_LIST is populated
  // Postconditions: m_cloud will have no words from EXCLUDE_LIST
  void WordCloud::RemoveCommon(){
      for(const auto& text : EXCLUDE_LIST){
          m_cloud->RemoveAt(text);
      }
  }
  // Name: RemoveSingles
  // Desc: Asks the user if they would like to remove words with a frequency of 1
  //       Should use the overloaded [] NOTE: Don't forget m_cloud is a pointer!
  // Preconditions: m_cloud is populated
  // Postconditions: m_cloud will have no words with a frequency of 1
  void WordCloud::RemoveSingles(){
      string answer;
      cout << "Would you like to remove all words with a frequency of 1? (yes or no)" << endl;
      cin >> answer;
      if (answer == "yes"){
        cout << &m_cloud[1];
      }
      else if (answer == "no"){
        return;
      }
      else{
        cout << "Invalid input" << endl;
        RemoveSingles();
      }

  }
  // Name: Export
  // Desc: Iterates through m_cloud and exports to file "data:frequency"
  // Preconditions: m_cloud is populated
  // Postconditions: New export file is created with "data:frequency" one on each line
  void WordCloud::Export(){

  }
  // Name: Start
  // Desc: Calls LoadFile, RemoveCommon, Diplay, and Export
  // Preconditions: None (filename is available)
  // Postconditions: None
  void WordCloud::Start(){
      LoadFile();
      RemoveCommon();
      RemoveSingles();
      m_cloud->Display();
      //Export();
  }
