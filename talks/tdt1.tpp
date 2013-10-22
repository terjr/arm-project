--fgcolor black
--bgcolor white

--title Decomposable and Responsive Power Models for Multicore Processors using Performance Counters



--author Stian Hvatum <hvatum@stud.ntnu.no>
--author Terje Runde <terjr@stud.ntnu.no>

--date today

--newpage motivation
--heading Motivation


* Need to _UNDERSTAND_ power consumption to _LOWER_ it

* A platform for online power-aware scheduling


--newpage outline
--heading Outline



--newpage perfcounters
--heading Performance Counters Recap


* Registers counting distinct events in and around the processor
TODO: Maybe a picture?

* 

--newpage observations
--heading Observations


Current models...


* ...are not fine-grained enough to model modern architectures
    - Superscalarity
    - Out-of-order execution

* ...are only evaluated by their ACCURACY
    - We want RESPONSIVENESS too


* ...does not apply to upcoming architectures
---

--center Solution: Define power components

--newpage methology
--heading Methology


Prerequisite: An overview of the microarchitectural components
---
--##exec feh -Z -F Fig3.png

Algorithm
--beginoutput
1) Define power components
---
2) Define training benchmarks
---
3) Execute benchmarks and sample data
---
4) Create model
--endoutput

--newpage methology_step1
--heading Step 1: Defining power components


* Inspect the microarchitecture and isolate as much as possible

* Problem: Some components are shared
           ==> Merge

--newpage methology_step2
--heading Step 2: Define training benchmarks


* Create micro-benchmarks to stress particular power components

* Use syntetic applications

* Decouple power components

* Intel Core 2 Duo specific: fxch instruction

--newpage methology_step3
--heading Step 3: Execute benchmarks and sample data


* Run benchmarks created in the previous step

* Turn off as much as possible

---
--##exec feh -Z -F Tab2.png

--newpage methology_step4
--heading Step 4: Create model


* Solve the linear system

--newpage shortcomings
--heading Shortcomings

* Hard to decompose unknown architectures (e.g. ARM)

--newpage notes
--heading Notes
- accuracy, responsiveness and decomposability :: power model must-haves
- should apply to up-and-coming architectures
