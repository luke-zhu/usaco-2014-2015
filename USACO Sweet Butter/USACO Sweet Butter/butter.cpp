
/*
USER: lukezhu1
LANG: C++
TASK: butter
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
#define CODE_WORKS true
#define MAXN 501
#define MAXP 801
#define INFIN 10000000
using namespace std;
ifstream in("butter.in");
ofstream out("butter.out");

struct node {
	int id;
	int dist;
	node(int id, int dist) : id(id), dist(dist) { }
	bool operator<(node const& other) const {
		return dist < other.dist;
	}
};
//Heap code from some online tutorial
class Heap{
public:
	Heap();
	~Heap();
	void insert(node element);
	node deletemin();
	void decreaseKey(int index, int newVal);
	int size(){ return heap.size(); }
public:
	int heapMap[801];
private:
	int left(int parent);
	int right(int parent);
	int parent(int child);
	void heapifyup(int index);
	void heapifydown(int index);
private:
	vector<node> heap;
};

Heap::Heap(){
}

Heap::~Heap(){
}

void Heap::insert(node element){
	heap.push_back(element);
	heapMap[element.id] = heap.size() - 1;
	heapifyup(heap.size() - 1);
}

node Heap::deletemin(){
	node min = heap.front();
	heap[0] = heap[heap.size() - 1];
	heap.pop_back();
	heapifydown(0);
	return min;
}

void Heap::decreaseKey(int index, int newVal){
	//cout << heapMap[index] << endl;
	heap[heapMap[index]].dist = min(heap[heapMap[index]].dist, newVal);
	heapifyup(heapMap[index]);
}

void Heap::heapifyup(int index){
	while (index > 0 && parent(index) >= 0 && heap[index] < heap[parent(index)]){
		heapMap[heap[index].id] = parent(index);
		heapMap[heap[parent(index)].id] = index;
		node temp = heap[parent(index)];
		heap[parent(index)] = heap[index];
		heap[index] = temp;
		index = parent(index);
	}
}

void Heap::heapifydown(int index){
	if (heap.size() == 0) return;
	int child = left(index);
	if (child > 0 && right(index) > 0 && heap[right(index)] < heap[child]){
		child = right(index);
	}
	if (child > 0 && heap[child] < heap[index]){
		heapMap[heap[index].id] = child;
		heapMap[heap[child].id] = index;
		node temp = heap[index];
		heap[index] = heap[child];
		heap[child] = temp;
		heapifydown(child);
	}
}

int Heap::left(int parent){
	int i = (parent << 1) + 1;
	return i < heap.size() ? i : -1;
}

int Heap::right(int parent){
	int i = (parent << 1) + 2;
	return i < heap.size() ? i : -1;
}

int Heap::parent(int child){
	if (child != 0){
		return (child - 1) >> 1;
	}
	return -1;
}

int main(){
	int N, P, C;
	in >> N >> P >> C;
	int cows[MAXP], past;
	memset(cows, 0, sizeof(cows));
	for (int i = 0; i < N; i++){
		in >> past;
		cows[past]++;
	}
	vector<vector<node> > grid(MAXP);
	int a, b, w;
	for (int i = 0; i < C; i++){
		in >> a >> b >> w;
		grid[a].push_back(node(b, w));
		grid[b].push_back(node(a, w));
	}

	int minDist = INFIN, v[MAXP];
	for (int i = 1; i <= P; i++){
		memset(v, 0, sizeof(v));
		Heap pQ;
		for (int j = 1; j <= P; j++){
			pQ.insert(node(j, INFIN));
		}
		pQ.decreaseKey(i, 0); //i is source
		int totalDist = 0;

		while (pQ.size()){
			node c = pQ.deletemin();
			v[c.id]++;

			if (c.dist == INFIN) break;
			if (cows[c.id]) totalDist += cows[c.id] * c.dist;
			for (int d = 0; d < grid[c.id].size(); d++){
				if (v[grid[c.id][d].id]) continue;
				int alt = c.dist + grid[c.id][d].dist;
				pQ.decreaseKey(grid[c.id][d].id, alt);
			}
		}
		minDist = min(minDist, totalDist);
	}
	out << minDist << endl;
}