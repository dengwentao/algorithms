//
//  PathBetweenTwoWords.cpp
//  algorithms
//
//  Created by Wentao Deng on 11/11/14.
//  Copyright (c) 2014 WENTAO INC. All rights reserved.
//

// Given a dictionary, start word and end word. Find a path to transform from start word to end word.
// Each step of transformation results in a valid word in the dictionary.

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const char* words[] = {"cap", "cat", "cats", "bat", "tap", "top", "tip", "to", "no", "on", "do", "dot", "dog", "dogs", "dots"};
unordered_set<string> dict;
stack<string> path;
unordered_set<string> visited;

//find all neighbors that have edit distance 1.
vector<string> AllNeighbors(const string& word)
{
    vector<string> result;
    
    //Remove 1
    for(int i=0; i<word.size(); i++)
    {
        string tmp = word;
        tmp.erase(i, 1);
        result.push_back(tmp);
    }
    //Replace 1 char
    for(int i=0; i<word.size(); i++)
        for(char c='a'; c<='z'; c++)
        {
            string tmp = word;
            tmp.replace(i, 1, 1, c);
            result.push_back(tmp);
        }
    //Insert 1 char
    for(int i=0; i<=word.size(); i++)
        for(char c='a'; c<='z'; c++)
        {
            string tmp = word;
            tmp.insert(i, 1, c);
            result.push_back(tmp);
        }
    
    return result;
}

//With DFS, starting from word trying to find target.
//Since it's DFS, the path is not garanteed to be shortest.
bool DFS(const string& word, const string& target)
{
    //if the input word has been visited, or not in the dict, return false.
    if(visited.find(word)!=visited.end() || dict.find(word)==dict.end())
        return false;
    path.push(word);
    if(word==target)
        return true;
    visited.insert(word);
    
    vector<string> neighbors = AllNeighbors(word);
    for(vector<string>::const_iterator it=neighbors.begin(); it!=neighbors.end(); ++it)
    {
        if(DFS(*it, target))
            return true;
    }
    
    //the end word not reachable.
    path.pop();
    return false;
}

//
queue<string> q;
unordered_map<string, string> parent;//to record each string's parent string so that we can print out path.
bool BFS(const string& word, const string& target)
{
    q.push(word);
    while(!q.empty())
    {
        const string w = q.front();
        q.pop();
        if(w==target)
            return true;
    
        vector<string> neighbors = AllNeighbors(w);
        for(vector<string>::const_iterator it=neighbors.begin(); it!=neighbors.end(); ++it)
        {
            if(visited.find(*it)!=visited.end() || dict.find(*it)==dict.end())
                continue;
            q.push(*it);
            visited.insert(*it);
            parent[*it] = w; //*it is derived from w
        }
    }
    return false;
}

void PrintPath(const string& start, const string& end)
{
    if(dict.find(start)==dict.end() || dict.find(end)==dict.end())
        return;
    
    if(BFS(start, end))//(DFS(start, end))
    {
        cout << "Path found:" << endl;
        string w = end;
        while(w!=start)
        {
            cout << w << endl;
            w = parent[w];
        }
        cout << w << endl;
    }
    else
        cout << "No such path." << endl;
}

int mainPath()
{
    string start = "dog";
    string end = "cat";
    dict.insert(words, words+sizeof(words)/sizeof(words[0]));
    //for(unordered_set<string>::const_iterator it=dict.begin(); it!=dict.end(); ++it)
    //{
    //    cout << *it << endl;
    //}

    //vector<string> v = AllNeighbors(start);
    //for(vector<string>::const_iterator it=v.begin(); it!=v.end(); ++it)
    //{
    //    cout << *it << endl;
    //}
    PrintPath(start, end);
    return 0;
}
