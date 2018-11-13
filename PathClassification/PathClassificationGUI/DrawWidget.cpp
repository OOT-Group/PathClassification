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
	tempPix = pixmap;
	routesNum = 0;
	pen.setColor(Qt::black);
	pen.setWidth(5);
	pen.setCapStyle(Qt::RoundCap);
	undoPixList.push(pixmap);

	colors.push_back(Qt::GlobalColor::black);
	colors.push_back(Qt::GlobalColor::red);
	colors.push_back(Qt::GlobalColor::blue);
	colors.push_back(Qt::GlobalColor::gray);
	colors.push_back(Qt::GlobalColor::yellow);
	colors.push_back(Qt::GlobalColor::green);
	colors.push_back(Qt::GlobalColor::darkYellow);
	colors.push_back(Qt::GlobalColor::darkRed);
	colors.push_back(Qt::GlobalColor::darkGreen);
	colors.push_back(Qt::GlobalColor::darkBlue);
	colors.push_back(Qt::GlobalColor::darkCyan);
	colors.push_back(Qt::GlobalColor::darkMagenta);

	/*for (int i = 4; i < 19; i++) {
		colors.push_back(Qt::GlobalColor(i));
	}*/
}

DrawWidget::~DrawWidget()
{
}

void DrawWidget::mousePressEvent(QMouseEvent * ent)
{
	if (ent->button() == Qt::LeftButton && !classified) {
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
		classified = false;
		this->update();
	}
}

void DrawWidget::Undo()
{
	if (undoPixList.size() >1 && !classified) {
		this->paintType = PaintType::Undo;
			routes.pop_back();
			alRoutes.pop_back();
			routesNum--;
		undoPixList.pop();
		this->update();
	}

}

void DrawWidget::Classify() {
	if (alRoutes.size() > 1 && !classified) {
		
		this->paintType = PaintType::Classify;
		IClassfyAlgo* algo = new Judge();
		algo->InitPara(distanceParam, bendParam);
		auto newRoutes = algo->ClassfyRoute(alRoutes);

		routesTypes.clear();
		for each (auto r in newRoutes)
		{
			routesTypes.insert(r.GetFlag());
		}
		emit EmitTypes(routesTypes.size());
		int num = newRoutes.size();
		alRoutes = newRoutes;
		classified = true;
		this->update();
	}
}
void DrawWidget::UpdateDistance(int dis)
{
	this->distanceParam = dis;
}
void DrawWidget::UpdateBend(double bend)
{
	this->bendParam = bend;
}
void DrawWidget::DrawUndo()
{
	this->paintType = PaintType::Normal;
	pixmap = undoPixList.top();
	QPainter pain(this);
	pain.setRenderHint(QPainter::Antialiasing, true);
	pain.setPen(pen);
	pain.drawPixmap(0, 0, pixmap);

}
void DrawWidget::DrawNormal()
{

	if (beginDraw) {
		QPainter p(&pixmap);
		p.setRenderHint(QPainter::Antialiasing, true);
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
	pain.setRenderHint(QPainter::Antialiasing, true);
	pain.setPen(pen);
	pain.drawPixmap(0, 0, pixmap);
}
void DrawWidget::DrawClear()
{
	this->paintType = PaintType::Normal;
	pixmap = undoPixList.top();
	QPainter pain(this);
	pain.setRenderHint(QPainter::Antialiasing, true);
	pain.setPen(pen);
	pain.drawPixmap(0, 0, pixmap);
}

void DrawWidget::DrawClassify()
{
	this->paintType = PaintType::Normal;
	pixmap= tempPix;
	QPainter paint(&pixmap);
	QPen newpen;
	newpen.setWidth(5);
	newpen.setCapStyle(Qt::RoundCap);
	paint.setRenderHint(QPainter::Antialiasing, true);
	for (int i = 0; i < alRoutes.size(); i++) {
		int flag=alRoutes[i].GetFlag();
		/*QColor color;
		auto colorStr="#"+QString("%1").arg((hexColor+flag*0x3300)%0xFFFFFF, 6, 16, QLatin1Char('0'));
		color.setNamedColor(colorStr);*/
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
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.drawPixmap(0,0,pixmap);

	undoPixList.push(pixmap);

}


