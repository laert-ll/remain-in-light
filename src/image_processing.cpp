#include <iostream>

#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>

using namespace std;

cv::Mat load_image(char *input_image) {

  cv::Mat img = cv::imread(input_image);

  if (img.empty()) {
    cerr << "Couldn't load the image. \n";
  }

  return img;
}

dlib::full_object_detection detect_landmarks(const cv::Mat &img,
                                             const std::string &model_path) {

  dlib::frontal_face_detector face_detector = dlib::get_frontal_face_detector();

  dlib::shape_predictor sp;
  dlib::deserialize(model_path) >> sp;

  dlib::cv_image<dlib::bgr_pixel> dimg(img);

  std::vector<dlib::rectangle> faces = face_detector(dimg);

  if (faces.empty()) {
    cerr << "No faces found. \n";
  }

  dlib::full_object_detection shape = sp(dimg, faces[0]);

  return shape;
}

void output_debug(const cv::Mat &img, const dlib::full_object_detection &shape,
                  const std::string &output_path) {

  for (unsigned i = 0; i < shape.num_parts(); i++) {
    cv::circle(img, cv::Point(shape.part(i).x(), shape.part(i).y()), 2,
               cv::Scalar(0, 255, 0), -1);
  }
  cv::imwrite(output_path, img);
}
