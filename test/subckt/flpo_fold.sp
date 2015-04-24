* file flp9th.sp----9th order low-pass filter
*
*   reference: jiri vlach and kishore singhal, 'computer
*              methods for circuit analysis and design',
*              van nostrand reinhold co., 1983, pages 142
*              and 494 to 496.
*
*  pole/zero analysis and using vcvs as an ideal op-amp.
*  for just pole/zero analysis .ac statement is not required.



*.subckt in+ in- out
.subckt opamp 5 6 7 
gmm1 16 13 5 13 9.380000e-04
gmbm1 16 13 0 13 4.880000e-05
rdsm1 16 13 0.184713e+04
cbdm1 0 16 4.290000e-14
cbsm1 0 13 3.370000e-14
cgsm1 5 13 1.180000e-13

gmm2 17 13 6 13 9.390000e-04
gmbm2 17 13 0 13 4.890000e-05
rdsm2 17 13 3.174603e+04
cbdm2 0 17 2.460000e-14
cbsm2 0 13 3.370000e-14
cgsm2 6 13 1.180000e-13

gmm3 16 0 12 0 4.810000e-03
gmbm3 16 0 0 0 2.020000e-03
rdsm3 16 0 1.203369e+04
cbdm3 0 16 7.170000e-13
cbsm3 0 0 1.110000e-12
cgsm3 12 0 4.350000e-13

gmm4 17 0 12 0 4.810000e-03
gmbm4 17 0 0 0 2.020000e-03
rdsm4 17 0 1.206273e+04
cbdm4 0 17 3.880000e-13
cbsm4 0 0 1.110000e-12
cgsm4 12 0 4.350000e-13

c1 5 6 1.9857e-15
c2 16 0 6.5607e-15

gmm5 13 0 9 0 1.900000e-03
gmbm5 13 0 0 0 2.270000e-04
rdsm5 13 0 3.257329e+04
cbdm5 0 13 1.580000e-13
cbsm5 0 0 5.740000e-13
cgsm5 9 0 1.140000e-12

gmmn 15 16 11 16 2.680000e-03
gmbmn 15 16 0 16 4.800000e-04
rdsmn 15 16 2.114165e+04
cbdmn 0 15 1.790000e-13
cbsmn 0 16 2.460000e-13
cgsmn 11 16 2.180000e-13
cgb 11 0 7.80378e-15
cgd 11 15 4.13687e-15

gmm6 7 17 11 17 2.720000e-03
gmbm6 7 17 0 17 4.870000e-04
rdsm6 7 17 2.469136e+04
cbdm6 0 7 1.650000e-13
cbsm6 0 17 2.450000e-13
cgsm6 11 17 2.180000e-13

c3 11 0 7.80378e-15
c4 11 7 4.13687e-15

gmm8 15 18 10 18 1.600000e-03
gmbm8 15 18 0 18 9.070000e-05
rdsm8 15 18 2.557545e+04
cbdm8 0 15 6.680000e-14
cbsm8 0 18 1.500000e-13
cgsm8 10 18 2.940000e-13


gmm9 7 19 10 19 1.580000e-03
gmbm9 7 19 0 19 8.940000e-05
rdsm9 7 19 2.518892e+04
cbdm9 0 7 6.980000e-14
cbsm9 0 19 1.500000e-13
cgsm9 10 19 2.940000e-13


gmm10 18 0 14 0 1.520000e-03
gmbm10 18 0 0 0 1.900000e-04
rdsm10 18 0 2.597403e+04
cbdm10 0 18 1.500000e-13
cbsm10 0 0 1.750000e-13
cgsm10 14 0 2.940000e-13

gmm11 19 0 14 0 1.520000e-03
gmbm11 19 0 0 0 1.890000e-04
rdsm11 19 0 2.597403e+04
cbdm11 0 19 8.630000e-14
cbsm11 0 0 1.750000e-13
cgsm11 14 0 2.940000e-13

gmm7 16 12 16 12 1.550000e-04
gmbm7 16 12 0 12 3.460000e-05
rdsm7 16 12 2.272727e+05
cbdm7 0 16 3.600000e-14
cbsm7 0 12 4.770000e-14
cgsm7 16 12 6.840000e-15


cp 10 16 1.05904e-15
c5 16 0 3.19403e-15

gmm12 17 12 17 12 1.610000e-04
gmbm12 17 12 0 12 3.590000e-05
rdsm12 17 12 2.136752e+05
cbdm12 0 17 3.590000e-14
cbsm12 0 12 4.770000e-14
cgsm12 17 12 6.840000e-15


c6 10 17 1.05904e-15
c7 17 0 3.19403e-15


gmmp 10 0 10 0 1.330000e-04
gmbmp 10 0 0 0 1.190000e-05
rdsmp 10 0 2.427184e+05
cbdmp 0 10 9.400000e-15
cbsmp 0 0 2.180000e-14
cgsmp 10 0 4.210000e-14
c8 10 0 6.73335e-15

gmm13 9 0 9 0 1.970000e-04
gmbm13 9 0 0 0 2.410000e-05
rdsm13 9 0 3.039514e+05
cbdm13 0 9 3.180000e-14
cbsm13 0 0 3.520000e-14
cgsm13 9 0 1.200000e-13


gmm14 11 0 9 0 2.110000e-04
gmbm14 11 0 0 0 2.560000e-05
rdsm14 11 0 3.267974e+05
cbdm14 0 11 2.290000e-14
cbsm14 0 0 3.520000e-14
cgsm14 9 0 1.200000e-13



gmm15 12 9 0 9 4.460000e-05
gmbm15 12 9 0 9 3.370000e-06
rdsm15 12 9 7.812500e+05
cbdm15 0 12 2.910000e-15
cbsm15 0 9 4.390000e-15
cgsm15 0 9 2.810000e-14


gmm16 11 0 11 0 9.330000e-05
gmbm16 11 0 0 0 2.180000e-05
rdsm16 11 0 2.808989e+05
cbdm16 0 11 1.580000e-14
cbsm16 0 0 6.970000e-14
cgsm16 11 0 1.790000e-14

c9 11 0 6.73335e-15


gmm17 12 0 12 0 6.060000e-04
gmbm17 12 0 0 0 2.580000e-04
rdsm17 12 0 6.369427e+04
cbdm17 0 12 1.320000e-13
cbsm17 0 0 1.600000e-13
cgsm17 12 0 5.810000e-14


c10 12 0 3.97095e-15

gmm18 10 0 12 0 7.240000e-04
gmbm18 10 0 0 0 3.000000e-04
rdsm18 10 0 1.355014e+05
cbdm18 0 10 6.250000e-14
cbsm18 0 0 1.600000e-13
cgsm18 12 0 5.810000e-14

gmm19 0 14 15 14 1.450000e-03
gmbm19 0 14 0 14 8.620000e-05
rdsm19 0 14 1.712329e+04
cbdm19 0 0 2.840000e-14
cbsm19 0 14 8.560000e-14
cgsm19 15 14 2.240000e-13

gmm20 14 0 14 0 4.690000e-03
gmbm20 14 0 0 0 4.490000e-04
rdsm20 14 0 3.676471e+03
cbdm20 0 14 1.840000e-13
cbsm20 0 0 3.260000e-13
cgsm20 14 0 2.110000e-13

c11 14 0 5.1795e-15
 
*vininv 6 0 dc 0.0v 
*vinnon 5 0 dc 10.100810mv ac 1.0v 0
 
*.plot ac vp(7)
.ends
 
.subckt fdnr 1 
r1 1 2 2k
c1 2 3 12n
r2 3 4 3.3k
r3 4 5 3.3k
r4 5 6 4.5k
c2 6 0 10n
xop1 2 4 5 opamp
xop2 6 4 3 opamp
*eop1 5 0  2 4   1000 
*eop2 3 0  6 4   1000
.ends
*
rs 10 1 5.4779k
r12 1 2 4.44k
r23 2 3 3.2201k
r34 3 4 3.63678k
r45 4 20 1.2201k
c5 20 0 10n
x1 1 fdnr 
x2 2 fdnr 
x3 3 fdnr 
x4 4 fdnr 

vin 10 0 dc 0 ac 1
.ac dec 200 1 10k
*.print vm(20) vm(10) vp(20)
.print vdb(20)
*.graph ac vdb(20,10) par('db(vm(20)/vm(10))')
.options post=2 dcstep=1e3 x0r=-1.23456e+3 x1r=-1.23456e+2 x2r=1.23456e+3 fscal=1e-6 gscal=1e3 cscal=1e9 lscal=1e3
.end
