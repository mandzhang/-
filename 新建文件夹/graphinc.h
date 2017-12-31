#ifndef GRAPHINC_H 
#define GRAPHINC_H 
#include<iostream>
#include<fstream>
#include"HashTable.h"
using namespace std;
template<class T, class E>
struct Edge
{
	T dest1;          //���϶���
	T dest2;			//�ߵ���һ������
	E cost;				//���ϵ�Ȩֵ
	Edge<T, E> * link;	//��һ������ָ��
	Edge<T, E>*next;    //�ڽӱ��е���һ��ָ��
	Edge<T, E>*last;    //�ڽӱ��е���һ��ָ��
	Edge<T, E>*brother; //�ڽӱ���ֵ�ָ�룬����ָ������
	Edge(T Vertex1, T Vertex2, E dis):dest1(Vertex1), dest2(Vertex2), cost(dis), next(NULL), last(NULL), brother(NULL) {};
	Edge():next(NULL),last(NULL),brother(NULL) {};
};

template<class T,class E>
struct Vertex
{
	T data;                    //����Ԫ��ֵ
	Edge<T, E> *adj;			//�������ͷָ��
	Vertex<T,E>*next;        //ָ����һ��
	Vertex<T,E>*last;       //ָ����һ��
	int degree;//����Ķ�
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
	graphinc();	//���캯��1
	~graphinc() {};				//��������
	int vertexCount();//����ͼ�еĶ����� O(1)
	int edgeCount();// ����ͼ�еı��� O(1)
    T* getVertices();// ���ذ������ж�������� O�� | v | ��?
	void addVertex(T vertex1);// ��Ӷ��� O(1)
	bool IsEmptyVertex();
	bool IsEmptyEdge(Vertex<T,E>* me);
	void removeVertex(T v);//ɾ������ O(d)
	Vertex<T,E>* isVertex(T v);// �жϸö����Ƿ���ͼ�� O(1),�ڵĻ������ص�ַ�����ڵĻ�������ֵΪ��
	int degree(T v);// ����Ķ� O(1)
	Edge<T,E>* getFirstNeighbor(T v);// ���ص�һ���ڽӶ��� O(1)
	Edge<T,E>* getNextNeighbor(T v1, T v2);// ������һ���ڽӶ��� O(d)
	void addEdge(T v1, T v2,E i);// ��ӱ� O(1)
	void removeEdge(T v1, T v2);// ɾ���� O(1)
	int isEdge(T v1, T v2);// �ж��Ƿ�Ϊ�� O(1)?
	E weight(T v1, T v2);//���رߵ�Ȩֵ
	void input1();//�����
	void input2();//�����
	void shortpath();//����������
	void menu();
private:
	Vertex<T,E> * first;					//����ͷָ��
	int numVertexVertex = 0,numVertexEdge=0;
	HashTable<Vertex<T,E>> V1;
	HashTable<Edge<T,E>> E1;
};
#endif