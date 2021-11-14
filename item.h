#pragma once
enum class Line { START, AFTER_FIRST, AFTER_SECOND, AFTER_THIRD };
class Item
{
private:
	int m_size;
	int m_x;
	int m_temp;
	Line m_line;

public: 
	Item() {};
	Item(int size, int x, int temp , Line line);

	/// get function
	Line getLine() { return m_line; }
	int getSize() { return m_size; }
	int getNum() { return m_x; }
	int getTemp() { return m_temp; }

	/// set function
	void setLine(Line line) {  m_line = line; }
	void setSize(int size) { m_size = size; }
	void setTemp(int temp) {  m_temp = temp; }
	void setAll(int size, int x, int temp, Line line) { m_size = size, m_x = x, m_temp = temp, m_line = line; };
};

