subplot(2,2,1),
plot(position.time,position.data(1,:));figure(gcf);
xlabel('Time');
title('Train-1');
ylabel('Position of Train-1');


subplot(2,2,2),
plot(position.time,position.data(2,:));figure(gcf);
xlabel('Time');
title('Train-2');
ylabel('Position of Train-2');

subplot(2,2,3),
plot(position.time,position.data(3,:));figure(gcf);
xlabel('Time');
title('Train-3');
ylabel('Position of Train-3');

subplot(2,2,4),
plot(position.time,position.data(4,:));figure(gcf);
xlabel('Time');
title('Train-4');
ylabel('Position of Train-4');

figure;
plot(position);figure(gcf);
xlabel('Time');
title('Four Trains');
ylabel('Positions Of Four Trains ');
