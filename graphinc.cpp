#include"graphinc.h"
template<class T,class E>
bool graphinc<T,E>::IsEmptyVertex()
{
	return first->next == first ? true : false;
}
template<class T,class E>
bool graphinc<T, E>::IsEmptyEdge(Vertex<T,E>* me)
{
	return me->adj->next == me->adj ? true : false;
}
template<class T,class E>
graphinc<T,E>::graphinc()
{
	first = new Vertex<T, E>();
	first->last = first;
	last->next = first;
	input1();
	input2();
}
template<class T, class E>
void graphinc<T, E>::input1()//顶点的输入
{
	ifstream ifile;
	T vertex;
	ifile.open("Vertexs.txt");
	while (ifile >> vertex1)
	{
		ifile >> vertex1;
		ifile >> vertex2;
		ifile >> cast;
		addVertex(vertex);
	}
	ifile.close();
}
/*template<class T, class E>
void graphinc<T, E>::output() {
Vertex<T,E> *p = first->next;
while (p != first) {
cout << p->data << endl;
p = p->next;
}
}*/

template<class T, class E>
int graphinc<T, E>::degree(T v)//顶点的度数
{
	Vertex<T, E> *curr;
	curr = V1.search(v);
	return curr->degree;
}

template<class T, class E>             //判断顶点
Vertex<T, E>* graphinc<T, E>::isVertex(T v)
{
	Vertex<T, E>* curr;
	curr = V1.search(v);
	return curr;
}

template<class T, class E>//添加边
void graphinc<T, E>::addEdge(T v1, T v2,E i)
{
	Vertex<T, E>* pre;
	Edge<T,E>*newEdge1 = new Edge<T, E>(T v1, T v2, E i), *newEdge2 = new Edge<T, E>(T v2, T v1, E i);
	pre = V1.search(v1);
	if (pre->adj->next == pre->adj)
	{
		pre->adj->last = newEdge1;
		pre->adj->next = newEdge1;
		newEdge1->next = pre->adj;
		newEdge1->last = pre->adj;
	}
	else
	{
		newEdge1->next = pre->adj->next;
		pre->adj->next = newEdge1;
		newEdge1->last = pre->adj;
		E1.add(newEdge1, 2, v1, v2);
	}
	pre = V1.search(v2);
	if (pre->adj->next == pre->adj)
	{
		pre->adj->last = newEdge2;
		pre->adj->next = newEdge2;
		newEdge2->next = pre->adj;
		newEdge2->last = pre->adj;
	}
	else
	{
		newEdge2->last = pre->adj;
		newEdge2->next = pre->adj->next;
		pre->adj->next = newEdge2;
		newEdge1->brother = newEdge2;
		newEdge2->brother = newEdge1;
		E1.add(newEdge2, 2, v2, v1);//之后这里要把边加入hash表里
	}
	numEdge++;
}

template<class T, class E>
Edge<T, E>* graphinc<T, E>::getFirstNeighbor(T v)//返回第一个临界顶点
{
	Vertex<T, E>* curr;
	curr = V1.search(v);
	return curr->adj->next;
}
template<class T, class E>
void graphinc<T, E>::addVertex(T vertex)//添加定点，前插法
{
	Vertex<T, E>* newnode = new Vertex<T, E>(Vertex);
	while (first->last == first)//插入第一个顶点时
	{
		first->last = newnode;
		first->next = newnode;
		newnode->next = first;
		newnode->last = first;
		return;
		numVertex++;
	}
	newnode->next = first->next;
	first->next = newnode;
	newnode->last = first;
	V1.add((*newnode));
	numVertex++;
}
template<class T, class E>
void graphinc<T, E>::removeVertex(T vertex1)
{
	while (!IsEmptyVertex())
	{
		Vertex<T, E>* curr;
		curr = V1.(vertex1);
		while (!IsEmptyEdge(curr))//删除边，直到curr链表无节点
		{
			removeEdge(vertex1, curr->adj->next->dest2);
		}
		delete curr->adj;
		curr->last->next = curr->next;
		curr->next->last = curr->last;
		delete curr;
		numVertex--;
		return;
	}
	cout << "图中以无顶点" << endl;
}
template<class T, class E>
void graphinc<T, E>::removeEdge(T v1, T v2)
{
	Edge<T, E>* pre;
	pre = E1.search(v1, v2);
	pre->brother->last->next = pre->brother->next;
	pre->brother->next->last = pre->brother->last;
	delete pre->brother;
	pre->last->next = pre->next;
	pre->next->last = pre->last;
	delete pre;
	numEdge--;
}
template<class T, class E>
graphinc<T, E>::graphinc()
{
	first= new Vertex<T, E>;
	first->next = first;
	first->last = first;
	input1();
	input2();
}
template<class T, class E>
void graphinc<T, E>::input2()//从文本输入边
{
	ifstream ifile;
	T vertex1,vertex2;
	E cast;
	ifile.open("Edges.txt");
	while (ifile >> vertex1)
	{
		ifile >> vertex1;
		ifile >> vertex2;
		ifile >> cast;
		addEdge(vertex1,vertex2,cast);
	}
	ifile.close();
}
template<class T,class E>
int graphinc<T, E>::isEdge(T v1, T v2)
{
	return 0;
}
template<class T,class E>
int graphinc<T, E>::vertexCount()//图的顶点数
{
	return numVertex;
}
template<class T,class E>
int graphinc<T, E>::edgeCount()//图的边数
{
	return numEdge;
}
template<class T,class E>
Edge<T, E>* graphinc<T, E>::getNextNeighbor(T v1, T v2)
{
	Vertex<T, E>*curr;
	curr = V1.search(v1);
	Edge<T, E>* pre;
	pre = E1.search(v1, v2);
	if(pre->next!=curr->adj)return pre->next;
	else return NULL;
}
template<class T,class E>
E graphinc<T, E>::weight(T v1, T v2)//?
{
	return (E1.search(v1, v2))->cost;

}
template<class T,class E>
T* graphinc<T, E>::getVertices()
{
	T vertices[numVertexVertex];
	Vertex<T, E>* curr = first;
	int i = 0;
	while (curr->next != first)
	{
		Vertices[i] = curr->data;
		i++;
	}
	return vertices;
}

