Machine Vision Platform
=======================

Machine vision
--------------

**Machine vision** encompasses all industrial and non-industrial applications in which a **combination of hardware and software** provide operational guidance to devices in the execution of their functions based on the capture and processing of images.

.. figure:: ../_static/pieces_machine_vision.png
  
  2022 LEnsE.


For example, machine vision is used to inspect parts in a production chain without stopping the manufacturing flow. If defaults are detected on a part (wrong color, bad shape...), a sorting system can eject bad elements.

|

In manufacturing settings, machine vision systems required the following items:

#. **Lighting** to illuminate the scene to make the object features visible.
#. **Lens** to captures the image and delivers it to a sensor.
#. **Image sensor** to collect a digital image of the object.
#. **Computer** (or digital signal processor) to process the images and extract the required information.

|

You can find more information about machine vision, for example, on the Cognex website : https://www.cognex.com/en-au/what-is/machine-vision

Pedagogical platform
--------------------

The platform was developped in order to sort pieces 

It is based on :

#. *EffiLux* **Effi-Ring** industrial lights 
#. A `Dobot Magician **Conveyor** <https://www.dobot.nu/en/product/dobot-conveyor-belt-kit/>`_ (step-motor and conveyor belt)
#. A *Basler* camera sensor




Pedagogical objectives
----------------------

Niveau 1 : pilotage du convoyeur
Niveau 2 : détection de forme et de couleur par caméra

Dans le milieu industriel, le convoyage de pièces, la détection de certains défauts ou le tri par types d’objets sont très couramment utilisés. L’objectif de ce projet est de mettre en place un système de tri de pièces à l’aide d’un convoyeur et d’un système de traitement d’images.


La mise en mouvement du convoyeur se fait par l’intermédiaire d’un moteur pas à pas. Le tri des pièces (par couleur ou forme) utilise une caméra associée à une Raspberry Pi permettant de faire le traitement des images et de transmettre le résultat à un système de tri.



Main steps
----------

Interface de base
~~~~~~~~~~~~~~~~~

Des bibliothèques de base en Python sont disponibles pour le développement autour des caméras Basler. Ces exemples nécessitent opencv et les API pypylon (Basler). Ces exemples peuvent être inclus dans des interfaces graphiques en PyQt6.

`Exemples pour cameras IDS et Basler <https://github.com/IOGS-Digital-Methods/SupOpNumTools/tree/main/src/SupOpNumTools/camera>`_

Des exemples (très complets) sont disponibles dans les projets suivants :  `IHM PyQt6 pour cameras IDS et Basler <https://github.com/IOGS-LEnsE/labwork-GUI>`_


Une première version d’une interface de commande (obsolète) des caméras IDS USB2 est disponible.  `IHM PyQt5 pour camera IDS - obsolete <https://github.com/IOGS-LEnsE-embedded/Python_SupOpLibraries/tree/main/CameraControl/IDS/LEnsE_version1>`_

*Cette application nécessite PyQt5, OpenCV, l’API PyUeye et les drivers des caméras.*

Partie matérielle
~~~~~~~~~~~~~~~~~

* Comprendre le fonctionnement d'un moteur pas à pas (indépendamment de ceux de la table) - `Vidéo <https://www.youtube.com/watch?v=eyqwLiowZiU>`_
* Etudier les signaux à appliquer sur le moteur pas à pas pour l'entrainer en rotation
* Etudier le driver `**TMCSILENTSTEPSTICK** <https://fr.farnell.com/trinamic/tmc-silentstepstick/carte-driver-moteur-pas-a-pas/dp/2822153>`_ (basé  sur un composant de type **TMC2100**) et l'associer au moteur pas à pas
* Voir aussi les tutoriels associés aux cartes Nucléo parlant des étages de puissance
	* Régler l’intensité lumineuse d’une LED – partie puissance
	* Faire varier la vitesse d’un moteur à courant continu – partie pont en H
* Réaliser un programme de pilotage simple pour entrainer en rotation le moteur

Partie logicielle / traitement d’image
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* Prendre en main PyQt6 sous Python 3
* Tester les fonctionnalités de base de Open CV sous Python

Autres étapes

* Mettre en place une communication RS232 entre la Raspberry Pi (via un programme en Python) et une carte Nucléo
* Décider des données à transmettre de l’un à l’autre et d’un protocole à mettre en oeuvre
* Tester le code de la carte Nucléo à l’aide de commande directement saisie dans un terminal
* Voir aussi les tutoriels associés aux cartes Nucléo parlant des communications inter-systèmes
	* Echanger des données entre deux systèmes communicants (et les tutoriels précédents sur la communication RS232)

Une série de tutoriels sont en cours de rédaction à ce sujet :  `Tutoriel Python / PySerial et PyQt5/6 pour échange entre un PC et une Nucléo <http://lense.institutoptique.fr/mine/python-interfacage-et-affichage/>`_

Ils sont basés sur les exemples suivants :  `IHM PyQt5 pour échange entre un PC et une Nucléo <https://github.com/IOGS-LEnsE-embedded/Python_SupOpLibraries/tree/main/SerialComm>`_