#ifndef BASE_NODE_H_
#define BASE_NODE_H_
class BaseNode
{
private:
	int m_index;
public:
	BaseNode(int idx)
	{
		SetID(idx);
	}
	void SetID(int idx)
	{
		m_index = idx;
	}
	int GetID()
	{
		return m_index;
	}
};
#endif