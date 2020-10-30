CC = g++
CFLAGS = -g
COPTFLAGS = -O3 -g
LDFLAGS =

default:
	@echo "=================================================="
	@echo "To build your code, use:"
	@echo "  make edit      # For EditDistance.cpp"
	@echo ""
	@echo "To clean this subdirectory (remove object files"
	@echo "and other junk), use:"
	@echo "  make clean"
	@echo "=================================================="

# Queue driver 
edit: EditDistance.o
	$(CC) $(COPTFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) $(COPTFLAGS) -o $@ -c $<

clean:
	rm -f core *.o *~ edit

# eof
