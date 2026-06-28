# Portfolio

### Digital Design and Fabrication
### Author: Niklas Schmidt

### Table of Contents

- [Exercise 1: Electrical Circuits](#exercise-1-electrical-circuits)
  - [Task 1: LED Control Circuit](#task-1-led-control-circuit)
  - [Task 2: Transistor Switch Circuit](#task-2-transistor-switch-circuit)
  

- [Exercise 2: Introduction to Arduino](#exercise-2-introduction-to-arduino)
  - [Sub-circuit 1 - Connecting the buzzer](#sub-circuit-1---connecting-the-buzzer)
  - [Sub-circuit 2 - Connecting the LED screen](#sub-circuit-2---connecting-the-led-screen)
  - [Sub-circuit 3 - Expanding the setup with a Real Time Clock](#sub-circuit-3---expanding-the-setup-with-a-real-time-clock)
  - [Sub-circuit 4 - Using the Push Button](#sub-circuit-4---using-the-push-button)
  - [Final task - Building the Alarm Clock](#final-task---building-the-alarm-clock)
  

- [Exercise 3: Sensors & Actuators](#exercise-3-sensors--actuators)
  - [Task 1: Pneumatic & Electrical Circuit](#task-1-pneumatic--electrical-circuit)
  - [Task 2: Sensor Interaction](#task-2-sensor-interaction)
  - [Task 3: Combining Both Parts](#task-3-combining-both-parts)
  

- [Exercise 4: E-Textiles](#exercise-4-e-textiles)
  - [Step 1: The Design Idea](#step-1-the-design-idea)
  - [Step 2: The Model Becomes Reality](#step-2-the-model-becomes-reality)
  - [Step 3: Sewing and Connecting the LEDs](#step-3-sewing-and-connecting-the-leds)
  

- [Exercise 5: CNC-Milling](#exercise-5-cnc-milling)


- [Exercise 6: Laser cutting](#exercise-6-laser-cutting)


- [Exercise 6.5: CAD Exercises](#exercise-65-cad-exercises)


- [Exercise 7: 3D-Printing](#exercise-7-3d-printing)

---

## Exercise 1: Electrical Circuits
<!--suppress CheckImageSize -->
<img src="photos/01/20260430-4.jpg" alt="picture" width="400"/>

### Task 1: LED Control Circuit

#### Task 1.1: Simple LED Circuit
We observed that the larger the resistance in the circuit, the higher the voltage across the resistor V1 and the lower the voltage across the LED (V<sub>LED</sub>).

| R1 [Ω] | Measured V1 [V] | Measured V_LED [V] |
|--------|-----------------|--------------------|
| 220    | 2.0             | 2.8                |
| 1000   | 2.5             | 2.5                |
| 4700   | 2.9             | 2.2                |

<img src="photos/01/20260430-6.jpg" alt="picture" width="400"/>

#### Task 1.2: Switchable LED Circuit
<img src="photos/01/20260430-13.jpg" alt="picture" width="400"/>

In this subtask, we observed that operating the switch turned the LED on or off. When we flipped the switch in the opposite direction, the behavior reversed: if the LED was previously off, it turned on, and vice versa.

In the following video, you can see that the switch works.

[Video of the switch](photos/01/DF-FHD_169.mp4)

#### Task 1.3: Dimmable LED Circuit
As we turned the potentiometer, the brightness increased gradually after the minimal current necessary for the LED has been reached. Then it rised quickly near the "on" threshold. The LED does not brighten linearly with knob position.

| Position | V<sub>LED</sub> [V] | V<sub>2</sub> [V] |
|--------|-----------------|--------------------|
| a) full brightness    | 3.0             | 3.0                |
| b) dimmed  | 2.3             | 2.3                |
| c) OFF  | 2.0             | 2.0             |

### Task 2: Transistor Switch Circuit
<img src="photos/01/20260430-6-2.jpg" alt="picture" width="400"/>

#### Task 2.1: Switchable LED Strip
First, we recreated the circuit based on the template from the exercise sheet. Essentially, the switch simply turned the LED strip on and off.

We control 5V with the switch, which is applied to the base of the transistor. As long as this voltage is present, the transistor conducts the current supplied to the LED (12V).

The transistor acts as an electronic switch. When a positive voltage (5V) is applied to the base, the base-emitter diode becomes conductive and allows current to flow from the collector to the emitter. This enables the transistor to control the 12V current through the LED. Without base voltage, the transistor blocks and no current flows through the LED. The advantage is that a small control current at the base can switch a large load current (12V LED).

Otherwise, the implementation worked well and the result was a white glowing LED strip!

<img src="photos/01/20260430-8-2.jpg" alt="picture" width="400"/>

#### Task 2.2: Dimmable LED Strip
It became somewhat more complicated when we tried to implement the second subtask. The switch caused issues because the LED strip did not light up. In the end, we cannot say with 100% certainty what the problem was, but we suspect that the switch cables were damaged. However, with Mikołaj’s help, we simply removed it to proceed with the task.

In this task, we were supposed to integrate a PWM generator and measure what happens when, on the one hand, the duty cycle is changed at a constant frequency (90 Hz), and on the other hand, the frequency is changed at a constant duty cycle (50%).

When the duty cycle is increased at a constant 90 Hz, the LED strip becomes brighter. At 2%, the light is barely visible, while at 100% it is almost blinding 😉

If, on the other hand, only the frequency is changed, a varying degree of flickering can be observed. At 5 Hz, the flickering is clearly visible and slow; at 25 Hz or 45 Hz, it becomes much faster and uncomfortable for the eye. From about 60 Hz onwards, our visual system perceives the light as almost constant, although periodic pulsations still occur at higher frequencies. The flickering was still visible on camera because its frame rate was not synchronized with the switching frequency of the LED strip.

In the video, the flickering at 5 Hz can be observed.

[Video of the blinking LED-Strip](photos/01/DF2-FHD_169.mp4)

Here are the remaining photos with constant frequency and varying duty cycle:

<img src="photos/01/20260430-9-2.jpg" alt="picture" width="400"/>
<img src="photos/01/20260430-10-2.jpg" alt="picture" width="400"/>
<img src="photos/01/20260430-11-2.jpg" alt="picture" width="400"/>
<img src="photos/01/20260430-12-2.jpg" alt="picture" width="400"/>
<img src="photos/01/20260430-13-2.jpg" alt="picture" width="400"/>

Compared to the LED you can notice that the LED-Strip was able to glow much darker thanks to the use of the PWM generator.
While the LED needed a minimal voltage / current and had therefore also a minimal brightness, the LED stip could glow darker,
because of the optical illusion caused by the PWM generator, which switched the light / current (with the transistor) off for unnoticeable time periods.











---

## Exercise 2: Introduction to Arduino


<img src="photos/02/20260507-2.jpg" alt="picture" width="400"/>

### Sub-circuit 1 - Connecting the buzzer
In this first task, we were supposed to connect a buzzer to the Arduino, run a test program on it, and modify parameters in it.

First, we placed the buzzer and a resistor on a breadboard and connected it to the Arduino. This worked without any issues.

<img src="photos/02/20260507-3.jpg" alt="picture" width="400"/>

However, when uploading the test program, we got an exit status 1 compilation error.

<img src="photos/02/20260507-4.jpg" alt="picture" width="400"/>

This frustrated Julian a bit.

<img src="photos/02/20260507-1_2.jpg" alt="picture" width="400"/>

After some debugging, we found out that the problem was a missing library. We had to install the "Adafruit BusIO" library for the program to compile.

<img src="photos/02/20260507-5.jpg" alt="picture" width="400"/>

With both fixes, it worked then.

<img src="photos/02/20260507-7.jpg" alt="picture" width="400"/>

<img src="photos/02/20260507-8.jpg" alt="picture" width="400"/>

There was a missing delay between LOW and HIGH in the code, and the control pin had to be changed from 4 to 13. If the delay between the highs is effectively 0, we don't get three alarm tones, but a continuous one.

<img src="photos/02/20260507-9.jpg" alt="picture" width="400"/>

Also noteworthy: If we omit the resistor, the sound is very loud. We captured this in these two videos.

[Video of the silent buzzer with the resistor](photos/02/01-4K30.mp4)

[Video of the loud buzzer without the resistor](photos/02/02-4K30.mp4)



### Sub-circuit 2 - Connecting the LED screen
<img src="photos/02/20260507-10.jpg" alt="picture" width="400"/>

In the next subtask, an LED screen was connected to the Arduino. This worked wonderfully thanks to the clear circuit diagram. Without it, we wouldn't have intuitively understood what SCL and SDA are and where they are connected on the Arduino.

<img src="photos/02/20260507-11.jpg" alt="picture" width="400"/>

Additionally, the display's resistor had to be adjusted using a screwdriver on the back.

Using the provided test program for the display, we then found out what the I2C address of the display is. This allowed us to control it and display text in the first place.

<img src="photos/02/20260507-12.jpg" alt="picture" width="400"/>

The inscription "Whatever makes sense to show" was then successfully displayed.

<img src="photos/02/20260507-15.jpg" alt="picture" width="400"/>



### Sub-circuit 3 - Expanding the setup with a Real Time Clock
<img src="photos/02/20260507-17.jpg" alt="picture" width="400"/>

In the third subtask, we were supposed to connect an RTC module, to which a battery is attached, which keeps the time even when the Arduino is turned off. We first placed the module on the breadboard and then established the I2C connections to the Arduino. It was important to connect SDA and SCL correctly and insert the battery into the module so that the real-time clock doesn't reset during a power outage.

Subsequently, we verified that the module reliably provides the current time and that the display can later show the correct time.

In the video, you can see that thanks to the module, the seconds continue to count even when the Arduino has no power.

[Video of the RTC-Module saving the time](photos/02/03-4K30.mp4)


### Sub-circuit 4 - Using the Push Button
<img src="photos/02/20260507-18.jpg" alt="picture" width="400"/>

In the last subtask, we first connected one button and later several buttons to the Arduino. First, we tested a single button to ensure that the digital input signal is read correctly. Then we expanded the circuit and built in several buttons to support different functions such as alarm stop, confirmation, and menu navigation.

We made sure to use the buttons with pull-down resistors so that the input doesn't float when idle. In the program, we queried the state changes and built in short debounce times to avoid accidental multiple triggering.

This way, we could later reliably control the start/stop and time setting in the alarm project via button press.

<img src="photos/02/20260507-27.jpg" alt="picture" width="400"/>

### Final task - Building the Alarm Clock

In the final step, we then built and programmed the actual alarm clock. Here, all subtasks came together, and in the end, we added our own functions and revised and improved the given code.

First we improved the alarm sound of our alarm clock. To do that, we had the idea to change the simple beeping to a more advanced melody.
Because, we aren't the greatest musicians we used the following library to do so: https://github.com/robsoncouto/arduino-songs.
We planned to include three different melodies we selected from the library. The Mario Theme, Pink Panther and Tetris. If the alarm was triggered, one of the melodies should have been played.
Unfortunately, the RAM of the Arduino UNO wasn't sufficiently big enough for the tree melodies. Therefore, we had to simplify our idea and only include one of these songs. Our decision was the Tetris-Melody.

But after we succeeded to play this melody as our new alarm sound, we had another problem. The melody wasn't stoppable. Because the code run though the tones (and delays) step by step,
there was no time to check, whether the red button, which should stop the alarm, was pressed or not. To fix that problem, and be able to stop the alarm at any time, we researched how concurrency
could be handled with the Arduino UNO. We hoped that there would be some kind of multithreading and that it would be possible to simply start the alarm in another thread and stop this thread, if
the button is pressed. Unfortunately there is no multithreading :/  
Therefore we analysed the code of the song-library and expanded it regarding the possibility stop the melody. Then, this feature working like we had planned it :)  

Afterward, we tried to improve the controls of the alarm clock. The controls of the given code weren't always very user-friendly. In fact, we raged sometimes a bit, if we tried to set e.g. the minutes of the alarm time.
If we wanted to set the minute at 40, but skipped accidentally one minute and set it to 41, we had to press the button controlling the minutes 59 times. For that reason we tried to protect our fingertips and program the
controls so that you could increase the minutes with the green button and decrease them with the yellow button. Now you can press the red button and the alarm-hour starts blinking.
Then, you can set it with the green button (increase) and the yellow button (decrease). If you press the red button again, the minutes start blinking. Then you can set them as well.
If the red button is pressed again, the alarm is successfully set and the current time is displayed.

For debugging reasons we also programmed that the alarm-time is automatically set to one minute after the time, which is set in the start-method of the code.


<img src="photos/02/20260507-30.jpg" alt="picture" width="400"/>

<img src="photos/02/20260507-31.jpg" alt="picture" width="400"/>

Below is a video showing the functionality of the clock.

[Click to watch on YouTube](https://www.youtube.com/watch?v=gtaooIpYjuc)

The arduino code can be found under: [Click to view the code](/arduino_sketches/exercise_02/Alarm_Improved_V2/Alarm_Improved_V2.ino)







---

## Exercise 3: Sensors & Actuators

<img src="photos/03/20260521-15.jpg" alt="picture" width="400"/>

### Task 1: Pneumatic & Electrical Circuit

First, we connected the pumps to the air cushion via the valve. After that, we connected the three MOSFET modules to the Arduino, the two motors, and the external power supply.

Overall, this worked quite smoothly. However, at first we tried to connect the cables to the MOSFET modules without using a screwdriver because we did not have one available. That turned out to be a very bad idea... So we decided to do it properly and asked one of the tutors for a screwdriver instead.

<img src="photos/03/20260521-2.jpg" alt="picture" width="400"/>

Regarding the wiring:
- We connected the MOSFET signal pin to Arduino pin 11.
- The MOSFET ground pin was connected to both the Arduino ground and the ground of the external power supply.
- The MOSFET Vin pin was connected to the positive terminal of the external power supply.
- Finally, one of the pumps was connected to the V+ and V− outputs of the transistor module.

<img src="photos/03/20260521-3.jpg" alt="picture" width="400"/>

We repeated the same setup for the second pump and for the valve.

<img src="photos/03/20260521-4.jpg" alt="picture" width="400"/>

Afterward, we wrote a small test program that allowed the Arduino to inflate and deflate the cushion using the pumps.

<img src="photos/03/20260521-5.jpg" alt="picture" width="400"/>

Unfortunately, during the first test run, the cushion did not react as expected. The motors were not running, although the LEDs on the MOSFET modules indicated that the transistors themselves were active.

After some debugging, we realized that the ground cable of the external power supply had been connected incorrectly. It should have been connected to the blue negative terminal instead of the green middle terminal. The ground symbol above the green connector had confused us.

<img src="photos/03/20260521-6.jpg" alt="picture" width="400"/>

Once we corrected the wiring, the program worked perfectly. The cushion alternated between inflating and deflating for five seconds each. Between these phases, we inserted a short delay to allow the valve to switch correctly. One pump was responsible for inflation, while the other handled deflation.

<img src="photos/03/20260521-7.jpg" alt="picture" width="400"/>

<img src="photos/03/20260521-8.jpg" alt="picture" width="400"/>

And here is the final program!

<img src="photos/03/20260521-9.jpg" alt="picture" width="400"/>

Click here to view the code: [Click to view the code](/arduino_sketches/exercise_03/Pump_Test/Pump_Test.ino)



### Task 2: Sensor Interaction

In Task 2, we additionally connected a force sensor. Our goal was to inflate and deflate the cushion through touch interaction. Pressing strongly on the sensor should inflate the cushion, while pressing lightly should deflate it.

<img src="photos/03/20260521-10.jpg" alt="picture" width="400"/>

First, we connected the sensor to the Arduino:
- one pin was connected to an analog input,
- a 10kΩ pull-down resistor connected the signal line to ground,
- and the second sensor pin was connected to the Arduino’s 5V output.

We then wrote another test program to determine the sensor threshold values for distinguishing between weak and strong pressure.

Unfortunately, the test program did not work as expected at first :(

As shown in the image, instead of displaying the expected analog values, the serial monitor only showed unreadable symbols and gibberish :((

The issue turned out to be relatively simple: in the code, the string `"Force-Value: "` was concatenated with the measured sensor value, but the concatenation syntax was incorrect.

(Off-topic fun fact: we also struggled quite a bit with spelling the word ~~conce~~ ~~croncat~~ “concatenation.” What an unnecessarily complicated word!)

After fixing the bug, the sensor values were displayed correctly. Perfect!!! 🥳

But our excitement did not last long. Unfortunately, we quickly realized that the force sensor produced rather unreliable measurements. It was difficult to reliably distinguish between light pressure, no pressure, and strong pressure. Therefore, for Task 3 we decided to use a different method for controlling the pumps.

<img src="photos/03/20260521-11.jpg" alt="picture" width="400"/>

Click here to view the code: [Click to view the code](/arduino_sketches/exercise_03/Force_Sensor_Test/Force_Sensor_Test.ino)


### Task 3: Combining Both Parts

Our idea was the following:
- inflating the cushion should work via the force sensor,
- while deflating should be controlled through an additional push button.

We therefore added a button to the breadboard.

As learned in Exercise 2, we connected the button to a digital pin on the Arduino.

<img src="photos/03/20260521-14.jpg" alt="picture" width="400"/>

Finally, we modified the code so that:
- the force sensor inflates the cushion, and
- the button deflates it.

The threshold was defined as follows:
Whenever the measured pressure value exceeded 1020, the cushion inflated. This corresponded to pressing the force sensor very firmly.

As long as the button was held down, the cushion continuously deflated.

If neither sensor was activated, the pumps stayed off and the cushion remained completely still.

<img src="photos/03/20260521-13.jpg" alt="picture" width="400"/>

Last but not least: a short video of our setup in action (sadly not cats this time).

[Video of our setup](photos/03/DF-1080_30_mp4.mp4)

Click here to view the code: [Click to view the code](/arduino_sketches/exercise_03/Pump_With_Force_Sensor/Pump_With_Force_Sensor.ino)





--- 

# Exercise 4: E-Textiles

Today's exercise focused on E-Textiles, which involves electronics sewn into clothing—or more generally, into fabric.

<img src="photos/04/20260528-1.jpg" alt="picture" width="400"/>

After the introductory presentation, my team partner and I decided to sew an airplane onto a patch, similar to the cellphone photo. We wanted to position the five LEDs to be installed under the wings, in the nose, and in the tail—in each case placed between the airplane and the patch.

At that point, however, we had no idea how much work this idea would actually bring us.

But let's start from the beginning.

<img src="photos/04/20260528-3.jpg" alt="picture" width="400"/>

### Step 1: The Design Idea

To somehow transfer the airplane from the Google image onto fabric, we tried several approaches. First, I took a sheet of A4 paper and traced the airplane using a ballpoint pen. This generally worked very well, but it quickly became apparent that the airplane was much too small. Crucially, the battery module still had to fit underneath the airplane—ideally without showing.

Our next idea was to simply draw the airplane freehand onto a sheet of A4 paper. Well, there was actually nothing "simple" about that. My drawing skills are rather limited, and so in the end, the airplane didn't really look like the original model. It was simply too difficult to get the proportions right freehand.

<img src="photos/04/DF.jpg" alt="picture" width="400"/> (Memes provided by Julian) 

That left only one option: designing an airplane on the PC, printing it out, transferring it to the fabric, and then cutting it out.

So, we booted up our laptops and created a suitable model in a drawing program of our choice.

<img src="photos/04/20260528-7.jpg" alt="picture" width="400"/>

Thanks to our tutor, we were able to print it out quickly afterwards. Thanks again for that! :)

<img src="photos/04/20260528-6.jpg" alt="picture" width="400"/>


### Step 2: The Model Becomes Reality

The model was then cut out by each of us.

<img src="photos/04/20260528-8.jpg" alt="picture" width="400"/>

Next, we placed it onto the fabric and traced the contours with a ballpoint pen. Working as a pair worked significantly better than doing it alone: while one person held the airplane in place, the other could easily trace the outlines.

<img src="photos/04/20260528-13.jpg" alt="picture" width="350"/> <img src="photos/04/20260528-16.jpg" alt="picture" width="350"/>

Afterward, we cut out the fabric along the drawn line. The curves in particular were a bit tricky because the fabric was already starting to fray slightly. By this time, about 60% of the tutorial session had already passed, which meant we had to start rushing to sew on the sensors and connect everything to each other and to the battery holder.

<img src="photos/04/20260528-17.jpg" alt="picture" width="350"/> <img src="photos/04/20260528-21.jpg" alt="picture" width="350"/>

<img src="photos/04/20260528-22.jpg" alt="picture" width="350"/>



### Step 3: Sewing and Connecting the LEDs

In the next step we had to sew the LEDs onto the black background-fabric and connect them with the conductive yarn.
Since nobody in the course could sew very well, this was a very time-consuming process. To "simplify" the work and be able to see on which places I had to sew the LEDs, I abandoned the original idea of creating the background patch for the airplane,
which you could see in the picture from before. Instead, I cut out the background fabric in the shape of the airplane as well and sewed the LEDs on top of it.

Nevertheless, the sewing process was still very difficult for me (and if you looked in the faces of the others, seemingly for them too ;)).
First, you had handle the yarn, get it through the needle, and then sew it through the outlines of the airplane, while connecting it to the positive pins of the LEDs.
So the LEDs were fastened to the fabric, which was already a great success, in my opinion :)

In the next step I did the same thing for the negative pins of the LEDs, which were in the inner part of the airplane.
While sewing, I always had to make sure that the positive and negative connections didn't touch each other, otherwise the LEDs would have short-circuited and not worked at all.

<img src="photos/04/20260608_182155.jpg" alt="picture" width="400"/>

The positive and negative connections were then connected to the battery holder, which was placed on the back of the airplane. The battery holder has a switch, which allows us to turn the LEDs on and off.
I connected both positive and negative pins for a more redundant connection, which should make the circuit more reliable. The positive pins of the LEDs were connected to the positive terminal of the battery holder, while the negative pins were connected to the negative terminal.

<img src="photos/04/20260608_182953.jpg" alt="picture" width="400"/>

After that, I checked everything again to make sure that there were no short circuits and that all connections were correct. Then I turned on the switch of the battery holder, and ...
nothing happened :-/
I thought that maybe there was nevertheless a short circuit somewhere, because it could have been, that I the two poles of the yarn were connection by a little fiber, which I hadn't noticed.
But then I checked the battery holder and move the battery a bit out of position and suddenly the LEDs started to glow! So the problem was that the battery wasn't making good contact with the terminals of the battery holder. After I fixed that, everything worked perfectly like you can see in the picture below :)

<img src="photos/04/20260608_210356.jpg" alt="picture" width="400"/>

To finish the "little" project (which turned out to be quite the challenge), I sewed the front of the airplane over the side with the LEDs, so that all the conductive yarn and the LEDs were hidden and the battery holder was still accessible. 

<img src="photos/04/20260609_191134.jpg" alt="picture" width="350"/> <img src="photos/04/20260609_205536.jpg" alt="picture" width="350"/>

Finally, the airplane was ready for takeoff :)

<img src="photos/04/20260609_205357.jpg" alt="picture" width="400"/>


---


## Exercise 5: CNC-Milling

<img src="photos/05/20260604_114310.jpg" alt="start picture" width="400"/>

After the lecture about CNC-Milling, we were supposed to design a simple wooden 2D candle holder with the program Inkscape.
Since I personally use candles especially in the Christmas season, I wanted to design a star shaped candle holder, which could be used as a christmas decoration.

To be able to draw the form without just the imagination and my artistic skills, I first searched for a picture of a star on the internet, which I could use as a template.

<img src="photos/05/star_template.png" alt="template picture" width="400"/>

After that, I imported the picture into Inkscape and traced the edges with the pen tool.
To manage to draw the star as symmetrically as possible, I used the alignment tool to align the nodes horizontally or vertically like you can see in the pictures below.

<img src="photos/05/star_outline_inkscape.png" alt="picture" width="380"/> <img src="photos/05/star_candle_hole_inkscape.png" alt="picture" width="380"/>

The candle holder consists of two shapes. The first shape is the outer contour of the star, which defines the shape of the candle holder. The second shape is a circle in the middle of the star, which defines were the CNC machine should cut the star out of the wood.
The inner circle defines the place where the candle should be placed. The diameter of the circle is 39.5 mm, which should be sufficient for a standard tea light candle.

After I finished the design, I exported it as a .svg file and uploaded it in Stud.IP to be milled by Juliusz with the CNC machine. The general process of milling was not just explained in the lecture, but shown to us in a live demonstration by Juliusz.
In the demonstration, a small candle holder was milled, which didn't take longer than 5 minutes. In preparation the CAD file was converted to a G-code file, which is the format that
the CNC machine can read. After the file was uploaded to the machine, the wood was fixed and the milling head was calibrated. The height of the head was adjusted so that it barely touched the wood (or a piece of paper above it).
The calibration of the milling head in relation to the wood is very important to ensure that the machine starts milling at the correct place and no material is wasted.
This had be done for the x, y, z axis via the control panel of the CNC machine, a remote control and a little "screw" above the head. Then, the machine was started.

<img src="photos/05/20260604_114310.jpg" alt="picture" width="350"/> <img src="photos/05/20260604_114318.jpg" alt="picture" width="350"/>

<img src="./photos/05/GIF_20260617_191259_362.gif" alt="Milling-Gif" width="350"/>

While milling, the milling head moved along the x, y, z axis like specified in the G-code file and cut the example candle holder. This process was very loud, so we had to wear ear protection.
The result was a perfectly milled candle holder, which looked exactly like shown in control panel of the CNC machine.



---



## Exercise 6: Laser Cutting

<img src="./photos/06/20260612-12.jpg" alt="picture" width="350"/>

This exercise focused on laser cutting, which is a manufacturing process that uses a laser to cut or engrave different materials.
After the lecture, we were supposed to design a business card with the program Inkscape. Since you simply could cut the card out of the used wooden plate or engrave it,
the design could be entirely in 2D. Therefore, we simply had to draw in one plane in Inkscape.

In the first step, I created a rectangle with the rectangle tool, which defined the outer contour of the business card. The dimensions of the rectangle were 89 mm x 51 mm, which is a common size for business cards.
Because these edges should be cut by the laser cutter later, I set the stroke width to 0.001 mm, which is interpreted by the laser cutter as a cutting line. Higher stroke widths are interpreted
as lines to be engraved.

Afterwards, I brainstormed a bit about what I could put on the business card. Since I am a computer science student with a lot of interest in development and tinkering,
I decided to put under my name the text "Software Engineering and more", which should indicate my "future customers" for what I could be hired for ;)
To allow my customers to contact me, I also put my email address on the card. Since this project were done in the university, I used my university email address for that.

Furthermore, I wanted to add a simple drawing of my profile picture to the card to add a more personal touch to it. Therefore, I took a picture of myself and converted it with ChatGPT into a simpler picture,
which should be possible to be engraved with the laser cutter. You can see the result in the picture below.

<img src="./photos/06/eaca00a97968bf212ae9a2913eabdb7e2d73274dfa0cf6d5464289e86530a56b.png" alt="picture" width="350"/>

Of course, this picture still was far too complex to be engraved with the laser cutter. Therefore, I asked ChatGPT to simplify the picture even more and to convert it into an SVG.
Unfortunately, my instruction has been misunderstood by ChatGPT, which resulted in a very abstract picture of me, which was not really recognizable anymore.

<img src="./photos/06/profile_picture_to_simple.png" alt="picture" width="350"/>

After many more failed attempts, I gave up the idea and decided to simply put fitting logos on the left side of the card, which still had a lot of free space.
I chose a logo of a laptop and one of a gear, which seemed to fit well with my field of study and my interests. The final inkscape-design of the business card can be seen in the picture below.

<img src="./photos/06/inkscape_business_card.png" alt="picture" width="350"/>

In the next part of the exercise, we had to manufacture the business card with the laser cutter. Since many people wanted to use the laser cutter at the same time, I had no
time to that in the regular Thursday time slot. For that reason, I used the laser cutter of the "Department für Informatik" in the university building, to which Julian had access as a Soft Skills Tutor.
This laser cutter was a different model than the one in the Offis. It was the "Beambox Pro", which was controlled with the software "Beam Studio". There we had to import an SVG file (not a PDF like in the Offis).
We first tried to load an PDF file to the laser cutter, but it failed since everything was cut out and the text wasn't very fitting anymore like you can see in the picture below.

<img src="./photos/06/20260612-1.jpg" alt="picture" width="350"/>

Therefore, we did the same thing with an SVG file. This process looked a lot more promising and took not longer than 5 minutes.

<img src="./photos/06/20260612-3.jpg" alt="picture" width="350"/> <img src="./photos/06/20260612-12.jpg" alt="picture" width="350"/>

You can see the final result of the finished business card in the picture below. Overall I am satisfied with the result, although the engraving of the text below the name and the email address could have been a bit more precise.
Probably the power level of the laser cutter was too high, which caused the laser to burn a bit too much into the wood. I decided to leave it like that and not to repeat the process with a lower power level,
because the result was still good enough for me and I didn't want to waste more wood of the university than necessary.

<img src="./photos/06/20260612-13.jpg" alt="picture" width="350"/>



---



## Exercise 6.5: CAD-Exercises

In this exercise, we were supposed to learn how to use a CAD software to design 3D-Objects.
Since the course didn't take place in this week, we had to self-study with the software Onshape. There we had to complete the following exercises:

<img src="photos/07/onshape_exercises.png" alt="picture" width="400"/>

Like you can see in the picture below, I completed all exercises successfully.

<img src="photos/07/onshape_training_dashboard.png" alt="picture" width="400"/>



---



## Exercise 7: 3D-Printing

In this exercise, we had the task to design a small 3D-Object of our choice, which will be printed with the 3D-Printer. While smartphone utilities like a case were given as a suggested theme,
we haven't been limited in our design ideas. Therefore, I brainstormed a bit about the things I still need in my life or for work. Since I already have a smartphone case or stand, I thought about other objects.
After considering the inspirantional websites given for this exercise, I had the idea that I could use a pencil holder with a little compartment for USB-Sticks. This would improve the order of my desk were often
pencils and USB-sticks, which I need for work, are laying around all over the place.

First, I have begun drawing a sketch in Onshape (on the top plane). To begin, I draw a rectangle with the size of 150mm * 100mm, because I estimated that this would be enough space for the pencil holder.
Then, I placed two circles on the inside of the rectangle which should hold my pencils and pens in the future. To ensure that everything looks symmetrical, I place different diagonal construction-lines in the inside of the rectangle,
which intersections could be used as anchor points of the two circles. Furthermore, I placed a horizontal construction line in the middle of the rectangle, which I used as a mirror line for the two circles.
The mirroring moreover guaranteed that both circles were equal in their radius all the time. That had the advantage that you could change the size of one circle and the other one would be changed as well automatically.

On the upper right quarter I placed a inner rectangle which should hold a ruler and other utils, which wouldn't fit into the two circular holes. Since the two circles had a radius of 35mm I constrained the rectangle with a height of 35mm too.
In the right bottom quarter of the rectangle I separated another rectangle from it, which should be the USB compartment. I haven't added walls to it, because I planed to do it with the use of fillet and extrudes (shown later).
The following picture shows the whole sketch:

<img src="photos/08/Onshape_Sketch.png" alt="picture" width="400"/>

After the sketch was finished I had to begin to create the 3D object of it. To do that, I used extrudes in the first step. To give the pencil holder a more stylish look,
I had the idea to give every hole / quarter of the sketch another height. Starting from the upper left quarter I used four different extrudes (excluding the holes) with different heights for every quarter.
The heights were 60, 50 and 40mm for the 3 holes and 20mm for the USB compartment.

<img src="photos/08/Onshape_Extrude_Upper_Left.png" alt="picture" width="350"/> <img src="photos/08/Onshape_Extrude_Right_Bottom.png" alt="picture" width="350"/>

Looking from above, I noticed that the holes of the pencil holder still had no bottom and the pencils would just fall through, if you lift the pencil holder.
To fix this issue, I added extrudes for the 3 holes from the bottom. For the height I chose 7mm which should be enough for the bottom.

<img src="photos/08/Onshape_Bottom_Extrude.png" alt="picture" width="350"/> <img src="photos/08/Onshape_Bottom_Finished.png" alt="picture" width="350"/>

Since everything looked a bit cheap, I began using fillets to round out the edges and make the look of the pencil holder more modern.
First, I used the fillet-tool with a radius of 6mm to round out the edges laying on the sketch plane. Then I used the newly added inner edges of the USB compartment to create
a new extrude removing 13mm in height of the material. This resulted in a notch, from which the USB-Sticks shouldn't slide out.

<img src="photos/08/Onshape_Fillet_Plane_Edges.png" alt="picture" width="350"/> <img src="photos/08/Onshape_Extrude_USB_Compartment.png" alt="picture" width="350"/>

In the next step I added the same fillet that I have already applied to the sketch-plane-edges to the vertical ones in the inner and outer structure of the pencil holder.
Furthermore, I did the same for inner edges of the hole in the upper right quarter, so that every hole and edge is rounded and everything follows the same style.

<img src="photos/08/Onshape_Fillet_Upper_Vertical_Edges.png" alt="picture" width="350"/> <img src="photos/08/Onshape_Fillet_Outer_Vertical_Edges.png" alt="picture" width="350"/>
<img src="photos/08/Onshape_Fillet_Upper_Right_Hole.png" alt="picture" width="350"/>

This resulted in the final design which you can see in the picture below.

<img src="photos/08/Onshape_Part.png" alt="picture" width="400"/>

I exported the design via the part-studio in Onshape and imported it in the next step in the slicer-software "QIDI-Studio". There I selected all options like described in the
given slides for the exercise. I had to select the printer "Q2", the filament type "PLA Rapido" and a process-preset, which set the layer height to 0.28mm. After I set all options
I started the slicing-process, which fortunately finished without errors. This allowed me to see how each layer of the pencil holder would be printed. Here you can the see internal walls
as well. These are needed to support the whole structure and enable the printer to print the top layer of the walls without any sacking of the filament, while reducing the material cost.

<img src="photos/08/Slice_Process.png" alt="picture" width="350"/> <img src="photos/08/Slice_To_Big.png" alt="picture" width="350"/>

Unfortunately the material cost was still too high. The maximum mass which was allowed for this exercise was 120g. Unfortunately the sliced pencil holder still had a mass of 146g.
To fix this problem, I used the scale-feature of the slicer-software to scale the pencil holder down in size. After the scaling the width was only 138mm while the length was 92mm.
This resulted in the desired weight of about 119g which met the requirements.

<img src="photos/08/Slicer_Scaling.png" alt="picture" width="350"/> <img src="photos/08/Slicer.png" alt="picture" width="350"/>

In the final step I exported the sliced design as an 3MF-file and uploaded it along with the step-file from Onshape to Stud.IP.
I am very excited to see how the printed pencil holder will look in reality and if it will help me to order my desk :)