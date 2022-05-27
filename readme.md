# Reliability tools
Here, we propose algorithms for the calculation of Cohen’s K and associated measures (Kmax, Prevalence or P,and Bias or B) of behavioral ratings, aimed to estimate and evaluate inter- and intra-HO reliability. This software use bootstrap technique to infer this parameters to population, and calculate 95% confidence intervals for the metrics.



# DATA ANALYSIS  TOOLS: Intra- and inter observers reliability analysis


Interface to reliability analysis from transcriptions produced int [EthoWatcher-OS](ethowatcher.com)


![Gui](./realiability_tool_module_1.png)


## Load ethography button
Click this button to load the desirable ethography, do this step again to load the second ethography. Next, head to the Bootstrap controller.

## Bootstrap controller
Use this section to adjust some important parameters, configure and optimize the time required to perform bootstrap analysis. Next, click on the “Generate report” button

### Original matrix
Adjust this value to increase the speed in calculating the maximum AM of the catalog, the greater the number, the greater the divisions of values ​​in the cells, see a preview of the result in "Agreement matrice".

-TIP: Adjust so that the values in the cells are smaller without being equal to 0. The processing time is the value of each cell multiplied.

### Bootstrap matrices
 
Adjust this value to increase the speed of calculating the maximum agreement matrix of the catalog during the bootstrap technique, the greater the number the greater the divisions of values ​​in the cells, see a preview of the result in "Agreement matrice".

### Optimization of the prevalence and bias calculation
Adjust the maximum number of combinations explored by calculating bias and prevalence by adjusting this number.

### Bootstrap sample size
Adjust the amount of bootstrap sample size

### Threads

Adjust the amount of processing required during bootstrap analysis for the computer. BEWARE, the program may use 100% of the CPU and crash.

### Seed
Set the seed used in the bootstrap data generator, this parameter is for the result to be reproduced.

## Generate report
Click this button to run the agreement analysis routines for the uploaded ethography and produce a report with the results.


# Library
This program was develop with QT librarys and C++ 11, report are generate using a python script.