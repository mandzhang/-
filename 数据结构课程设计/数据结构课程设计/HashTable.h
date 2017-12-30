#ifndef _HASHTABLE_
#define _HASHTABLE_
#include<string>
#include<fstream>
#include<iostream>
#include<math.h>
#include<cstdio>
#include<stdarg.h>
using namespace std;
#define DefaultSize 100								//最多顶点数
void MaxPrime(int &m) {
	int y, t1 = 0, t2 = 0;
	int sig = 0;
	int x = DefaultSize;
	for (int i = 2; i <= x; i++)
	{
		sig = 0;
		for (y = 2; y <= sqrt(x); y++)
			if (i%y == 0)
			{
				sig = 1;
				break;
			}
		if (sig == 0)
		{
			t1 = i;
		}
	}
	m = t1;
}
template<class T,class E>
struct Node{
	T *pointer;			          //hash存放链表指针
	E  data[2];           //hash表存放数据,顶点名称或线
	int sign;                //hash表位置是否为空
	Node() { 
		sign = 0;
		pointer = NULL; 
	}
};
template<class T, class E>
class HashTable
{
public:
	HashTable();
	~HashTable() {}
	T* search(int n,E data, ...);						//边的查找和顶点
	void add( int n,T *p,E data, ...);
	void remove(int n,E data,...);
	int getPos(E data);
private:
	Node<T,E> *ht;									//hash表
	int divitor;              
	int CurrentSize, TableSize;
	//int GetPos(string da1, ...);		   //hash地址生成函数
};
template<class T, class E>
HashTable<T,E>::HashTable()
{
	int x, y;
	MaxPrime(x);						//得到100之内最大的素数
	divitor = x;
	TableSize = DefaultSize, CurrentSize = 0;
	ht = new Node<T,E>[TableSize];
}
template<class T, class E>
void HashTable<T,E>::add( int n,T *point,E data, ...) {
	double sum=0;
	int start = 0, pos = 0,y=0,t=0,i=0;
	E str;
	E tem[2];
	str=tem[0] = data;
	va_list ap = 0;
	va_start(ap,data);
	for (i = 0; i<n; ++i)
	{
		char *p;
		va_arg(ap, char *);
		tem[1] = ap;
		str += ap;
	}
	va_end(ap);
	for (i = 0; i < str.size(); i++)
	{
		sum += str[i]*pow(3,str[i]-'A');

	}
	start = pos = fmod(sum, divitor);
		if (ht[pos].sign == 0)
		{
			t = 1;
		}
		else {
			while (ht[pos].sign != 0)
			{
				y++;
				pos= (pos+ 1) % TableSize;
				if (pos == start)
				{
					cout << "表满" << endl;
					break;
				}
			}
			if (ht[pos].sign == 0)
				t = 1;
		}
		if (t==1)
		{
			for(i=0;i<n+1;i++)
			ht[pos].data[i] = tem[i];
			ht[pos].pointer = point;
			ht[pos].sign = 1;
			CurrentSize++;
		}
		else {
			cout << "hash表长度不足" << endl;
		}
}
template<class T,class E>
T* HashTable<T,E>::search(int n,E data, ...)//搜索，返回顶点的指针位置,
{
	double sum = 0;
	int start = 0, pos = 0, y = 0, t = 0, i = 0;
	E str;
	E tem[2];
	str = tem[0] = data;
	va_list ap = 0;
	va_start(ap, data);
	for (i = 0; i<n; ++i)
	{
		char *p;
		va_arg(ap, char *);
		tem[1] = ap;
		str += ap;
	}
	va_end(ap);
	for (i = 0; i < str.size(); i++)
	{
		sum += str[i] * pow(3, str[i] - 'A');

	}
	start = pos = fmod(sum, divitor);
	for (i = 0; i<n+1; ++i)
		if (ht[pos].data[i] != tem[i])		//判断是否相等
		{
			t = 0;
		}
	if (t == 0)
	{
		if (ht[pos].sign == 1)
			while (j < 5)
			{
				if (pos == start)
				{
					cout << "不存在" << endl;
					return false;
				}
				pos++;
				j++;
				for (i = 0; i < n+1; i++)
					if (ht[pos].data[i] == tem[i])
					{
						cout << "查找成功" << endl;
						return ht[pos].pointer;
					}
			}
		else
		{
			cout << "不存在" << endl;
			return NULL;
		}
	}
	else
	{
		cout << "查找成功" << endl;
		return ht[pos].pointer;
	}
}
template<class T, class E>
void HashTable<T, E>::remove(int n, E data, ...) {
	double sum = 0;
	int start = 0, pos = 0, y = 0, t = 0, i = 0;
	E str;
	E tem[2];
	str = tem[0] = data;
	num = n;
	va_list ap = 0;
	va_start(ap, data);
	for (i = 0; i < n; ++i)
	{
		char *p;
		va_arg(ap, char *);
		tem[1] = ap;
		str += ap;
	}
	va_end(ap);
	start = pos = fmod(sum, divitor);
	for (i = 0; i < n+1; ++i)
		if (ht[pos].data[i] != tem[i])		//判断是否相等
		{
			t = 0;
		}
	if (t == 0)
	{
		if (ht[pos].sign == 1)
			while (j < 5)
			{
				if (pos == start)
				{
					cout << "不存在" << endl;
					return false;
				}
				pos++;
				j++;
				for (i = 0; i < n+1; i++)
					if (ht[pos].data[i] == tem[i])
					{
						t = 1;
					}
			}
		else
		{
			ht[pos].sign = 0;							//将标志位置为0
			CurrentSize--;
		}
	}
}
#endif // !_HASHTABLE_
