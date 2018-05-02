#include "port_ui.h"
#include "style.h"
#include <QPainter>
#include <QPainterPath>
#include <QApplication>
#include "graph_ui.h"

PortBaseUI::PortBaseUI(const std::string name, QWidget *parent)
	: QWidget(parent), label(name.c_str(), parent), p(parent)
{
	resize(Style::PortSize + 2, Style::PortSize + 2);

	show();
	label.show();

	setMouseTracking(true);
}

InPortUI::InPortUI(const InPortUI &other) : InPortUI(other, other.p) { }

InPortUI::InPortUI(const InPort &p, QWidget *parent)
	: InPort(p), PortBaseUI(p.name, parent) {
	Move(0, 0);
}

void InPortUI::mouseMoveEvent(QMouseEvent *event)
{
	static_cast<GraphUI&>(this->block.graph).hoverConnectionUI(event->pos() + pos());
	PortBaseUI::mouseMoveEvent(event);
}

OutPortUI::OutPortUI(const OutPortUI &other) : OutPortUI(other, other.p) { }

OutPortUI::OutPortUI(const OutPort &p, QWidget *parent)
	: OutPort(p), PortBaseUI(p.name, parent) {
	Move(0, 0);
}

void OutPortUI::mouseMoveEvent(QMouseEvent *event)
{
	static_cast<GraphUI&>(this->block.graph).hoverConnectionUI(event->pos() + pos());
	PortBaseUI::mouseMoveEvent(event);
}

int PortBaseUI::getWidth() const{
	return Style::PortNamePadding * 2 + QApplication::fontMetrics().width(label.text());
}

void InPortUI::Move(int x, int y)
{
	move(x - Style::PortSize/2 - 1, y - Style::PortSize/2 - 1);
	label.move(x + Style::PortNamePadding, y - label.height() / 2);

	GraphUI &g = static_cast<GraphUI&>(this->block.graph);
	g.updateConnectionUI(*this);
}

void OutPortUI::Move(int x, int y)
{
	move(x - Style::PortSize/2 - 1, y - Style::PortSize/2 - 1);
	label.move(x - Style::PortNamePadding - label.width(), y - label.height() / 2);

	GraphUI &g = static_cast<GraphUI&>(this->block.graph);
	g.updateConnectionUI(*this);
}

void PortBaseUI::paintEvent(QPaintEvent *event)
{
	(event);
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.setPen(Style::PortOutlineCol);
	if(hover){
		painter.setBrush(Style::PortHoverCol); //hover
	} else {
		painter.setBrush(Style::PortFreeCol); //free
	}
	painter.drawEllipse(QPoint((Style::PortSize/2 + 1), (Style::PortSize/2 + 1)),
						Style::PortDrawSize/2, Style::PortDrawSize/2);
}

void PortBaseUI::mouseMoveEvent(QMouseEvent *event)
{
	QPoint diff = (event->pos() - QPoint(Style::PortSize/2, Style::PortSize/2));
	int dist = sqrt(diff.x()*diff.x() + diff.y()*diff.y());
	hover = (dist <= Style::PortSize/2);
	update();
}

void PortBaseUI::leaveEvent(QEvent *event)
{
	(event);
	hover = false;
	update();
}

QPoint PortBaseUI::Pos()
{
	return QPoint(pos().x() + Style::PortSize/2 + 1, pos().y() + Style::PortSize/2 + 1);
}

void PortBaseUI::mouseReleaseEvent(QMouseEvent *event)
{
	(event);
}
