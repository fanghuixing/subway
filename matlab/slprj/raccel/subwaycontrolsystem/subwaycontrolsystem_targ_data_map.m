  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% rtP.b3_Value
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.a3_Value
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.b2_Value
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.a2_Value
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.b1_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.a1_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.b_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.a_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.d7_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.c7_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.d6_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.c6_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.d5_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtP.c5_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtP.d4_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtP.c4_Value
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtP.d3_Value
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtP.c3_Value
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtP.d2_Value
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtP.c2_Value
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtP.d1_Value
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtP.c1_Value
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtP.d_Value
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtP.c_Value
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtP.TDV_CurrentSetting
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.TDV1_CurrentSetting
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.TDV2_CurrentSetting
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.TDV3_CurrentSetting
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.PSDV_CurrentSetting
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.PSDV1_CurrentSetting
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.PSDV2_CurrentSetting
	  section.data(7).logicalSrcIdx = 30;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.PSDV3_CurrentSetting
	  section.data(8).logicalSrcIdx = 31;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.PSDV4_CurrentSetting
	  section.data(9).logicalSrcIdx = 32;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.PSDV5_CurrentSetting
	  section.data(10).logicalSrcIdx = 33;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.PSDV6_CurrentSetting
	  section.data(11).logicalSrcIdx = 34;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.PSDV7_CurrentSetting
	  section.data(12).logicalSrcIdx = 35;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtB.mgreqddwbk
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.nojiyg1svu
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.h32onzoiii
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.cytqvalje5
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.mewmcyb4gt
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.l3p1u43lj0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtB.bdv4orwwct
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtB.gotfm0hfnu
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 16;
	
	  ;% rtB.e2bcofptlp
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDWork)
    ;%
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% rtDWork.csmhj2mobz
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.bzilocoerc
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.e5i3qovgis
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 5;
	
	  ;% rtDWork.ov5pkqlglu
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
	  ;% rtDWork.jknd2rgprd
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 17;
	
	  ;% rtDWork.isgvs5svtv
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 25;
	
	  ;% rtDWork.omfdvdtquy
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 29;
	
	  ;% rtDWork.j04e3heoks
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 33;
	
	  ;% rtDWork.duzuwa454g
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 37;
	
	  ;% rtDWork.kd0unb3ts3
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 41;
	
	  ;% rtDWork.ms2wqypsep
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 45;
	
	  ;% rtDWork.bdoe3sih52
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 49;
	
	  ;% rtDWork.guc4ezu4vd
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 53;
	
	  ;% rtDWork.a2j0p0cym5
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 57;
	
	  ;% rtDWork.mhps55ndar
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 65;
	
	  ;% rtDWork.ppgpg2d5gp
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 66;
	
	  ;% rtDWork.avfoep3api
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 67;
	
	  ;% rtDWork.k3zetjkg2t
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 68;
	
	  ;% rtDWork.pd5fkmhg4c
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 69;
	
	  ;% rtDWork.igjejaivpx
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 70;
	
	  ;% rtDWork.ne5tcs23kl
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 71;
	
	  ;% rtDWork.bkhrmaqhhj
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 72;
	
	  ;% rtDWork.fsek2utpw2
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 73;
	
	  ;% rtDWork.nuqllrp43p
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 74;
	
	  ;% rtDWork.n5wof223jc
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 75;
	
	  ;% rtDWork.lmgwt2ihoi
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 76;
	
	  ;% rtDWork.eyeyekatwb
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 77;
	
	  ;% rtDWork.esraav3jfu
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 78;
	
	  ;% rtDWork.edvs5rk3fa
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 79;
	
	  ;% rtDWork.c1gduapxde
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 80;
	
	  ;% rtDWork.bffxdmyjnr
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 81;
	
	  ;% rtDWork.drbwe4rydf
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 82;
	
	  ;% rtDWork.fao3lacynd
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 83;
	
	  ;% rtDWork.acxds11k1q
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 84;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDWork.fcdtvsyw4o.LoggedData
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% rtDWork.jxt0tifn1m
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.mgytiqynw0
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.op2f2jmd1g
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.l2jamqzsvo
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 6;
	
	  ;% rtDWork.gophpoqjs0
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtDWork.bso50stzuv
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtDWork.kiu22l5yga
	  section.data(7).logicalSrcIdx = 41;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtDWork.pvpbflzhwc
	  section.data(8).logicalSrcIdx = 42;
	  section.data(8).dtTransOffset = 13;
	
	  ;% rtDWork.eli0bu1nqi
	  section.data(9).logicalSrcIdx = 43;
	  section.data(9).dtTransOffset = 14;
	
	  ;% rtDWork.p5wmqc33qy
	  section.data(10).logicalSrcIdx = 44;
	  section.data(10).dtTransOffset = 15;
	
	  ;% rtDWork.ov1u3dz22b
	  section.data(11).logicalSrcIdx = 45;
	  section.data(11).dtTransOffset = 16;
	
	  ;% rtDWork.hodq0clkgt
	  section.data(12).logicalSrcIdx = 46;
	  section.data(12).dtTransOffset = 17;
	
	  ;% rtDWork.o4qhycsmoh
	  section.data(13).logicalSrcIdx = 47;
	  section.data(13).dtTransOffset = 18;
	
	  ;% rtDWork.mf54iquk4a
	  section.data(14).logicalSrcIdx = 48;
	  section.data(14).dtTransOffset = 19;
	
	  ;% rtDWork.gt42aq5wqz
	  section.data(15).logicalSrcIdx = 49;
	  section.data(15).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 44;
      section.data(44)  = dumData; %prealloc
      
	  ;% rtDWork.cj4jryemsn
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.argt12xgun
	  section.data(2).logicalSrcIdx = 51;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.ek5x23uca5
	  section.data(3).logicalSrcIdx = 52;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.gorxzp2tc5
	  section.data(4).logicalSrcIdx = 53;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDWork.milvjxyyuk
	  section.data(5).logicalSrcIdx = 54;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDWork.gbpi15raxo
	  section.data(6).logicalSrcIdx = 55;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDWork.lpvn5skrbx
	  section.data(7).logicalSrcIdx = 56;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDWork.l5nch0wfe0
	  section.data(8).logicalSrcIdx = 57;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDWork.mk3y1ej5sc
	  section.data(9).logicalSrcIdx = 58;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDWork.e0siqbw4px
	  section.data(10).logicalSrcIdx = 59;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDWork.f4ecgcwjef
	  section.data(11).logicalSrcIdx = 60;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDWork.e2s0vhz32j
	  section.data(12).logicalSrcIdx = 61;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDWork.dv1e4s4igc
	  section.data(13).logicalSrcIdx = 62;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDWork.af0eeezn4z
	  section.data(14).logicalSrcIdx = 63;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDWork.gwkbtmpoqm
	  section.data(15).logicalSrcIdx = 64;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDWork.h0gr1gfnip
	  section.data(16).logicalSrcIdx = 65;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDWork.dq53dldqu5
	  section.data(17).logicalSrcIdx = 66;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDWork.pwv1ttrztn
	  section.data(18).logicalSrcIdx = 67;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDWork.h1eicbufky
	  section.data(19).logicalSrcIdx = 68;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDWork.lfw2ucpenn
	  section.data(20).logicalSrcIdx = 69;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDWork.a3d24qkbyc
	  section.data(21).logicalSrcIdx = 70;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDWork.psc01ml3a2
	  section.data(22).logicalSrcIdx = 71;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDWork.idrkgh24mh
	  section.data(23).logicalSrcIdx = 72;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDWork.ho4yv0pef5
	  section.data(24).logicalSrcIdx = 73;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDWork.ee02mqd4oz
	  section.data(25).logicalSrcIdx = 74;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDWork.fgm4uvex5n
	  section.data(26).logicalSrcIdx = 75;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDWork.hwylozrfgv
	  section.data(27).logicalSrcIdx = 76;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDWork.kxzqsowcq4
	  section.data(28).logicalSrcIdx = 77;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDWork.j2iwqhng5v
	  section.data(29).logicalSrcIdx = 78;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDWork.puu0onps1o
	  section.data(30).logicalSrcIdx = 79;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtDWork.ityqbqwxs3
	  section.data(31).logicalSrcIdx = 80;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtDWork.m1coawef1z
	  section.data(32).logicalSrcIdx = 81;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtDWork.c20f0hecbl
	  section.data(33).logicalSrcIdx = 82;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtDWork.piy1mfyq04
	  section.data(34).logicalSrcIdx = 83;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtDWork.aaa3dwwbpb
	  section.data(35).logicalSrcIdx = 84;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtDWork.cor0ek34i1
	  section.data(36).logicalSrcIdx = 85;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtDWork.p1swflzbuh
	  section.data(37).logicalSrcIdx = 86;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtDWork.bieuzbl5sa
	  section.data(38).logicalSrcIdx = 87;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtDWork.pqex5itzoo
	  section.data(39).logicalSrcIdx = 88;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtDWork.m4axwklc2n
	  section.data(40).logicalSrcIdx = 89;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtDWork.kkmwpgcwey
	  section.data(41).logicalSrcIdx = 90;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtDWork.d5gd34izwy
	  section.data(42).logicalSrcIdx = 91;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtDWork.hjfnzxphh4
	  section.data(43).logicalSrcIdx = 92;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtDWork.lfluclczgd
	  section.data(44).logicalSrcIdx = 93;
	  section.data(44).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDWork.fwktsfwhv4
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.jviamtmzv0
	  section.data(2).logicalSrcIdx = 95;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.ag3dlvdnni
	  section.data(3).logicalSrcIdx = 96;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.p4v1pjyxuj
	  section.data(4).logicalSrcIdx = 97;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1570811217;
  targMap.checksum1 = 3232968676;
  targMap.checksum2 = 3323065162;
  targMap.checksum3 = 1679384083;

