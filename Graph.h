#include "Node.h"
#include "Edge.h"
#include "Box.h"
#include <vector>
#include <list>
#include <conio.h>
class Graph
{
private:
	Node* node;
	Edge* edge;
public:
	vector<Node*> nodeList;
	vector<Edge*> edgeList;
	vector<Node*> AStarPath;
	vector<Node*> expandedNodes;
	vector<Edge*> visitedEdges;
	vector<Node*> visitedNodes;
	vector<Edge*> pathEdges;
	vector<int> HValues;
	vector<int> FValues;
	list<int> Flist;
	Graph()
	{
	
	}
	void Initialize()
	{
		node = new Node(Node::GetNextValidIndex(),100, 100);
		nodeList.push_back(node);

	}
	void AddNode(float x, float y, bool walkable)
	{
		bool add = true;
		for(int i = 0; i<(int)nodeList.size(); i++)
		{
			if(nodeList[i]->GetPositionX() ==x && nodeList[i]->GetPositionY() == y)
			{
				add = false;
			}
		}
		if(add) 
		{
			node = new Node(Node::GetNextValidIndex(), x, y, walkable);
			cout<<node->GetID();
			nodeList.push_back(node);
		}
	}
	void AddNode(float x, float y)
	{
		bool add = true;
		for(int i = 0; i<(int)nodeList.size(); i++)
		{
			if(nodeList[i]->GetPositionX() ==x && nodeList[i]->GetPositionY() == y)
			{
				add = false;
			}
		}
		if(add) 
		{
			node = new Node(Node::GetNextValidIndex(), x, y);
			cout<<node->GetID();
			nodeList.push_back(node);
		}
	}

	Node* GetNode(int id)
	{
		for(int i = 0; i<(int)nodeList.size(); i++)
		{
			if(nodeList[i]->GetID() == id)
			{
				return nodeList[i];
			}
		}
		return NULL;
	}

	int GetNodeID(int x)
	{
		return nodeList[x]->GetID();
		
	}
	void AddEdge(int from, int to, int cost = 1)
	{
		if(cost == 1)
		edge = new Edge(from, to);
		else edge = new Edge(from, to, cost);
		edgeList.push_back(edge);
		

	}
	void DrawNodes(RenderWindow *win)
	{
		for(int i = 0; i<(int)nodeList.size(); i++)
		{
			nodeList[i]->Draw(win);
		}


	}
	void DrawEdges(RenderWindow *win)
	{
		for(int i = 0; i<(int)edgeList.size(); i++)
		{
			
			edgeList[i]->Draw(win, nodeList[edgeList[i]->GetFrom()]->GetPositionX(),nodeList[edgeList[i]->GetFrom()]->GetPositionY(), nodeList[edgeList[i]->GetTo()]->GetPositionX(),nodeList[edgeList[i]->GetTo()]->GetPositionY(),1);			
		}
		for(int i = 0; i<(int)pathEdges.size(); i++)
		{
			pathEdges[i]->Draw(win, nodeList[pathEdges[i]->GetFrom()]->GetPositionX(),nodeList[pathEdges[i]->GetFrom()]->GetPositionY(), nodeList[pathEdges[i]->GetTo()]->GetPositionX(),nodeList[pathEdges[i]->GetTo()]->GetPositionY(),2);
		}
	}

	void Clear()
	{
		nodeList.clear();
		edgeList.clear();
		//cout<<nodeList.size();
		//cout<<edgeList.size();
	}

	vector<Node*> GetAStarPath()
	{
		return AStarPath;
	}

	vector<Node*> GetNodeList()
	{
		return nodeList;
	}

	void AddPathEdge(int from, int to)
	{
		edge = new Edge(from, to);
		pathEdges.push_back(edge);
	}

	void AStarSearch(Node* source, Node* target)
	{
		//Edge* dummy;
		bool sort = false;
		bool visited = false;
		HValues.clear();
		HValues.empty();
		AStarPath.clear();
		AStarPath.empty();
		expandedNodes.clear();
		expandedNodes.empty();
		visitedNodes.clear();
		visitedNodes.empty();
		visitedEdges.clear();
		visitedEdges.empty();
		pathEdges.clear();
		if(source->GetID() != target->GetID())
		{
		//1. Put the source in the path list
		AStarPath.push_back(source);
		//cout<<AStarPath.back()->GetID();
		int br = 0;
		while(!AStarPath.empty())
		{
			
			//ADDING TO EXPANDED NODES
			for(int i = 0; i<(int)edgeList.size(); i++)
			{
				if(AStarPath.back()->GetID() == edgeList[i]->GetFrom())
				{
					//Checking if the to and from is same
					if(edgeList[i]->GetTo() != AStarPath.back()->GetID())
					{
						if(GetNode(edgeList[i]->GetTo())->IsWalkable())
						expandedNodes.push_back(GetNode(edgeList[i]->GetTo()));
					}
				}
				/*if(AStarPath.back()->GetID() == edgeList[i]->GetTo())
				{
					expandedNodes.push_back(GetNode(edgeList[i]->GetFrom()));
				}*/
			}

			

			//CHECKING IF THE NODES ARE ALREADY IN VISITED NODES
			for(int i = 0; i<(int)visitedNodes.size(); i++)
			{
				for(int j = 0; j<(int)expandedNodes.size(); j++)
				{
					if(visitedNodes[i]->GetID() == expandedNodes[j]->GetID())
					{
						expandedNodes.erase(expandedNodes.begin()+j);
					}
				}
			}

			for(int i = 0; i<(int)expandedNodes.size(); i++)
			{
				cout<<"NODE:"<<expandedNodes[i]->GetID()<<endl;
			}

			//Edge* edge;
			for(int i = 0; i<(int)expandedNodes.size(); i++)
			{
				for(int j = 0; j<(int)edgeList.size(); j++)
				{
					if(edgeList[j]->GetFrom() == AStarPath.back()->GetID() && edgeList[j]->GetTo() == expandedNodes[i]->GetID())
					{
						FValues.push_back(edgeList[j]->GetCost() + HValues[expandedNodes[i]->GetID()]);
					}
				}
			}

			int min;
			int minValue;
			min = expandedNodes[0]->GetID();
			minValue = FValues[0];
			for(int i = 0; i<(int)FValues.size(); i++)
			{
				
				if(FValues[i]<minValue)
				{
					min = expandedNodes[i]->GetID();
					minValue = FValues[i];
				}
			}

			AStarPath.push_back(GetNode(min));
			for(int i = 0; i<(int)expandedNodes.size(); i++)
			{
				if(expandedNodes[i]->GetID()!=AStarPath.back()->GetID())
				{
					visitedNodes.push_back(expandedNodes[i]);
				}
			}
			cout<<"H VALUE 9"<<HValues[9];
			cout<<"SELECTED NODE:"<<AStarPath.back()->GetID()<<endl<<"VAL"<<minValue;
			expandedNodes.empty();
			expandedNodes.clear();
			FValues.clear();
			FValues.empty();
			for(int i = 0; i<(int)visitedNodes.size(); i++)
			{
				cout<<"VNODE:"<<visitedNodes[i]->GetID()<<endl;
			}
			
			for(int i = 0; i<(int)AStarPath.size()-1; i++)
			{
				AddPathEdge(AStarPath[i]->GetID(), AStarPath[i+1]->GetID());
			
			}
			if(AStarPath.back()->GetID() == target->GetID())
			{
				break;
				HValues.clear();
			}
			//break;
			//_getch();
		}
		}
		else
		{
			cout<<"SOURCE and TARGET is Same";
		}
	}
	void CalculateHValue(Node* target)
	{

		for(int i = 0; i<(int)nodeList.size(); i++)
		{
			int H = abs((int)GetHeuristic(nodeList[i]->GetPositionX(),nodeList[i]->GetPositionY(),target->GetPositionX(), target->GetPositionY()));
			HValues.push_back(H);
			cout<<i<<":"<<H;
		}
	}
	float GetHeuristic(float x1, float y1, float x2, float y2)
	{
		float dist;
		dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
		return dist;
	}
	void PrintHValue()
	{
		for(int i = 0; i<(int)HValues.size(); i++)
		{
			cout<<i<<":"<<HValues[i]<<endl;
		}


	}
	void PrintGValue()
	{
		for(int i = 0; i<(int)edgeList.size(); i++)
		{
			cout<<edgeList[i]->GetFrom()<<":"<<edgeList[i]->GetTo()<<":"<<edgeList[i]->GetCost()<<endl;
		}


	}
};