#pragma once

#include <dlib/image_processing.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/opencv.h>
#include <opencv2/opencv.hpp>

cv::Mat load_image(char *input_image);

dlib::full_object_detection detect_landmarks(const cv::Mat &img,
                                             const std::string &model_path);

void output_debug(const cv::Mat &img, const dlib::full_object_detection &shape,
                  const std::string &output_path);
