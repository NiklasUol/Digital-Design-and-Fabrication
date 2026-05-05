# Portfolio

### Digital Design and Fabrication
### Author: Niklas Schmidt

---

## Exercise 1
<img src="photos/01/20260430-4.jpg" alt="profile picture" width="400"/>

### Task 1: LED Control Circuit

#### Task 1.1: Simple LED Circuit
We observed that the larger the resistance in the circuit, the higher the voltage across the resistor V1 and the lower the voltage across the LED (V<sub>LED</sub>).

| R1 [Ω] | Measured V1 [V] | Measured V_LED [V] |
|--------|-----------------|--------------------|
| 220    | 2.0             | 2.8                |
| 1000   | 2.5             | 2.5                |
| 4700   | 2.9             | 2.2                |

<img src="photos/01/20260430-6.jpg" alt="profile picture" width="400"/>

#### Task 1.2: Switchable LED Circuit
<img src="photos/01/20260430-13.jpg" alt="profile picture" width="400"/>

In this subtask, we observed that operating the switch turned the LED on or off. When we flipped the switch in the opposite direction, the behavior reversed: if the LED was previously off, it turned on, and vice versa.

In the following video, you can see that the switch works.

<video controls width="400">
  <source src="photos/01/DF-FHD_169.mp4" type="video/mp4">
</video>

#### Task 1.3: Dimmable LED Circuit
TODO: Proportional to the resistance?

### Task 2: Transistor Switch Circuit
<img src="photos/01/20260430-6-2.jpg" alt="profile picture" width="400"/>

#### Task 2.1: Switchable LED Strip
First, we recreated the circuit based on the template from the exercise sheet. Essentially, the switch simply turned the LED strip on and off.

We control 5V with the switch, which is applied to the base of the transistor. As long as this voltage is present, the transistor conducts the current supplied to the LED (12V).

The transistor acts as an electronic switch. When a positive voltage (5V) is applied to the base, the base-emitter diode becomes conductive and allows current to flow from the collector to the emitter. This enables the transistor to control the 12V current through the LED. Without base voltage, the transistor blocks and no current flows through the LED. The advantage is that a small control current at the base can switch a large load current (12V LED).

Otherwise, the implementation worked well and the result was a white glowing LED strip!

<img src="photos/01/20260430-8-2.jpg" alt="profile picture" width="400"/>

#### Task 2.2: Dimmable LED Strip
TODO: 2.2a

It became somewhat more complicated when we tried to implement the second subtask. The switch caused issues because the LED strip did not light up. In the end, we cannot say with 100% certainty what the problem was, but we suspect that the switch cables were damaged. However, with Mikołaj’s help, we simply removed it to proceed with the task.

In this task, we were supposed to integrate a PWM generator and measure what happens when, on the one hand, the duty cycle is changed at a constant frequency (90 Hz), and on the other hand, the frequency is changed at a constant duty cycle (50%).

When the duty cycle is increased at a constant 90 Hz, the LED strip becomes brighter. At 2%, the light is barely visible, while at 100% it is almost blinding 😉

If, on the other hand, only the frequency is changed, a varying degree of flickering can be observed. At 5 Hz, the flickering is clearly visible and slow; at 25 Hz or 45 Hz, it becomes much faster and uncomfortable for the eye. From about 60 Hz onwards, our visual system perceives the light as almost constant, although periodic pulsations still occur at higher frequencies. The flickering was still visible on camera because its frame rate was not synchronized with the switching frequency of the LED strip.

In the video, the flickering at 5 Hz can be observed.

<video controls width="400">
  <source src="photos/01/DF2-FHD_169.mp4" type="video/mp4">
</video>

Here are the remaining photos with constant frequency and varying duty cycle:

<img src="photos/01/20260430-9-2.jpg" alt="profile picture" width="400"/>
<img src="photos/01/20260430-10-2.jpg" alt="profile picture" width="400"/>
<img src="photos/01/20260430-11-2.jpg" alt="profile picture" width="400"/>
<img src="photos/01/20260430-12-2.jpg" alt="profile picture" width="400"/>
<img src="photos/01/20260430-13-2.jpg" alt="profile picture" width="400"/>
---

## Exercise 2
