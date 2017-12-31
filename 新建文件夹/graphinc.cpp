#include"graphinc.h"
template<class T, class E>
graphinc<T, E>::graphinc()
{
	first = new Vertex<T, E>();
	first->next = first;
	first->last = first;
	input1();
	input2();
	menu();
}
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
template<class T, class E>
void graphinc<T, E>::input1()//���������
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
int graphinc<T, E>::degree(T v)//����Ķ���
{
	Vertex<T, E> *curr;
	curr = V1.search(1,v);
	return curr->degree;
}

template<class T, class E>             //�ж϶���
Vertex<T, E>* graphinc<T, E>::isVertex(T v)
{
	Vertex<T, E>* curr;
	curr = V1.search(1,v);
	return curr;
}

template<class T, class E>//��ӱ�
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
		E1.add(newEdge1, 2, v1, v2);
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
		E1.add(newEdge1, 2, v2, v1);
	}
	else
	{
		newEdge2->last = pre->adj;
		newEdge2->next = pre->adj->next;
		pre->adj->next = newEdge2;
		newEdge1->brother = newEdge2;
		newEdge2->brother = newEdge1;
		E1.add(newEdge2, 2, v2, v1);//֮������Ҫ�ѱ߼���hash����
		E1.add(newEdge1, 2, v2, v1);
	}
	numEdge++;
}

template<class T, class E>
Edge<T, E>* graphinc<T, E>::getFirstNeighbor(T v)//���ص�һ���ٽ綥��
{
	Vertex<T, E>* curr;
	curr = V1.search(1,v);
	return curr->adj->next;
}
template<class T, class E>
void graphinc<T, E>::addVertex(T vertex)//��Ӷ��㣬ǰ�巨
{
	Vertex<T, E>* newnode = new Vertex<T, E>(vertex);
	while (first->last == first)//�����һ������ʱ
	{
		first->last = newnode;
		first->next = newnode;
		newnode->next = first;
		newnode->last = first;
		V1.add(newnode, 1, vertex);
		return;
		numVertex++;
	}
	newnode->next = first->next;
	first->next = newnode;
	newnode->last = first;
	V1.add(newnode,1,vertex);
	numVertex++;
}

template<class T, class E>
void graphinc<T, E>::removeVertex(T v)
{
	while (!IsEmptyVertex())
	{
		Vertex<T, E>* curr;
		curr = V1.search(1,v);
		while (!IsEmptyEdge(curr))//ɾ���ߣ�ֱ��curr�����޽ڵ�
		{
			removeEdge(v, curr->adj->next->dest2);
		}
		delete curr->adj;
		curr->last->next = curr->next;
		curr->next->last = curr->last;
		delete curr;
		numVertex--;
		return;
	}
	cout << "ͼ�����޶���" << endl;
}
template<class T, class E>
void graphinc<T, E>::removeEdge(T v1, T v2)
{
	Edge<T, E>* pre;
	pre = E1.search(2,v1, v2);
	pre->brother->last->next = pre->brother->next;
	pre->brother->next->last = pre->brother->last;
	delete pre->brother;
	pre->last->next = pre->next;
	pre->next->last = pre->last;
	delete pre;
	numEdge--;
}
template<class T, class E>
void graphinc<T, E>::input2()//���ı������
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
int graphinc<T, E>::vertexCount()//ͼ�Ķ�����
{
	return numVertex;
}
template<class T,class E>
int graphinc<T, E>::edgeCount()//ͼ�ı���
{
	return numEdge;
}
template<class T,class E>
Edge<T, E>* graphinc<T, E>::getNextNeighbor(T v1, T v2)
{
	Vertex<T, E>*curr;
	curr = V1.search(1,v1);
	Edge<T, E>* pre;
	pre = E1.search(2,v1, v2);
	if(pre->next!=curr->adj)return pre->next;
	else return NULL;
}
template<class T,class E>
E graphinc<T, E>::weight(T v1, T v2)//?
{
	return (E1.search(2,v1, v2))->cost;

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
template<class T,class E>
void graphinc<T, E>::shortpath()
{
	return;
}
template<class T,class E>
void graphinc<T,E>::menu()
{
	char x;
	E cost;
	T a, b;
	while (1)
	{
		cout << "  ����ҳ��       " << endl;
		cout << "1.��Ӷ���              " << endl;
		cout << "2.ɾ������                " << endl;
		cout << "3.��ӱ�              " << endl;
		cout << "4.ɾ����              " << endl;
		cout << "5.������С������               " << endl;
		cout << "6.�˳�����           " << endl;
		cin >> x;
		if (x == '6') {
			cout << "��ӭ�´�ʹ��" << endl;
			break;
		}
		switch (x)
		{
		case'1':
			cout << " ��������Ӷ��������" << endl;
			//cout << "����������Ҫ��ѯ��·�����ı��";
			//cout << "(�ֿɹ���ѯ��·����: 1 - " << g.NumberOfVertices() << ')' << endl;
			//cin >> Router.numRouter;
			cin >> a;
			addVertex(a);
			break;
		case'2':
			cout << "������ɾ�����������" << endl;
			cin >> a;
			removeVertex(a);
			break;
		case'3':
			cout << "�������������������Լ�����Ȩֵ";
			cin >> a >> b >> cost;
			addEdge(a, b, cost);
			break;
		case'4':
			cout << "����������Ҫɾ���ı������������";
			cin >> a >> b;
			removeEdge(a, b); break;
		case '5':
			//cout << "����������Ҫɾ������·����·�������";
			//cout << "(�ֿɹ�ɾ����·����: 1 - " << g.NumberOfVertices() << ')' << endl;
			//cin >> v1 >> v2;
			shortpath(); break;
		default:break;
		}
	}
}
