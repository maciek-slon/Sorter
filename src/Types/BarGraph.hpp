/*
 * Line.hpp
 *
 *  Created on: 09-12-2010
 *      Author: mateusz
 */

#ifndef LINE_HPP_
#define LINE_HPP_

#include "Types/Drawable.hpp"

#include <cmath>

namespace Types {

class BarGraph: public Types::Drawable
{
public:
	BarGraph()
	{
		m_origin = cv::Point(0, 0);
		m_scale = 1;
		m_size = cv::Size(320, 240);

		m_values.push_back(10);
		m_values.push_back(30);
		m_values.push_back(20);
		m_values.push_back(15);
		m_values.push_back(3);

		m_top.push_back(12);
		m_top.push_back(40);
		m_top.push_back(45);
		m_top.push_back(15);
		m_top.push_back(10);
	}

	BarGraph(const BarGraph& o)
	{
		m_values = o.m_values;
		m_top = o.m_top;
		m_origin = o.m_origin;
		m_size = o.m_size;
		m_scale = o.m_scale;
	}

	virtual ~BarGraph()
	{
	}

	virtual BarGraph * clone()
	{
		return new BarGraph(*this);
	}

	virtual void draw(cv::Mat& image, cv::Scalar color, int offsetX = 0, int offsetY = 0)
	{
		int cnt = m_values.size();
		cv::Rect bar(m_origin, cv::Size(m_size.width / cnt, 0));
		cv::Point step(m_size.width / cnt, 0);
		for (size_t i = 0 ; i < cnt; ++i) {
			bar.height = m_scale * m_values[i];
			cv::rectangle(image, bar, color, CV_FILLED);
			cv::line(image, cv::Point(bar.x, bar.y+m_scale*m_top[i]), cv::Point(bar.x+step.x, bar.y+m_scale*m_top[i]), cv::Scalar(0, 0, 255));
			bar += step;
		}
	}


private:
	std::vector<float> m_values;
	std::vector<float> m_top;
	cv::Point m_origin;
	cv::Size m_size;
	float m_scale;
};

}

#endif /* LINE_HPP_ */
