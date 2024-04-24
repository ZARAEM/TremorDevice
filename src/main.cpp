#include <Adafruit_CircuitPlayground.h>
//#define FFT_SPEED_OVER_PRECISION /* faster but prone to precision errors */
//#define USE_AVR_PROGMEM /* stores some stuff in memory ? */
#include <arduinoFFT.h>

float X, Y, Z;

const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const float signalFrequency = 1000;
const float samplingFrequency = 5000;
const uint8_t amplitude = 100;

float xReal[samples];
float yReal[samples];
float zReal[samples];
float emptyImag[samples];

ArduinoFFT<float> ThreeFFT = ArduinoFFT<float>(xReal, emptyImag, samples, samplingFrequency);
ArduinoFFT<float> FourFFT = ArduinoFFT<float>(yReal, emptyImag, samples, samplingFrequency);
ArduinoFFT<float> FiveFFT = ArduinoFFT<float>(zReal, emptyImag, samples, samplingFrequency);
ArduinoFFT<float> SixFFT = ArduinoFFT<float>(zReal, emptyImag, samples, samplingFrequency);

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {

  X = CircuitPlayground.motionX();
  Y = CircuitPlayground.motionY();
  Z = CircuitPlayground.motionZ();

  Serial.print("X: ");
  Serial.print(X);
  Serial.print("  Y: ");
  Serial.print(Y);
  Serial.print("  Z: ");
  Serial.println(Z);

  ThreeFFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);
  FourFFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);
  FiveFFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);
  SixFFT.windowing(FFTWindow::Hamming, FFTDirection::Forward);

  ThreeFFT.compute(FFTDirection::Forward);
  FourFFT.compute(FFTDirection::Forward);
  FiveFFT.compute(FFTDirection::Forward);
  SixFFT.compute(FFTDirection::Forward);

  ThreeFFT.complexToMagnitude();
  FourFFT.complexToMagnitude();
  FiveFFT.complexToMagnitude();
  SixFFT.complexToMagnitude();

  float threeHz = ThreeFFT.majorPeak();
  float fourHz = FourFFT.majorPeak();
  float fiveHz = FiveFFT.majorPeak();
  float sixHz = SixFFT.majorPeak();

  Serial.print("3Hz: ");
  Serial.print(threeHz);
  Serial.print("4Hz: ");
  Serial.print(fourHz);
  Serial.print("5Hz: ");
  Serial.print(fiveHz);
  Serial.print("6Hz: ");
  Serial.print(sixHz);
}