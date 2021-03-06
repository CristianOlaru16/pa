#include <iostream>
#include <queue> // priority_queue

using namespace std;

struct cmp {
  // operatorul (functia) intoarce true 
  // daca A are prioritate mai mica decat B
  // ceea ce inseamna ca daca ar fi un max-heap, 
  // A este spre frunze, iar B spre radacina
  bool operator() (const pair<int, int>& A, const pair<int, int>& B) const {
  	// (3, 2) (2, 3)
  	if (A.first > B.first)   return true; 
  	if (A.first < B.first)   return false;

  	if (A.second > B.second) return false;
  	if (A.second < B.second) return true;
  	
  	return false;
  }
};
/*
const cmp c1;
cmp c2;
c1.()(A, B)

*/

int main() {
	// declarare
	priority_queue< pair<int, int>, vector< pair<int, int> >, cmp > pq;

	pair<int, int> p = {2, 3};
	pair<int, int> q = {2, 4};
	pq.push(p);
	pq.push(p);
	pq.push(q);
	pq.push(q);
	pq.push({3, 5});
	pq.push({3, 6});

	cout << "size: " << pq.size() << "\n";

	// se foloseste ca o coada
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
 	
		cout << p.first << " " << p.second << "\n";
	}

	return 0;
}