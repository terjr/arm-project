--fgcolor black
--bgcolor white

--title Decomposable and Responsive Power Models for Multicore Processors using Performance Counters



--author Stian Hvatum <hvatum@stud.ntnu.no>
--author Terje Runde <terjr@stud.ntnu.no>

--date today

--newpage motivation
--heading Motivation


* Power wall

* A platform for online power-aware scheduling

---
--exec feh -Z -F Fig1.png
---
--exec feh -Z -F Fig2.png

--newpage outline
--heading Outline



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

--newpage methodology
--heading Methodology


Prerequisite: An overview of the microarchitectural components
---
--exec feh -Z -F Fig3.png

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

--newpage methodology_step1
--heading Step 1: Defining power components


* Inspect the microarchitecture and isolate as much as possible

* Problem: Some components are shared
           ==> Merge

--newpage methodology_step2
--heading Step 2: Define training benchmarks


* Create micro-benchmarks to stress particular power components

* Use syntetic applications

* Decouple power components

* Intel Core 2 Duo specific: fxch instruction

--newpage methodology_step3
--heading Step 3: Execute benchmarks and sample data


* Run benchmarks created in the previous step

* Turn off as much as possible

---
--exec feh -Z -F Tab2.png Eq1.png

--newpage methodology_step4
--heading Step 4: Create model


* Solve the linear system

* ...but do so incrementally



--newpage validation
--heading Validation

--boldon
Model Correctness
--boldoff


* All models performs about the same in terms of accuracy
    ==> Model accuracy has not improved

* ...however, standard deviation decreases when tracking more components

TODO: Pro'lly add Table 4?

--horline


--boldon
Model Responsiveness
--boldoff


* MICRO are far more responsive

* Phase detection algorithm

* Observation: 63% of phases are (2,10] seconds long
  ==> Long enough to overhead of power aware policies

--newpage conclusion
--heading Conclusion

--boldon
Power model must-haves
--boldoff

    * Accuracy

    * Responsiveness

    * Decomposability

--horline


--boldon
Shortcomings
--boldoff
* Hard to decompose proprietary architectures (e.g. ARM)
