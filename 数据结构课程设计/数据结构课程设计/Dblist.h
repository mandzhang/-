#ifndef DBLIST_H  
#define DBLIST_H
#include<iostream>
#include<fstream>
template<class T>
struct Node
{
	Node<T> *left, *right;
	T data;
	int sign;
	int degree;
	Node() :left(NULL), right(NULL) { sign = 0; };
	Node(T vertex1, T vertex2, Node<T> *l = NULL, Node<T> *r = NULL) :data(x), left(l), right(r) {}
	Node(T data1, Node<T> *l = NULL, Node<T> *r = NULL) :data(data1), left(l), right(r) {
	}
	~Node() {
	}
};
template<class T>
class Dblist
{
public:
	Dblist()	//���캯��1
	{
		last=first = new Node<T>();
		 first->left = last;
		 last->right = first;
	}
	~Dblist(){}					//��������
	bool IsEmpty()const						//�жϱ�շ񣬿շ���true
	{
		return first->next == NULL ? true : false;
	}
	bool IsFull()const //������
	{
		return false;
	}
	Node<T> *gethead() {
		return first;
	}
	int getvertices() {
		return num;
	}
	void output();
	void input();
protected:
	Node<T> * first;					//����ͷָ��
	Node<T> *last;
	int num=0;
};
template<class T>
void Dblist<T>::input() {
	ifstream ifile;
	T vertex1;
	ifile.open("Vertices.txt");
	ifile>> vertex1;
	num++;
	Node<T> * p1 = new Node<T>(vertex1);
	first->right = p1;
	first->left = p1;
	p1->left = first;
	p1->right = first;
	last = p1;
	while (1) {
		ifile >> vertex1;
		if (ifile.eof() != 0)
			break;
		num++;
		Node<T> * newNode = new Node<T>(vertex1);
		if (newNode == NULL)
		{
			cout << "�ڴ�������" << endl;
			exit(1);
		}
		last->right = newNode;
		newNode->left = last;
		newNode->right = first;
		first->left = newNode;				//���½ڵ���ǰ��һ���ڵ��Լ�����һ������������������
		last = newNode;
		p1 = newNode;
		
	}
}
template<class T>
void Dblist<T>::output() {
	Node<T> *p = first->right;
	while (p != first) {
		cout << p->data << endl;
		p = p->right;
	}
}
#endif