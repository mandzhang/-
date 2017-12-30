template<class T, class E>
void graphinc<T, E>::menu()
{
	graphinc<string, int> g;
	char x, c;
	int cost;
	string a, b;
	g.input();
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
			g.addVertex(a);
			break;
		case'2':
			cout << "请输入删除顶点的名称" << endl;
			cin >> a;
			g.removeVertex(a);
			break;
		case'3':
			cout << "请输入边俩顶点的名称以及边上权值";
			cin >> a>>b>>cost;
			g.addEdge(a,b,cost);
			break;
		case'4':
			cout << "请输入你需要删除的边俩顶点的名称";
			cin >> a >> b;
			g.removeEdge(a,b); break;
		case '5':
			//cout << "请输入你需要删除的链路俩侧路由器编号";
			//cout << "(现可供删除的路由器: 1 - " << g.NumberOfVertices() << ')' << endl;
			//cin >> v1 >> v2;
			g.shortPath(); break;
		default:break;
		}

	}
}