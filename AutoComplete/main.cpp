
#include "Suggest.h"
#include <iostream>
#include <string>
#include<bits/stdc++.h>

#define CHAR_TO_value(c) ((int)c - (int)'a')
using namespace std;

int main(){

  TrieNode T = TrieNode();
  TrieNode* root = T.getNode();
  T.ReadFile(root,"words.txt");
  string word;
  string option;

  while(option != "2")
  {
    cout << "======Main Menu======" << endl;
    cout << "1. Complete the word/ find words that start with..." << endl;
    //cout << "2. Print most recent words/history" << endl;
    cout << "2. Quit" << endl;
    cin>>option;
    if(option != "1" && option != "2" && option != "-1")
    {
      cout << "Please input a Valid choice!" << endl;
    }
    if(option == "1")
    {
      cout << "Enter the beginning of word or part of word:" << endl;
      getline(cin, word);
      getline(cin, word);
      T.printAutoSuggestions(root,word);

      if(T.wordC == 0)
      {
        cout << "No words with this part" << endl;
      }

      T.counter = 1;
      T.wordC = 0;
      option = -1;
    }
    if(option == "2")
    {
      break;
    }
    else{

    }
  }
  cout << "Goodbye!" << endl;
  return 0;
}
