#include <iostream>
#include <string>
#include <fstream>
#include<bits/stdc++.h>
#define CHAR_TO_value(c) ((int)c - (int)'a')
using namespace std;

class TrieNode{

    private:

    TrieNode *children[26];
    string word;
    bool isWordEnd;

    public:

      int counter = 1;
      int wordC = 0;

    TrieNode(){
    for(int i = 0; i < 26; i++)
    {
        children[i] = NULL;
    }

    isWordEnd = false;
    }

    void insert(TrieNode *root, string word){
    TrieNode *temp = root;

    for (int height = 0; height < word.length(); height++)
    {
        int value = CHAR_TO_value(word[height]);
        if (!temp->children[value])
        {
           temp->children[value] = getNode();
        }

        temp = temp->children[value];
    }


        temp->isWordEnd = true;

    }

    TrieNode *getNode(){
    TrieNode *pNode = new TrieNode;
    pNode->isWordEnd = false;

    for(int i = 0; i < 26; i++)
    {
        pNode->children[i] = NULL;
    }

    return pNode;
    }

    bool search(TrieNode *root, string word){
    int length = word.length();
    TrieNode *temp = root;
    for (int height = 0; height < length; height++)
    {
        int value = CHAR_TO_value(word[height]);
        if (!temp->children[value])
        {
        return false;
        }

    temp = temp->children[value];
    }

    return (temp != NULL && temp->isWordEnd);

    }

    bool isLastNode(TrieNode* root){
        for (int i = 0; i < 26; i++)
        if (root->children[i])
            return 0;
        return 1;
    }

    void suggestionsRec(TrieNode* root, string wordPart){

    if (root->isWordEnd)
    {
      wordC++;
      cout << counter <<". " << wordPart << endl;
      counter++;
    }

    if (isLastNode(root))
    {
        return;
    }

    for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
            wordPart.push_back('a' + i);
            suggestionsRec(root->children[i], wordPart);
            wordPart.pop_back();
            }
        }
    }



    int printAutoSuggestions(TrieNode* root, string query){
    TrieNode* temp = root;
    int height;
    int n = query.length();

    for (height = 0; height < n; height++)
    {
        int value = CHAR_TO_value(query[height]);

            if (!temp->children[value])
            {
                return 0;
            }
            temp = temp->children[value];
        }

        bool isWord = (temp->isWordEnd == true);
        bool isLast = isLastNode(temp);

        if (isWord && isLast)
        {
            cout << query << endl;
            return -1;
        }

        if (!isLast)
        {
        string prefix = query;
        suggestionsRec(temp, prefix);
        return 1;
        }
    }

    void ReadFile(TrieNode *root, string fname)
    {

        string line;
        ifstream myfile(fname);
        if(myfile.is_open())
        {
            while(getline(myfile,line))
            {
                insert(root, line);
            }
            myfile.close();
        }else
        {
            cout << "File not read" <<endl;
        }
    }

};
