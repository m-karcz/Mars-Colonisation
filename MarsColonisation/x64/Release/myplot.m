close all;
for i = 1:5
    num = int2str(i);
    filename = strcat(num,'.txt');
    solution = load(filename);
    figure(i);
    hold on;
    grid on;
    plot(solution(:,1),'r-');
    plot(solution(:,2),'b-');
    xlabel('Iteracja');
    ylabel('Warto�� funkcji celu');
    title('Przebieg rozwi�zania');
    legend('Aktualne rozwi�zanie','Najlepsze rozwi�zanie','Location','southeast');
    pngname = strcat(num,'plot','.png');
    saveas(figure(i),pngname);
    close all;
end