#ifndef BOX_H_
#define BOX_H_
//#include "Graph.h"
#include <SFML\Graphics.hpp>

using namespace sf;

class Box
{
private:
	Image m_boxImg;
	Sprite m_boxSp;
	//float m_positionX;
	//float m_positionY;
public:
	Box(float x, float y)
	{
		m_boxImg.LoadFromFile("box.png");
		m_boxSp.SetImage(m_boxImg);
		m_boxSp.SetCenter((float)m_boxImg.GetWidth()/2, (float)m_boxImg.GetHeight()/2);
		m_boxSp.SetPosition(x, y);
	}

	float GetX()
	{
		return m_boxSp.GetPosition().x;
	}
	float GetY()
	{
		return m_boxSp.GetPosition().y;
	}
	void Move(float x, float y, RenderWindow *win)
	{
		m_boxSp.Move(x*win->GetFrameTime(), y * win->GetFrameTime());
	}
	void SetPos(float x, float y)
	{
		m_boxSp.SetPosition(x,y);
	}

	void Draw(RenderWindow *win)
	{
		win->Draw(m_boxSp);
	}
};

#endif