#ifndef GRAPHINC_H 
#define GRAPHINC_H 
#include<iostream>
#include<fstream>
#include"HashTable.h"
using namespace std;
template<class T, class E>
struct Edge
{
	T dest1;          //边上顶点
	T dest2;			//边的另一个顶点
	E cost;				//边上的权值
	Edge<T, E> * link;	//下一条边链指针
	Edge<T, E>*next;    //邻接表中的下一个指针
	Edge<T, E>*last;    //邻接表中的上一个指针
	Edge<T, E>*brother; //邻接表的兄弟指针，可以指向自身
	Edge(T Vertex1, T Vertex2, E dis):dest1(Vertex1), dest2(Vertex2), cost(dis), next(NULL), last(NULL), brother(NULL) {};
	Edge():next(NULL),last(NULL),brother(NULL) {};
};

template<class T,class E>
struct Vertex
{
	T data;                    //顶点元素值
	Edge<T, E> *adj;			//边链表的头指针
	Vertex<T,E>*next;        //指向下一点
	Vertex<T,E>*last;       //指向上一点
	int degree;//顶点的度
	Vertex(T Vertex1): data(Vertex1), last(NULL), next(NULL)
	{
		adj = new Edge<T, E>;
		adj->next = adj;
		adj->last = adj;
	};
	Vertex():adj(NULL),next(NULL),last(NULL){};
};

template<class T, class E>
class graphinc
{
public:
	graphinc();	//构造函数1
	~graphinc() {};				//析构函数
	int vertexCount();//返回图中的顶点数 O(1)
	int edgeCount();// 返回图中的边数 O(1)
    T* getVertices();// 返回包含所有顶点的数组 O（ | v | ）?
	void addVertex(T vertex1);// 添加顶点 O(1)
	bool IsEmptyVertex();
	bool IsEmptyEdge(Vertex<T,E>* me);
	void removeVertex(T v);//删除顶点 O(d)
	Vertex<T,E>* isVertex(T v);// 判断该顶点是否在图中 O(1),在的话，返回地址。不在的话，返回值为空
	int degree(T v);// 顶点的度 O(1)
	Edge<T,E>* getFirstNeighbor(T v);// 返回第一个邻接顶点 O(1)
	Edge<T,E>* getNextNeighbor(T v1, T v2);// 返回下一个邻接顶点 O(d)
	void addEdge(T v1, T v2,E i);// 添加边 O(1)
	void removeEdge(T v1, T v2);// 删除边 O(1)
	int isEdge(T v1, T v2);// 判断是否为边 O(1)?
	E weight(T v1, T v2);//返回边的权值
	void input1();//输入点
	void input2();//输入边
	void shortpath();//最下生成树
	void menu();
private:
	Vertex<T,E> * first;					//链表头指针
	int numVertexVertex = 0,numVertexEdge=0;
	HashTable<Vertex<T,E>> V1;
	HashTable<Edge<T,E>> E1;
};
#endif