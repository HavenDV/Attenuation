/*
 * Line.cpp
 *
 *  Created on: 2016. nov. 4.
 *      Author: Laszlo Lazar
 */

#include "Line.h"

#include "CVector2D.h"

namespace geom {

Line::Line() {


}

Line::~Line() {

}

bool Line::intersect(const Line &line, std::vector<CVector2D> &intersection_points)
{
	CVector2D b;
	b.x = point.cross(direction); //direction.y * point.x - direction.x * point.y;
	b.y = line.getPoint().cross(line.getDirection()); //line.getPoint().y * line.getPoint().x - line.direction.x * line.point.y;
	double det;
	CVector2D result;
	det = direction.cross(line.getDirection());
	if (!NumericComparator::EssentiallyEqual(det, 0.0)) {	
		result.x = (-b.x * line.getDirection().x + direction.x * b.y) / det;
		result.y = (direction.y * b.y - b.x * line.getDirection().y) / det;
		intersection_points.push_back(result);
		return true;
	}
	return false;
}

}
