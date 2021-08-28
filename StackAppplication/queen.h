#pragma once
struct Queen {
	int x, y; //棋盘上的坐标位置
	Queen(int xx = 0, int yy = 0) :x(xx), y(yy) {};
	bool operator==(Queen const& q) const
	{
		return (x == q.x) || (y == q.y) || (x + y == q.x + q.y) || (x - y == q.x - q.y);

	}

	bool operator !=(Queen const& q) const
	{
		return !(*this == q);   //重载！操作符

	}
	
	
};