# Team 25

## Members
Student name: Zhen Zhang, student number:101002369
Student name: Guillaume St-Pierre, student number:101066038

## How to run
You can run our project using Qt Creator

In our project, there are two sub-projects that are used to manage the different parts of the project: the app sub-project and the tests sub-project.

To run a specific sub-project, right click on that given project and select "run". Make sure you have cleaned the main project build before you run the application so you don't use an old version.

### App sub-project
The App sub-project contains our main application for simulating the device. On the main window, there is one screen and seven button.
* Pwr button can be used to turn on and turn off the device.
* → ← ↑ ↓ buttons are used to control the selection on the main screen and set values when necessary.
* Enter button is used to select something or move forward in the application.
* Back button is used to go back one step.
* Menu button is used to go back to the main menu.

On the main screen, you are given three options. Change which option is selected with the ↑ ↓ buttons and press enter to select. **PROGRAMS** will display the possible treatment programs, once you have selected one, enter the power level with → ← and start the treatment by pressing enter. **FREQUENCIES** will display the available frequencies for a more specific treatment, enter the power level and start the treatment like you would in the **PROGRAMS** menu. **SETTINGS** will display the settings form where you can change some of the settings (Not covered by our simulation).

### Tests sub-project
The test sub-project contains all the units tests for the app project.

The main files are for testing specific functionalities on all the classes and making sure things work as expected.

The files names `tst_uc<number>` are the tests that execute specific use cases and their extensions to make sure that they are working and tested. Refer to the testability matrix for more information.
