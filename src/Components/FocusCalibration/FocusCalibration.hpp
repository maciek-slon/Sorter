/*!
 * \file
 * \brief 
 * \author Maciej Stefanczyk
 */

#ifndef FOCUSCALIBRATION_HPP_
#define FOCUSCALIBRATION_HPP_

#include "Component_Aux.hpp"
#include "Component.hpp"
#include "DataStream.hpp"
#include "Property.hpp"
#include "EventHandler2.hpp"

#include <opencv2/opencv.hpp>

#include "Types/BarGraph.hpp"

#include "Types/MatrixTranslator.hpp"

namespace Processors {
namespace FocusCalibration {

/*!
 * \class FocusCalibration
 * \brief FocusCalibration processor class.
 *
 * FocusCalibration processor.
 */
class FocusCalibration: public Base::Component {
public:
	/*!
	 * Constructor.
	 */
	FocusCalibration(const std::string & name = "FocusCalibration");

	/*!
	 * Destructor
	 */
	virtual ~FocusCalibration();

	/*!
	 * Prepare components interface (register streams and handlers).
	 * At this point, all properties are already initialized and loaded to 
	 * values set in config file.
	 */
	void prepareInterface();

protected:

	/*!
	 * Connects source to given device.
	 */
	bool onInit();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	bool onFinish();

	/*!
	 * Start component
	 */
	bool onStart();

	/*!
	 * Stop component
	 */
	bool onStop();


	// Input data streams

	Base::DataStreamIn<cv::Mat> in_img;

	// Output data streams

	Base::DataStreamOut<Types::BarGraph> out_mtf;

	// Handlers
	Base::EventHandler2 h_onNewImage;
	void onNewImage();

	Base::Property<cv::Mat, Types::MatrixTranslator > sections;
	Base::Property<int> line_from;
	Base::Property<int> line_to;
};

} //: namespace FocusCalibration
} //: namespace Processors

/*
 * Register processor component.
 */
REGISTER_COMPONENT("FocusCalibration", Processors::FocusCalibration::FocusCalibration)

#endif /* FOCUSCALIBRATION_HPP_ */
