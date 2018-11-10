#pragma once
#include <QtWidgets>
#include <vector>
#include <qpoint.h>
#include <qpainter.h>
#include <stack>

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
	PaintType paintType = PaintType::Normal;
	bool beginDraw = false;
	std::vector<QPoint> points;
	std::vector<std::vector<QPoint>> routes;

	std::vector<Point> alPoints;
	std::vector<Route> alRoutes;

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
private:
	void DrawUndo();
	void DrawNormal();
	void DrawClear();
	void DrawClassify();
};

