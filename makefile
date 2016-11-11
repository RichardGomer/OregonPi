CXXFLAGS += -O2 -Wall -g -pthread

all: oregonrcv

test: RCSwitch.o RcOok.o Sensor.o test.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

oregonrcv: RCSwitch.o RcOok.o Sensor.o oregonrcv.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o test oregonrcv
