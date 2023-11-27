#pragma once
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
using std::string;

class TimeMap
{
private:
	static unordered_map<string, vector<pair<string, int>>> mimapa;
public:

	TimeMap();

	void set(string key, string value, int timestamp);

	string get(string key, int timestamp);
};

