#include "image_processing.h"

using namespace std;

int main(int argc, char **argv) {

  const std::string MODEL_PATH =
      std::string(PROJECT_ROOT) +
      "/models/shape_predictor_68_face_landmarks.dat";
  const std::string OUTPUT_PATH =
      std::string(PROJECT_ROOT) + "output/output.png";

  auto img = load_image(argv[1]);

  auto shape = detect_landmarks(img, MODEL_PATH);

  output_debug(img, shape, OUTPUT_PATH);

  return 0;
}
