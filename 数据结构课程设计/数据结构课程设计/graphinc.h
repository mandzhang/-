#ifndef GRAPHINC_H 
#define GRAPHINC_H 
#include "HashTable.h"
template<class T>
struct Edge
{
	string dest1;          //边上顶点
	string dest2;			//边的另一个顶点
	T cost;				//边上的权值
	Edge<T> * link;	//下一条边链指针
	Edge<T>*next;    //邻接表中的下一个指针
	Edge<T>*last;    //邻接表中的上一个指针
	Edge<T>*brother; //邻接表的兄弟指针，可以指向自身
	Edge(string Vertex1,string Vertex2, T dis):dest1(Vertex1), dest2(Vertex2), cost(dis), next(NULL), last(NULL), brother(NULL) {}
	Edge():dest(0){}
};
template<class T>
struct Vertex
{
	string data;                    //顶点元素值
	Edge<T> *adj;			//边链表的头指针
	Vertex<T>*next;        //指向下一点
	Vertex<T>*last;       //指向上一点
	int degree;//顶点的度
	Vertex(string Vertex1, Vertex<T> *left=NULL, Vertex<T> *right=NULL):data(Vertex1), last(left), next(right) {};
	Vertex() {};
};

template<class T>
class graphinc
{
public:
	graphinc()	//构造函数1
	{
		last = first = new Vertex<T>();
		first->last = last;
		last->next = first;
	};
	~graphinc() {};				//析构函数
	bool IsEmpty()const						//判断表空否，空返回true
	{
		return first->next == NULL ? true : false;
	}
	bool IsFull()const //表不会满
	{
		return false;
	};
	Vertex<T> *gethead()
	{
		return first;
	};
	int getvertices() //返回顶点个数
	{
		return num;
	};
	int vertexCount();//返回图中的顶点数 O(1)
	int edgeCount（）;// 返回图中的边数 O(1)
	//getVertices();// 返回包含所有顶点的数组 O（ | v | ）
	void addVertex(string vertex1);// 添加顶点 O(1)
	void removeVertex(string vertex1);//删除顶点 O(d)
	Vertex<T>* isVertex(string v);// 判断该顶点是否在图中 O(1),在的话，返回地址。不在的话，返回值为空
	int degree(string v);// 顶点的度 O(1)
	Vertex<T>* getFirstNeighbor(string v);// 返回第一个邻接顶点 O(1)
	Vertex<T>* getNextNeighbor(string v1, string v2);// 返回下一个邻接顶点 O(d)
	void addEdge(string v1, string v2);// 添加边 O(1)
	void removeEdge(string v1, string v2);// 删除边 O(1)
	void input();
	void output();
	//int isEdge(Object, Object);// 判断是否为边 O(1)
	//int weight(Object, Object);//
protected:
	Vertex<T> * first;					//链表头指针
	Vertex<T> *last;
	int num = 0;
	HashTable<Vertex<T>>  V;
	HashTable<Edge<T>> E;
};
template<class T>
void graphinc<T>::input() {
	ifstream ifile;
	string vertex1;
	ifile.open("Vertices.txt");
	ifile >> vertex1;
	num++;
	Vertex<T> * p1 = new Vertex<T>(vertex1);
	V.add(p1,2,vertex1,"ss");
	first->next = p1;
	first->last = p1;
	p1->last = first;
	p1->next = first;
	last = p1;
	while (1) {
		ifile >> vertex1;
		if (ifile.eof() != 0)
			break;
		num++;
		Vertex<T> * newVertex = new Vertex<T>(vertex1);
		if (newVertex == NULL)
		{
			cout << "内存分配错误！" << endl;
			exit(1);
		}
		V.add(newVertex, 1, vertex1);
		last->next = newVertex;
		newVertex->last = last;
		newVertex->next = first;
		first->last = newVertex;				//将新节点与前面一个节点以及后面一个结点的四条边连起来
		last = newVertex;
		p1 = newVertex;

	}
}
template<class T>
void graphinc<T>::output() {
	Vertex<T> *p = first->next;
	while (p != first) {
		cout << p->data << endl;
		p = p->next;
	}
}
template<class T>
int graphinc<T>::degree(string v)//顶点的度数
{
	Vertex<T> *curr;
	curr = ht.search(v);
	return curr->degree;
}
template<class T>             //判断顶点
Vertex<T>* graphinc<T>::isVertex(string v)
{
	Vertex<T>* curr;
	curr = ht.search(v);
	return curr;
}

template<class T>//添加边
void graphinc<T>::addEdge(string v1, string v2)
{
	T i;
	cout >> "输入边上的权值:";
	cin >> i;
	Edge<T>* pre, *newEdge1 = new Edge<T>(string v1, string v2, T i), *newEdge2 = new Edge<T>(string v2, string v1, T i);
	pre = ht.search(v1);
	newEdge1->next = pre->adj->next;
	pre->adj->next = newEdge1;
	newEdge1->last = pre->adj;
	pre = ht.search(v2);
	newEdge2->last = pre->adj;
	newEdge2->next = pre->adj->next;
	pre->adj->next = newEdge2;
	newEdge1->brother = newEdge2;
	newEdge2->brother = newEdge1;
	ht.add();//之后这里要把边加入hash表里
}
template<class T>
Vertex<T>* graphinc<T>::getFirstNeighbor(string v)//返回第一个临界顶点
{
	Vertex<T>*curr;
	curr = ht.search(v);
	return curr->adj->next;
}
template<class T>
void graphinc<T>::addVertex(string vertex)//添加定点
{
	string newVertex;
	cout >> "输入添加新节点名称：";
	cin >> newVertex;
	Vertex<T>* newnode = new Vertex<T>(newVertex);


}
#endif