/*!
 * \file CameraV4L_Source.hpp
 * \brief
 * \author mstefanc
 * \date 2010-05-27
 */

#ifndef CAMERAV4L_SOURCE_HPP_
#define CAMERAV4L_SOURCE_HPP_

#include "Kernel_Aux.hpp"
#include "Kernel.hpp"
#include "Panel_Empty.hpp"
#include "DataStream.hpp"
#include "CameraProps.hpp"

#include <cv.h>

namespace Sources {
namespace CameraV4L {

class VL;

using namespace cv;

/*!
 * \class CameraV4L_Source
 * \brief
 */
class CameraV4L_Source : public Base::Kernel {

public:
	/*!
	 * Constructor. Sets ID and startup variables.
	 */
	CameraV4L_Source();

	/*!
	 * Destructor.
	 */
	~CameraV4L_Source();

	/*!
	 * Connects source to given device.
	 */
	void initialize();

	/*!
	 * Disconnect source from device, closes streams, etc.
	 */
	void finish();

	/*!
	 * Retrieves data from device.
	 */
	int step();

	/*!
	 * Return movie properties
	 */
	Base::Props * getProperties() {
		return &props;
	}

protected:

private:
	/// pointer to specific camera object (V4L or V4L2, depending on hardware support)
	VL * cam;

	// last grabbed frame
	Mat frame;

	/// Event signaling that new image was retrieved.
	Base::Event * newImage;

	/// Output data stream
	Base::DataStreamOut<Mat> out_img;

	/// camera properties
	CameraProps props;
};

}//: namespace CameraV4L
}//: namespace Sources

/*
 * Register source kernel.
 */
REGISTER_SOURCE_KERNEL("CameraV4L", Sources::CameraV4L::CameraV4L_Source, Common::Panel_Empty)

#endif /* CAMERAV4L_SOURCE_HPP_ */