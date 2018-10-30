#pragma once
class Point
{
private:
	double x;
	double y;
public:

	Point();
	Point(double x, double y);
	inline void SetY(double y) { this->y = y; }
	inline void SetX(double x) { this->x = x; }
	inline double GetX() { return x; }
	inline double GetY() { return y; }
	double CalcDistance(const Point* p)const;		// ¡Ωµ„º‰æ‡¿Î
	~Point();
};

