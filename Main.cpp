#include "Graph.h"
#include <math.h>
#include <vector>

float GetDistance(float x1, float y1, float x2, float y2)
{
	float dist;
	dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	return dist;
}

int main()
{
	RenderWindow win(VideoMode(800, 600), "ASTAR");
	Graph graph;
	vector <Node*> Path;
	Box box(100,100);
	
	for(int i = 100; i<=500; i+=100)
	{
		for(int j = 100; j<=500; j+=100)
		{
			if(j == 200 && i == 200) graph.AddNode((float)j, (float)i, false);
			else
			{
			graph.AddNode((float)j,(float)i);
			}
		}
		
	}

	//HORIZONTAL EDGES

	graph.AddEdge(graph.GetNodeID(0), graph.GetNodeID(1), abs((int)GetDistance(graph.GetNode(0)->GetPositionX(),graph.GetNode(0)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(1), graph.GetNodeID(0), abs((int)GetDistance(graph.GetNode(0)->GetPositionX(),graph.GetNode(0)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(1), graph.GetNodeID(2), abs((int)GetDistance(graph.GetNode(2)->GetPositionX(),graph.GetNode(2)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(2), graph.GetNodeID(1), abs((int)GetDistance(graph.GetNode(2)->GetPositionX(),graph.GetNode(2)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));
	
	graph.AddEdge(graph.GetNodeID(2), graph.GetNodeID(3), abs((int)GetDistance(graph.GetNode(2)->GetPositionX(),graph.GetNode(2)->GetPositionY(),graph.GetNode(3)->GetPositionX(), graph.GetNode(3)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(3), graph.GetNodeID(2), abs((int)GetDistance(graph.GetNode(2)->GetPositionX(),graph.GetNode(2)->GetPositionY(),graph.GetNode(3)->GetPositionX(), graph.GetNode(3)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(3), graph.GetNodeID(4), abs((int)GetDistance(graph.GetNode(3)->GetPositionX(),graph.GetNode(3)->GetPositionY(),graph.GetNode(4)->GetPositionX(), graph.GetNode(4)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(4), graph.GetNodeID(3), abs((int)GetDistance(graph.GetNode(3)->GetPositionX(),graph.GetNode(3)->GetPositionY(),graph.GetNode(4)->GetPositionX(), graph.GetNode(4)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(5), graph.GetNodeID(6), abs((int)GetDistance(graph.GetNode(5)->GetPositionX(),graph.GetNode(5)->GetPositionY(),graph.GetNode(6)->GetPositionX(), graph.GetNode(6)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(6), graph.GetNodeID(5), abs((int)GetDistance(graph.GetNode(5)->GetPositionX(),graph.GetNode(5)->GetPositionY(),graph.GetNode(6)->GetPositionX(), graph.GetNode(6)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(6), graph.GetNodeID(7), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(7)->GetPositionX(), graph.GetNode(7)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(7), graph.GetNodeID(6), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(7)->GetPositionX(), graph.GetNode(7)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(7), graph.GetNodeID(8), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(8), graph.GetNodeID(7), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(8), graph.GetNodeID(9), abs((int)GetDistance(graph.GetNode(8)->GetPositionX(),graph.GetNode(8)->GetPositionY(),graph.GetNode(9)->GetPositionX(), graph.GetNode(9)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(9), graph.GetNodeID(8), abs((int)GetDistance(graph.GetNode(8)->GetPositionX(),graph.GetNode(8)->GetPositionY(),graph.GetNode(9)->GetPositionX(), graph.GetNode(9)->GetPositionY())));
	
	graph.AddEdge(graph.GetNodeID(10), graph.GetNodeID(11), abs((int)GetDistance(graph.GetNode(10)->GetPositionX(),graph.GetNode(10)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(11), graph.GetNodeID(10), abs((int)GetDistance(graph.GetNode(10)->GetPositionX(),graph.GetNode(10)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(11), graph.GetNodeID(12), abs((int)GetDistance(graph.GetNode(11)->GetPositionX(),graph.GetNode(11)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(12), graph.GetNodeID(11), abs((int)GetDistance(graph.GetNode(11)->GetPositionX(),graph.GetNode(11)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(12), graph.GetNodeID(13), abs((int)GetDistance(graph.GetNode(12)->GetPositionX(),graph.GetNode(12)->GetPositionY(),graph.GetNode(13)->GetPositionX(), graph.GetNode(13)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(13), graph.GetNodeID(12), abs((int)GetDistance(graph.GetNode(12)->GetPositionX(),graph.GetNode(12)->GetPositionY(),graph.GetNode(13)->GetPositionX(), graph.GetNode(13)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(13), graph.GetNodeID(14), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(14)->GetPositionX(), graph.GetNode(14)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(14), graph.GetNodeID(13), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(14)->GetPositionX(), graph.GetNode(14)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(15), graph.GetNodeID(16), abs((int)GetDistance(graph.GetNode(15)->GetPositionX(),graph.GetNode(15)->GetPositionY(),graph.GetNode(16)->GetPositionX(), graph.GetNode(16)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(16), graph.GetNodeID(15), abs((int)GetDistance(graph.GetNode(15)->GetPositionX(),graph.GetNode(15)->GetPositionY(),graph.GetNode(16)->GetPositionX(), graph.GetNode(16)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(16), graph.GetNodeID(17), abs((int)GetDistance(graph.GetNode(16)->GetPositionX(),graph.GetNode(16)->GetPositionY(),graph.GetNode(17)->GetPositionX(), graph.GetNode(17)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(17), graph.GetNodeID(16), abs((int)GetDistance(graph.GetNode(16)->GetPositionX(),graph.GetNode(16)->GetPositionY(),graph.GetNode(17)->GetPositionX(), graph.GetNode(17)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(17), graph.GetNodeID(18), abs((int)GetDistance(graph.GetNode(17)->GetPositionX(),graph.GetNode(17)->GetPositionY(),graph.GetNode(18)->GetPositionX(), graph.GetNode(18)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(18), graph.GetNodeID(17), abs((int)GetDistance(graph.GetNode(17)->GetPositionX(),graph.GetNode(17)->GetPositionY(),graph.GetNode(18)->GetPositionX(), graph.GetNode(18)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(18), graph.GetNodeID(19), abs((int)GetDistance(graph.GetNode(18)->GetPositionX(),graph.GetNode(18)->GetPositionY(),graph.GetNode(19)->GetPositionX(), graph.GetNode(19)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(19), graph.GetNodeID(18), abs((int)GetDistance(graph.GetNode(18)->GetPositionX(),graph.GetNode(18)->GetPositionY(),graph.GetNode(19)->GetPositionX(), graph.GetNode(19)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(20), graph.GetNodeID(21), abs((int)GetDistance(graph.GetNode(20)->GetPositionX(),graph.GetNode(20)->GetPositionY(),graph.GetNode(21)->GetPositionX(), graph.GetNode(21)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(21), graph.GetNodeID(20), abs((int)GetDistance(graph.GetNode(20)->GetPositionX(),graph.GetNode(20)->GetPositionY(),graph.GetNode(21)->GetPositionX(), graph.GetNode(21)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(21), graph.GetNodeID(22), abs((int)GetDistance(graph.GetNode(21)->GetPositionX(),graph.GetNode(21)->GetPositionY(),graph.GetNode(22)->GetPositionX(), graph.GetNode(22)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(22), graph.GetNodeID(21), abs((int)GetDistance(graph.GetNode(21)->GetPositionX(),graph.GetNode(21)->GetPositionY(),graph.GetNode(22)->GetPositionX(), graph.GetNode(22)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(22), graph.GetNodeID(23), abs((int)GetDistance(graph.GetNode(22)->GetPositionX(),graph.GetNode(22)->GetPositionY(),graph.GetNode(23)->GetPositionX(), graph.GetNode(23)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(23), graph.GetNodeID(22), abs((int)GetDistance(graph.GetNode(22)->GetPositionX(),graph.GetNode(22)->GetPositionY(),graph.GetNode(23)->GetPositionX(), graph.GetNode(23)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(23), graph.GetNodeID(24), abs((int)GetDistance(graph.GetNode(23)->GetPositionX(),graph.GetNode(23)->GetPositionY(),graph.GetNode(24)->GetPositionX(), graph.GetNode(24)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(24), graph.GetNodeID(23), abs((int)GetDistance(graph.GetNode(23)->GetPositionX(),graph.GetNode(23)->GetPositionY(),graph.GetNode(24)->GetPositionX(), graph.GetNode(24)->GetPositionY())));

	//VERTICAL EDGES

	graph.AddEdge(graph.GetNodeID(0), graph.GetNodeID(5), abs((int)GetDistance(graph.GetNode(0)->GetPositionX(),graph.GetNode(0)->GetPositionY(),graph.GetNode(5)->GetPositionX(), graph.GetNode(5)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(5), graph.GetNodeID(0), abs((int)GetDistance(graph.GetNode(0)->GetPositionX(),graph.GetNode(0)->GetPositionY(),graph.GetNode(5)->GetPositionX(), graph.GetNode(5)->GetPositionY())));
	
	graph.AddEdge(graph.GetNodeID(5), graph.GetNodeID(10), abs((int)GetDistance(graph.GetNode(10)->GetPositionX(),graph.GetNode(10)->GetPositionY(),graph.GetNode(5)->GetPositionX(), graph.GetNode(5)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(10), graph.GetNodeID(5), abs((int)GetDistance(graph.GetNode(10)->GetPositionX(),graph.GetNode(10)->GetPositionY(),graph.GetNode(5)->GetPositionX(), graph.GetNode(5)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(10), graph.GetNodeID(15), abs((int)GetDistance(graph.GetNode(10)->GetPositionX(),graph.GetNode(10)->GetPositionY(),graph.GetNode(15)->GetPositionX(), graph.GetNode(15)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(15), graph.GetNodeID(10), abs((int)GetDistance(graph.GetNode(10)->GetPositionX(),graph.GetNode(10)->GetPositionY(),graph.GetNode(15)->GetPositionX(), graph.GetNode(15)->GetPositionY())));
	
	graph.AddEdge(graph.GetNodeID(15), graph.GetNodeID(20), abs((int)GetDistance(graph.GetNode(20)->GetPositionX(),graph.GetNode(20)->GetPositionY(),graph.GetNode(15)->GetPositionX(), graph.GetNode(15)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(20), graph.GetNodeID(15), abs((int)GetDistance(graph.GetNode(20)->GetPositionX(),graph.GetNode(20)->GetPositionY(),graph.GetNode(15)->GetPositionX(), graph.GetNode(15)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(1), graph.GetNodeID(6), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(6), graph.GetNodeID(1), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(6), graph.GetNodeID(11), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(11), graph.GetNodeID(6), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(11), graph.GetNodeID(16), abs((int)GetDistance(graph.GetNode(16)->GetPositionX(),graph.GetNode(16)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(16), graph.GetNodeID(11), abs((int)GetDistance(graph.GetNode(16)->GetPositionX(),graph.GetNode(16)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(16), graph.GetNodeID(21), abs((int)GetDistance(graph.GetNode(21)->GetPositionX(),graph.GetNode(21)->GetPositionY(),graph.GetNode(16)->GetPositionX(), graph.GetNode(16)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(21), graph.GetNodeID(16), abs((int)GetDistance(graph.GetNode(21)->GetPositionX(),graph.GetNode(21)->GetPositionY(),graph.GetNode(16)->GetPositionX(), graph.GetNode(16)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(2), graph.GetNodeID(7), abs((int)GetDistance(graph.GetNode(2)->GetPositionX(),graph.GetNode(2)->GetPositionY(),graph.GetNode(7)->GetPositionX(), graph.GetNode(7)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(7), graph.GetNodeID(2), abs((int)GetDistance(graph.GetNode(2)->GetPositionX(),graph.GetNode(2)->GetPositionY(),graph.GetNode(7)->GetPositionX(), graph.GetNode(7)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(7), graph.GetNodeID(12), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(12), graph.GetNodeID(7), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(12), graph.GetNodeID(17), abs((int)GetDistance(graph.GetNode(12)->GetPositionX(),graph.GetNode(12)->GetPositionY(),graph.GetNode(17)->GetPositionX(), graph.GetNode(17)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(17), graph.GetNodeID(12), abs((int)GetDistance(graph.GetNode(12)->GetPositionX(),graph.GetNode(12)->GetPositionY(),graph.GetNode(17)->GetPositionX(), graph.GetNode(17)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(17), graph.GetNodeID(22), abs((int)GetDistance(graph.GetNode(22)->GetPositionX(),graph.GetNode(22)->GetPositionY(),graph.GetNode(17)->GetPositionX(), graph.GetNode(17)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(22), graph.GetNodeID(17), abs((int)GetDistance(graph.GetNode(22)->GetPositionX(),graph.GetNode(22)->GetPositionY(),graph.GetNode(17)->GetPositionX(), graph.GetNode(17)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(3), graph.GetNodeID(8), abs((int)GetDistance(graph.GetNode(3)->GetPositionX(),graph.GetNode(3)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(8), graph.GetNodeID(3), abs((int)GetDistance(graph.GetNode(3)->GetPositionX(),graph.GetNode(3)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(8), graph.GetNodeID(13), abs((int)GetDistance(graph.GetNode(8)->GetPositionX(),graph.GetNode(8)->GetPositionY(),graph.GetNode(13)->GetPositionX(), graph.GetNode(13)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(13), graph.GetNodeID(8), abs((int)GetDistance(graph.GetNode(8)->GetPositionX(),graph.GetNode(8)->GetPositionY(),graph.GetNode(13)->GetPositionX(), graph.GetNode(13)->GetPositionY())));	
	
	graph.AddEdge(graph.GetNodeID(13), graph.GetNodeID(18), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(18)->GetPositionX(), graph.GetNode(18)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(18), graph.GetNodeID(13), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(18)->GetPositionX(), graph.GetNode(18)->GetPositionY())));
	
	graph.AddEdge(graph.GetNodeID(18), graph.GetNodeID(23), abs((int)GetDistance(graph.GetNode(23)->GetPositionX(),graph.GetNode(23)->GetPositionY(),graph.GetNode(18)->GetPositionX(), graph.GetNode(18)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(23), graph.GetNodeID(18), abs((int)GetDistance(graph.GetNode(23)->GetPositionX(),graph.GetNode(23)->GetPositionY(),graph.GetNode(18)->GetPositionX(), graph.GetNode(18)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(4), graph.GetNodeID(9), abs((int)GetDistance(graph.GetNode(4)->GetPositionX(),graph.GetNode(4)->GetPositionY(),graph.GetNode(9)->GetPositionX(), graph.GetNode(9)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(9), graph.GetNodeID(4), abs((int)GetDistance(graph.GetNode(4)->GetPositionX(),graph.GetNode(4)->GetPositionY(),graph.GetNode(9)->GetPositionX(), graph.GetNode(9)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(9), graph.GetNodeID(14), abs((int)GetDistance(graph.GetNode(9)->GetPositionX(),graph.GetNode(9)->GetPositionY(),graph.GetNode(14)->GetPositionX(), graph.GetNode(14)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(14), graph.GetNodeID(9), abs((int)GetDistance(graph.GetNode(9)->GetPositionX(),graph.GetNode(9)->GetPositionY(),graph.GetNode(14)->GetPositionX(), graph.GetNode(14)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(14), graph.GetNodeID(19), abs((int)GetDistance(graph.GetNode(14)->GetPositionX(),graph.GetNode(14)->GetPositionY(),graph.GetNode(19)->GetPositionX(), graph.GetNode(19)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(19), graph.GetNodeID(14), abs((int)GetDistance(graph.GetNode(14)->GetPositionX(),graph.GetNode(14)->GetPositionY(),graph.GetNode(19)->GetPositionX(), graph.GetNode(19)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(19), graph.GetNodeID(24), abs((int)GetDistance(graph.GetNode(24)->GetPositionX(),graph.GetNode(24)->GetPositionY(),graph.GetNode(19)->GetPositionX(), graph.GetNode(19)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(24), graph.GetNodeID(19), abs((int)GetDistance(graph.GetNode(24)->GetPositionX(),graph.GetNode(24)->GetPositionY(),graph.GetNode(19)->GetPositionX(), graph.GetNode(19)->GetPositionY())));

	//DIAGONAL EDGES

	graph.AddEdge(graph.GetNodeID(0), graph.GetNodeID(6), abs((int)GetDistance(graph.GetNode(0)->GetPositionX(),graph.GetNode(0)->GetPositionY(),graph.GetNode(6)->GetPositionX(), graph.GetNode(6)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(6), graph.GetNodeID(0), abs((int)GetDistance(graph.GetNode(0)->GetPositionX(),graph.GetNode(0)->GetPositionY(),graph.GetNode(6)->GetPositionX(), graph.GetNode(6)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(5), graph.GetNodeID(1), abs((int)GetDistance(graph.GetNode(5)->GetPositionX(),graph.GetNode(5)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(1), graph.GetNodeID(5), abs((int)GetDistance(graph.GetNode(5)->GetPositionX(),graph.GetNode(5)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(1), graph.GetNodeID(7), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(7), graph.GetNodeID(1), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(1)->GetPositionX(), graph.GetNode(1)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(6), graph.GetNodeID(2), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(2)->GetPositionX(), graph.GetNode(2)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(2), graph.GetNodeID(6), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(2)->GetPositionX(), graph.GetNode(2)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(2), graph.GetNodeID(8), abs((int)GetDistance(graph.GetNode(2)->GetPositionX(),graph.GetNode(2)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(8), graph.GetNodeID(2), abs((int)GetDistance(graph.GetNode(2)->GetPositionX(),graph.GetNode(2)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(7), graph.GetNodeID(3), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(3)->GetPositionX(), graph.GetNode(3)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(3), graph.GetNodeID(7), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(3)->GetPositionX(), graph.GetNode(3)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(3), graph.GetNodeID(9), abs((int)GetDistance(graph.GetNode(3)->GetPositionX(),graph.GetNode(3)->GetPositionY(),graph.GetNode(9)->GetPositionX(), graph.GetNode(9)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(9), graph.GetNodeID(3), abs((int)GetDistance(graph.GetNode(3)->GetPositionX(),graph.GetNode(3)->GetPositionY(),graph.GetNode(9)->GetPositionX(), graph.GetNode(9)->GetPositionY())));
	
	graph.AddEdge(graph.GetNodeID(8), graph.GetNodeID(4), abs((int)GetDistance(graph.GetNode(4)->GetPositionX(),graph.GetNode(4)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(4), graph.GetNodeID(8), abs((int)GetDistance(graph.GetNode(4)->GetPositionX(),graph.GetNode(4)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));


	graph.AddEdge(graph.GetNodeID(5), graph.GetNodeID(11), abs((int)GetDistance(graph.GetNode(5)->GetPositionX(),graph.GetNode(5)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(11), graph.GetNodeID(5), abs((int)GetDistance(graph.GetNode(5)->GetPositionX(),graph.GetNode(5)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(10), graph.GetNodeID(6), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(10)->GetPositionX(), graph.GetNode(10)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(6), graph.GetNodeID(10), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(10)->GetPositionX(), graph.GetNode(10)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(6), graph.GetNodeID(12), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(12), graph.GetNodeID(6), abs((int)GetDistance(graph.GetNode(6)->GetPositionX(),graph.GetNode(6)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(11), graph.GetNodeID(7), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(7), graph.GetNodeID(11), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));


	graph.AddEdge(graph.GetNodeID(7), graph.GetNodeID(13), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(13)->GetPositionX(), graph.GetNode(13)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(13), graph.GetNodeID(7), abs((int)GetDistance(graph.GetNode(7)->GetPositionX(),graph.GetNode(7)->GetPositionY(),graph.GetNode(13)->GetPositionX(), graph.GetNode(13)->GetPositionY())));
	
	graph.AddEdge(graph.GetNodeID(12), graph.GetNodeID(8), abs((int)GetDistance(graph.GetNode(12)->GetPositionX(),graph.GetNode(12)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(8), graph.GetNodeID(12), abs((int)GetDistance(graph.GetNode(12)->GetPositionX(),graph.GetNode(12)->GetPositionY(),graph.GetNode(8)->GetPositionX(), graph.GetNode(8)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(8), graph.GetNodeID(14), abs((int)GetDistance(graph.GetNode(8)->GetPositionX(),graph.GetNode(8)->GetPositionY(),graph.GetNode(14)->GetPositionX(), graph.GetNode(14)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(14), graph.GetNodeID(8), abs((int)GetDistance(graph.GetNode(8)->GetPositionX(),graph.GetNode(8)->GetPositionY(),graph.GetNode(14)->GetPositionX(), graph.GetNode(14)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(13), graph.GetNodeID(9), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(9)->GetPositionX(), graph.GetNode(9)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(9), graph.GetNodeID(13), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(9)->GetPositionX(), graph.GetNode(9)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(10), graph.GetNodeID(16), abs((int)GetDistance(graph.GetNode(10)->GetPositionX(),graph.GetNode(10)->GetPositionY(),graph.GetNode(16)->GetPositionX(), graph.GetNode(16)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(16), graph.GetNodeID(10), abs((int)GetDistance(graph.GetNode(10)->GetPositionX(),graph.GetNode(10)->GetPositionY(),graph.GetNode(16)->GetPositionX(), graph.GetNode(16)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(15), graph.GetNodeID(11), abs((int)GetDistance(graph.GetNode(15)->GetPositionX(),graph.GetNode(15)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(11), graph.GetNodeID(15), abs((int)GetDistance(graph.GetNode(15)->GetPositionX(),graph.GetNode(15)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(11), graph.GetNodeID(17), abs((int)GetDistance(graph.GetNode(17)->GetPositionX(),graph.GetNode(17)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(17), graph.GetNodeID(11), abs((int)GetDistance(graph.GetNode(17)->GetPositionX(),graph.GetNode(17)->GetPositionY(),graph.GetNode(11)->GetPositionX(), graph.GetNode(11)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(16), graph.GetNodeID(12), abs((int)GetDistance(graph.GetNode(16)->GetPositionX(),graph.GetNode(16)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(12), graph.GetNodeID(16), abs((int)GetDistance(graph.GetNode(16)->GetPositionX(),graph.GetNode(16)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(12), graph.GetNodeID(18), abs((int)GetDistance(graph.GetNode(18)->GetPositionX(),graph.GetNode(18)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(18), graph.GetNodeID(12), abs((int)GetDistance(graph.GetNode(18)->GetPositionX(),graph.GetNode(18)->GetPositionY(),graph.GetNode(12)->GetPositionX(), graph.GetNode(12)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(13), graph.GetNodeID(17), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(17)->GetPositionX(), graph.GetNode(17)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(17), graph.GetNodeID(13), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(17)->GetPositionX(), graph.GetNode(17)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(13), graph.GetNodeID(19), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(19)->GetPositionX(), graph.GetNode(19)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(19), graph.GetNodeID(13), abs((int)GetDistance(graph.GetNode(13)->GetPositionX(),graph.GetNode(13)->GetPositionY(),graph.GetNode(19)->GetPositionX(), graph.GetNode(19)->GetPositionY())));

	graph.AddEdge(graph.GetNodeID(18), graph.GetNodeID(14), abs((int)GetDistance(graph.GetNode(18)->GetPositionX(),graph.GetNode(18)->GetPositionY(),graph.GetNode(14)->GetPositionX(), graph.GetNode(14)->GetPositionY())));
	graph.AddEdge(graph.GetNodeID(14), graph.GetNodeID(18), abs((int)GetDistance(graph.GetNode(18)->GetPositionX(),graph.GetNode(18)->GetPositionY(),graph.GetNode(14)->GetPositionX(), graph.GetNode(14)->GetPositionY())));

	
	Event events;
	bool move = true;
	bool pressed = false;
	
	graph.PrintHValue();
	graph.PrintGValue();
	bool search = false;
	
	
	int source, target;
	bool takesource = true;
	bool taketarget = false;

	while(win.IsOpened())
	{
		while(win.GetEvent(events))
		{
			if((events.Type == Event::KeyPressed) && events.Key.Code == Key::Escape)
			{
				win.Close();
			}
			if((events.Type == Event::Closed))
			{
				win.Close();
			}
		}
		win.Clear();
		if(win.GetInput().IsKeyDown(Key::A))
		{
			//	graph.Clear();
			
			
			/*for(int i = 0; i<test.size(); i++)
			{
				cout<<test[i]<<endl;
			}*/
		}
		if(win.GetInput().IsKeyDown(Key::B) && !search) 
		{
			cin>>source;
			cin>>target;
			graph.CalculateHValue(graph.GetNode(target));
			graph.AStarSearch(graph.GetNode(source), graph.GetNode(target));
			search = true;
		}
//		if(!win.GetInput().IsKeyDown(Key::B)) search = false;
		if(win.GetInput().IsKeyDown(Key::Space) && search == true)
		{
			float targetx, targety;
			float velocityx, velocityy;
			float differenceAngle;
			for(int i = 0; i<graph.GetAStarPath().size(); i++)
			{
				targetx = graph.GetAStarPath()[i]->GetPositionX();
				targety = graph.GetAStarPath()[i]->GetPositionY();
				if(box.GetX() <=targetx || box.GetY()<= targety ||box.GetX() >=targetx || box.GetY()>= targety)
				{
					float differenceX = targetx - box.GetX();
					float differenceY = targety - box.GetY();
					differenceAngle = atan2(differenceY, differenceX); // in radians
					velocityx = cos(differenceAngle) * 10; // 100 is the speed you want to move towards the target point
					velocityy = sin(differenceAngle) * 10;
				}
				
				if(targetx>box.GetX())
				{
				while(box.GetX() <= targetx)
				{
					box.Move(velocityx, velocityy, &win);
				}//box.SetPos(graph.GetAStarPath()[i]->GetPositionX(), graph.GetAStarPath()[i]->GetPositionY());
				}
				else if(targetx<box.GetX())
				{
					while(box.GetX() >= targetx)
				{
					box.Move(velocityx, velocityy, &win);
				}//box.SetPos(graph.GetAStarPath()[i]->GetPositionX(), graph.GetAStarPath()[i]->GetPositionY());
				}
				else if(targety>box.GetY())
				{
					cout<<"TEST2";
				while(box.GetY() <= targety)
				{
					cout<<"TEST";
					box.Move(velocityx, velocityy, &win);
				}
				}
				else if(targety<box.GetY())
				{
					cout<<"TEST2";
				while(box.GetY() >= targety)
				{
					cout<<"TEST";
					box.Move(velocityx, velocityy, &win);
				}
				}
			
			}
		}
		if(win.GetInput().IsMouseButtonDown(Mouse::Button::Left) && pressed == false)
		{	
			pressed = true;
			if(takesource)
			{
				for(int i = 0; i<(int)graph.GetNodeList().size(); i++)
				{
					if(win.GetInput().GetMouseX()>=(graph.GetNodeList()[i]->GetPositionX() - graph.GetNodeList()[i]->GetSizeX()/2) && win.GetInput().GetMouseX()<=(graph.GetNodeList()[i]->GetPositionX() + graph.GetNodeList()[i]->GetSizeX()/2) &&
						win.GetInput().GetMouseY()>=(graph.GetNodeList()[i]->GetPositionY() - graph.GetNodeList()[i]->GetSizeY()/2) && win.GetInput().GetMouseY()<=(graph.GetNodeList()[i]->GetPositionY() + graph.GetNodeList()[i]->GetSizeY()/2)
						)
					{
						source = graph.GetNodeList()[i]->GetID();
						takesource = false;
						taketarget = true;
					}
				
				}
			}
			else if(taketarget)
			{
				for(int i = 0; i<(int)graph.GetNodeList().size(); i++)
				{
					if(win.GetInput().GetMouseX()>=(graph.GetNodeList()[i]->GetPositionX() - graph.GetNodeList()[i]->GetSizeX()/2) && win.GetInput().GetMouseX()<=(graph.GetNodeList()[i]->GetPositionX() + graph.GetNodeList()[i]->GetSizeX()/2) &&
						win.GetInput().GetMouseY()>=(graph.GetNodeList()[i]->GetPositionY() - graph.GetNodeList()[i]->GetSizeY()/2) && win.GetInput().GetMouseY()<=(graph.GetNodeList()[i]->GetPositionY() + graph.GetNodeList()[i]->GetSizeY()/2)
						)
					{
						target = graph.GetNodeList()[i]->GetID();
						takesource = true;
						taketarget = false;
					}
				}

				graph.CalculateHValue(graph.GetNode(target));
				graph.AStarSearch(graph.GetNode(source), graph.GetNode(target));
				search = true;
			}
			
		}
		if(!win.GetInput().IsMouseButtonDown(Mouse::Button::Left) && pressed == true)
		{	

			//graph.AddNode((float)win.GetInput().GetMouseX(), (float)win.GetInput().GetMouseY());
			pressed = false;
		}

		
		graph.DrawNodes(&win);
		graph.DrawEdges(&win);
		
		/*if(search == true)
		{
			for(int i = 0; i<graph.GetAStarPath().size(); i++)
			{
				Path[i] = graph.GetAStarPath()[i];
			}
		}*/

		box.Draw(&win);
		win.Display();
	}
}