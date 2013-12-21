#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Edge
{
private:
	int m_from;
	int m_to;
	int m_cost;
public:
	Edge(int from, int to, int cost = 1)
	{
		m_from = from;
		m_to = to;
		m_cost = cost;
	}

	int GetFrom()
	{
		return m_from;
	}
	int GetTo()
	{
		return m_to;
	}
	int GetCost()
	{
		return m_cost;
	}
	void Draw(RenderWindow *win, float x1, float y1, float x2, float y2, int c)
	{
		if(c == 1)
		{
			win->Draw(Shape::Line(x1, y1, x2, y2, 5, Color(Color::Blue)));
		}
		else if(c == 2)
		{
			win->Draw(Shape::Line(x1, y1, x2, y2, 5, Color(Color::Red)));
		}
	}


};