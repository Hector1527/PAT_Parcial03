#include "Ejercicio03.h"
#include "unordered_map"
using namespace std;

unordered_map<string, vector<pair<string, int>>> TimeMap::mimapa;

TimeMap::TimeMap()
{
}


void TimeMap::set(string key, string value, int timestamp)
{
	mimapa[key].emplace_back(value, timestamp);

}

string TimeMap::get(string key, int timestamp)
{
	auto it = mimapa.find(key);
	if (it != mimapa.end())
	{
		const vector<pair<string, int>>& valores = it->second;
		for (auto iter = valores.rbegin(); iter != valores.rend(); iter++)
		{
			if (iter->second <= timestamp)
			{
				return iter->first;
			}
		}
	}
	return "";
}
