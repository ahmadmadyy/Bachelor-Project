num = [1];
%Cheetah
den = [7.9 68 10930.4];
CheetahOL = tf(num,den)
K_p1 = 4.2294;
K_i1 = 65.5225;
K_d1 = 0.068083;
N1 = 12962.0285;
C1 = pid(K_p1,K_i1,K_d1,N1)
CheetahCL = feedback(CheetahOL*C1,1)
Cnew1 = c2d(CheetahCL,0.01)

%Kangaroo
den2 = [7.3 68 10930.4];
KangarooOL = tf(num,den2)
K_p2 = 4.1693;
K_i2 = 67.1737;
K_d2 = 0.064537;
N2 = 13393.6142;
C2 = pid(K_p2,K_i2,K_d2,N2)
KangarooCL = feedback(KangarooOL*C2,1)
Cnew2 = c2d(KangarooCL,0.01)