#include <iostream>

#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char **argv) {
  cv::Mat img = cv::imread(argv[1]);

  if (img.empty()) {
    cerr << "Couldn't load the image. \n";
    return 1;
  }

  dlib::frontal_face_detector face_detector = dlib::get_frontal_face_detector();

  dlib::shape_predictor sp;
  dlib::deserialize("../models/shape_predictor_68_face_landmarks.dat") >> sp;

  dlib::cv_image<dlib::bgr_pixel> dimg(img);

  std::vector<dlib::rectangle> faces = face_detector(dimg);

  if (faces.empty()) {
    cerr << "No faces found. \n";
    return 1;
  }

  dlib::full_object_detection shape = sp(dimg, faces[0]);

  for (unsigned i = 0; i < shape.num_parts(); i++) {
    cv::circle(img, cv::Point(shape.part(i).x(), shape.part(i).y()), 2,
               cv::Scalar(0, 255, 0), -1);
    cv::imwrite("../output/landmarks.png", img);
  }

  return 0;
}
