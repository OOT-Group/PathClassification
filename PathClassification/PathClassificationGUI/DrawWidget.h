#pragma once
#include <QtWidgets>
#include <vector>
#include <qpoint.h>
#include <qpainter.h>
#include <stack>
#include <set>
#include "IClassfyAlgo.h"
#include "Judge.h"
#pragma comment(lib, "PathClassificationAlgo.lib")
enum PaintType
{
	Normal,
	Undo,
	Clear,
	Classify,
};
class DrawWidget:public QWidget
{
	Q_OBJECT
public:
	DrawWidget(QWidget *parent = Q_NULLPTR);
	void Init();
	~DrawWidget();
protected:
	int hexColor = 0x00000F;
	PaintType paintType = PaintType::Normal;
	bool beginDraw = false;
	bool classified = false;
	std::vector<QPoint> points;
	std::vector<std::vector<QPoint>> routes;

	std::vector<Point> alPoints;
	std::vector<Route> alRoutes;
	std::set<int> routesTypes;
	int distanceParam = 50;
	double bendParam = 0.5;


	int routesNum;
	std::vector<QPoint> drawPoints;
	QPixmap pixmap;
	QPixmap tempPix;
	std::stack<QPixmap> undoPixList;
	
	std::vector<Qt::GlobalColor> colors;

	QPen pen;
	void mousePressEvent(QMouseEvent * ent);
	void mouseMoveEvent(QMouseEvent* ent);
	void mouseReleaseEvent(QMouseEvent* ent);
	void paintEvent(QPaintEvent *ent);
	public slots:
	void Clear();
	void Undo();
	void Classify();
signals:
	void EmitTypes(int types);
public:
	void UpdateDistance(int dis);
	void UpdateBend(double bend);
private:
	void DrawUndo();
	void DrawNormal();
	void DrawClear();
	void DrawClassify();
};

