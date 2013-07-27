LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../lib .././spaceex --model-file TwoTrains.xml --rel-err '1.0e-12' --abs-err '1.0e-11' --output-error '0.001' --scenario 'phaver' --directions 'box' --set-aggregation 'none' --verbosity m --time-horizon '400000' --sampling-time '0.1' --simu-init-sampling-points '20' --flowpipe-tolerance '0.05' --iter-max '20000' --initially 'distance==-1 & trainsys_1.stationid==0 & pos1==0 & trainsys_1.train.v==0 & dir1==1 & trainsys_1.train.time==0 & urgentcontrol.urstopped_1==0 & trainsys_1.train.acc == 0 & trainsys_1.train.maxp ==0 & trainsys_1.traindoors.y==0 & trainsys_1.traindoors.needclose ==0 & trainsys_1.controller.z ==0 & trainsys_1.controller.sdid == 1 & trainsys_2.stationid==0 & pos2==0 & trainsys_2.train.v==0 & dir2==1 & trainsys_2.train.time==0 & urgentcontrol.urstopped_2==0 & trainsys_2.train.acc == 0 & trainsys_2.train.maxp ==0 & trainsys_2.traindoors.y==0 & trainsys_2.traindoors.needclose ==0 & trainsys_2.controller.z ==0 & trainsys_2.controller.sdid == 1 & screendoors_1.y==0 & screendoors_1.needclose ==0 & screendoors_2.y==0 & screendoors_2.needclose ==0 & screendoors_3.y==0& screendoors_3.needclose ==0 & screendoors_4.y==0 & screendoors_4.needclose ==0 & screendoors_5.y==0 & screendoors_5.needclose ==0 & screendoors_6.y==0 & screendoors_6.needclose ==0 & screendoors_7.y==0 & screendoors_7.needclose ==0 & screendoors_8.y==0& screendoors_8.needclose ==0 & trainsys_1.train.S==0 & trainsys_2.train.S==0 & urgentcontrol.t==0 & loc(urgentcontrol)==Delay & loc(trainsys_1.train)==init & loc(trainsys_2.train)==init & loc(trainsys_1.traindoors)==closed & loc(trainsys_2.traindoors)==closed & loc(trainsys_1.controller)==idle & loc(trainsys_2.controller)==idle & loc(screendoors_1)==closed & loc(screendoors_2)==closed & loc(screendoors_3)==closed & loc(screendoors_4)==closed & loc(screendoors_5)==closed & loc(screendoors_6)==closed & loc(screendoors_7)==closed & loc(screendoors_8)==closed & urgentcontrol.globalTime==0 ' --forbidden 'loc(trainsys_1.train)!=init & loc(trainsys_2.train)!=init & pos1==pos2' --system 'system' --output-format 'TXT' --output-variables globalTime,distance,pos1,pos2 --output-file run-2w-T1-T2-StopAtSameStation.TXT > run-2w-T1-T2-StopAtSameStation-TXT.log