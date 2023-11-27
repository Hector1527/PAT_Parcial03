#include "Ejercicio02.h"
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
	unordered_map<string, int> mapadeADN;
	vector<string>* result = new vector<string>;
	int max = 10;

	Node<char>* current = head;

	while (current)
	{
		string ADN;
		Node<char>* temp = current;
		for (int i = 0; i < max && temp; i++, temp = temp->next)
		{
			ADN.push_back(temp->value);
		}

		if (ADN.length() == max) {
			mapadeADN[ADN]++;
			if (mapadeADN[ADN] > 1) {
				auto it = find(result->begin(), result->end(), ADN);
				if (it == result->end())
					result->push_back(ADN);
			}
		}
		else {
			break;
		}

		current = current->next;
	}

	return result;
}
