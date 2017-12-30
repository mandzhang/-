#ifndef GRAPHINC_H 
#define GRAPHINC_H 
#include "HashTable.h"
template<class T>
struct Edge
{
	string dest1;          //���϶���
	string dest2;			//�ߵ���һ������
	T cost;				//���ϵ�Ȩֵ
	Edge<T> * link;	//��һ������ָ��
	Edge<T>*next;    //�ڽӱ��е���һ��ָ��
	Edge<T>*last;    //�ڽӱ��е���һ��ָ��
	Edge<T>*brother; //�ڽӱ���ֵ�ָ�룬����ָ������
	Edge(string Vertex1,string Vertex2, T dis):dest1(Vertex1), dest2(Vertex2), cost(dis), next(NULL), last(NULL), brother(NULL) {}
	Edge():dest(0){}
};
template<class T>
struct Vertex
{
	string data;                    //����Ԫ��ֵ
	Edge<T> *adj;			//�������ͷָ��
	Vertex<T>*next;        //ָ����һ��
	Vertex<T>*last;       //ָ����һ��
	int degree;//����Ķ�
	Vertex(string Vertex1, Vertex<T> *left=NULL, Vertex<T> *right=NULL):data(Vertex1), last(left), next(right) {};
	Vertex() {};
};

template<class T>
class graphinc
{
public:
	graphinc()	//���캯��1
	{
		last = first = new Vertex<T>();
		first->last = last;
		last->next = first;
	};
	~graphinc() {};				//��������
	bool IsEmpty()const						//�жϱ�շ񣬿շ���true
	{
		return first->next == NULL ? true : false;
	}
	bool IsFull()const //������
	{
		return false;
	};
	Vertex<T> *gethead()
	{
		return first;
	};
	int getvertices() //���ض������
	{
		return num;
	};
	int vertexCount();//����ͼ�еĶ����� O(1)
	int edgeCount����;// ����ͼ�еı��� O(1)
	//getVertices();// ���ذ������ж�������� O�� | v | ��
	void addVertex(string vertex1);// ��Ӷ��� O(1)
	void removeVertex(string vertex1);//ɾ������ O(d)
	Vertex<T>* isVertex(string v);// �жϸö����Ƿ���ͼ�� O(1),�ڵĻ������ص�ַ�����ڵĻ�������ֵΪ��
	int degree(string v);// ����Ķ� O(1)
	Vertex<T>* getFirstNeighbor(string v);// ���ص�һ���ڽӶ��� O(1)
	Vertex<T>* getNextNeighbor(string v1, string v2);// ������һ���ڽӶ��� O(d)
	void addEdge(string v1, string v2);// ��ӱ� O(1)
	void removeEdge(string v1, string v2);// ɾ���� O(1)
	void input();
	void output();
	//int isEdge(Object, Object);// �ж��Ƿ�Ϊ�� O(1)
	//int weight(Object, Object);//
protected:
	Vertex<T> * first;					//����ͷָ��
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
			cout << "�ڴ�������" << endl;
			exit(1);
		}
		V.add(newVertex, 1, vertex1);
		last->next = newVertex;
		newVertex->last = last;
		newVertex->next = first;
		first->last = newVertex;				//���½ڵ���ǰ��һ���ڵ��Լ�����һ������������������
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
int graphinc<T>::degree(string v)//����Ķ���
{
	Vertex<T> *curr;
	curr = ht.search(v);
	return curr->degree;
}
template<class T>             //�ж϶���
Vertex<T>* graphinc<T>::isVertex(string v)
{
	Vertex<T>* curr;
	curr = ht.search(v);
	return curr;
}

template<class T>//��ӱ�
void graphinc<T>::addEdge(string v1, string v2)
{
	T i;
	cout >> "������ϵ�Ȩֵ:";
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
	ht.add();//֮������Ҫ�ѱ߼���hash����
}
template<class T>
Vertex<T>* graphinc<T>::getFirstNeighbor(string v)//���ص�һ���ٽ綥��
{
	Vertex<T>*curr;
	curr = ht.search(v);
	return curr->adj->next;
}
template<class T>
void graphinc<T>::addVertex(string vertex)//��Ӷ���
{
	string newVertex;
	cout >> "��������½ڵ����ƣ�";
	cin >> newVertex;
	Vertex<T>* newnode = new Vertex<T>(newVertex);


}
#endif