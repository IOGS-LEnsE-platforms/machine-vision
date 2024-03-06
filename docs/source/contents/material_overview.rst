Overview of the platform
========================

The **LEnsE** team developped a platform to reproduce a part of an **industrial system of machine vision**.

Machine Vision platform is a combination of a **conveyor** driven in movement by a **step motor**, a sorting system, a **CMOS industrial sensor** and a **lighting system**.

PICTURE OF THE SYSTEM



Materials
---------

Conveyor and sorting system
~~~~~~~~~~~~~~~~~~~~~~~~~~~

This platform is mainly based on a **Dobot conveyor** that permits to transport small pieces 

Step Motor
""""""""""

A **step-motor** is used to move the conveyor. It is driven by a **TMC SILENTSTEPSTICK** from *Analog Devices*.

The step-motor must be powered up by a 4.6 to 4.8 V power supply.

Sensors
"""""""

Three **SEN0239** infrared presence detectors could be implemented on the board.

SCHEMA ?

A digital output is at a **high level** when an object is detected close to the sensor and at a low level when no object is detected. The sensibility (i.e. the detection distance) can be set up by modifying the value of a potentiometer using a screwdriver.


Sorter System
~~~~~~~~~~~~~

The conveyor is equiped with three home-made sorter systems, based on a servomotor.

IMAGE ?




CMOS Sensor
~~~~~~~~~~~

The CMOS Camera is a **Basler** *XXXX*. The **Pylon Camera Software Suite** is a software package comprised of an easy-to-use SDK, drivers, configuration tools and vTools that you can use to operate any Basler camera and utilize image processing using a Windows PC.

IMAGE OF THE SENSOR

You can also interface this camera with a Python program, using the `PyPylon library <https://github.com/basler/pypylon>`_.

An example based on the PyPylon library is given on this GitHub page : https://github.com/IOGS-Digital-Methods/SupOpNumTools/blob/main/src/SupOpNumTools/camera/cameraBasler.py

More details on the `Basler Documentation Website <https://www.baslerweb.fr/fr/20-cameras-matricielles>`_.

| 

Electronic control board
~~~~~~~~~~~~~~~~~~~~~~~~

This platform is associated to an **electronic board** for controlling : the translation of the conveyor, the activation of each sorting system, the activation of the lighting system.

.. note::
	This board can be used to control 2 different step-motors.

IMAGE OF THE BOARD


