$(CC)=gcc

appn  : cal.o cal_mean.o cal_sub.o
	$(CC) cal.o cal_mean.o cal_sub.o -o appn

cal.o : cal.c cal_mean.h
	$(CC) -c cal.c

cal_mean.o : cal_mean.c cal_mean.h
	$(CC) -c cal_mean.c

cal_sub.o : cal_sub.c cal_mean.h
	$(CC) -c cal_sub.c

clean : 
	rm -f *.o
