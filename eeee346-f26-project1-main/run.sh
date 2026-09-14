rm -rf main
rm -rf output_images/*.pgm
g++ -o main *.cpp

cat testInput.txt | ./main

if [ -f "output_images/stretching.pgm" ]; then
  STRETCHING_CHECK=$(diff -b -B output_images/stretching.pgm golden_images/stretching.pgm)
  if [ "$STRETCHING_CHECK" !=  "" ]; then
    echo "HISTOGRAM STRETCHING - FAIL"
  else
    echo "HISTOGRAM STRETCHING - PASS"
  fi
else
  echo "HISTOGRAM STRETCHING - FAIL (MISSING FILE)"
fi

if [ -f "output_images/btc.pgm" ]; then
  GAUSSIAN_CHECK=$(diff -b -B output_images/btc.pgm golden_images/btc.pgm)
  if [ "$GAUSSIAN_CHECK" !=  "" ]; then
    echo "BLOCK TRUNCATION CODING - FAIL"
  else
    echo "BLOCK TRUNCATION CODING - PASS"
  fi
else
  echo "BLOCK TRUNCATION CODING - FAIL (MISSING FILE)"
fi

if [ -f "output_images/edgedetect.pgm" ]; then
  EDGEDETECT_CHECK=$(diff -b -B output_images/edgedetect.pgm golden_images/edgedetect.pgm)
  if [ "$EDGEDETECT_CHECK" !=  "" ]; then
    echo "EDGE DETECTION - FAIL"
  else
    echo "EDGE DETECTION - PASS"
  fi
else
  echo "EDGE DETECTION - FAIL (MISSING FILE)"
fi
