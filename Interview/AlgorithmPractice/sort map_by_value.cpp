/*******************************************************************
* https://www.techiedelight.com/sort-map-values-cpp/
* 
* Sort map by value likes hash_map in Java
*
*******************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string,int> pairs;

int main(){

    // input map
    map<std::string,int> map = {
		{"two", 2}, {"one", 1}, {"four", 4}, {"three", 3}
    };

    // create an empty vector of pairs
    vector<pairs> vec;

    // copy key-value pairs from the map to the vector
    copy(map.begin(),
        map.end(),
        back_inserter<vector<pairs>>(vec));

    // sort the vector by increasing order of its pair's second value
    // if second value are equal, order by the pair's first value
    sort(vec.begin(), vec.end(),
		[](const pairs& l, const pairs& r) {
			if (l.second != r.second)
				return l.second < r.second;

			return l.first < r.first;
		});

    // print the vector
    for (auto const &pairs: vec) {
        cout << '{' << pairs.first << "," << pairs.second << '}' << '\n';
    }

	return 0;
}