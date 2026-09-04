#include "image_processing.h"

using namespace std;

int main(int argc, char **argv) {

  auto img = load_image(argv[1]);

  auto shape = detect_landmarks(img);

  output_debug(img, shape);

  return 0;
}
