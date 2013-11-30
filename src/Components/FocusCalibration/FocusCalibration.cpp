/*!
 * \file
 * \brief
 * \author Maciej Stefanczyk
 */

#include <memory>
#include <string>

#include "FocusCalibration.hpp"
#include "Common/Logger.hpp"

#include <boost/bind.hpp>

namespace Processors {
namespace FocusCalibration {

FocusCalibration::FocusCalibration(const std::string & name) :
		Base::Component(name) , 
		sections("sections"),
		line_from("line.from"),
		line_to("line.to") {
		registerProperty(sections);
		registerProperty(line_from);
		registerProperty(line_to);

}

FocusCalibration::~FocusCalibration() {
}

void FocusCalibration::prepareInterface() {
	// Register data streams, events and event handlers HERE!
registerStream("in_img", &in_img);
registerStream("out_mtf", &out_mtf);
	// Register handlers
	h_onNewImage.setup(boost::bind(&FocusCalibration::onNewImage, this));
	registerHandler("onNewImage", &h_onNewImage);
	addDependency("onNewImage", &in_img);

}

bool FocusCalibration::onInit() {

	return true;
}

bool FocusCalibration::onFinish() {
	return true;
}

bool FocusCalibration::onStop() {
	return true;
}

bool FocusCalibration::onStart() {
	return true;
}

void FocusCalibration::onNewImage() {
	out_mtf.write(Types::BarGraph);
}



} //: namespace FocusCalibration
} //: namespace Processors
