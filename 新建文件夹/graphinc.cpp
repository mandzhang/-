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
	curr = V1.search(1,v);
	return curr->degree;
}

template<class T, class E>             //判断顶点
Vertex<T, E>* graphinc<T, E>::isVertex(T v)
{
	Vertex<T, E>* curr;
	curr = V1.search(1,v);
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
		E1.add(newEdge2, 2, v2, v1);//之后这里要把边加入hash表里
		E1.add(newEdge1, 2, v2, v1);
	}
	numEdge++;
}

template<class T, class E>
Edge<T, E>* graphinc<T, E>::getFirstNeighbor(T v)//返回第一个临界顶点
{
	Vertex<T, E>* curr;
	curr = V1.search(1,v);
	return curr->adj->next;
}
template<class T, class E>
void graphinc<T, E>::addVertex(T vertex)//添加定点，前插法
{
	Vertex<T, E>* newnode = new Vertex<T, E>(vertex);
	while (first->last == first)//插入第一个顶点时
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
		while (!IsEmptyEdge(curr))//删除边，直到curr链表无节点
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
	cout << "图中以无顶点" << endl;
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
		cout << "  功能页面       " << endl;
		cout << "1.添加顶点              " << endl;
		cout << "2.删除顶点                " << endl;
		cout << "3.添加边              " << endl;
		cout << "4.删除边              " << endl;
		cout << "5.生成最小生成树               " << endl;
		cout << "6.退出操作           " << endl;
		cin >> x;
		if (x == '6') {
			cout << "欢迎下次使用" << endl;
			break;
		}
		switch (x)
		{
		case'1':
			cout << " 请输入添加顶点的名称" << endl;
			//cout << "请输入你需要查询的路由器的编号";
			//cout << "(现可供查询的路由器: 1 - " << g.NumberOfVertices() << ')' << endl;
			//cin >> Router.numRouter;
			cin >> a;
			addVertex(a);
			break;
		case'2':
			cout << "请输入删除顶点的名称" << endl;
			cin >> a;
			removeVertex(a);
			break;
		case'3':
			cout << "请输入边俩顶点的名称以及边上权值";
			cin >> a >> b >> cost;
			addEdge(a, b, cost);
			break;
		case'4':
			cout << "请输入你需要删除的边俩顶点的名称";
			cin >> a >> b;
			removeEdge(a, b); break;
		case '5':
			//cout << "请输入你需要删除的链路俩侧路由器编号";
			//cout << "(现可供删除的路由器: 1 - " << g.NumberOfVertices() << ')' << endl;
			//cin >> v1 >> v2;
			shortpath(); break;
		default:break;
		}
	}
}
