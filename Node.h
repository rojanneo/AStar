#ifndef NODE_H_
#define NODE_H_
#include <SFML\Graphics.hpp>
#include "BaseNode.h"
#include <iostream>
using namespace sf;
class Node:public BaseNode
{
private:
	Image m_nodeImage;
	Sprite m_nodeSprite;
	float m_nodePositionX;
	float m_nodePositionY;
	static int m_nodeIndex;
	bool m_walkable;
		//m_nodeIndex = 0;
public:
	Node(int idx, float x, float y, bool walkable = true):BaseNode(idx)
	{
		m_nodeImage.LoadFromFile("node.png");
		m_nodeSprite.SetImage(m_nodeImage);
		m_nodePositionX = x;
		m_nodePositionY = y;
		m_nodeSprite.SetPosition(m_nodePositionX, m_nodePositionY);
		m_nodeSprite.SetCenter((float)m_nodeImage.GetWidth()/2, (float)m_nodeImage.GetHeight()/2);
		m_nodeIndex++;
		m_walkable = walkable;
	}
	float GetSizeX()
	{
		return m_nodeSprite.GetSize().x;
	}

	float GetSizeY()
	{
		return m_nodeSprite.GetSize().y;
	}
	float GetPositionX()
	{
		return m_nodePositionX;
	}
	float GetPositionY()
	{
		return m_nodePositionY;
	}
	
	static int GetNextValidIndex()
	{
		return m_nodeIndex;
	}
	void Draw(RenderWindow *win)
	{
		win->Draw(m_nodeSprite);
	}

	bool IsWalkable()
	{
		return m_walkable;
	}
};

int Node::m_nodeIndex = 0;
#endif