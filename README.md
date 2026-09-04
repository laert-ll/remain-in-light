# Remain in Light

Work in progress.

This project is meant as a hobby of mine to write some more code manually in my spare time.

The purpose of this tool will be to have a script which takes an image of a face as an input and have the output be the same image in the style of the Talking Heads legendary 1980 album Remain in Light: blue tint and a red mask over the face with horizontal and vertical lines covering everything but the eyes, nose and mouth.

Given the vintage status of the album cover (the band members working with MIT used the computers at the time to draw the masks over the faces of the band members) I felt like using rather older technology as a stylistic choice, namely the 68 point landmark model (instead of newer more accurate and complicated deep learning models) as well as dlib's older frontal_face_detector (HOG + linear SVM).

## Dependencies

- C++14 compiler
- CMake 3.16+
- OpenCV 4+
- dlib

## Model

This project uses dlib's 68 point landmark model. You can download it manually [here](http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2) or run the following commands:

```
mkdir -p models
curl -L -o models/shape_predictor_68_face_landmarks.dat.bz2 http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2
bunzip2 models/shape_predictor_68_face_landmarks.dat.bz2
```

## Build and run

Work in progress.
