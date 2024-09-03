Prototype Tremor Detection Device
Developed for Embedded Challenge Spring 2024 
EE4144 Intro to Embedded Systems NYU Tandon

Team Members:
Mearaj Ahmed, Azaz-ur-Rehman Nasir, Kaddy Koroma

This semester's embedded challenge consisted in building a wearable Parkinson tremor detector
by using the Adafruit Playground Classic board with its embedded accelerometer The Classic
board can calculate real time acceleration by measuring the values obtained from the built in
IMU. The idea is to capture time segments from the accelerometer, analyze the data, and provide
a visual indication for the presence of resting tremor and its intensity (using any board resources
such as LEDs, speaker, neopixels etc…). No additional hardware may be used.

In order to implement a working code the following libraries were imported into the main file:
![image](https://github.com/user-attachments/assets/0d9c3fcb-9742-46d3-9951-7e42abd7910f)

This was done to have access to the respective functions and algorithms that would be relevant to
the development of the code. Global variables for storage were initialized. These were meant to
be called through the code loop.
The set up part of the code included the initialization statement for the circuit playground for the
accelerometer and Neopixel.
The main loop code started off with a for loop statement. This was used to collect the samples
based on previously identified samples, where the X,Y, Z values were stored in their respective
variables that were used to calculate the overall magnitude of the vector.
![image](https://github.com/user-attachments/assets/24d2bcd1-4c3c-45be-83e5-a0d827fb78e1)
![image](https://github.com/user-attachments/assets/223233a1-affd-476c-8d89-c95465f02721)

After the for loop a statement was written to center the signal around 0. The fast fourier
transform was then calculated. Once the frequency was obtained the code then looked for the
peak frequency, with this if statements were used to determine if the found peak frequency was
found within the Parkinson tremor frequencies (between 3 - 6 Hz), , then this was used to
determine the tremor count, as it is known that Parkinson tremor episodes last more than a few
seconds.
![image](https://github.com/user-attachments/assets/80aa84a4-d6f7-41f6-beee-4f7fd8375454)

Once it is determined that a tremor is indeed happening, the circuit playground is programmed to
behave with continuous beeping to indicate the patient of the ongoing tremor. The sound will
continue until the patient presses the button to turn it off.
In case the peak frequency within the tremor threshold is not a lasting frequency throughout a
period of time, there is a statement to dismiss the flagged frequency as this can simply indicate
regular arm movements.
![image](https://github.com/user-attachments/assets/0057f87a-f1e5-444d-b17d-3637d69d9927)

Working in this challenge allowed the implementation of the topics learned in class as well as
more in depth familiarization with the Adafruit Playground Classic board and its relevant
components. It also allowed to understand how Parkinson Tremors appear in patients and the
importance of the use of embedded systems in real world applications.
