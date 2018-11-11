#include "DrawWidget.h"






DrawWidget::DrawWidget(QWidget *parent) :QWidget(parent)
{

}



void DrawWidget::Init()
{

	int width = this->width();
	int height = this->height();
	pixmap = QPixmap(width, height);
	this->setStyleSheet("background:white;");
	pixmap.fill();
	routesNum = 0;
	pen.setColor(Qt::black);
	pen.setWidth(5);
	undoPixList.push(pixmap);

	colors.push_back(Qt::GlobalColor::black);
	colors.push_back(Qt::GlobalColor::red);
	colors.push_back(Qt::GlobalColor::blue);
	colors.push_back(Qt::GlobalColor::gray);
	colors.push_back(Qt::GlobalColor::yellow);
	colors.push_back(Qt::GlobalColor::green);
	colors.push_back(Qt::GlobalColor::darkYellow);
}

DrawWidget::~DrawWidget()
{
}

void DrawWidget::mousePressEvent(QMouseEvent * ent)
{
	if (ent->button() == Qt::LeftButton) {
		beginDraw = true;
	}
}

void DrawWidget::mouseMoveEvent(QMouseEvent * ent)
{
	if (beginDraw) {
		QPoint point = ent->pos();
		points.push_back(point);
		Point po(point.rx(), point.ry());
		alPoints.push_back(po);
		drawPoints.push_back(point);
		this->repaint();
	}
}

void DrawWidget::mouseReleaseEvent(QMouseEvent * ent)
{
	if (ent->button() == Qt::LeftButton) {
		beginDraw = false;
		routes.push_back(points);
		points.clear();
		undoPixList.push(pixmap);

		Route route;
		route.SetNum(routesNum);
		route.SetPoints(alPoints);
		alRoutes.push_back(route);
		alPoints.clear();
		routesNum++;
	}
}

void DrawWidget::paintEvent(QPaintEvent * ent)
{
	switch (this->paintType) {
	case PaintType::Normal:
		DrawNormal();
		break;
	case PaintType::Undo:
		DrawUndo();
		break;
	case PaintType::Clear:
		DrawClear();
		break;
	case PaintType::Classify:
		DrawClassify();
		break;
	}

}
void DrawWidget::Clear()
{
	if (undoPixList.size() >1) {
		this->paintType = PaintType::Clear;
		routes.clear();
		alRoutes.clear();
		routesNum = 0;
		while (undoPixList.size() != 1) {
			undoPixList.pop();
		}
		this->update();
	}
}

void DrawWidget::Undo()
{
	if (undoPixList.size() >1) {
		this->paintType = PaintType::Undo;
		routes.pop_back();
		alRoutes.pop_back();
		routesNum--;
		undoPixList.pop();
		this->update();
	}

}

void DrawWidget::Classify() {
	if (alRoutes.size() > 1) {
		while (undoPixList.size() != 1) {
			undoPixList.pop();
		}
		this->paintType = PaintType::Classify;
		IClassfyAlgo* algo = new Judge();
		algo->InitPara(50, 0.3);
		auto newRoutes = algo->ClassfyRoute(alRoutes);
		int num = newRoutes.size();
		alRoutes = newRoutes;
		this->update();
	}
}
void DrawWidget::DrawUndo()
{
	this->paintType = PaintType::Normal;
	pixmap = undoPixList.top();
	QPainter pain(this);
	pain.setPen(pen);
	pain.drawPixmap(0, 0, pixmap);

}
void DrawWidget::DrawNormal()
{

	if (beginDraw) {
		QPainter p(&pixmap);
		p.setPen(pen);



		////±ÜÃâ¶Ïµã
		if (!points.empty()) {
			if (points.size() > 1) {
				int last = points.size() - 1;
				p.drawLine(points[last - 1], points[last]);
			}
			else {
				p.drawPoint(points[0]);
			}
		}
		//if (!points.empty()) {
		//			int last = points.size() - 1;
		//			p.drawPoint(points[last]);
		//}

	}
	else {
		
	}
	QPainter pain(this);
	pain.setPen(pen);
	pain.drawPixmap(0, 0, pixmap);
}
void DrawWidget::DrawClear()
{
	this->paintType = PaintType::Normal;
	pixmap = undoPixList.top();
	QPainter pain(this);
	pain.setPen(pen);
	pain.drawPixmap(0, 0, pixmap);
}

void DrawWidget::DrawClassify()
{
	this->paintType = PaintType::Normal;
	pixmap= undoPixList.top();
	QPainter paint(&pixmap);
	QPen newpen;
	newpen.setWidth(5);
	for (int i = 0; i < alRoutes.size(); i++) {
		int flag=alRoutes[i].GetFlag();
		newpen.setColor(colors[flag]);
		paint.setPen(newpen);
		int num = alRoutes[i].GetNum();
		auto ps = routes[num];

		for (int l = 0; l < ps.size(); l++) {
			if (l >= 1) {
				paint.drawLine(ps[l - 1], ps[l]);
			}
			else {
				paint.drawPoint(ps[0]);
			}
		}
		
		

	}
	QPainter painter(this);
	painter.drawPixmap(0,0,pixmap);

	undoPixList.push(pixmap);

}


